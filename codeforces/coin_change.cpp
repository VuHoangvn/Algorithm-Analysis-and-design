#include<iostream>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;

int INF = 1000000;
int d[10];
int mem[10][10000];
// memset(mem, 0, sizeof(mem));

int opt(int i, int x){
    if(x<0) return INF;
    if(x == 0) return 0;
    if(i == -1) return INF;

    int res = INF;
    res = min(res, 1+ opt(i, x - d[i]));
    res = min(res, opt(i-1, x));

    return res;
}
int main(){

    return 0;
}