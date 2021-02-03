//
//  tool_debug.cpp
//  AlgorithmsNotbookTest
//
//  Created by 王哲 on 2021/2/1.
//

#include <fstream>
#include <iostream>
#include <vector>
#include "tool_debug.hpp"
using namespace std;
string CHAPTER;
string TYPEOFFILE;
ifstream in;
vector<string> split(const string &str,const string &pattern)
{
    //const char* convert to char*
    char * strc = new char[strlen(str.c_str())+1];
    strcpy(strc, str.c_str());
    vector<string> resultVec;
    char* tmpStr = strtok(strc, pattern.c_str());
    while (tmpStr != NULL)
    {
        resultVec.push_back(string(tmpStr));
        tmpStr = strtok(NULL, pattern.c_str());
    }
    delete[] strc;
    return resultVec;
}
void  inputRedirection(string inputFile){
    inputFile = CHAPTER + inputFile + TYPEOFFILE;
    in.open(inputFile);
    cin.rdbuf(in.rdbuf());
    char * fileName = new char[inputFile.length()];
    strcpy(fileName, inputFile.c_str());
    freopen(fileName,"r",stdin);
    delete[] fileName;
}

void printIntArrary(int *arrary, int length){
    for (int i = 0;i < length;i++) {
        cout<<arrary[i];
        if (i != length - 1) {
            cout<<" ";
        }
    }
    cout<<endl;
}

void copyIntArrary(int *from, int *to, int length){
    for (int i = 0; i < length; i++) {
        to[i] = from[i];
    }
}
