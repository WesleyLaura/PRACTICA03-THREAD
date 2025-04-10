#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>

using namespace std;

double sum1 = 0;
double sum2 = 0;
vector<int> myvector;

void task1() {
    cout << "Task1 esta empezando ... \n";
    double c = 0;
    while (c < 10) { c++; sum1 += c; }
    cout << "Task1 esta completa. \n";
}

void task2() {
    cout << "Task2 esta empezando ... \n";
    double c = 0;
    while (c < 5) { c++; sum2 += c; }
    cout << "Task2 esta completa. \n";
}

void task3() {
    cout << "Task3 esta empezando ... \n";
    myvector = {12, 33, 22, 41, 15, 66, 56, 39, 72};
    sort(myvector.begin(), myvector.end());
    cout << "Task3 esta completa. \n";
}

int main() {
    thread t1(task1);
    thread t2(task2);
    thread t3(task3);

    if (t1.joinable()) {
        t1.join();
        cout << "t1 id = " << t1.get_id() << "\n";
    }

    if (t2.joinable()) {
        t2.join();
        cout << "t2 id = " << t2.get_id() << "\n";
    }

    if (t3.joinable()) {
        t3.join();
        cout << "t3 id = " << t3.get_id() << "\n";
        for (size_t c = 0; c < myvector.size(); c++) {
            cout << "vector(" << c << ") : " << myvector[c] << "\n";
        }
    }

    cout << "sum1: " << sum1 << ", sum2: " << sum2 << "\n";
    return 0;
}
