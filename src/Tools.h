#pragma once
#include<string>
#include<fstream>
#include"DL.h"
#include"json.hpp"


using namespace std;
using json = nlohmann::json;
int mod(int a, int b);
string PlusOne(string& num);
void LoadInFile(int index, string value, string fileName, string);
int ByteToInt(string str);
bool fileExists(const string& filename);
void createNewFile(string fileName, string Name);
bool containsString(json jArray, string str);
DL<string> split(string str);
bool ValidFile(const string& filename);
int64_t dg(int64_t base, int64_t exponent);
