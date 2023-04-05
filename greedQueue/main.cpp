#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> makeCombination(vector<int> customers) {
    sort(customers, customers+3);

}

void calculateTime(vector<int> times){ // calcula el tiempo de una fila de 3 clientes
    int totalTime = times[0] + (times[0] + times[1]) + (times[0] + times[1] + times[2]);
    cout << "TotalTimeIs: " << totalTime << endl;
}

int main() {
    vector<int> times;
    times.push_back(6);
    times.push_back(12);
    times.push_back(4);
    calculateTime(times);
    return 0;
}