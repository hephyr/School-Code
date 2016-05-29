#include <iostream>
#include <cmath>

class Queen {
public:
    //Queen() = default;
    Queen(int n);
    //~Queen() = default;
    bool Place(int k);
    void Backtrack(int t);
    void setPtr(int *p);
    long getSum();
private:
    int n;
    int *x;
    long sum;
};
Queen::Queen(int k) {
    this->n = k;
    sum = 0;
}
bool Queen::Place(int k) {
    for (int j = 1; j < k; ++j) {
        if ((std::abs(k-j) == std::abs(x[j] - x[k])) || (x[j] == x[k]))
            return false;
    }
    return true;
}
void Queen::Backtrack(int t) {
    if (t > n) {
        ++sum;
    } else {
        for (int i = 1; i <= n; ++i) {
            x[t] = i;
            if (Place(t))
                Backtrack(t+1);
        }
    }
}
void Queen::setPtr(int *p) {
    x = p;
}
long Queen::getSum() {
    return sum;
}