#include <iostream>
#include <fstream>
using namespace std;

void readEntry( int& entry);

int main() {

    // read input
    ifstream input;

    input.open("input");

    if(input.is_open()){
        cout << "File for input is not opened" << endl;
    }

    // print output

    ofstream output;

    output.open("output.txt");
    if(!output.is_open()){
        cout << "File for output is not opened" << endl;
    }


    // read table dimensions and allocate 2D array
    int nRows, nCols;
    cout<<"Enter the number of rows and columns: ";
    input >> nRows >> nCols;
    int** table = new int*[nRows];
    for(int i = 0; i < nRows; i++) {
        table[i] = new int[nCols];
    }

    // read table data
    cout<<"Enter your numbers: ";
    for(int i = 0; i < nRows; i++) {
        for(int j = 0; j < nCols; j++) {
            try {
                int a;
                input >> a;
              table[i][j] = a;
            }


            catch (int x) {
                    cout << "Entry " << i << "," << j << " not an integer, was set to " << x << ", now setting it to 0" << endl;
                    table[i][j] = 0;
                    input.clear();
                    string tmp;
                    input >> tmp;
            }
        }
    }


    // write table data to the screen in transposed order
    cout << nCols << " " << nRows << endl;
    for(int i = 0; i < nCols; i++) {
        for(int j = 0; j < nRows; j++) {
            output << table[j][i] << " ";
        }
        cout << endl;
    }


    // free memory
    for(int i = 0; i < nRows; i++) {
        delete [] table[i];
    }
    delete [] table;

    input.close();
    output.close();

}

void readEntry( int& entry) {

    cin >> entry;
    if(cin.fail()) {
        throw entry;
    }
}