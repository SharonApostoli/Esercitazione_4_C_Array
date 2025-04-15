#include <iostream>
#include <fstream>
#include <sstream>
#include "Utils.hpp" // g++ requires: "src/Utils.hpp"
// #include "ClassObj.hpp" // error if pragma once is not used in ClassObj

using namespace std;

int main()
{
    //open the file and check if import went well
    string inputFileName = "./vectors.txt";
    size_t n = 0;
    unsigned int* v1 = nullptr;
    unsigned int* v2 = nullptr;

    if(!ImportVectors(inputFileName, n, v1, v2))
    {
        cerr << "File not imported correctly!" << endl;
        return -1;
    }
    else
    {
        cout << "Import went correctly! \n n: " << n << ", v1: " << ArrayToString(n, v1) << ",v2: " << ArrayToString(n, v2) << endl;
    }
    


    //do the dot product on the two vectors

    return 0;
}


