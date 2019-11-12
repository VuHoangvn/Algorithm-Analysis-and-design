#include<iostream>
#include<map>

using namespace std;

map<int, int> mem;

int fibonacci(int n){
    if (n <= 2) {
        return 1;
    }

    if(mem.find(n) != mem.end()){
        return mem[n];
    }

    int res = fibonacci(n-2) + fibonacci(n-1);
    mem[n] = res;
    return res;

}

int main() {
    cout << fibonacci(10) << endl;
    return 0;
}