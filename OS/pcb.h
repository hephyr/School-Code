#include <iostream>
#include <random>

namespace pcb {
    int timeslice = 0;
    int PCB_ID = 0;
    enum state { Ready, Run, Block, Finish };
}


struct process_control_block {
    int ID;
    int PRIORITY;
    int ARTIME;
    int ALLTIME;
    int CPUTIME;
    int STARTBLOCK;
    int BLOCKTIME;
    pcb::state STATE;
    struct process_control_block* next;
};
typedef struct process_control_block PCB;

class Process_Queue
{
public:
    Process_Queue();
    Process_Queue(int n);   //构造函数
    ~Process_Queue();
    PCB* random_process();  //产生进程
    void showout();         //输出
    int size();             //返回队列中元素个数
    void pri_sort();        //使用优先级对pcb排序
    void swap_queue(PCB *p, PCB* q);    //交换队列中两个元素
    PCB* findPre(PCB *p);   //查找前驱结点
    PCB* pop();             //将第一个元素弹出队列
    bool push(PCB *p);      //将元素插入队尾
    void wait();            //进程在就绪队列中待一个时间片，优先数加1
private:
    PCB *p_queue = new PCB();
    int start;
    int end;
};

Process_Queue::Process_Queue() : start(0), end(0){}

Process_Queue::Process_Queue(int n) {
    PCB *p;
    PCB *temp = p_queue;
    for (int i = 0; i < n; ++i) {
        p = this->random_process();
        temp->next = p;
        temp = p;
    }
    end = n;
}

Process_Queue::~Process_Queue() {
    PCB* p = p_queue;
    PCB* delete_ptr;
    while (p != nullptr) {
        delete_ptr = p;
        p = p->next;
        delete delete_ptr;
    }
}

PCB* Process_Queue::random_process() {
    std::random_device rd;                          //使用random库产生平均分布的随机数
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist1(1,10);
    std::uniform_int_distribution<> dist2(1,20);
    std::uniform_int_distribution<> dist3(1,50);
    PCB *p = new PCB;
    p->ID = pcb::PCB_ID;
    ++pcb::PCB_ID;
    p->PRIORITY = dist2(gen);
    p->ARTIME = pcb::timeslice;
    p->ALLTIME = dist3(gen);
    p->CPUTIME = p->STARTBLOCK = p->BLOCKTIME = 0;
    p->STATE = pcb::Ready;
    p->next = nullptr;
    return p;
}

void Process_Queue::showout() {
    std::cout << "ID\tPRIORITY\tARTIME\tALLTIME\tCPUTIME\t"
        << "STARTBLOCK\tBLOCKTIME\tSTATE" << std::endl;
    PCB *p = p_queue->next;
    while (p != nullptr) {
        std::cout << p->ID << '\t' << p->PRIORITY << "\t\t" << p->ARTIME << '\t'
        << p->ALLTIME << '\t' << p->CPUTIME << '\t' << p->STARTBLOCK << "\t\t"
        << p->BLOCKTIME << "\t\t" ;
        switch(p->STATE) {
            case pcb::Ready : std::cout << "Ready" << std::endl; break;
            case pcb::Run : std::cout << "Run" << std::endl; break;
            case pcb::Block : std::cout << "Block" << std::endl; break;
            case pcb::Finish : std::cout << "Finish" << std::endl; break;
        }
        p = p->next;
    }
}

int Process_Queue::size() {
    int i = 0;
    PCB*p = p_queue->next;
    while (p != nullptr) {
        ++i;
        p = p->next;
    }
    return i;
}

void Process_Queue::pri_sort() {
    for (PCB *p = p_queue->next; p != nullptr; p = p->next) {
        for (PCB *q = p_queue->next; q != p; q = q->next) {
            if (q->PRIORITY < p->PRIORITY) {
                this->swap_queue(p, q);
                break;
            }
        }
    }
}

void Process_Queue::swap_queue(PCB *node1, PCB *node2) {
    //若两结点相等
    if (node1 == node2) {
        return;
    }
    PCB *prenode1 = findPre(node1);
    PCB *prenode2 = findPre(node2);
    PCB *postnode1 = node1->next;
    PCB *postnode2 = node2->next;
    //若两结点相邻
    if (postnode1 == node2){
        prenode1->next = node2;
        node2->next = node1;
        node1->next = postnode2;
        return;
    }
    if (postnode2 == node1) {
        prenode2->next = node1;
        node1->next = node2;
        node2->next = postnode1;
        return;
    }
    //其它情况
    prenode1->next = node2;
    node2->next = postnode1;
    prenode2->next = node1;
    node1->next = postnode2;
}

PCB* Process_Queue::findPre(PCB *p) {
    PCB* temp = p_queue;
    while (temp->next != p) {
        temp = temp->next;
    }
    return temp;
}

PCB* Process_Queue::pop() {
    PCB* p = p_queue->next;
    p_queue->next = p->next;
    --end;
    return p;
}

bool Process_Queue::push(PCB *p) {
    PCB *tail = p_queue->next;
    int i = 1;
    while (tail != nullptr) {
        tail = tail->next;
    }
    tail = findPre(tail);
    tail->next = p;
    p->next = nullptr;
    ++end;
    return true;
}

void Process_Queue::wait() {
    PCB *p = p_queue->next;
    while (p != nullptr) {
        ++p->PRIORITY;
        p = p->next;
    }
}