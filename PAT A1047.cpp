#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
#include<string>
#include <algorithm>
#include<cstring>
using namespace std;
int getid(char s[])
{
	int res=0;
	for(int i=0;i<3;i++)
	{
		res =(s[i]-'A') + res*26;
	}
	res =  (s[3]-'0') + res*10;
	return res;
}
void printnum(int id)
{
	int k=id;
	int t1=id%10+'0';
	id=id/10;
	int t2=id%26+'A';
	id=id/26;
	int t3=id%26+'A';
	id=id/26;
	int t4=id%26+'A';
	printf("%c%c%c%c\n",t4,t3,t2,t1);
}
vector <int> T[40010];
int main()
{
	int m,n;
	int t,temp;
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++)
	{
		char x[5];
		memset(x,sizeof(x),0);
		scanf("%s",x);
		int p=getid(x);
		scanf("%d",&t);
		for(int j=0;j<t;j++)
		{
			scanf("%d",&temp);
			T[temp].push_back(p);
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d %d\n",i,T[i].size());
		sort(T[i].begin(),T[i].end());
		for(int j=0;j<T[i].size();j++)
			printnum(T[i][j]);
	}

}
