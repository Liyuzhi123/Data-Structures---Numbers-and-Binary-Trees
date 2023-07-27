#include<iostream>
using namespace std;
#define OK 1
typedef struct bitnode   //�������Ķ�������洢��ʾ
{
	char data;
	struct bitnode* lchild, * rchild;
}bitnode, * bitree;

void creatbitree(bitree& t)   //���򴴽�������
{
	char ch;
	cin >> ch;
	if (ch == '#')
		t = NULL;
	else
	{
		t = new bitnode;
		t->data = ch;
		creatbitree(t->lchild);
		creatbitree(t->rchild);
	}
}

void preorder(bitree t)   //�������������
{
	if (t)
	{
		cout << t->data;
		preorder(t->lchild);
		preorder(t->rchild);
	}
}

void inorder(bitree t)   //�������������
{
	if (t)
	{
		inorder(t->lchild);
		cout << t->data;
		inorder(t->rchild);
	}
}

void postorder(bitree t)   //�������������
{
	if (t)
	{
		postorder(t->lchild);
		postorder(t->rchild);
		cout << t->data;
	}
}

int nodecount(bitree t)   //��������Ľ�����
{
	if (t == NULL)
		return 0;
	else
		return nodecount(t->lchild) + nodecount(t->rchild) + 1;
}

void leafcount(bitree t)   //���������Ҷ�ӽ��
{
	if (t) {
		if (!t->lchild && !t->rchild)
			cout << t->data << " ";		
		leafcount(t->lchild);	
		leafcount(t->rchild);	
	}
	
}

int depth(bitree t)   //��������ĸ߶�
{
	if (t == NULL)
		return 0;
	else
	{
		int l = depth(t->lchild);
		int r = depth(t->rchild);
		if (l > r)
			return l + 1;
		else
			return r + 1;
	}
}

int main()
{
	bitree t;
	cout << "������������ڵ�ֵ��" ;
	creatbitree(t);
	cout << "------------------" << endl;
	cout << "���������ִ�г���" << endl;
	cout << "�������������������1" << endl;
	cout << "�������������������2" << endl;
	cout << "�������������������3" << endl;
	cout << "��������ڵ���������4" << endl;
	cout << "���Ҷ�ӽڵ�������5" << endl;
	cout << "��������ĸ߶�������6" << endl;
	cout << "�˳������밴0" << endl;
	cout << "------------------" << endl;
	int n;
	while (OK)
	{
		cout << "������Ҫִ�еĹ���" << endl;
		cin >> n;
		switch (n) 
		{
		case 1:
			cout << "�������" << endl;
			preorder (t);	//�������
			cout << endl;
			break;
		case 2:
			cout << "�������" << endl;
			inorder(t);	//�������
			cout << endl;
			break;
		case 3:
			cout << "�������" << endl;
			postorder(t);	//�������
			cout << endl;
			break;
		case 4:
			cout << "�������ڵ����Ϊ��" << nodecount(t) << endl;	//������������
			break;
		case 5:
			cout << "������Ҷ�ӽڵ�Ϊ��";
			leafcount(t);
			cout << endl;
			break;
		case 6:
			cout << "�������߶�Ϊ��" << depth(t) << endl;	//����������߶�
			break;
		case 0:
			exit(0);
		}
	}


	return 0;
}