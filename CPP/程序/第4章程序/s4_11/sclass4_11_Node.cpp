//���ʵ���ļ�
//�ļ�����s4_11\sclass4_11_Node.cpp

#include <iostream>  					//����ͷ�ļ�,ʹ��iostream��
#include "sclass4_11_Node.h"    		//����������ͷ�ļ�

/*****************************************************************************/
//CNode�Ĵ��ι��캯��
CNode::CNode(string str)				//�ڵ㹹�캯��
{
	m_pStr = new string(str);			//new�ַ�������ռ䣬��ڵ���
	if( m_pStr==NULL )
	{
		cout << "�ڴ����ʧ�ܡ�" << endl;
		exit(0);						//�ڴ����ʧ�ܣ��˳�
	}
	m_nodeNum = GetNumber();			//ȡ�ýڵ��ţ�����ֵ��m_nodeNum
	cout << "CNodeȫ�´����ڵ�,No: "<<m_nodeNum<<",Name: " << *m_pStr << endl;
}

//CNode�Ŀ������캯��
CNode::CNode(const CNode &oCN)
{
	m_pStr = new string(*oCN.m_pStr);	//new�ַ�������ռ䣬��ڵ���
	if( m_pStr==NULL )
	{
		cout << "�ڴ����ʧ�ܡ�" << endl;
		exit(0);						//�ڴ����ʧ�ܣ��˳�
	}
	m_nodeNum = GetNumber();			//ȡ�ýڵ��ţ�����ֵ��m_nodeNum
	cout << "CNode���������ڵ�,No: "<<m_nodeNum<<",Name: " << *m_pStr << endl;
}

//CNode����������
CNode::~CNode()
{
	cout << "~CNode���ٽڵ�,No: "<<m_nodeNum<<",Name: " << *m_pStr << endl;
	delete m_pStr;						//�Զ�����m_pStrָ���string����
}

//����CNode�ĸ�ֵ�����������ڵ������ڵ�����ͬ�Ķ�����ڣ�
CNode &CNode::operator=(const CNode &oCN)
{
	if (this == &oCN)							//�ж��Ƿ��Լ���ֵ���Լ�
	{
		return *this;							//����ǣ����ظ��ƣ�����
	}
	delete m_pStr;		//�ͷŸ�ֵ�������߶�����ַ�������ָ����ָ����
	m_pStr = new string(*oCN.m_pStr);	//new�ַ�������ռ䣬��ڵ���
	if( m_pStr==NULL )
	{
		cout << "�ڴ����ʧ�ܡ�" << endl;
		exit(0);		//�ڴ����ʧ�ܣ��˳�
	}
	// ע���˴�ֻ�ܿ��Ǹ�ֵ�������ָ�ֵ������ı��⡣��m_nodeNum�����ظ���
	m_nodeNum = oCN.m_nodeNum;			//ȡ�ýڵ��ţ�����ֵ��m_nodeNum
	cout << "CNode�����˶���,No: "<<m_nodeNum<<",Name: " << *m_pStr << endl;
	return *this;
}

//����CNode��','���������
const CNode & CNode::operator,(const CNode &oCN)
{
	return oCN;								//ֱ�ӷ��صڶ�������
}

//����CNode����������,
ostream& operator<<(ostream& scout, CNode& obj)	//����<<
{
	scout << "Node Name: " << *(obj.GetStr()) << ",";
	scout << "Node Number: "<< obj.GetNodeNum() << "." << endl;
	return scout; 
}

//����CNode�����������  		 
istream& operator>>(istream& scin, CNode& obj)			//����>>
{
	char s[81];						// ����81����Ϊ�˱�̷���
    cout << "Please Enter Node Name: ";
 	scin.getline(s, 81, '\n');		//getline(scin, *(obj.GetStr()));
	*(obj.GetStr()) = s;			//sת��Ϊstring������ٸ�ֵ
    cout << "Please enter Node Number: ";
    scin >> obj.GetNodeNum();		//�˴�������Ľڵ��Ŵ�Сδ������
	return scin;
}

//���ص�ǰsNodeNum,������1.
int CNode::GetNumber(void)				
{
	return sNodeNum<LEN-1 ? sNodeNum++:(sNodeNum=0,LEN-1);	//ȷ��С��LEN
}

