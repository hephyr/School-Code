
#include<iostream>
using namespace std;

template <class T>
struct LinkNode {     //链表结点类的定义
    T data;                   //数据域
    LinkNode<T> *link;      //指针域

    LinkNode() {
        link = NULL;    //构造函数
    }

    LinkNode(const T &item, LinkNode<T> *ptr = NULL) {
        data = item;     //构造函数
        link = ptr;
    }

};

template <class T>
class LinkedQueue {

  public:
    LinkedQueue() {
        rear = front = new LinkNode<T>;
    }
    ~LinkedQueue() {
        makeEmpty();
    }
    bool EnQueue(T x);
    bool DeQueue(T &x);
    bool getFront(T &x);
    void makeEmpty();
    bool IsEmpty() const {
        return front == rear;
    }
    int getSize();
    void output();

  private:
    LinkNode<T> *front, *rear;   //队头、队尾指针
};


template <class T>
bool LinkedQueue<T>::EnQueue(T x) { //将新元素x插入到队列的队尾
    LinkNode<T> *p = new LinkNode<T>(x);
    if (p != NULL) {
        rear->link = p;
        rear = p;
        return true;
    } else {
        return false;
    }

}


template <class T>
bool LinkedQueue<T>::DeQueue(T &x) {
    //请将其补充完整
    if (IsEmpty() == true) return false;
    LinkNode<T> *delete_ptr = front->link;
    front->link = front->link->link;
    x = delete_ptr->data;
    if (delete_ptr == rear)
        rear = front;
    delete delete_ptr;
    return true;
}

template <class T>
bool LinkedQueue<T>::getFront(T &x) { //若队列不空，则函数返回队头元素的值
    if (IsEmpty() == true) return false;
    x = front->link->data;
    return true;
}


template <class T>
void LinkedQueue<T>::makeEmpty() {  //将链表置为空表
    LinkNode<T> *q;
    while ( front->link != NULL) {
        q = front->link;              //q指向被删结点
        front->link = q->link;   //从链上删除该结点
        delete q;                  //释放结点空间
    }
    rear = front;
}


template <class T>
int LinkedQueue<T>::getSize() {     //计算链队列的长度
    //请将其补充完整
    LinkNode<T> *p = front;
    int length = 0;
    for (; p != rear; p = p->link) {
        ++length;
    }
    return length;
}


template <class T>    //输出链队列
void LinkedQueue<T>::output() {
    LinkNode<T> *p = front->link;
    if(p == NULL) {
        cout << "空队列！\n";
        return;
    }
    while(p != NULL) {
        cout << p->data << "  ";
        p = p->link;
    }
    cout << endl;
}