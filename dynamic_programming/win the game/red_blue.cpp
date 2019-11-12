#include<iostream>

using namespace std;

int main(){
    double dp[1003][1003];
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                if(i == 0){ dp[i][j] = 1; continue;}
                if(j == 0){ dp[i][j] = 1; continue;}
                dp[i][j] = i*1.0/(i+j) + (j *1.0/(i+j)) * ((j-1) * 1.0/(i+j-1)) * dp[i][j-2];
            }
        }
        printf("%.6f\n", dp[n][m]);
    }
    return 0;
}