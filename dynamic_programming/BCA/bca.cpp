#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int main(){
    freopen("test.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    int *h = new int[n];
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    int **tt = new int*[n];
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        tt[i] = new int[temp];
        for(int j = 0; j < temp; j++){
            cin >> tt[i][j];
        }
    }

    vector<pii> conflict;
    int temp;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
        {
            cin >> temp;
            if(j >= i && temp == 1){
                conflict.push_back({i, j});
            }
        }
    }

    return 0;
}