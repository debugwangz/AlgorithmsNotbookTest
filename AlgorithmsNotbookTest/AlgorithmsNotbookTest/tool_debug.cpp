//
//  tool_debug.cpp
//  AlgorithmsNotbookTest
//
//  Created by 王哲 on 2021/2/1.
//

#include <fstream>
#include <iostream>
#include "tool_debug.hpp"
using namespace std;
string CHAPTER;
string TYPEOFFILE;
ifstream in;

void  inputRedirection(string inputFile){
    inputFile = CHAPTER + inputFile + TYPEOFFILE;
    in.open(inputFile);
    cin.rdbuf(in.rdbuf());
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
