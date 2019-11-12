#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("nk.txt", "r", stdin);
    freopen("test/test50.txt", "w", stdout);
    int n, k;
    int i = 0;
    n = 2571;
    k = 16;
    cout << n << " " << k << endl;
    for (int i = 0; i < n; i++)
    {
        cout << rand() % n + 1 << " ";
    }
    cout << endl;
    fclose(stdout);
    fclose(stdin);
}