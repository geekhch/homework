// 文件路径名: translator\sclaa_ctranslator.cpp
#include "sclass_ctranslator.h"						// 包含译码器类的声明

// 译码器类的实现
void CTranslator::SkipSapces()						// 跳过空白(包括空格,制表符,换行符)
{
	char ch= fin.get();								// 接收字符
	while (isspace(ch)) ch = fin.get();				// 如ch为空白,则循环
	fin.putback(ch);								// 将非空白字符ch回送输入流
}

bool CTranslator::GetToken(string &token)			// 读取标记
{ 
	char ch, ch1;									// 用于接收字符
	static bool trackIndent = true;					// 是否追踪缩进字符串

	token = "";										// 置标记token为空串
	ch = fin.get();									// 从输入流fin取得字符
	if (fin.eof()) return false;					// 文件已结束,返回fasle
	
	if (isspace(ch) && ch != '\n')								
	{	// 处理空白串
		while (isspace(ch) && ch != '\n')
		{	// 循环处理空白字符
			token += ch;							// 将ch追加到标记token的末尾
			if (trackIndent) indent += ch;			// ch追加到缩进字符串末尾
			ch = fin.get();							// 从输入流fin取得字符
			if (fin.eof()) return false;			// 文件已结束,返回fasle
		}
		fin.putback(ch);							// 将非空白字符ch回送输入流
		return true;								// 文件未结束,返回true
	}

	if (ch == '\n')								
	{	// 换行符
		indent = "";								// 缩进空白串置空		
		trackIndent = true;							// 开始追踪缩进字符串
	}
	else trackIndent = false;						// 遇到非空白字符,结束追踪缩进字符串

	if (isalpha(ch) || ch == '_')
	{	// 标识符以字母或下划线开始
		while (isalpha(ch) || isdigit(ch) || ch == '_')
		{	// 标识符可包含字母,数字与下划线
			token += ch;							// 将ch追加到标记token的末尾
			ch = fin.get();							// 从输入流fin取得字符
			if (fin.eof()) return false;			// 文件已结束,返回fasle
		}
		fin.putback(ch);							// 将非标识符字符ch回送输入流
		return true;								// 文件未结束,返回true
	}

	if (isdigit(ch))
	{	// 以数字开始的数值
		while (isdigit(ch) || ch == '.' || ch == 'e' || ch == '+' || ch == '-' )
		{	// 数值可包含数字,小数点,字母e,正负号
			token += ch;							// 将ch追加到标记token的末尾
			ch = fin.get();							// 从输入流fin取得字符
			if (fin.eof()) return false;			// 文件已结束,返回fasle
		}
		fin.putback(ch);							// 将非数值字符ch回送输入流
		return true;								// 文件未结束,返回true
	}

	if (ch == '/')									
	{	// 处理"//"
		ch1 = fin.get();							// 从输入流fin取得字符
		if (fin.eof()) { cout << "文件异常结束!" << endl; exit(1); }// 文件异常结束
		if (ch1 == '/')
		{	// 表示"//"
			token += ch;							// 将ch(即字符'/')追加到标记token的末尾
			token += ch1;							// 将ch(即字符'/')追加到标记token的末尾
			return true;							// 文件未结束,返回true
		}
		else fin.putback(ch1);						// 将ch1回送到输入流fin
	}

	if (ch == '/')									
	{	// 处理"/*"
		ch1 = fin.get();							// 从输入流fin取得字符
		if (fin.eof()) { cout << "文件异常结束!" << endl; exit(2); }// 文件异常结束
		if (ch1 == '*')
		{	// 表示"/*"
			token += ch;							// 将ch(即字符'/')追加到标记token的末尾
			token += ch1;							// 将ch(即字符'*')追加到标记token的末尾
			return true;							// 文件未结束,返回true
		}
		else fin.putback(ch1);						// 将ch1回送到输入流fin
	}

	if (ch == '*')									
	{	// 处理"*/"
		ch1 = fin.get();							// 从输入流fin取得字符
		if (fin.eof()) { cout << "文件异常结束!" << endl; exit(3); }// 文件异常结束
		if (ch1 == '/')
		{	// 表示"*/"
			token += ch;							// 将ch(即字符'*')追加到标记token的末尾
			token += ch1;							// 将ch(即字符'/')追加到标记token的末尾
			return true;							// 文件未结束,返回true
		}
		else fin.putback(ch1);						// 将ch1回送到输入流fin
	}

	token += ch;									// 其它情况,将ch作为标记
	return true;									// 文件未结束,返回true
}

