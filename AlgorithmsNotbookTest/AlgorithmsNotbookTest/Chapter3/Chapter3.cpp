//
//  Chapter3.cpp
//  AlgorithmsNotbookTest
//
//  Created by 王哲 on 2021/1/31.
//

#include "Chapter3.hpp"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>

using namespace std;
const string inputFile = "Chapter3/B1016.txt";//相对路径起点在inputs
ifstream in;

void b1011();
void b1016();

void  inputRedirection(const string input){
    in.open(input);
    cin.rdbuf(in.rdbuf());
}

void mainInC3(){
//    b1011();
    b1016();
}

#pragma mark - A+B和C
//const string inputFile = "Chapter3/B1011.txt";//相对路径起点在inputs
void b1011(){
    cout<<"A+B和C"<<endl;
//    inputRedirection(inputFile);
    long long int a;
    long long int b;
    long long int c;
    int cases;
    cin>>cases;
    for (int i=0; i<cases; i++) {
        cin>>a>>b>>c;
        cout<<"#Case #"<<i+1<<": ";
        if (a+b > c) {
            cout<<"ture"<<endl;
        }else{
            cout<<"false"<<endl;
        }
    }
    
}

#pragma mark - 部分A+B
//const string inputFile = "Chapter3/B1016.txt";//相对路径起点在inputs
long long getP(long long num,int dNum){
    long long result = 0;
    int d = 0;
    while (num) {
        int n = num % 10;
        if (dNum == n) {
            d++;
        }
        num /= 10;
    }
    for (int i = 0; i < d; i++) {
        result *= 10;
        result += dNum;
    }
    return result;
}

void b1016(){
    inputRedirection(inputFile);
    cout<<"部分A+B"<<endl;
    long long a;
    long long b;
    int da;
    int db;
    while (cin>>a>>da>>b>>db) {
        cout<<a<<" "<<da<<" "<<b<<" "<<db<<" "<<endl;
        long long pa = getP(a, da);
        long long pb = getP(b, db);
        cout<<pa + pb<<endl;
    }
}
