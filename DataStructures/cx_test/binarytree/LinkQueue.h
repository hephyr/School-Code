#include<iostream>
//using namespace std;

template <class T>   
struct LinkNode       //链表结点类的定义
{       
     T data;                   //数据域
     LinkNode<T> *link;        //指针域
     LinkNode() { link = NULL; }                         //构造函数1
     LinkNode(T item) { data = item;  link = NULL; }     //构造函数2
};

template <class T>
class LinkedQueue 
{   
  public: 
    LinkNode<T> *front, *rear;   //队头、队尾指针

    LinkedQueue() { rear=front=new LinkNode<T>; }
    ~LinkedQueue() {makeEmpty();}                   
    bool EnQueue(T x);
    bool DeQueue(T& x);         
    bool getFront(T& x);            
    void makeEmpty();            
    bool IsEmpty() { return front == rear; }
};

template <class T> 
bool LinkedQueue<T>::EnQueue(T x) //将新元素x插入到队列的队尾
{
    rear->link = new LinkNode<T> (x);
    rear = rear->link;
    return true;
}

template <class T> 
bool LinkedQueue<T>::DeQueue(T& x) 
{
     if (IsEmpty() == true) return false;        //判队空
     LinkNode<T> *p = front->link;      
     x = p->data;  
     front->link=p->link;   
     if(p==rear) rear=front;    //最后一个元素出队后，修改尾指针
     delete p;   
     return true;               
}

template <class T> 
bool LinkedQueue<T>::getFront(T& x) //若队列不空，则函数返回队头元素的值 
{
    if (IsEmpty() == true) return false;    
    x = front->link->data;  
    return true;
}

template <class T>
void LinkedQueue<T>::makeEmpty()    //将链表置为空表
{
     LinkNode<T> *q;
     while ( front->link != NULL) 
     {   
          q = front->link;              //q指向被删结点
          front->link = q->link;   //从链上删除该结点
          delete q;                 //释放结点空间
     }
     rear=front;
}