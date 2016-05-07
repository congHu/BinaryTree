//************BinaryTree.h****************// 
 
#include <stack> 
#include <queue> 
#include "BinaryTreeNode.h" 
 
enum Tags{Left,Right};			//枚举类型 
 
template <class T> 
class StackElement  {			//StackElement,用于非递归方式遍历二叉树 
public: 
	BinaryTreeNode<T>* pointer; 
	Tags tag; 
};	 
 
using namespace std; 
 
template <class T> 
class BinaryTree { 
private: 
	BinaryTreeNode<T>*  root;      					//二叉树根结点 
public: 
	BinaryTree(){root = NULL;};						//构造函数 
	~BinaryTree() {DeleteBinaryTree(root);};		//析构函数 
	bool isEmpty() const{return ( root? false : true); };//判定二叉树是否为空树 
	BinaryTreeNode<T>* Root(){return root;};		//返回二叉树根结点 				
	BinaryTreeNode<T>*  CreateBinaryTree();			//创建二叉树，返回指向所创建的二叉树的根结点的指针				

	void PreOrder(BinaryTreeNode<T>* root);  		//前序周游二叉树或其子树 
	void InOrder(BinaryTreeNode<T>* root);			//中序周游二叉树或其子树 
	void PostOrder(BinaryTreeNode<T>* root);		//后序周游二叉树或其子树 
	void LevelOrder(BinaryTreeNode<T>* root); 		//按层次周游二叉树或其子树 

	void DeleteBinaryTree(BinaryTreeNode<T>* root);	//删除二叉树或其子树 
	void Visit(T Value) {cout << Value;};           //访问 
};
 
template<class T> 
void BinaryTree<T>:: DeleteBinaryTree(BinaryTreeNode<T>* root)  { //以后序周游的方式删除二叉树 
	if(root)  { 
		DeleteBinaryTree(root->left);				//递归删除左子树 
		DeleteBinaryTree(root->right);				//递归删除右子树 
		delete root;								//删除根结点 
	} 
} 
   
template<class T> 
BinaryTreeNode<T>*  BinaryTree<T>:: CreateBinaryTree()  { 
	//按前序构造二叉链表表示的二叉树root 
	BinaryTreeNode<T> * N;
	T ch;
	cin>>ch;

	/*书本124页，好像是层序创建
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
	else{											//此处需补充完整
		N = new BinaryTreeNode<T>(ch);
		N->left = CreateBinaryTree();
		N->right = CreateBinaryTree();
	}
	return root=N;
}


template<class T> 
void BinaryTree<T>::PreOrder (BinaryTreeNode<T>* root)  {  //前序周游二叉树 
	if (root!=NULL)
	{
		cout << root->info << " ";
		PreOrder(root->left);
		PreOrder(root->right);
	}
} 

template<class T> 
void BinaryTree<T>:: InOrder (BinaryTreeNode<T>* root)  {  //中序周游二叉树 
	if (root != NULL)
	{
		
		InOrder(root->left);
		cout << root->info << " ";
		InOrder(root->right);
	}
} 

template<class T> 
void BinaryTree<T>:: PostOrder (BinaryTreeNode<T>* root)  { //后序周游二叉树 
	if (root != NULL)
	{
		
		PostOrder(root->left);
		PostOrder(root->right);
		cout << root->info << " ";
	}
} 
 
template<class T> 
void BinaryTree<T>::LevelOrder(BinaryTreeNode<T>* root)	{ //按层次周游二叉树或其子树 
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
