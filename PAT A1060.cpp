#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n;
string stringdeal(string s, int *len)
{
    string res;
    while (s[0] == '0' && s.size() > 0)
    {
        s.erase(s.begin());
    }
    int i = 0;
    if (s[0] != '.')
    {
        while (i < s.size())
        {
            if (s[i] != '.')
            {
                i++;
                (*len)++;
            }
            else
            {
                break;
            }     
        }
        if (i < s.size())
            s.erase(s.begin() + i);
    }
    else
    {
        s.erase(s.begin());
        while (s[0] == '0' && s.size() > 0)
        {
            s.erase(s.begin());
            (*len)--;
        }
    }
    if(s.size()==0)
    {
        *len = 0;
    }
    int num = 0;
    i = 0;
    while (num < n)
    {
        if (i < s.size())
            res += s[i++];
        else
            res += '0';
        num++;
    }
    return res;
}
int main()
{
	printf("%d",-4%8);
    scanf("%d", &n);
    string s1, s2;
    cin >> s1 >> s2;
    int len1 = 0, len2 = 0;
    string r1, r2;
    r1 = stringdeal(s1, &len1);
    r2 = stringdeal(s2, &len2);
    if(r1==r2&&len1==len2)
        printf("YES 0.%s*10^%d", r1.c_str(), len1);
    else
    {
        printf("NO 0.%s*10^%d 0.%s*10^%d", r1.c_str(), len1, r2.c_str(), len2);
    }
    
}
