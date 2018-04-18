//���ļ����ļ�����ch5_5\smain5_5.cpp

#include <iostream>			//����ͷ�ļ���ʹ��iostream��
#include <string>			//����ͷ�ļ���ʹ��string��
using namespace std;		//ʹ��std���ֿռ�

class CNode;				// CNode��ǰ���������Ա���TLinkList��ʹ��

//����һ���������ģ�塪���ڸ������еĽڵ�������ġ�
template <class Type>
class TLinkList
{
public:
	TLinkList( );						//���캯��
	virtual ~TLinkList( );				//��������

	virtual bool Insert( Type value );	//�������в���һ���ڵ㣬���ڱ�ͷ����
	bool Delete( Type value );			//��������ɾ��ֵΪvalue�Ľڵ�
	bool Search( Type value );			//�ж��������Ƿ����ֵΪvalue�Ľڵ�
	bool Modify( Type v1, Type v2 );	//���ҽڵ�ֵΪv1�Ľڵ㣬���޸�Ϊv2
	virtual void Print( );				//��������˳����������еĽڵ�ֵ

public:
	CNode *m_pHead;						//���������ͷ���ָ��
};

//�������������ģ�塪���ڸ������еĽڵ�������ġ�
template<class Type>
class TOrderedLinkList : public TLinkList<Type>
{
public:
	TOrderedLinkList( );				//���캯��
	virtual ~TOrderedLinkList( );		//��������

public:
	virtual bool Insert( Type value );	//�������
	virtual void Print( );				//��������˳����������еĽڵ�ֵ
};

//�����ڵ�ṹ��
class CNode
{
	friend class TLinkList<int>;		//����ģ����ΪCNode����Ԫ
	friend class TOrderedLinkList<int>;	//����ģ����ΪCNode����Ԫ

public:
	CNode( int value );
	~CNode( );
	
private:
	int m_value;		//�ڵ�ֵ
	CNode *m_pNext;		//�ڵ��̣�ָ����һ���ڵ�
	CNode *m_pPre;		//�ڵ�ǰ����ָ����һ���ڵ�
};


//�ڵ��๹�캯��
CNode::CNode( int value )
{
	m_value = value;			//�ڵ�ֵ
	m_pNext = NULL;				//�ڵ���
	m_pPre = NULL;				//�ڵ�ǰ��
}

//�ڵ�����������
CNode::~CNode( )
{
	;
}

//TLinkList��ģ��Ĺ��캯��
template <class Type>
TLinkList<Type>::TLinkList( )
{
	m_pHead = NULL;				//����ͷ
}

//TLinkList��ģ�����������
template <class Type>
TLinkList<Type>::~TLinkList( )
{
	CNode *p = m_pHead;			//pָ���һ���ڵ�
	for (  ; p!=NULL;  )		//ֱ���ڵ㲻Ϊ��
	{
		m_pHead = p->m_pNext;	//ͷָ��ָ����һ���ڵ�
		delete p;				//�ͷ�p��ָ��Ľڵ�
		p = m_pHead;			//pָ���µ�ͷ�ڵ�
	}
}

//����һ���½ڵ㣬��ֻ��ͷָ��������
template <class Type>
bool TLinkList<Type>::Insert( Type value )
{
	CNode  *pTemp = new CNode( value );		//����һ���½ڵ�
	if ( pTemp == NULL )					//�ڴ�ռ����벻�ɹ�
	{
		exit(0);							//ִֹͣ�г���
	}

	if (m_pHead == NULL)				//��ͷΪ��ʱ��������в�ͬ
	{
		pTemp->m_pNext = NULL;				//1. �ڵ���Ϊ��
		pTemp->m_pPre = NULL;				//2. �ڵ�ǰ��Ϊ��
		m_pHead = pTemp;					//3. ͷָ��ָ����½ڵ�
	}
	else								//��ͷ��Ϊ��ʱ
	{
		pTemp->m_pNext = m_pHead;		// 1. ��ԭͷ�ڵ�����Ϊ��ͷ�ڵ�ĺ��
		pTemp->m_pPre = NULL;			// 2. ����ͷ�ڵ��ǰ������ΪNULL
		m_pHead->m_pPre = pTemp;		// 3. ����ͷ�ڵ�����Ϊԭͷ�ڵ��ǰ��
		m_pHead = pTemp;				// 4. ����ͷ�ڵ�����Ϊ�µı�ͷ��
	}
	
	return true;
}

