#pragma once

#include <iostream>

using namespace std;

bool ImportArrays(const string& ImputFilePath, size_t& n, double& S, double*& w, double*& r);

double RateOfReturn(const double* const& r, const size_t& n);

double FinalValue(const double& S, const double& rate);

bool ExportResult(const string& OutputFilePath, const size_t& n, const double& S, const double* const& w, const double* const& r, const double& Rate, const double& Value);

string ArrayToString(const size_t& n, const double* const& v);