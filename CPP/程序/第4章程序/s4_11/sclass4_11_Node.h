//�������ļ�
//�ļ�����s4_11\sclass4_11_Node.h 

//����Ԥ������䣺���δ����__SCLASS4_11_NODE_H__��������
//ֱ������#endif����
#ifndef __SCLASS4_11_NODE_H__ 
#define __SCLASS4_11_NODE_H__ 

#include <iostream>  					//����ͷ�ļ�,ʹ��iostream��
#include <string>  						//����ͷ�ļ�,ʹ��string��
using namespace std; 					//ʹ��std�����ռ�

const int LEN = 20;	//����ָ������鳤�ȣ������ó��㣬����:1000���ڵ�
class CNodeArray;	//ǰ�������ڵ������࣬�Ա���CNode��������Ϊ��Ԫ��ʱʹ��

/******************************************************************************
//�����ڵ���, ����ֻ�����˽ڵ����ֺͽڵ����������ݳ�Ա��
//Ϊ��˵���������캯����������������صı�Ҫ�ԣ����ڵ����ֶ���Ϊstring����ָ�롣
//�ڽڵ����ж����˿������캯���ȡ�
//��ϰʱ�˿���һ���������CNode��Ƹ��ӵĽڵ�ṹ���磺ͼ5.6�е�CEmployee���塣
******************************************************************************/
class CNode
{
	friend CNodeArray;	//CNodeArray��CNode����Ԫ���������˽�г�Ա
	friend ostream& operator<<(ostream& cout,CNode& obj);	//����<<
   	friend istream& operator>>(istream& cin,CNode& obj);		//����>>
	static int sNodeNum;	//��̬��Ա,ÿ����һ���ڵ�����Զ���1,

public:
	CNode(string str);		//���캯��,�ڵ��ŵ���CreatNumber()����ȡ��
	CNode(const CNode &oCN);			//�������캯��
	virtual ~CNode();					//����������
	CNode &operator=(const CNode &oCN);	//���ظ�ֵ����� 
	const CNode &operator,(const CNode &oCN);		//����","
	int GetNumber(void);				//���ص�ǰsNodeNum,������1.
	string *GetStr();					//����ָ��ڵ����ֵ��ַ���ָ��
	int &GetNodeNum();					//���ؽڵ�ı��

private:
	string *m_pStr;			//�ַ�������ָ�룬����ָ��һ���ַ�������
	int m_nodeNum;			//�ڵ��ţ������Ա��ŵȣ��ñ��Ҫ����Ψһ�ԡ�
};

/******************************************************************************
//�����ڵ�������,����Ҫ���ڹ����ڶ�ڵ㡣�������ݳ�Ա�ͺ�����Ա�����Ҫ����
//��������ڶ�ڵ����Ҫ��Ϊ�˲����򵥣��ڱ������������һ������ΪLEN��ָ��
//���顣�����ÿһ����Ա������ָ��һ��CNode�ڵ���󡣵�ϵͳ����һ���ڵ��
//�͸���m_aIndexȷ���ڵ��������е�λ�á����ڵ����ٺ�Ҳ�������ջ������Ӧ
//��Ԫ��ָ���������á���ϰʱ���ɴ����¼����Ƕȿ�����չ��
//1. ���ǻ��սڵ�ɾ���������ָ���������ã�
//2. �������һ���Ƚ�С�����飬���糤��Ϊ26��Ȼ���սڵ����ֵ�����ĸ��ͬ��
//   Ӧ����ڲ�ͬ������ָ��λ�ã���������ĸ��ͬ�Ľڵ㰴������ʽ������
//3. ����������չ������������Ŀ����Ҫ��Ϊ�˷���۲�����ִ�й��̡�
******************************************************************************/
class CNodeArray
{
	friend CNode;
public:
	CNodeArray(int aLength = LEN);				//���캯��,Ĭ�����鳤��ΪLEN��
	virtual ~CNodeArray(void);					//����������
	CNode operator[](int i);					//����"[ ]"
	void *operator new(size_t size);			//����new
	void operator delete(void *p);				//����delete
	bool Insert(CNode &oCN);					//�ڽڵ������в���һ���ڵ�
	bool Delete(int index);						//�ڽڵ�������ɾ��һ���ڵ�

private:
	CNode *m_poCN[LEN];			//�ڵ�ָ������,�������ָ��ڵ��ָ��
	int m_aLength;				//ָ�����鳤��
	int m_aIndex;				//�ڵ�ָ������������ĵ�ǰ���±�ֵ
};

#endif   //��������Ԥ���� 