//����ָ��ڵ����ֵ��ַ���ָ��
string *CNode::GetStr()					
{
	return m_pStr;
}

//���ؽڵ�ı��,Ҳ��m_nodeNum
int &CNode::GetNodeNum()					
{
	return m_nodeNum;
}

//CNodeArray��Ĺ��캯��
CNodeArray::CNodeArray(int aLength)	
{
	for (int i=0; i<aLength; i++)
	{
		m_poCN[i] = NULL;		//ָ�������ʼ����ȫ��ָ��NULL
	}
    m_aLength = aLength;		//���鳤������
	m_aIndex = 0;				//��ǰ�ڵ��±�����Ϊ0
	cout << "CNodeArray������һ���ڵ��������length=: " << m_aLength << endl;
}

//~CNodeArray��������,ȷ��m_poCNָ��Ķ����ָ����ָ��Ŀռ��Ƿ�������
CNodeArray::~CNodeArray(void)							
{
	for (int i=0; i<m_aIndex; i++)
	{
		if ( m_poCN[i]!=NULL )	//m_poCN[i]ָ�����ʱ,�ŵ���delete�����
		{
			delete m_poCN[i];	//��m_poCN[i]ָ��CNode���󣬻��Զ�����~CNode( )
			cout << "delete: m_poCN[" << i << "]." << endl;
		}
	}
	cout << "~CNodeArray:������ɡ�" << endl;
}

//��������˺ܼ򵥵Ľڵ���빦�ܣ���ֻ���������CNodeָ��ָ���½ڵ���ѡ�
//Ϊ�˰�ȫ���ȶԲ���λ�����жϣ����ԭ���нڵ㣬������ʧ�ܣ����ء�
//Ҳ������ԭ�ڵ㣬ǿ�Ʋ��롣
bool CNodeArray::Insert(CNode &oCN)	//����һ���ڵ�
{
	if( m_aIndex>=m_aLength )
	{
		cout << "�Բ��𣬳�������������±꣬�����ٲ���!" << endl;
		return false;
	}

	//��Ҫ����Ľڵ㸴�Ƶ��ڵ�������
	if (m_poCN[m_aIndex] != NULL)
	{
		cout << "��λ�����нڵ㣬�����ٲ���!" << endl;
		return false;
	}

	m_poCN[m_aIndex] = &oCN;
	cout << "�����½ڵ�,Pos: "<< m_aIndex << ",No: " << oCN.GetNodeNum( ) 
		<<",Name:" << *oCN.GetStr( ) << endl;
	m_aIndex++;
	return true;
}

//���ﲻ������������൱��deleteһ���ڵ㣬����ָ��Ϊ�ռ���
bool CNodeArray::Delete(int index)			//ɾ��һ���ڵ�
{
	if (m_poCN[index] == NULL)
	{
		cout << "Pos: " << index << "=NULL,�������delete�����." << endl;
		return false;
	}
	delete m_poCN[index];					//�ͷŵ�ǰ�ڵ�
	m_poCN[index] = NULL;
	cout << "delete: m_poCN[" << index << "]," << "Pos: " <<  index 
		<< ",��λ��ָ��Ľڵ�delete�ɹ�!" << endl;
	return true;
}


//CNodeArray��'[ ]'���������. ���ﷵ����һ�����󣬵�[ ]������ʱ
//���Թ۲쵽CNode�Ŀ������캯�������������ĵ��ù��̡�
CNode CNodeArray::operator[](int i)
{
	if ( (i<=m_aIndex)&&( i>=0 ) )
	{
		if (m_poCN[i]==NULL)	
		{
			cout << "û��Ԫ��,����." << endl;
			exit(0);
		}
		return *m_poCN[i];			//���ص�i���ڵ�ָ����ָ��Ķ���
	}
	else 
	{
		cout << "����Խ��" << endl;
		exit(0);					//Խ������ֹ����
	}
}

//����CNodeArray��new�����
void *CNodeArray::operator new(size_t size)
{
	cout << "����CNodeArray�Զ����new��������.\n";
	return malloc(size);
}

//����CNodeArray��delete�����
void CNodeArray::operator delete(void *p)
{
	cout << "����CNodeArray�Զ����delete���ٶ���.\n";
	free(p);
}


