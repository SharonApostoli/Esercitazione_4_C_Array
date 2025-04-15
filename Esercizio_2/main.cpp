#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "src/Utils.hpp"

using namespace std;

int main()
{
    //Check if ifle is opened correctly
    string inputFileName = './data.txt';
    size_t n = 0;
    double S = 0;
    double* w = nullptr;
    double* r = nullptr;

    if(!ImportVectors(inputFileName, n, S, w, r))
    {
        cerr << "Error while importing data" << endl;
        return -1;
    }
    else
        cout << "The import was succesful!" << endl;
        cout << "S = " << S << "n = " << n << "w = " << ArrayToString(n, w) << "r = " << ArrayToString(n, r) << endl;
    

    //Get all the information from the file: S, n, w=[], r=[]

    //Compute the rate of return

    //Print on screen and on a new file named "reslut.txt"
    return 0;
}

