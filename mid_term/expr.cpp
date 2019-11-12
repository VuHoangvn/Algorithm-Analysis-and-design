#include<bits/stdc++.h>
 
using namespace std;
 
int cnt = 0;
int mem[10000][30];
bool check[10000][30];
int m = pow(10, 9) + 7;
 
int expr(int *arr, int b, int i){
    if(i == 1){
        if( b == arr[0])
            return 1;
        else return 0;
    }
    if(!check[b-arr[i-1] + 3005][i-1]){
        mem[b-arr[i-1] + 3005][i-1] = expr(arr, b-arr[i-1], i-1);
        check[b-arr[i-1] + 3005][i-1] = true;
    }

    if(!check[b+arr[i-1] + 3005][i-1]){
        mem[b+arr[i-1] + 3005][i-1] = expr(arr, b+arr[i-1], i-1);
        check[b+arr[i-1] + 3005][i-1] = true;
    }
    check[b + 3005][i] = true;
    mem[b + 3005][i] = (mem[b-arr[i-1] + 3005][i-1] + mem[b+arr[i-1] + 3005][i-1]) % m;
    return (mem[b + 3005][i] + m) %m;
 
}
 
int main(){
    int n,b, count = 0;
    cin >> n >> b;
    int *arr = new int[n];
 
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
 
    cout << expr(arr, b, n);
 
 
    return 0;
}