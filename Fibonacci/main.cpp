#include <iostream>

using namespace std;

void fibonacci(int,int,int);

void checkProx(int curr, int next, int target){
    if (next == target){
        cout << next << endl;
        cout << "Target is in range at: " << next << endl;

    } else if (next < target ){
        cout << next << " ";
        fibonacci(next, curr, target);
    } else {
        cout << next << endl;
        cout << "Closest to target: " << curr << endl;
    }

}

void mergeNumbers(int curr, int prev, int target){
    int next;

    next = curr + prev;
    checkProx(curr, next, target);

}

void fibonacci(int curr, int prev, int target){
    mergeNumbers(curr, prev, target);

}

int main (){
    int target;
    cout << "Enter Target: ";
    cin >> target;
    cout << 0 << " " << 1 << " ";
    fibonacci(1, 0, target);

    return 0;
}