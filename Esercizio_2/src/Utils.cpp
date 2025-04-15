#include "Utils.hpp"
#include "iostream"
#include "fstream"
#include "sstream"
#include "string"
#include "iomanip"

using namespace std;

bool ImportArrays(const string& ImputFilePath, size_t& n, double& S, double*& w, double*& r)
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

double RateOfReturn(const double* const& r, const size_t& n)
{
    //Si calcola il rate come somma dei singoli rate e non come somma pesata
    double rate = 0.0;
    for(unsigned int i = 0; i < n; i++)
        rate += r[i];
    return rate;
}

double FinalValue(const double& S, const double& rate)
{
    double Value = S * (1.0 + rate);
    return Value;
}

bool ExportResult(const string& OutputFilePath, const size_t& n, const double& S, const double* const& w, const double* const& r, const double& Rate, const double& Value)
{
    ofstream file;
    file.open(OutputFilePath);

    if(file.fail())
    {
        cerr << "File did not open successfully!" << endl;
        return false;
    }

    file << fixed << setprecision(2);
    file << "S = " << S << ", n = " << n << endl;

    file << "w = [ ";
    for(unsigned int i = 0; i < n; i++)
        file << fixed << setprecision(2) << w[i] << " ";    
    file << "]" << endl;

    file << "r = [ ";
    for(unsigned int i = 0; i < n; i++)
        file << fixed << setprecision(2) << r[i] << " ";
    file << "]" << endl;

    file << fixed << setprecision(4);
    file << "Rate of return of the portfolio: " << Rate << endl;

    file << fixed << setprecision(2);
    file << "V: " << Value << endl;

    file.close();
    return true;
}

string ArrayToString(const size_t& n, const double* const& v)
{
    string str;
    ostringstream toString;
    toString << "[";
    for(unsigned int i = 0; i < n; i++)
        toString << v[i] << " ";
    toString << "]";

    return toString.str();
}