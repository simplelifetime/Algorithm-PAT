#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

string sbit[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string dbit[12] = {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
string n2s[169];
int main()
{
    map<string, int> s2n;
    int n;
    for (int i = 0; i < 169; i++)
    {
        if (i > 12)
        {
            if (!(i % 13))
            {
                n2s[i] += dbit[i / 13 - 1];
                continue;
            }
            else
            {
                n2s[i] += dbit[i / 13 - 1];
                n2s[i] += " ";
                n2s[i] += sbit[i % 13];
            }
        }
        else
        {
            n2s[i] += sbit[i % 13];
        }
    }
    for (int i = 0; i < 13; i++)
    {
        s2n[sbit[i]] = i;
        if (i != 12)
            s2n[dbit[i]] = (i + 1) * 13;
    }
    scanf("%d%*c", &n);
    for (int i = 0; i < n; i++)
    {
        string temp;
        getline(cin, temp);
        if (temp[0] >= '0' && temp[0] <= '9')
        {
            int n = 0;
            for (int i = 0; i < temp.size(); i++)
            {
                n = n * 10 + temp[i] - '0';
            }
            cout << n2s[n] << endl;
        }
        else
        {
            if (temp.size() > 3)
                cout << s2n[temp.substr(0, 3)]  + s2n[temp.substr(4, 3)] << endl;
            else
            {
                cout << s2n[temp] << endl;
            }
        }
    }
}
