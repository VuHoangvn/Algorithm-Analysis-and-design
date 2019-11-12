#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair mp;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

using namespace std;

bool isTarget(int x, int y, int N, int M)
{
    if ((x == 0) || (x == N - 1) || (y == 0) || (y == M - 1))
        return true;
    return false;
}

int BFS(int **arr, int i_start, int j_start, int N, int M)
{
    if (isTarget(i_start, j_start, N, M))
        return 0;
    map<pii, int> no_step;
    bool isSolvable = false;
    queue<pii> q;
    q.push({i_start, j_start});
    no_step[{i_start, j_start}] = 1;

    while (!q.empty())
    {
        pii u = q.front();
        q.pop();
        if (isTarget(u.first, u.second, N, M))
        {
            isSolvable = true;
            // cout << u.first << " " << u.second<< endl;
            return no_step[{u.first, u.second}];
        }

        for (int i = 0; i < 4; i++)
        {
            int xx = u.first + dx[i];
            int yy = u.second + dy[i];
            if (arr[xx][yy] == 1)
                continue;
            q.push({xx, yy});
            no_step[{xx, yy}] = no_step[{u.first, u.second}] + 1;
        }
    }
    if (!isSolvable)
    {
        return -1;
    }
}

void readMatrix(int **arr, int N, int M)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }
}

int main()
{
    int N, M, i_start, j_start;
    scanf("%d %d %d %d", &N, &M, &i_start, &j_start);
    int **arr = new int *[N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = new int[M];
    }
    readMatrix(arr, N, M);
    cout << BFS(arr, i_start-1, j_start-1, N, M);
    delete arr;
    return 0;
}