//
//  Chapter3.cpp
//  AlgorithmsNotbookTest
//
//  Created by 王哲 on 2021/1/31.
//

#include "Chapter3.hpp"
#include <iostream>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <algorithm>
#include "tool_debug.hpp"

using namespace std;
void b1011();
void b1016();
void b1026();
void b1046();
void b1008();
void b1012();
void b1018();
void a1042();
void a1046();
void b1010();
void a1002();

void initEnvironment(){
    CHAPTER = "Chapter3/";
    TYPEOFFILE = ".txt";
}
void mainInC3(){
    initEnvironment();
    //    b1011();
    //    b1016();
    //    b1026();
    //    b1046();
    //    b1008();
    //    b1012();
    //    b1018();
    //    a1042();
    //    a1046();
    //    b1010();
    a1002();
}

#pragma mark - A+B和C
void b1011(){
    cout<<"A+B和C"<<endl;
    inputRedirection("B1011");
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
    cout<<"部分A+B"<<endl;
    inputRedirection("B1016");
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

#pragma mark - 程序运行时间
const int clk_ctk = 100;
void b1026(){
    cout<<"程序运行时间"<<endl;
    int c1;
    int c2;
    cin>>c1>>c2;
    int c = c2 - c1;
    int t = c/clk_ctk;
    if (c % 100 >= 50) {
        t++;
    }
    int hour = t/3600;
    int mintue = t/60%60;
    int second = t%60;
    cout<<hour<<":"<<mintue<<":"<<second<<endl;
}

#pragma mark - 划拳
void b1046(){
    inputRedirection("B1046");
    int n;
    cin>>n;
    int jiaDrink = 0;
    int yiDrink = 0;
    int jiaSay;
    int yiSay;
    int jiaShow;
    int yiShow;
    while (n--) {
        cin>>jiaSay>>jiaShow>>yiSay>>yiShow;
        if (jiaShow == yiShow) {
            continue;
        }
        if (jiaShow == jiaSay + yiSay) {
            yiDrink++;
        }else if (yiShow == jiaSay +yiSay) {
            jiaDrink++;
        }
    }
    cout<<jiaDrink<<" "<<yiDrink<<endl;
    
}

#pragma mark - 数组元素循环右移
void b1008(){
    cout<<"数组循环右移"<<endl;
    int length;
    int m;
    cin>>length>>m;
    m = m % length;
    int a[length];
    for (int i = 0; i<length; i++) {
        cin>>a[i];
    }
    for (int i = 0; i<length; i++) {
        cout<<a[(length - m + i)%length];
        if (i!= length) {
            cout<<" ";
        }
    }
    cout<<endl;
}

#pragma mark - 数字分类
int typeOfNumber(int num){
    if (num % 5 == 0) {
        if (num % 2 == 0) {
            return 0;
        }
        return -1;
    }
    return num % 5;
}

void b1012(){
    cout<<"数字分类"<<endl;
    inputRedirection("B1012");
    int length;
    while (cin>>length){
        int count[5] = {0};
        double ans[5] ={0};
        while (length--){
            int num;
            cin>>num;
            int type = typeOfNumber(num);
            if (type == -1) {
                continue;
            }
            count[type]++;
            switch (type) {
                case 0:ans[0] += num;
                    break;
                case 1:
                {
                    if (count[1] % 2==0) {
                        ans[1] -= num;
                    }else{
                        ans[1] += num;
                    }
                }
                    break;
                case 2:ans[2]++;
                    break;
                case 3:ans[3]+=num;
                    break;
                case 4:
                {
                    if (num > ans[4]) {
                        ans[4] = num;
                    }
                }
                    break;
                default:
                    break;
            }
            
        }
        ans[3] = ans[3] / count[3];
        for (int i = 0; i < 5; i++) {
            if (i != 0) {
                cout<<" ";
            }
            if (count[i] == 0) {
                cout<<"N";
                continue;
            }
            if (i!=3) {
                cout<<(int)ans[i];
            }else{
                cout<<fixed<<setprecision(1)<<ans[i];
            }
        }
        cout<<endl;
    }
}

#pragma mark - 剪刀石头布
int change(char c){
    if (c == 'B') {
        return 0;
    }
    if (c == 'C') {
        return 1;
    }
    if (c == 'J') {
        return 2;
    }
    return -1;
}
void b1018(){
    inputRedirection("B1018");
    cout<<"剪刀石头布"<<endl;
    int length = 0;
    while (cin>>length) {
        char mp[3] = {'B','C','J'};
        int times_A[3] = {0};
        int times_B[3] = {0};
        int hands_A[3] = {0};
        int hands_B[3] = {0};
        while (length--) {
            char A;
            char B;
            cin>>A>>B;
            int a = change(A);
            int b = change(B);
            if ((a+1) % 3 == b) {
                times_A[0]++;
                times_B[2]++;
                hands_A[a]++;
            }else if (a == b){
                times_A[1]++;
                times_B[1]++;
            }else if((a-1) % 3 == b){
                times_A[2]++;
                times_B[0]++;
                hands_B[b]++;
            }
        }
        printIntArrary(times_A, 3);
        printIntArrary(times_B, 3);
        int id1 = 0;
        int id2 = 0;
        for (int i = 0; i < 3; i++) {
            if (hands_A[i] >hands_A[id1] ) {
                id1 = i;
            }
            if (hands_B[i] >hands_B[id1] ) {
                id2 = i;
            }
        }
        cout<<mp[id1]<<" "<<mp[id2]<<endl;
    }
}

#pragma mark - 洗牌
const int N =54;
void a1042(){
    cout<<"洗牌"<<endl;
    inputRedirection("A1042");
    int length = 0;
    while (cin>>length) {
        int start[N] = {0};
        int end[N] = {0};
        char mp[]={'S','H','C','D','J'};
        int next[N] = {0};
        for (int i = 0; i < N; i++) {
            start[i] = i;
        }
        for (int i = 0; i < N; i++) {
            cin>>next[i];
        }
        while (length--) {
            for (int i = 0; i < N; i++) {
                end[next[i]-1] = start[i];
            }
            copyIntArrary(end, start, N);
        }
        for (int i = 0; i < N; i++) {
            cout<<mp[start[i]/13]<<start[i] % 13 +1;
            if (i != N-1) {
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

#pragma mark - 最短距离
void a1046(){
    cout<<"最短距离"<<endl;
    inputRedirection("A1046");
    int cases = 0;
    while (cin>>cases) {
        int dis[10005] = {0};
        int result[10005] = {0};
        int sum = 0;
        for (int i = 1; i < cases + 1; i++) {
            int distance = 0;
            cin>>distance;
            sum += distance;
            dis[i] = sum;
        }
        int questions;
        cin>>questions;
        for (int i = 0; i < questions; i++) {
            int left = 0;
            int right = 0;
            cin>>left>>right;
            if (left > right) {
                swap(left, right);
            }
            int distance = dis[right -1] - dis[left - 1];
            result[i] = sum - distance  < distance ? sum - distance : distance;
        }
        printIntArrary(result, questions);
    }
}

#pragma mark - 一元多项式求导
void printPolynomials(int *arrary, int length, int count){
    for (int i = length; i >= 0; i--) {
        if (arrary[i] != 0) {
            cout<<arrary[i]<<" "<<i;
            count--;
            if (count != 0) {
                cout<<" ";
            }
        }
    }
}
void b1010(){
    cout<<"一元多项式求导"<<endl;
    inputRedirection("B1010");
    int k = 0;
    int e = 0;
    int a[1005] = {0};
    int count = 0;
    while (cin>>k>>e) {
        a[e] = k;
    }
    a[0] = 0;
    for (int i = 1; i <= 1000; i++) {
        a[i-1] = i * a[i];
        a[i] = 0;
        if (a[i-1] != 0) {
            count++;
        }
    }
    if (count == 0) {
        cout<<"0 0";
    }else{
        printPolynomials(a, 1000, count);
    }
    cout<<endl;
}

#pragma mark - 多项式求和
void a1002(){
    cout<<"多项式求和"<<endl;
    inputRedirection("A1002");
    int length = 0;
    while (cin>>length) {
        int count = 0;
        double p[1111] = {0};
        count = length;
        int e = 0;
        double k = 0;
        for (int i = 0; i < length; i++) {
            cin>>e>>k;
            p[e] = k;
        }
        cin>>length;
        for (int i = 0; i < length; i++) {
            cin>>e>>k;
            if (p[e] != 0) {
                p[e] += k;
                if (p[e] == 0) {
                    count--;
                }
            }else{
                p[e] = k;
                count++;
            }
        }
        if (count == 0) {
            cout<<"0 0 0";
        }else{
            cout<<count<<" ";
            for (int i = 1000; i >= 0; i--) {
                if (p[i] != 0) {
                    cout<<i<<" "<<fixed<<setprecision(1)<<p[i];
                    if (i !=0) {
                        cout<<" ";
                    }
                }
            }
        }
        cout<<endl;
    }
}
