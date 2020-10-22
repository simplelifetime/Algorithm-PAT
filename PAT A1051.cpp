#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main()
{
    stack<int> a;
    int m, n, l;
    cin >> m >> n >> l;
    int d[m][n];
    int flag = 0;
    for (int i = 0; i < l; i++)
        for (int j = 0; j < n; j++)
            cin >> d[i][j];
    for (int i = 0; i < l; i++)
    {
        flag = 0;
        int st = 1;
        int j = 0;
        while (!a.empty())
            a.pop();
        while (st <= n)
        {
            a.push(st);
            // printf("+%d ", st);
            st++;
            if (a.top() > d[i][j] || a.size() > m)
            {
                flag = 1;
                break;
            }
            while (a.top() == d[i][j])
            {
                // printf("-%d ", a.top());
                a.pop();
                j++;
                if (a.empty())
                    break;
            }
            if (j == n)
                break;
        }
        if (!a.empty())
            flag = 1;
        if (flag == 0)
            cout << "YES" << endl;
        else
        {
            cout << "NO" << endl;
        }
    }
}
