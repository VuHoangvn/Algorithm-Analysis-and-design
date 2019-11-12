#include<iostream>
#include<cstring>

using namespace std;

int *fib = new int[35];

void cal_fibonacci(){
    fib[0] = 1;
    fib[1] = 1;
    for(int i = 2; i < 35; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
}

int find_length_position(int p){
    if(p == 1){
        return 0;
    }
    for(int i = 0; i < 35; i++){
        if(fib[i] == p)
            return i;
    }
}

void fibonacii_word(int j, string* fibword){
    fibword[0] = '0';
    fibword[1] = '1';
    for(int i =2; i <= j; i++){
        fibword[i] = fibword[i-1] + fibword[i-2];
    }
}

int main(){
    int n;
    string p;
    cin >> n;
    cin >> p;
    int len = p.length();
    if(len == 0){
        cout << "So lan xuat hien: " << 0;
    }
    int position = find_length_position(p.length());
    string* fibword = new string[35];
    fibonacii_word(position, fibword);
    return 0;
}