#include "FileLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

string FileLoader::readFile(const string &path)
{
    ifstream file(path);

    if (!file.is_open())
    {
        cout << "Error: Cannot open file: " << path << endl;
        return "";
    }

    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}
