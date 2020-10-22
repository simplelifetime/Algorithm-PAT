#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int dx[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {1, -1, 0, 0, 0, 0};
bool chose[1290][130][65] = {0};
int stroke[1290][130][65];
int M, N, L, T;
typedef struct A
{
    int x;
    int y;
    int z;
    A() {}
    A(int _x, int _y, int _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }
} cod;
int judge(int x, int y, int z)
{
    if (x < 0 || x >= M || y < 0 || y >= N || z < 0 || z >= L)
        return 0;
    if (chose[x][y][z] == true || stroke[x][y][z] == 0)
        return 0;
    return 1;
}
int bfs(cod source)
{
    int sum = 0;
    queue<cod> q;
    q.push(source);
    chose[source.x][source.y][source.z] = 1;
    sum++;
    int xt, yt, zt;
    while (!q.empty())
    {
        cod tmp = q.front();
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            xt = tmp.x + dx[i];
            yt = tmp.y + dy[i];
            zt = tmp.z + dz[i];
            if (judge(xt, yt, zt))
            {
                q.push(cod(xt, yt, zt));
                chose[xt][yt][zt] = 1;
                sum++;
            }
        }
    }
    return sum;
}
int main()
{
    cin >> M >> N >> L >> T;
    int sum, S = 0;
    queue<cod> q;
    for (int i = 0; i < L; i++)
        for (int j = 0; j < M; j++)
            for (int k = 0; k < N; k++)
            {
                scanf("%d", &stroke[j][k][i]);
            }
    for (int i = 0; i < L; i++)
        for (int j = 0; j < M; j++)
            for (int k = 0; k < N; k++)
            {
                if (stroke[j][k][i] == 1 && chose[j][k][i] == 0)
                {
                    sum = bfs(cod(j, k, i));
                    if (sum >= T)
                        S += sum;
                }
            }
    printf("%d", S);
}
