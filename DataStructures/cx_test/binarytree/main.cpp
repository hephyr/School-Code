#include <iostream>
#include "BinaryTree.h"


int main()
{  
     BinaryTree<int> A;
     A.CreatTree(A.root);

     int h=A.Height(A.root);     
     cout<<"树的高度="<<h<<endl;
     int n=A.Size(A.root);
     cout<<"树的结点总数="<<n<<endl;
     int s=A.Sum(A.root);
     cout<<"树的结点总和="<<s<<endl;

     cout<<"先序序列："<<endl;
     A.PreOrder(A.root);
     cout<<endl<<"中序序列："<<endl;
     A.InOrder(A.root);
      cout<<endl<<"后序序列："<<endl;
     A.PostOrder(A.root);
     cout<<endl<<"层次遍历:"<<endl;
     A.LevelOrder(A.root);
     return 0;
//选作部分：设计算法判断所创建的二叉树是否完全二叉树
}