//ɾ��ֵΪvalue�����нڵ㡣
//ɾ���㷨���£����ȴ���һ����ʱ�ڵ�(�ڵ�ֵ����趨)���뵽����ͷ��Ϊ�µ���ʱ
//ͷ��㣬Ȼ����p1ָ���µ�ͷ��㣬p2ָ������(ԭͷ���)��Ȼ�����p2��ָ�Ƿ�
//Ӧ��ɾ�������Ӧ��ɾ������ɾ����ɾ������p1������p2ָ�����̡������Ӧ��ɾ��
//��p1��p2��ָ�����̡���˷���ֱ��p2ָ��NULLΪֹ�������m_pHeadָ����ʱͷ��㡣
template <class Type>
bool TLinkList<Type>::Delete( Type value )
{
	bool flag = false;					// 0��ʾû��ɾ���κνڵ㣬1��ʾɾ���ˡ�
	//������ͷ����һ����ʱ��ͷ
	CNode oCN(0);					// ����һ���½ڵ��Բ��뵽��ͷ��Ϊ��ʱͷ�ڵ�
	oCN.m_pNext = m_pHead;			// ��ԭͷ�ڵ�����Ϊ��ʱͷ�ڵ�ĺ��	
	oCN.m_pPre = NULL;				// ����ʱͷ�ڵ��ǰ������ΪNULL
	m_pHead->m_pPre = &oCN;			// ����ʱͷ�ڵ�����Ϊԭͷ�ڵ��ǰ��
	m_pHead = &oCN;					// ����ʱͷ�ڵ�����Ϊ�µı�ͷ��
	//ɾ��ֵΪvalue�����нڵ�
	CNode *p1=m_pHead, *p2=m_pHead->m_pNext;	//p1ָ���±�ͷ�ڵ㣬p2ָ������	
	for (  ; p2!=NULL;  )			// p2Ϊ�յĻ�˵�������Ѿ�������ȫ��			
	{
		if ( p2->m_value == value )	// ��p2��ָ�ڵ�����Ҫɾ���Ľڵ�
		{
			p1->m_pNext = p2->m_pNext;		//p2�ĺ�̸�ֵ��p1�ĺ�� 
			(p2->m_pNext)->m_pPre = p1;		//p1��ֵ��p2�ĺ�̵�ǰ���ַ
			delete p2;						//ɾ��p2��ָ�ڵ㣨������������
			p2 = p1->m_pNext;				//p2ָ��p1���º��
			flag = true;						//˵���нڵ㱻ɾ��
		}
		else								//���p2��ָ����Ҫɾ���Ľڵ�
		{
			p1 = p2;						//p1ָ��p2
			p2 = p2->m_pNext;				//p2ָ��p1�ĺ��
		}
	}
	// ����ʱ��ͷɾ����ע��oCN����new�Ķ�������delete��
	m_pHead = oCN.m_pNext;
	(oCN.m_pNext)->m_pPre = NULL;

	return flag;
}

//�����������Ƿ�����ڵ�ֵΪvalue�Ľڵ㣬�з���true��û�з���false
template <class Type>
bool TLinkList<Type>::Search( Type value )
{	
	for ( CNode  *p=m_pHead; p!=NULL; p=p->m_pNext )
	{
		if ( p->m_value == value )			//�ҵ��ýڵ㣬����true
		{
			return true;
		}
	}
	return false;
}

//�������нڵ�ֵΪv1�Ľڵ�ȫ���޸�Ϊv2���޸ĳɹ�����true������false
template <class Type>
bool TLinkList<Type>::Modify( Type v1, Type v2 )
{	
	bool flag = false;				// 0��ʾû���κ��޸Ľڵ㣬1��ʾ���޸�
	for ( CNode  *p=m_pHead; p!=NULL; p=p->m_pNext )
	{
		if ( p->m_value == v1 )			//�ҵ��ýڵ㣬�޸�Ϊv2������true
		{
			p->m_value = v2;
			true = 1;
		}
	}
	return flag;
}

//��������˳��ӱ�ͷ��ʼȡ���ڵ�ֵ����ʾ
template <class Type>
void TLinkList<Type>::Print( )
{
	cout << "��TLinkList��ͷ��ʼ�ڵ��ֵ����Ϊ:\n";
	//���������Զ���ÿһ���ڵ��ֵ�����ն�����ʾ��
	for ( CNode  *p = m_pHead; p != NULL; p = p->m_pNext )
	{
		cout << " " << p->m_value << ", ";      //��ʾ�ڵ�ֵ
	}
	cout << endl;								//���������
}


//TOrderedLinkList��ģ��Ĺ��캯��
template <class Type>
TOrderedLinkList<Type>::TOrderedLinkList( ):TLinkList<Type>()
{
	;
}

//TOrderedLinkList��ģ��Ĺ��캯��
template <class Type>
TOrderedLinkList<Type>::~TOrderedLinkList( )
{
	;
}

