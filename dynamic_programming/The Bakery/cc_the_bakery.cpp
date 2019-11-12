#include <bits/stdc++.h>
typedef long long ll;
const int INF = -1000000;
int F[55][35005];
int P[55][35005];
int arr[35005];
int n, k;
using namespace std;

// int cost(int i, int j)
// {
//     set<int> value;
//     for (int x = i; x <= j; x++)
//     {
//         value.insert(arr[x]);
//     }
//     // cout << value.size()<<endl;
//     return value.size();
// }

set<int> *segment;

void build(int i, int s, int e, int arr[])
{

    if (s == e)
    {
        segment[i].insert(arr[s]);
        return;
    }

    build(2 * i, s, (s + e) / 2, arr);
    build(1 + 2 * i, 1 + (s + e) / 2, e, arr);

    segment[i].insert(segment[2 * i].begin(),
                      segment[2 * i].end());

    segment[i].insert(segment[2 * i + 1].begin(),
                      segment[2 * i + 1].end());
}

set<int> query(int node, int l, int r, int a, int b)
{
    set<int> left, right, result;

    if (b < l || a > r)
        return result;

    if (a <= l && r <= b)
        return segment[node];

    left = query(2 * node, l, (l + r) / 2, a, b);
    result.insert(left.begin(), left.end());

    right = query(1 + 2 * node, 1 + (l + r) / 2, r, a, b);
    result.insert(right.begin(), right.end());

    return result;
}

void init(int n)
{
    int h = (int)ceil(log2(n));
    h = (2 * (pow(2, h))) - 1;

    segment = new set<int>[h];
}

int getDistinct(int l, int r, int n)
{
    set<int> ans = query(1, 0, n - 1, l, r);
    return ans.size();
    // cout << ans.size() << endl;
}

int cost(int i, int j)
{
    // cout << n << endl;
    return getDistinct(i, j, n);
}

void solve(int g, int L, int R, int optL, int optR)
{
    if (L > R)
        return;
    int mid = (L + R) / 2;
    F[g][mid] = INF;
    for (int i = optL; i <= min(mid - 1, optR); i++)
    {
        int new_cost = F[g - 1][i] + cost(i + 1, mid);
        if (F[g][mid] < new_cost)
        {
            F[g][mid] = new_cost;
            P[g][mid] = i;
        }
    }
    solve(g, L, mid - 1, optL, P[g][mid]);
    solve(g, mid + 1, R, P[g][mid], optR);
}

int main()
{
    // freopen("test.txt", "r", stdin);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    init(n+1); 
    build(1, 0, n - 1, arr);
    // cout << n << endl;
    // cout << cost (0, 2);
    for (int i = 0; i < n; i++)
    {
        F[0][i] = cost(0, i);
    }
    for (int g = 1; g <= k; g++)
        solve(g, 0, n - 1, 0, n - 1);
    cout << F[k - 1][n - 1] << endl;
    return 0;
}