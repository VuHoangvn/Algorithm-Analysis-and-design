#include <iostream>

using namespace std;

void fib(int n){
    int *fib_arr = new int[n];
    fib_arr[0] = 1;
    fib_arr[1] = 1;

    for(int i = 2; i < n; i++){
        fib_arr[i] = fib_arr[i-1] + fib_arr[i-2];
    }

    cout << "So fibonacci thu " << n-1 << ": " << fib_arr[n-1] << endl;
}

int main(){
    int n;
    cin >> n;
    fib(n);
    return 0;
}