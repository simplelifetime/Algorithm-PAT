#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main()
{
    map<int, int> s;
    int m, n, temp, max = 0;
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &temp);
            s[temp]++;
            if (s[temp] > max)
                max = temp;
        }
    }
    cout << temp;
}
