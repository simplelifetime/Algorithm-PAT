#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
typedef struct a
{
    int w;
    int order;
    int oriorder;
    int rank;
    a()
    {
        rank = 0;
    }
} mouse;
bool cmp1(mouse A,mouse B)
{
    return A.order < B.order;
}
int main()
{
    int m, n;
    cin >> m >> n;
    mouse mou[m];
    for (int i = 0; i < m; i++)
        cin >> mou[i].w;
    for (int i = 0; i < m; i++)
        cin >> mou[i].order;
    for (int i = 0; i < m; i++)
        mou[i].oriorder = i;
    sort(mou, mou + m, cmp1);
    for (int i = 0; i < m;i++)
        cout << mou[i].w << " " << mou[i].order << " " << mou[i].oriorder << endl;
}
