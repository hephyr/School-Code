#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"LinkQueue.h"
using namespace std;

template <class T> 
struct BinTreeNode        //二叉树结点类定义
{     
     T data;                          //数据域
     BinTreeNode<T> *leftchild, *rightchild;   //左子女、右子女链域
     BinTreeNode ()                   //构造函数
        { leftchild=NULL;  rightchild=NULL; }
     BinTreeNode (T x)
        { data = x;  leftchild=NULL;  rightchild=NULL; }
};

template <class T> 
class BinaryTree        //二叉树类定义
{
  public:
    BinTreeNode<T> *root;   //二叉树的根指针


    BinaryTree () : root (NULL) { }   //构造函数
    ~BinaryTree () { Destroy(root); }     //析构函数


    void PreOrder (BinTreeNode<T> * t);   //先序遍历
    void InOrder (BinTreeNode<T> * t);    //中序遍历
    void PostOrder (BinTreeNode<T> * t);   //后序遍历

    void LevelOrder (BinTreeNode<T> * t);  //层次遍历
     
    void CreatTree(BinTreeNode<T> *& t);   //先序遍历建树

    bool IsEmpty () { return root==NULL;}   //判二叉树是否为空
    
    int Height (BinTreeNode<T> * t) ;    //求树高度
     
    int Size (BinTreeNode<T> * t);      //求结点数

    int Sum (BinTreeNode<T> * t);       //求结点总和

    void Destroy(BinTreeNode<T> * t);

};

template <class T>
void BinaryTree<T>::Destroy(BinTreeNode<T> *t)
{
    if(t!=NULL)
    {  
        Destroy(t->leftchild);
        Destroy(t->rightchild);
        delete t;
    }
}


template <class T>
void BinaryTree<T>::PreOrder (BinTreeNode<T> *t)   //先序遍历
{
     if (t != NULL)
     {
         cout<<t->data<<"  ";           //访问根结点
         PreOrder (t->leftchild);       //遍历左子树
         PreOrder (t->rightchild);          //遍历右子树
     }
}

template <class T>
void BinaryTree<T>::InOrder (BinTreeNode<T> *t)   //中序遍历
{
     if (t != NULL)
     {      
         InOrder (t->leftchild);        //遍历左子树
         cout<<t->data<<"  ";           //访问根结点
         InOrder (t->rightchild);       //遍历右子树
     }
}

template <class T>
void BinaryTree<T>::PostOrder (BinTreeNode<T> *t)   ///后序遍历
{
     if (t != NULL)
     {      
         PostOrder (t->leftchild);      //遍历左子树
         PostOrder (t->rightchild);         //遍历右子树
         cout<<t->data<<"  ";           //访问根结点
     }
}

template <class T>
void BinaryTree<T>::LevelOrder (BinTreeNode<T> *t)   //层次遍历
{
     
}


template <class T>
void BinaryTree<T>::CreatTree (BinTreeNode<T> * &t) //先序遍历建树
{
   T item;
   cin>>item;
   if(item!=-1)
   {  t=new BinTreeNode<T>(item);
      if(t ==NULL)
      { cerr<<"分配结点失败！\n";  exit(1);  }

      CreatTree(t->leftchild);
      CreatTree(t->rightchild);
   }
   else t=NULL;
}


template <class T>
int BinaryTree<T>::Size (BinTreeNode<T> * t)  
{//利用二叉树后序遍历算法计算二叉树的结点个数
     static int num = 0;
     if (t != NULL) {
        Size(t->leftchild);
        Size(t->rightchild);
        ++num;
     }
     return num;
}


template <class T>
int  BinaryTree<T>::Height ( BinTreeNode<T> *  t) 
{//利用二叉树后序遍历算法计算二叉树的高度或深度
     int deep = 0;
     if (t != NULL) {
        int leftdeep = Height(t->leftchild);
        int rightdeep = Height(t->rightchild);
        deep = leftdeep >= rightdeep ? leftdeep : rightdeep;
     }
     return deep;
}


template <class T>
int BinaryTree<T>::Sum (BinTreeNode<T> * t)  
{//利用二叉树遍历算法计算二叉树的叶结点个数
    static int num = 0;
    if (t == NULL) {
        return num;
    }
    if (t->leftchild == NULL && t->rightchild == NULL) {
        ++num;
    } else {
        Sum(t->leftchild);
        Sum(t->rightchild);
    }
    return num;
}