string CTranslator::IntToStr(int i)					// 将整数i转化为长度为4的串 
{
	char str[5];									// 临时串

	if (i <= 0 || i > 9999) { cout << "整数超过范围!" << endl; exit(4); }// 整数超过范围
	str[4] = '\0';									// 串结束符
	for (int pos = 3; pos >= 0; pos--)
	{	// 依次将各位数字存入串str中
		str[pos] = i % 10 + '0';					// 将i的个位数字转化为字符存放str[pos]中			
		i = i / 10;									// 将i去除个位数字后的整数存入i
	}

	return str;										// 返回串
}

void CTranslator::ForEach()							// 处理foreach循环
//	例如:
//	foreach(double v in a)
//	转化为:
//	int _i0001 = 0;
//	for (double v = a[0];
//		-i0001 < sizeof(a) / sizeof(a[0]);
//		-i0001++, v = a[i0001])
{
	static int counter = 0;							// 记数器
	string token;									// 标记
	string forVarName = "_i" + IntToStr(++counter);	// for循环变量名(从_i0001到_i9999)
	string typeName, arrayName;						// 类型名, 数组名
	
	// 读取相关信息, 例如读取"foreach(double v in a)"中的"(double v in a)"
	SkipSapces();									// 跳过空白(包括空格,制表符,换行符)
	GetToken(token);								// 读取标记(应为"(")
	if (token != "(") { cout << "应为(" << endl; exit(5); }// 应为(
	
	SkipSapces();									// 跳过空白(包括空格,制表符,换行符)
	GetToken(token);								// 读取标记(应为类例,例如"double")
	typeName = token;								// 类型名(例如"double")
	
	SkipSapces();									// 跳过空白(包括空格,制表符,换行符)
	GetToken(token);								// 读取标记(变量名,例如"v")
	string varName = token;							// 变量名(例如"v")
	
	SkipSapces();									// 跳过空白(包括空格,制表符,换行符)
	GetToken(token);								// 读取标记(应为"in")
	if (token != "in") { cout << "应为in" << endl; exit(6); }// 应为in

	SkipSapces();									// 跳过空白(包括空格,制表符,换行符)
	GetToken(token);								// 读取标记(应为数据名,例如"a")
	arrayName = token;								// 数组名(例如"a")
	
	SkipSapces();									// 跳过空白(包括空格,制表符,换行符)
	GetToken(token);								// 读取标记(应为")")
	if (token != ")") { cout << "应为)" << endl; exit(7); }// 应为)
	
	// 输出相关信息
	fout << "int " << forVarName << " = 0;" << endl;				// 用于定义变量(例如: int _i0001 = 0;)
	fout << indent << "for ( " << typeName << " "					// 用于输出for循环第1行
		<< varName << " = " << arrayName << "[0];" << endl;			// 例如: for (double v = a[0];
	fout << indent << '\t' << forVarName << " < sizeof("			// 用于输出for循环第2行
		<< arrayName << ") / sizeof(" << arrayName << "[0]);" << endl;
		// 例如: 	-i0001 < sizeof(a) / sizeof(a[0]);
	fout << indent << '\t' << forVarName << "++, " << varName		// 用于输出for循环第3行
		<< " = " << arrayName << "[" << forVarName << "])";			// 例如: 	-i0001++, v = a[i0001])
}

CTranslator::CTranslator(const string &infName, const string &outfName):
	fin(infName.c_str()), fout(outfName.c_str()), indent("")		// 构造函数
{
	if (fin.fail()) { cout << "打开文失败!" << endl; exit(8); }		// 打开文失败!
	if (fout.fail()) { cout << "打开文失败!" << endl; exit(9); }	// 打开文失败!
}

void CTranslator::Run()								// 运行译码器
{
	string token;									// 标记串
	while (GetToken(token))
	{	// 输入文件未结束
		if (token == "//")
		{	// 处理以//开始的注释
			do
			{
				fout << token;						// 输出标记
				if (!GetToken(token)) return;		// 读取新标记
			} while (token != "\n");				// 标记不是换行,则循环
			fout << token;							// 输出最后的标记(含换行符,表示以"//"开始的注释行已结束)
		}
		else if (token == "/*")
		{	// 处理以/*开始的注释
			do
			{
				fout << token;						// 输出标记
				if (!GetToken(token)) { cout << "文件异常标记" << endl; exit(10); }
					// 读取新标记,如遇文件结束,则抛出异常
			} while (token != "*/");				// 标记不为"*/",则循环
			fout << token;							// 输出最后的标记"*/"
		}
		else if (token == "\"")
		{	// 处理以以'\"'开始的字符串
			do
			{
				fout << token;						// 输出标记
				if (!GetToken(token)) { cout << "文件异常标记" << endl; exit(11); }
					// 读取新标记,如遇文件结束,则抛出异常
			} while (token != "\"");				// 标记不为"\"",串未结束,则循环
			fout << token;							// 输出最后的标记"\""
		}
		else if (token == "foreach") ForEach();		// 处理foreach循环
		else fout << token;							// 输出一般的标记
	}
}
