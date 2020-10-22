#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
vector<int> temp;
vector<int> res;
vector<int> tab; //打表
int tempsum = 0;
int n, k, p, maxnum;
int flag = 0;
void dfs(int chosen, int kn, int sumc, int sump)
{
    if (kn == k && sump == n && sumc > tempsum)
    {
        tempsum = sumc;
        res = temp;
        flag = 1;
        return;
    }
    if (chosen == maxnum+1 || kn == k || sump >= n)
        return;
    temp.push_back(chosen);
    dfs(chosen, kn + 1, sumc + chosen, sump + tab[chosen]);
    temp.pop_back();
    dfs(chosen + 1, kn, sumc, sump);
    return;
}
bool cmp(int a,int b )
{
    return a > b;
}
int main()
{
    cin >> n >> k >> p;
    int tmp = 0;
    int done = 0;
    for (int i = 0; tmp < n; i++)
    {
        tmp = pow(i, p);
        tab.push_back(tmp);
    }
    maxnum = tab.size();
    dfs(1, 0, 0, 0);
    if (flag == 1)
    {
        sort(res.begin(), res.end(), cmp);
        printf("%d =", n);
        for (int i = 0; i < res.size(); i++)
        {
            printf(" %d^%d", res[i], p);
            if (i != res.size() - 1)
                printf(" +");
        }
    }
    else
    {
        cout << "Impossible";
    }
}
