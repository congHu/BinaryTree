
//创建一棵如下所示的二叉树 (如图5.5所示)   
//                A   
//              /   \   
//             B      C   
//           /   \     \
//          D     E      F
//               /      / \
//              G      H   I
//   
  
#include <iostream>    
#include "BinaryTree.h"   
using namespace std;
int main() {   
    //建一棵二叉树(如图5.5所示) 
	//输入前序序列(*表示NULL)：ABD**EG***C*FH**I**
	
	BinaryTree<char> a;
	cout<<"input node(preorder):";
	a.CreateBinaryTree();

    //前序周游二叉树    
    cout << "Preorder sequence is: "<<endl;   
    a.PreOrder(a.Root());                 
    cout << endl;   
   
    //中序周游二叉树    
    cout << "Inorder sequence is: "<<endl;   
    a.InOrder(a.Root());			  
    cout << endl;    
   
    //后序周游二叉树    
    cout << "Postorder sequence is: "<<endl;   
    a.PostOrder(a.Root());			
    cout << endl;      
   
	//请补充输出层次顺序遍历部分
	cout << "Level sequence is: " << endl;
	a.LevelOrder(a.Root());
	cout << endl;



    //输出root    
   // cout << "Root is: " << a.Root()->value() <<endl;
	return 0;
}  

