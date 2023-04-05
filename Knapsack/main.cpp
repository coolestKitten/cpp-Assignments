#include <vector>
#include <iostream>

using namespace std;

int knapsack(int capacity, vector<int> values, vector<int> weight){
    int len = values.size();
    vector<vector<int>> sack(len + 1, vector<int>(capacity + 1) );

    for (int i = 0; i <= len; i++){
        for(int j = 0; j <= capacity; j++){
            if (i == 0 || j == 0){
                sack[i][j] = 0;
            } else if (weight[i - 1] <= j) {
                if ((values[i - 1] + sack[i - 1][j - weight[i - 1]]) > sack[i - 1][j]) {
                    sack[i][j] = values[i - 1] + sack[i - 1][j - weight[i - 1]];
                } else {
                    sack[i][j] = sack[i - 1][j];
                }
            } else {
                sack[i][j] = sack[i - 1][j];
            }
        }
        
    }
    return sack[len][capacity];
}

int main(){
    int capacity, gatocontrol;
    vector<int> values;
    vector<int> weight;
    cin >> gatocontrol;
    while(cin.fail() || gatocontrol <= 0){
        cout << "Invalid input" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> gatocontrol;
    }
    values.resize(gatocontrol);
    weight.resize(gatocontrol);
    for (int i = 0; i < gatocontrol; i++){
        cin >> values[i];
        while(cin.fail() || values[i] <= 0){
        cout << "Invalid input at " << i << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> values[i];
        }
    }
    for (int i = 0; i < gatocontrol; i++){
        cin >> weight[i];
        while(cin.fail() || weight[i] <= 0){
        cout << "Invalid input at " << i << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> weight[i];
        }
    }
    cin >> capacity;
    while(cin.fail() || capacity <= 0){
        cout << "Invalid input" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> capacity;
    }
    cout << knapsack(capacity, values, weight) << endl;
    return 0;
}