#include <iostream>

using std::cout; using std::endl;

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
        keep, tail = head;
    }
    LinkList(int n) {
        head = new Node(0);
        head->next = head;
        keep, tail = head;
        for (int i = 0; i < n; ++i) {
            Node *p = new Node(i+1);
            this->insert(p);
        }
    }
    void insert(Node *node) {
        tail->next = node;
        tail = node;
        tail->next = head;
    }
    void delete(int n) {
        // for (int i = 1; i <= n; ++i) {
        // }
    }
    void show() {
        Node *p = head->next;
        while (p != head) {
            cout << p->value << endl;
            p = p->next;
        }
    }
private:
    Node *head;
    Node *keep;
    Node *tail;
};

int main() {
    LinkList l(10);
    l.show();

    return 0;
}