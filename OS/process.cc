#include <iostream>
#include <string>
#include <vector>
#include "pcb.h"

using std::cout; using std::cin;
using std::endl; using std::string;
using std::vector;

void run(Process_Queue &pcb_q, Process_Queue &finish_pcb, PCB *running);

int main() {
    Process_Queue pcb_q(10);                //随机产生10个进程
    Process_Queue finish_pcb;
    PCB *running;
    pcb_q.pri_sort();
    pcb_q.showout();
    for (int i = 0; i < 100; ++i) {         //运行100个时间片
        run(pcb_q, finish_pcb, running);
    }
    cout << "\nAfter 100 timeslices" << endl;
    pcb_q.showout();
    cout << "\nFinished process" << endl;
    finish_pcb.showout();
    return 0;
}

void run(Process_Queue &pcb_q, Process_Queue &finish_pcb, PCB *running) {
    running = pcb_q.pop();
    pcb::timeslice++;
    pcb_q.wait();
    running->ALLTIME--;
    running->CPUTIME++;
    if (running->ALLTIME == 0) {
        running->STATE = pcb::Finish;
        finish_pcb.push(running);
        return;
    }
    pcb_q.push(running);
    pcb_q.pri_sort();
}