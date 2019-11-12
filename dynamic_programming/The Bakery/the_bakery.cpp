#include <bits/stdc++.h>
typedef long long ll;
const int INF = -1000000;
using namespace std;

int cost(int *arr, int i, int j)
{
    set<int> value;
    for (int x = i; x <= j; x++)
    {
        value.insert(arr[x]);
    }
    // cout << value.size()<<endl;
    return value.size();
}

int main()
{
    freopen("test.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    int arr[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        // cout << arr[i] << endl;
    }
    int F[k + 1][n + 1];
    for (int g = 0; g < k; g++)
    {
        for (int i = 0; i < n; i++)
        {
            if (g == 0)
            {
                F[g][i] = cost(arr, 0, i);
            }
            else
            {
                F[g][i] = INF;
                for (int x = 0; x < i; x++)
                {
                    int new_cost = F[g - 1][x] + cost(arr, x+1, i);
                    if (F[g][i] < new_cost)
                        F[g][i] = new_cost;
                }
            }
        }
    }
    cout << F[k - 1][n - 1] << endl;
    return 0;
}