#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "src/Utils.hpp"

using namespace std;

int main()
{
    //Define first set of variables
    string inputFileName = "./data.txt";
    size_t n = 0;
    double S = 0;
    double* w = nullptr;
    double* r = nullptr;

    //Check if ifle is opened correctly
    if(!ImportArrays(inputFileName, n, S, w, r))
    {
        cerr << "Error while importing data" << endl;
        return -1;
    }
    else
    {
        cout << "The import was succesful!" << endl;
    }

    //Defined the two new variables that needed the information inside the text to be defined
    double rate = RateOfReturn(r, n);
    double V = FinalValue(S, rate);

    //Print on screen
    cout.precision(2);
    cout << "S = " << S << "n = " << n << endl;
    cout << "w = " << ArrayToString(n, w) << endl;
    cout << "r = " << ArrayToString(n, r) << endl;
    cout << "Rate of return of the portfolio: " << rate << endl;
    cout << "V: " << V << endl;

    //Print on a new file named "reslut.txt"
    string outputFileName = "./result.txt";
    if(!ExportResult(outputFileName, n, S, w, r, rate, V))
    {
        cerr << "Something went wrong while exporting!" << endl;
        return -1;
    }
    else
        cout << "Export successful!" << endl;

    //Delete pointers
    delete[] w;
    delete[] r;

    return 0;
}

