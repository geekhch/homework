// �ļ�·����: translator\sclaa_ctranslator.cpp
#include "sclass_ctranslator.h"						// �����������������

// ���������ʵ��
void CTranslator::SkipSapces()						// �����հ�(�����ո�,�Ʊ��,���з�)
{
	char ch= fin.get();								// �����ַ�
	while (isspace(ch)) ch = fin.get();				// ��chΪ�հ�,��ѭ��
	fin.putback(ch);								// ���ǿհ��ַ�ch����������
}

bool CTranslator::GetToken(string &token)			// ��ȡ���
{ 
	char ch, ch1;									// ���ڽ����ַ�
	static bool trackIndent = true;					// �Ƿ�׷�������ַ���

	token = "";										// �ñ��tokenΪ�մ�
	ch = fin.get();									// ��������finȡ���ַ�
	if (fin.eof()) return false;					// �ļ��ѽ���,����fasle
	
	if (isspace(ch) && ch != '\n')								
	{	// ����հ״�
		while (isspace(ch) && ch != '\n')
		{	// ѭ������հ��ַ�
			token += ch;							// ��ch׷�ӵ����token��ĩβ
			if (trackIndent) indent += ch;			// ch׷�ӵ������ַ���ĩβ
			ch = fin.get();							// ��������finȡ���ַ�
			if (fin.eof()) return false;			// �ļ��ѽ���,����fasle
		}
		fin.putback(ch);							// ���ǿհ��ַ�ch����������
		return true;								// �ļ�δ����,����true
	}

	if (ch == '\n')								
	{	// ���з�
		indent = "";								// �����հ״��ÿ�		
		trackIndent = true;							// ��ʼ׷�������ַ���
	}
	else trackIndent = false;						// �����ǿհ��ַ�,����׷�������ַ���

	if (isalpha(ch) || ch == '_')
	{	// ��ʶ������ĸ���»��߿�ʼ
		while (isalpha(ch) || isdigit(ch) || ch == '_')
		{	// ��ʶ���ɰ�����ĸ,�������»���
			token += ch;							// ��ch׷�ӵ����token��ĩβ
			ch = fin.get();							// ��������finȡ���ַ�
			if (fin.eof()) return false;			// �ļ��ѽ���,����fasle
		}
		fin.putback(ch);							// ���Ǳ�ʶ���ַ�ch����������
		return true;								// �ļ�δ����,����true
	}

	if (isdigit(ch))
	{	// �����ֿ�ʼ����ֵ
		while (isdigit(ch) || ch == '.' || ch == 'e' || ch == '+' || ch == '-' )
		{	// ��ֵ�ɰ�������,С����,��ĸe,������
			token += ch;							// ��ch׷�ӵ����token��ĩβ
			ch = fin.get();							// ��������finȡ���ַ�
			if (fin.eof()) return false;			// �ļ��ѽ���,����fasle
		}
		fin.putback(ch);							// ������ֵ�ַ�ch����������
		return true;								// �ļ�δ����,����true
	}

	if (ch == '/')									
	{	// ����"//"
		ch1 = fin.get();							// ��������finȡ���ַ�
		if (fin.eof()) { cout << "�ļ��쳣����!" << endl; exit(1); }// �ļ��쳣����
		if (ch1 == '/')
		{	// ��ʾ"//"
			token += ch;							// ��ch(���ַ�'/')׷�ӵ����token��ĩβ
			token += ch1;							// ��ch(���ַ�'/')׷�ӵ����token��ĩβ
			return true;							// �ļ�δ����,����true
		}
		else fin.putback(ch1);						// ��ch1���͵�������fin
	}

	if (ch == '/')									
	{	// ����"/*"
		ch1 = fin.get();							// ��������finȡ���ַ�
		if (fin.eof()) { cout << "�ļ��쳣����!" << endl; exit(2); }// �ļ��쳣����
		if (ch1 == '*')
		{	// ��ʾ"/*"
			token += ch;							// ��ch(���ַ�'/')׷�ӵ����token��ĩβ
			token += ch1;							// ��ch(���ַ�'*')׷�ӵ����token��ĩβ
			return true;							// �ļ�δ����,����true
		}
		else fin.putback(ch1);						// ��ch1���͵�������fin
	}

	if (ch == '*')									
	{	// ����"*/"
		ch1 = fin.get();							// ��������finȡ���ַ�
		if (fin.eof()) { cout << "�ļ��쳣����!" << endl; exit(3); }// �ļ��쳣����
		if (ch1 == '/')
		{	// ��ʾ"*/"
			token += ch;							// ��ch(���ַ�'*')׷�ӵ����token��ĩβ
			token += ch1;							// ��ch(���ַ�'/')׷�ӵ����token��ĩβ
			return true;							// �ļ�δ����,����true
		}
		else fin.putback(ch1);						// ��ch1���͵�������fin
	}

	token += ch;									// �������,��ch��Ϊ���
	return true;									// �ļ�δ����,����true
}

