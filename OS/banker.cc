#include <iostream>
#include <vector>
using std::cin; using std::cout;
using std::endl; using std::vector;

const int num_process = 3, num_resources = 4;         //总进程数 资源种类数
int ALL_RESOURCE[num_resources];          //各种资源的数目总和
int MAX[num_process][num_resources];    //进程对资源最大资源的需求量
int AVAILABLE[num_resources];           //系统可用资源数
int ALLOCATION[num_process][num_resources];    //进程已经得到的资源量
int NEED[num_process][num_resources];   //进程还需要的资源量
int Request[num_resources];           //请求资源个数
bool Finish[num_process];

void init();
void output_all_resource();
void output_max();
void output_avaiable();
void output_need();
void banker(int no);
bool check_safe();

int main() {
    init();
    output_all_resource();
    output_max();
    output_avaiable();
    output_need();
    if (check_safe()) {
        cout << "Safe" << endl;
    } else {
        cout << "Not Safe" << endl;
    }
    cout << "Enter the id of process request resources :";
    int id;
    cin >> id;
    banker(id);
    return 0;
}

void init() {
    cout << "There are " << num_resources << " resources." << endl;
    cout << "Enter The Maximum Number Of Instances Of Each Resource Type."
         << endl;
    cout << ">";
    for (int i = 0; i != num_resources; ++i) {
        cin >> ALL_RESOURCE[i];
    }
    cout << "There are " << num_process << " process." << endl;
    cout << "Enter Maximum Claim Table." << endl;
    for (int i = 0; i != num_process; ++i) {
        cout << ">";
        for (int j = 0; j != num_resources; ++j) {
            cin >> MAX[i][j];
        }
    }
    cout << "Enter The Available Resources" << endl;
    cout << ">";
    for (int i = 0; i != num_resources; ++i) {
        cin >> AVAILABLE[i];
    }
    cout << "Enter Allocated Resource Table" << endl;
    for (int i = 0; i != num_process; ++i) {
        cout << ">";
        for (int j = 0; j != num_resources; ++j) {
            cin >> ALLOCATION[i][j];
        }
    }
    for (int i = 0; i != num_process; ++i) {
        for (int j = 0; j != num_resources; ++j) {
            NEED[i][j] = MAX[i][j] - ALLOCATION[i][j];
        }
    }
    for (int i = 0; i != num_process; ++i) {
        Finish[i] = false;
    }
}

void output_all_resource() {
    cout << "The Maximum Number Of Instances Of Each Resource Type." << endl;
    for (int i = 0; i != num_resources; ++i) {
        cout << ALL_RESOURCE[i] << " ";
    }
    cout << endl;
}
void output_max() {
    cout << "The Maximum Claim Table." << endl;
    for (int i = 0; i != num_process; ++i) {
        for (int j = 0; j != num_resources; ++j) {
            cout << MAX[i][j] << " ";
        }
        cout << endl;
    }
}
void output_avaiable() {
    cout << "The Allocated Resource Table." << endl;
    for (int i = 0; i != num_resources; ++i) {
        cout << AVAILABLE[i] << " ";
    }
    cout << endl;
}
void output_need() {
    cout << "NEED" << endl;
    for (int i = 0; i != num_process; ++i) {
        for (int j = 0; j != num_resources; ++j) {
            cout << NEED[i][j] << " ";
        }
        cout << endl;
    }
}

void banker(int no) {       //进程no请求资源
    while (1) {
        bool flag = true;
        cout << "Enter the request resources: ";
        for (int i = 0; i != num_resources; ++i) {
            cin >> Request[i];
            if (Request[i] > NEED[no][i] || Request[i] > AVAILABLE[i]) {
                flag = false;
            }
        }
        if (flag) {
            for (int i = 0; i != num_resources; ++i) {
                NEED[no][i] -= Request[i];
                AVAILABLE[i] -= Request[i];
                ALLOCATION[no][i] += Request[i];
            }
            break;
        } else {
            cout << "Error value, enter again." << endl;
        }
    }
    if (check_safe()) {
        cout << "System Safe" << endl;
    } else {
        cout << "System Not Safe" << endl;
        for (int i = 0; i != num_resources; ++i) {
            NEED[no][i] += Request[i];
            AVAILABLE[i] += Request[i];
            ALLOCATION[no][i] -= Request[i];
        }
    }
}

bool check_safe() {     //安全性检查
    int WORK[num_resources];
    for (int i = 0; i != num_resources; ++i) {
        WORK[i] = AVAILABLE[i];
    }
    for (int check_times = 0; check_times != num_process; ++check_times) {
        for (int i = 0; i != num_process; ++i) {
            bool flag = true;
            if (Finish[i]) {
                continue;
            }
            for (int j = 0; j != num_resources; ++j) {
                if (NEED[i][j] > WORK[j]) {
                    flag = false;
                    break;
                }
            }
            if (!flag) {            //判断NEED <= WORK
                continue;
            }
            //如果进程未结束并且NEED <= WORK 则进程获得资源，可顺利执行，直至完成，从而释放资源
            for (int j = 0; j != num_resources; ++j) {
                WORK[j] += ALLOCATION[i][j];
            }
            Finish[i] = true;
        }
    }
    for (int i = 0; i != num_process; ++i) {
        if (!Finish[i])
            return false;
    }
    return true;
}