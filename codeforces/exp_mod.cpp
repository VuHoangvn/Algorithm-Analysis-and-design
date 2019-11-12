#include <iostream>
#include <math.h>

using namespace std;

int compute(long long a, long long b, int m){
    int res = 1;
    a = a%m;

    while(b > 0){
        if(b & 1){
            res = (res * a) % m;
        }

        b = b >> 1;
        a = (a * a) % m;
    }

    return res;
}

int main(){
    long long a, b;
    cin >> a >> b;
    int m = pow(10, 9) + 7;
    cout << compute(a, b, m);
    return 0;
}