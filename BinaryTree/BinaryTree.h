//************BinaryTree.h****************// 
 
#include <stack> 
#include <queue> 
#include "BinaryTreeNode.h" 
 
enum Tags{Left,Right};			//ö������ 
 
template <class T> 
class StackElement  {			//StackElement,���ڷǵݹ鷽ʽ���������� 
public: 
	BinaryTreeNode<T>* pointer; 
	Tags tag; 
};	 
 
using namespace std; 
 
template <class T> 
class BinaryTree { 
private: 
	BinaryTreeNode<T>*  root;      					//����������� 
public: 
	BinaryTree(){root = NULL;};						//���캯�� 
	~BinaryTree() {DeleteBinaryTree(root);};		//�������� 
	bool isEmpty() const{return ( root? false : true); };//�ж��������Ƿ�Ϊ���� 
	BinaryTreeNode<T>* Root(){return root;};		//���ض���������� 				
	BinaryTreeNode<T>*  CreateBinaryTree();			//����������������ָ���������Ķ������ĸ�����ָ��				

	void PreOrder(BinaryTreeNode<T>* root);  		//ǰ�����ζ������������� 
	void InOrder(BinaryTreeNode<T>* root);			//�������ζ������������� 
	void PostOrder(BinaryTreeNode<T>* root);		//�������ζ������������� 
	void LevelOrder(BinaryTreeNode<T>* root); 		//��������ζ������������� 

	void DeleteBinaryTree(BinaryTreeNode<T>* root);	//ɾ���������������� 
	void Visit(T Value) {cout << Value;};           //���� 
};
 
template<class T> 
void BinaryTree<T>:: DeleteBinaryTree(BinaryTreeNode<T>* root)  { //�Ժ������εķ�ʽɾ�������� 
	if(root)  { 
		DeleteBinaryTree(root->left);				//�ݹ�ɾ�������� 
		DeleteBinaryTree(root->right);				//�ݹ�ɾ�������� 
		delete root;								//ɾ������� 
	} 
} 
   
template<class T> 
BinaryTreeNode<T>*  BinaryTree<T>:: CreateBinaryTree()  { 
	//��ǰ������������ʾ�Ķ�����root 
	BinaryTreeNode<T> * N;
	T ch;
	cin>>ch;

	/*�鱾124ҳ�������ǲ��򴴽�
	queue<BinaryTreeNode<T>*> que;
	T ldata, rdata;
	root = new BinaryTreeNode<T>(ch);
	que.push(root);
	while (!que.empty())
	{
		N = que.front();
		que.pop();
		cin >> ldata >> rdata;
		if (ldata != '*') que.push(N->left = new BinaryTreeNode<T>(ldata));
		if (rdata != '*') que.push(N->right = new BinaryTreeNode<T>(rdata));
		
	}*/

	if(ch=='*') N=NULL;
	else{											//�˴��貹������
		N = new BinaryTreeNode<T>(ch);
		N->left = CreateBinaryTree();
		N->right = CreateBinaryTree();
	}
	return root=N;
}


template<class T> 
void BinaryTree<T>::PreOrder (BinaryTreeNode<T>* root)  {  //ǰ�����ζ����� 
	if (root!=NULL)
	{
		cout << root->info << " ";
		PreOrder(root->left);
		PreOrder(root->right);
	}
} 

template<class T> 
void BinaryTree<T>:: InOrder (BinaryTreeNode<T>* root)  {  //�������ζ����� 
	if (root != NULL)
	{
		
		InOrder(root->left);
		cout << root->info << " ";
		InOrder(root->right);
	}
} 

template<class T> 
void BinaryTree<T>:: PostOrder (BinaryTreeNode<T>* root)  { //�������ζ����� 
	if (root != NULL)
	{
		
		PostOrder(root->left);
		PostOrder(root->right);
		cout << root->info << " ";
	}
} 
 
template<class T> 
void BinaryTree<T>::LevelOrder(BinaryTreeNode<T>* root)	{ //��������ζ������������� 
	queue<BinaryTreeNode<T>*> que;
	que.push(root);
	while (!que.empty())
	{
		root = que.front();
		que.pop();
		cout << root->info << " ";
		if (root->left != NULL)
		{
			que.push(root->left);
		}
		if (root->right != NULL)
		{
			que.push(root->right);
		}
	}
}
