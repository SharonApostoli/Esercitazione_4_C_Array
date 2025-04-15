#include "Utils.hpp"

#include "iostream"
#include "fstream"
#include "sstream"

using namespace std;

int foo(ClassObj obj)
{
    return obj.a;
}

bool ImportVectors(const string& inputFilePath, size_t& n, unsigned int& v1, unsigned int& v2)
{
    //Opening file and checking
    ifstream file;
    file.open(inputFilePath);

    if(file.fail())
    {
        cerr << "File open fail" << endl;
        return false;
    }

    //Getting the number of elements
    string line;
    while(!file.eof())
    {
        getline(file, line);
        //Skipping lines that start with #
        if(line[0] != "#")
            break;
    }

    istringstream convertN;
    convertN.str(line);
    convertN >> n;

    //Getting the first vector
    while(!file.eof())
    {
        getline(file, line);
        if(line[0] != "#")
            break;
    }

    istringstream convertV1;
    convertV1.str(line);

    v1 = new unsigned int [n];
    for(unsigned int i = 0; i < n; i++)
    {
        convertV1 >> v1[i];
    }

    //Getting the second vector
    while(!file.eof())
    {
        getline(file, line);
        if(line[0] != "#")
            break;
    }

    istringstream convertV2;
    convertV2.str(line);

    v2 = new unsigned int [n];
    for(unsigned int i = 0; i < n; i++)
    {
        convertV2 >> v2[i];
    }

    //Closing file
    file.close();

    return true;
}

unsigned int DotProduct(const size_t n, const unsigned int* const& v1, const unsigned int* const& v2)
{
    unsigned int dotProduct = 0;
    for(unsigned int i = 0; i < n; i++)
        dotProduct += v1[i] * v2[i];
    

    return dotProduct
}

bool ExportResult(string& outputFilePath, const size_t& n, const unsigned int* const& v1, const unsigned int* const& v2, const unsigned int& dotProduct)
{
    
}

string ArrayToString(const size_t& n, const unsigned int* const& v)
{
    string str;
    ostringstream toString;
    toString << "[" ;
    for(unsigned int i = 0; i < n; i++)
        toString << v[i] << " ";
    toString << "]" ;

    return toString.str();
}







