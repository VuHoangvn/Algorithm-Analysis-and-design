#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int n;
    int res = 0;
    int p = pow(10, 9) + 7;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        res += arr[i] % p;
        res = res % p;
    }
        
    cout << res;
    return 0;
    
}