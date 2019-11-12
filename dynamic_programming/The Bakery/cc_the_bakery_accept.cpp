#include <bits/stdc++.h>
typedef long long ll;
const int MAXK = 55;
const int MAXN = 35005;
const int INF = -1000000;
int F[55][35005];
int P[55][35005];
int arr[35005];
using namespace std;
struct Node
{
    int st, l, r;
};

int cur = 1;
Node nodes[32 * MAXN];

int n, k;
int root[MAXN], prev_i[MAXN], prev_x[MAXN];
int prev_ti[MAXN], prev_tx[MAXN];
map<int, int> cache[MAXN];

inline int build(int l, int r)
{
    int t = cur++;
    if (l + 1 != r)
    {
        int m = (l + r) / 2;
        nodes[t].l = build(l, m);
        nodes[t].r = build(m, r);
    }
    return t;
}

inline int upd(int idx, int l, int r, int i)
{
    int t = cur++;
    nodes[t] = nodes[idx];
    if (l + 1 != r)
    {
        int m = (l + r) / 2;
        if (i < m)
            nodes[t].l = upd(nodes[t].l, l, m, i);
        else
            nodes[t].r = upd(nodes[t].r, m, r, i);
        nodes[t].st = nodes[nodes[t].l].st + nodes[nodes[t].r].st;
    }
    else
        nodes[t].st = 1;
    return t;
}

inline int query(int idx, int l, int r, int L, int R)
{
    if (l == L && r == R)
        return nodes[idx].st;
    int m = (l + r) / 2, res = 0;
    if (L < m)
        res += query(nodes[idx].l, l, m, L, min(m, R));
    if (R > m)
        res += query(nodes[idx].r, m, r, max(L, m), R);
    return res;
}

inline void build_pst()
{
    int t = 0;
    int cur_root = build(0, n);
    root[0] = cur_root;

    for (int i = 1; i <= n; i++)
    {
        prev_ti[i] = prev_tx[prev_i[i]];
        prev_tx[prev_i[i]] = i;
    }

    for (int i = 0; i <= n; i++)
    {
        int z = prev_tx[i];
        if (i > 0)
            root[i] = root[i - 1];
        while (z)
        {
            cur_root = root[i] = upd(cur_root, 0, n + 1, z);
            z = prev_ti[z], t++;
        }
    }
}

inline int cost(int l, int r)
{
    if (l > r)
        return 0;
    if (cache[l].count(r) == 0)
        cache[l][r] = query(root[l - 1], 0, n + 1, l, r + 1);
    return cache[l][r];
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
    char inputFile[30];
    char outputFile[30];
    // for (int i = 9; i <= 50; i++)
    // {
        int i = 50;
        sprintf(inputFile, "testcase/test%d/bakery.inp", i);
        sprintf(outputFile, "testcase/test%d/bakery.out", i);
        freopen(inputFile, "r", stdin);
        freopen(outputFile, "w", stdout);
        cin >> n >> k;
        // int arr[n + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            prev_i[i] = prev_x[arr[i]];
            prev_x[arr[i]] = i;
            // cout << arr[i] << endl;
        }

        build_pst();
        // int F[k + 1][n + 1];
        for (int i = 1; i <= n; i++)
        {
            F[1][i] = cost(1, i);
        }
        for (int g = 2; g <= k; g++)
            solve(g, 1, n, 0, n);
        cout << F[k][n] << endl;
        fclose(stdin);
        fclose(stdout);
    // }

    return 0;
}
