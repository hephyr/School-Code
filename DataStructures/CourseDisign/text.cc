#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> v1;
    v1.assign(10);
    for (auto &a : v1)
        cout << a << endl;
    return 0;
}