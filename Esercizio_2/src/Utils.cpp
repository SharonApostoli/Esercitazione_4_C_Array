#include "Utils.hpp"
#include "iostream"
#include "fstream"
#include "sstream"
#include "string"

using namespace std;

bool ImportVectors(const string& ImputFilePath, size_t& n, double& S, double*& w, double*& r)
{
    ifstream file;
    file.open(ImputFilePath);

    //Open file
    if(file.fail())
    {
        cerr << "File open failed!" << endl;
        return false;
    }

    //Get S
    string line;
    getline(file, line);
    S = stod(line.substr(2));

    //Get n
    getline(file, line);
    n = stod(line.substr(2));

    //Get w and r
    w = new double[n];
    r = new double[n];
    for(unsigned int i = 0; i < n; i++)
    {
        getline(file, line);
        stringstream ss(line);
        string w_str, r_str;
        getline(line, w_str, ';');
        getline(line, r_str);
        w[i] = stod(w_str);
        r[i] = stod(r_str);
    }

    file.close();

    return true;
}








string ArrayToString(const size_t& n, const double*& v)
{
    string str;
    ostringstream toString;
    toString << "[";
    for(unsigned int i = 0; i < n; i++)
        toString << v[i] << " ";
    toString << "]";

    return toString.str();
}