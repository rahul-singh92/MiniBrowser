#ifndef FILELOADER_H
#define FILELOADER_H
#include <string>
using namespace std;

class FileLoader
{
    public:
        static string readFile(const string& path);
};

#endif