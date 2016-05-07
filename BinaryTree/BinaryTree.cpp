
//����һ��������ʾ�Ķ����� (��ͼ5.5��ʾ)   
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
    //��һ�ö�����(��ͼ5.5��ʾ) 
	//����ǰ������(*��ʾNULL)��ABD**EG***C*FH**I**
	
	BinaryTree<char> a;
	cout<<"input node(preorder):";
	a.CreateBinaryTree();

    //ǰ�����ζ�����    
    cout << "Preorder sequence is: "<<endl;   
    a.PreOrder(a.Root());                 
    cout << endl;   
   
    //�������ζ�����    
    cout << "Inorder sequence is: "<<endl;   
    a.InOrder(a.Root());			  
    cout << endl;    
   
    //�������ζ�����    
    cout << "Postorder sequence is: "<<endl;   
    a.PostOrder(a.Root());			
    cout << endl;      
   
	//�벹��������˳���������
	cout << "Level sequence is: " << endl;
	a.LevelOrder(a.Root());
	cout << endl;



    //���root    
   // cout << "Root is: " << a.Root()->value() <<endl;
	return 0;
}  

