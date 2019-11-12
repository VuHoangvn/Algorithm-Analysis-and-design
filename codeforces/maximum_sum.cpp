#include<iostream>
#include<math.h>
#include<cstring>
using namespace std;

int arr[1000];
int mem[1000];
bool comp[1000];
// memset(comp, 0, sizeof(comp));

int max_sum(int i){
    if(i == 0){
        return arr[i];
    }

    int res = max(arr[i], arr[i] + max_sum(i-1));

    return res;
}

int main(){
    for(int i = 0; i < 101; i++){
        arr[i] = pow(1, i) * i;
    }
    cout<< max_sum(100)<<endl;
    return 0;
}