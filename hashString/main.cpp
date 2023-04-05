#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <fstream>

using namespace std;

bool fileExists(const char *filename){
    ifstream infile(filename);
    return infile.good();
  
}

string readFile(string filename){
  ifstream file(filename);
  char c;
  string line = "";
  
  while (file >> noskipws >> c) {
    line += c;
  }
  return line;
}

// Archivo.txt

string hexValue(int decimal){
    string result;
    char chars[128];
    int k = 0, catControl;
    while (decimal != 0) {


        catControl = 0;

        catControl = decimal % 16;

        if (catControl < 10) {


            chars[k] = catControl + 48;
            k++;

        } else {

            //cout << "Miki" << endl;
            //cout << catControl << endl;
            chars[k] = catControl + 55;
            k++;

        }
        decimal /= 16;

    }
    for (int i = k - 1; i >= 0; i--) {
        result += chars[i];

    }

    return result;

}

void computeHash(string data, int n){
    
    double s = data.size();
    
    vector<vector<int> > matrix;
    int cols = n;
    cout << "Columns: " << cols << endl;
    int rows = ceil(s / n);
    cout << "Rows: " << rows << endl;
    matrix.resize(rows, vector<int>(cols, n));

    
    int k = 0;
    for (int i = 0; i< rows; i++){
        for (int j = 0; j < cols; j++){
            if (k < s){matrix[i][j] = int(data[k]); k++;}
                
            
        }
    } 

    cout << "Matrix Made" << endl;
    
    /*
    for (int i = 0; i< rows; i++){
        for (int j = 0; j < cols; j++){
            cout << matrix[i][j] << " ";
           
        }
        cout << endl;

    } */
    

    vector<int> sums(n, 0);

    for (int i = 0; i < cols; i++){

        for (int j = 0; j < rows; j++){
            sums[i] += matrix[j][i];
        }
        
    }

    cout << "Column results obtained" << endl;

    vector<int> result(n/4,0);
    k = 0;
    int sumres = 0;
    for (int i = 0; i < sums.size(); i +=4){
        sumres = sums[i] + sums[i+1] + sums[i+2] + sums[i+3];
        result[k] += sumres; 
        k++;
    }

    cout << "Results grouped, converting to hexadecimal values:" << endl;

    string boah = " ";

    for (int i = 0; i < result.size(); i++){
        //cout << "mIKI: " << i << endl;
        boah = hexValue(result[i]);
        cout << boah << " ";
    }
    cout << endl;

}

bool validateNumber(int n){
    return ((16 <= n && n <= 64) && (n % 4 == 0));

}



int main(){
    string filename;
    int n;

    cout << "Enter filename with extension: ";
    cin >> filename;
    int filen = filename.size();
    char filechar[filen];
    strcpy(filechar, filename.c_str());
    if(!fileExists(filechar)){
        cout << "The specified file does not exist" << endl;
    } else {
        string text = readFile(filechar);
        if(text.size() == 0){
            cout << "The file entered is empty" << endl;
        } else {
            cout << "Enter a multiple of for between 16 and 64: ";
            cin >> n;
            while(cin.fail()){
                cout << "User input is not an integer number" << endl;
                cin.clear();
                cin.ignore(256,'\n');
                cin >> n;
            }
            cout << "User input is a number" << endl;
            while(true){
                if (!validateNumber(n)){
                    cout << "User input does not comply with parameters" << endl;
                    cout << "Input: ";
                    cin >> n;
                } else {    
                    cout << "User input is valid" << endl;
                    break;
                }
            }
            computeHash(text, n);

            
            
        }
    }

}