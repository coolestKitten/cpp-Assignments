#include <iostream>
#include <string>
#include <vector>


using namespace std;

void ZFunc(string zarr, vector<int> numbers, int p , int t){
    if(zarr[p] == '$'){
        p = 0;
    }
    for (int i = 4; i < zarr.length(); i ++){

    }

}

int main(){
    string text = "ACAAACACCADFSDDFSDGHEERGDFGFDSGYJRYIOURGS";
    string patt = "DFG";
    string Zstring = patt + "$" + text;
    int total, p, t;
    vector<int> numbers;
    total = patt.length();
    cout << total << endl;
    return 0;
}