//TOrderedLinkList�Ľڵ���뷽����TLinkList��Ψһ��ͬ������������롣
//Ҳ����˵����λ�ò�һ���ڱ�ͷ��������������롣��ͷֵС����βֵ��
//����ɿ�������һ���㷨�������ڱ�ͷ�ͱ�β�ֱ����һ����Сֵ��һ�����ֵ��
//����ڱ�ͷ�ͱ�β֮���ú����forѭ��Ѱ�Ҳ���λ�ò��룬���ɾ����ͷ�ͱ�β
template <class Type>
bool TOrderedLinkList<Type>::Insert( Type value )
{
	CNode  *p1,*p2;							//��������ָ��������ʱʹ��
	CNode  *pTemp = new CNode( value );		//����pTempָ��new�Ĵ�����ڵ�
	if ( pTemp == NULL )					//�ڴ�ռ����벻�ɹ�
	{
		exit(0);							//ִֹͣ�г���
	}

	if (m_pHead == NULL)					//��ͷΪ��ʱ����Ϊ��һ���ڵ�
	{
		pTemp->m_pNext = NULL;				//1. �½ڵ�ĺ��ΪNULL
		pTemp->m_pPre = NULL;				//2. �½ڵ��ǰ��ΪNULL
		m_pHead = pTemp;					//3. ͷָ��ָ���½ڵ�
	}
	else			//����ͷ��Ϊ��ʱ������ҪѰ�Ҳ���λ�ã�Ȼ����ܲ���ڵ�		
	{
		if (value<m_pHead->m_value)			//�ڱ��ͷ�ڵ�ǰ����
		{
			pTemp->m_pNext = m_pHead;		// 1. ��ԭͷ�ڵ�����Ϊ��ͷ�ڵ�ĺ��
			pTemp->m_pPre = NULL;			// 2. ����ͷ�ڵ��ǰ������ΪNULL
			m_pHead->m_pPre = pTemp;		// 3. ����ͷ�ڵ�����Ϊԭͷ�ڵ��ǰ��
			m_pHead = pTemp;				// 4. ����ͷ�ڵ�����Ϊ�µı�ͷ��
		}
		else								//������ͷ�ڵ�ǰ���� 
		{	//��p2ָ��p1��ǰ��(��Ҫ��������β���Ĳ���)
			for ( p2=m_pHead,p1=m_pHead->m_pNext; p1!=NULL; p2=p1,p1=p1->m_pNext )
			{
				if (value<p1->m_value)		// �������м����
				{
					(p1->m_pPre)->m_pNext = pTemp;	// 1. p1��ǰ���ĺ��ָ���½ڵ�
					pTemp->m_pPre = p1->m_pPre;		// 2. �½ڵ��ǰ��ָ��p1��ǰ��
					pTemp->m_pNext = p1;			// 3. �½ڵ�ĺ��ָ��p1
					p1->m_pPre = pTemp;				// 4. p1��ǰ��ָ���½ڵ�
					break;
				}
			}
			if (p1 == NULL)					// ������ĩβ����
			{
				pTemp->m_pNext = NULL;		// 1. �½ڵ�ĺ������ΪNULL
				pTemp->m_pPre = p2;			// 2. �½ڵ��ǰ��ָ��p2
				p2->m_pNext = pTemp;		// 3. p2�ĺ��ָ���½ڵ�
			}
		}
	}	
	return true;
}

//��������˳��ӱ�ͷ��ʼȡ���ڵ�ֵ����ʾ
template <class Type>
void TOrderedLinkList<Type>::Print( )
{
	cout << "��TOrderedLinkList��ͷ��ʼ,�ڵ��ֵ����Ϊ:\n";
	//���������Զ���ÿһ���ڵ��ֵ�����ն�����ʾ��
	for ( CNode  *p = m_pHead; p != NULL; p = p->m_pNext )
	{
		cout << " " << p->m_value << ", ";      //��ʾ�ڵ�ֵ
	}
	cout << endl;								//���������
}

//�����Գ���
void main( )  
{
	TLinkList<int> oILL;
	oILL.Insert( 12 );
	oILL.Insert( 24 );		//������oILL�У����β���24
	oILL.Insert( 48 );		//������oILL�У����β���48
	oILL.Insert( 96 );
	oILL.Insert( 24 );
	oILL.Insert( 48 );
	oILL.Insert( 96 );
	oILL.Insert( 35 );
	oILL.Print( );			//ɾ��ǰ��ʾ
	oILL.Delete( 24 );		//ɾ��ֵΪ24�Ľڵ�
	oILL.Print( );			//ɾ������ʾ

	TOrderedLinkList<int> oDOLL;
	oDOLL.Insert( 12 );
	oDOLL.Insert( 24 );		//�ڼ���oILL�У����β���24
	oDOLL.Insert( 48 );		//�ڼ���oILL�У����β���48
	oDOLL.Insert( 96 );
	oDOLL.Insert( 24 );
	oDOLL.Insert( 48 );	
	oDOLL.Insert( 96 );
	oDOLL.Insert( 35 );	
	oDOLL.Print( );			//ɾ��ǰ��ʾ
	oDOLL.Delete( 24 );		//ɾ��ֵΪ24�Ľڵ�
	oDOLL.Print( );			//ɾ������ʾ

	cin.get( );
}
