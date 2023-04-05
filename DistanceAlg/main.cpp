#include <vector>
#include <cmath>
#include <iostream>



double calculateProximity(double x1, double x2, double y1, double y2){
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void generatePermutations(){

}

int main(){
    std::cout << calculateProximity(3,7,2,8);
    return 0;
}