#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>

using namespace std;

struct Node
{
    int pos;
    int mask;
};

int main()
{
    //freopen("test.txt", "r", stdin);
    int n, new_mask, dist;
    cin >> n;
    int c[n + 1][n + 1];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            cin >> c[i][j];

    queue<Node> q;
    int f[n][1 << n];
    memset(f, -1, sizeof(f));

    for (int i = 0; i < n; i++)
    {
        f[i][1 << i] = c[0][i + 1];
        q.push(Node{i, 1 << i});
    }

    while (!q.empty())
    {
        Node node = q.front();
        q.pop();

        for (int i = 0; i < n; i++)
            if (!(node.mask & (1 << i)))
            {
                new_mask = node.mask | 1 << i;
                dist = f[node.pos][node.mask] + c[node.pos + 1][i + 1];
                if (f[i][new_mask] == -1)
                {
                    f[i][new_mask] = dist;
                    q.push(Node{i, new_mask});
                }
                else
                {
                    f[i][new_mask] = min(f[i][new_mask], dist);
                }
            }
    }
    new_mask = (1 << n) - 1;
    dist = f[0][new_mask] + c[1][0];
    for (int i = 1; i < n; i++)
        dist = min(dist, f[i][new_mask] + c[i + 1][0]);

    cout << dist;
}