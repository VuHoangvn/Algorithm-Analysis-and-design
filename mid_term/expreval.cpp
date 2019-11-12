#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, result = 0;
    cin >> n;
    int arr[n];
    bool check[n];
    int b[n-1];
    int mul = 0;

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < n-1; i++){
        scanf("%d", &b[i]);
    }    
    int m = pow(10,9) + 7;
    int i_result = 0;
    int i_cal = 0;
    int cnt = 0;
    int left= 0;
    int sign = 1;
    int right = arr[0];
    for(int i = 0; i < n-1; i++){
        if(b[i] != 2){
            
            left = sign == 0? ((((left - right) % m) +m) % m) : ((((left + right) % m) +m) % m);
            sign = b[i];
            right = ((arr[i+1] %m) + m) % m;
            
        }else{
            right = ((right * arr[i+1]) %m + m)%m;
        }
    }

    left = sign == 0? ((((left - right) % m) +m) % m) : ((((left + right) % m) +m) % m);
    cout << left;

}