string CTranslator::IntToStr(int i)					// ������iת��Ϊ����Ϊ4�Ĵ� 
{
	char str[5];									// ��ʱ��

	if (i <= 0 || i > 9999) { cout << "����������Χ!" << endl; exit(4); }// ����������Χ
	str[4] = '\0';									// ��������
	for (int pos = 3; pos >= 0; pos--)
	{	// ���ν���λ���ִ��봮str��
		str[pos] = i % 10 + '0';					// ��i�ĸ�λ����ת��Ϊ�ַ����str[pos]��			
		i = i / 10;									// ��iȥ����λ���ֺ����������i
	}

	return str;										// ���ش�
}

void CTranslator::ForEach()							// ����foreachѭ��
//	����:
//	foreach(double v in a)
//	ת��Ϊ:
//	int _i0001 = 0;
//	for (double v = a[0];
//		-i0001 < sizeof(a) / sizeof(a[0]);
//		-i0001++, v = a[i0001])
{
	static int counter = 0;							// ������
	string token;									// ���
	string forVarName = "_i" + IntToStr(++counter);	// forѭ��������(��_i0001��_i9999)
	string typeName, arrayName;						// ������, ������
	
	// ��ȡ�����Ϣ, �����ȡ"foreach(double v in a)"�е�"(double v in a)"
	SkipSapces();									// �����հ�(�����ո�,�Ʊ��,���з�)
	GetToken(token);								// ��ȡ���(ӦΪ"(")
	if (token != "(") { cout << "ӦΪ(" << endl; exit(5); }// ӦΪ(
	
	SkipSapces();									// �����հ�(�����ո�,�Ʊ��,���з�)
	GetToken(token);								// ��ȡ���(ӦΪ����,����"double")
	typeName = token;								// ������(����"double")
	
	SkipSapces();									// �����հ�(�����ո�,�Ʊ��,���з�)
	GetToken(token);								// ��ȡ���(������,����"v")
	string varName = token;							// ������(����"v")
	
	SkipSapces();									// �����հ�(�����ո�,�Ʊ��,���з�)
	GetToken(token);								// ��ȡ���(ӦΪ"in")
	if (token != "in") { cout << "ӦΪin" << endl; exit(6); }// ӦΪin

	SkipSapces();									// �����հ�(�����ո�,�Ʊ��,���з�)
	GetToken(token);								// ��ȡ���(ӦΪ������,����"a")
	arrayName = token;								// ������(����"a")
	
	SkipSapces();									// �����հ�(�����ո�,�Ʊ��,���з�)
	GetToken(token);								// ��ȡ���(ӦΪ")")
	if (token != ")") { cout << "ӦΪ)" << endl; exit(7); }// ӦΪ)
	
	// ��������Ϣ
	fout << "int " << forVarName << " = 0;" << endl;				// ���ڶ������(����: int _i0001 = 0;)
	fout << indent << "for ( " << typeName << " "					// �������forѭ����1��
		<< varName << " = " << arrayName << "[0];" << endl;			// ����: for (double v = a[0];
	fout << indent << '\t' << forVarName << " < sizeof("			// �������forѭ����2��
		<< arrayName << ") / sizeof(" << arrayName << "[0]);" << endl;
		// ����: 	-i0001 < sizeof(a) / sizeof(a[0]);
	fout << indent << '\t' << forVarName << "++, " << varName		// �������forѭ����3��
		<< " = " << arrayName << "[" << forVarName << "])";			// ����: 	-i0001++, v = a[i0001])
}

CTranslator::CTranslator(const string &infName, const string &outfName):
	fin(infName.c_str()), fout(outfName.c_str()), indent("")		// ���캯��
{
	if (fin.fail()) { cout << "����ʧ��!" << endl; exit(8); }		// ����ʧ��!
	if (fout.fail()) { cout << "����ʧ��!" << endl; exit(9); }	// ����ʧ��!
}

void CTranslator::Run()								// ����������
{
	string token;									// ��Ǵ�
	while (GetToken(token))
	{	// �����ļ�δ����
		if (token == "//")
		{	// ������//��ʼ��ע��
			do
			{
				fout << token;						// ������
				if (!GetToken(token)) return;		// ��ȡ�±��
			} while (token != "\n");				// ��ǲ��ǻ���,��ѭ��
			fout << token;							// ������ı��(�����з�,��ʾ��"//"��ʼ��ע�����ѽ���)
		}
		else if (token == "/*")
		{	// ������/*��ʼ��ע��
			do
			{
				fout << token;						// ������
				if (!GetToken(token)) { cout << "�ļ��쳣���" << endl; exit(10); }
					// ��ȡ�±��,�����ļ�����,���׳��쳣
			} while (token != "*/");				// ��ǲ�Ϊ"*/",��ѭ��
			fout << token;							// ������ı��"*/"
		}
		else if (token == "\"")
		{	// ��������'\"'��ʼ���ַ���
			do
			{
				fout << token;						// ������
				if (!GetToken(token)) { cout << "�ļ��쳣���" << endl; exit(11); }
					// ��ȡ�±��,�����ļ�����,���׳��쳣
			} while (token != "\"");				// ��ǲ�Ϊ"\"",��δ����,��ѭ��
			fout << token;							// ������ı��"\""
		}
		else if (token == "foreach") ForEach();		// ����foreachѭ��
		else fout << token;							// ���һ��ı��
	}
}
