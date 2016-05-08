#include <iostream>

class Node {
    friend class LinkList;
public:
    Node(int n) {
        value = n;
        next = nullptr;
    }
private:
    int value;
    Node *next;
};
class LinkList {
public:
    LinkList() {
        head = new Node(0);
        head->next = head;
        keep = head;
        tail = head;
    }
    LinkList(int n) {
        head = new Node(0);
        head->next = head;
        keep = head;
        tail = head;
        for (int i = 0; i < n; ++i) {
            Node *p = new Node(i+1);
            this->insert(p);
        }
    }
    bool insert(Node *node) {       //队列插入元素到队尾
        tail->next = node;
        tail = node;
        tail->next = head;
        return true;
    }
    bool a_delete(int n) {          //从第一个元素开始
        if (head == head->next) {
            std::cerr << "Empty list can't delete" << std::endl;
            return false;
        }
        Node *p = head;
        Node *pre;
        for (int i = 1; i <= n; ++i) {
            pre = p;
            p = p->next;
            if (p == head) {
                pre = p;
                p = head->next;
            }
        }
        pre->next = p->next;
        delete p;
        return true;
    }
    bool b_delete(int n) {          //从上一次删除的元素的下一个开始
        if (head == head->next) {
            std::cerr << "Empty list can't delete" << std::endl;
            return false;
        }
        Node *pre;
        for (int i = 1; i <= n; ++i) {
            pre = keep;
            keep = keep->next;
            if (keep == head) {
                pre = keep;
                keep = head->next;
            }
        }
        pre->next = keep->next;
        delete keep;
        keep = pre->next;
        return true;
    }
    bool empty() {          //判断是队列是否为空
        if (head->next == head) {
            return true;
        } else {
            return false;
        }
    }
    bool one_node() {       //判断是否队列中还剩一个结点（不包括头结点）
        if (head->next->next == head) {
            return true;
        } else {
            return false;
        }
    }
    void show() {           //输出
        Node *p = head->next;
        while (p != head) {
            std::cout << p->value << " ";
            p = p->next;
        }
    }
private:
    Node *head;
    Node *keep;
    Node *tail;
};