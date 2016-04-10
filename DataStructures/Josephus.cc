#include <iostream>
#include <cstdlib>
#include <ctime>

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
    bool insert(Node *node) {
        tail->next = node;
        tail = node;
        tail->next = head;
        return true;
    }
    bool a_delete(int n) {
        if (head == head->next) {
            std::cerr << "Empty list can't delete" << endl;
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
    bool b_delete(int n) {
        if (head == head->next) {
            std::cerr << "Empty list can't delete" << endl;
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
    bool empty() {
        if (head->next == head) {
            return true;
        } else {
            return false;
        }
    }
    bool one_node() {
        if (head->next->next == head) {
            return true;
        } else {
            return false;
        }
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

void foo(LinkList &l) {
    if (l.empty()) {
        std::cerr << "The list is empty" << endl;
        exit(1);
    }
    while (!l.one_node()) {
        srand( (unsigned)time( NULL ) );
        int n = rand() % 100;
        l.a_delete(n);
    }
}
int main() {
    LinkList l(10);
    foo(l);
    l.show();
    return 0;
}