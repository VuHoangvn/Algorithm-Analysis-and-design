#include<iostream>
#include<limits>

using namespace std;

int findMax(int arr[], int i, int j){
    int max = numeric_limits<int>::min();
    int ind = i;
    for(int x = i; x <= j; x++){
        if(arr[x] > max){
            max = arr[x];
            ind = x;
        }
    }

    return arr[ind];
}

int maxGold(int arr[], int L1, int L2, int num){
    int ms[num];
    for (int i = num -1; i >=num - L1; i--)
        ms[i] = arr[i];
    for (int i = num - L1 -1; i >= 0; i--){
        ms[i] = max(arr[i] + findMax(ms, i+L1, i+L1+L2 < num ? i + L1 + L2 : num-1), ms[i+1]);
    }

    return ms[0];
}

int main(){
    int num, L1, L2;
    ios::sync_with_stdio(false);
    cin.tie();
    cin >> num >> L1 >> L2;
    int arr[num];
    for(int i = 0; i < num; i++)
        cin >> arr[i];
    
    cout << maxGold(arr, L1, L2, num);
    return 0;
}