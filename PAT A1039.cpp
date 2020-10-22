#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
#include<string>
#include <algorithm>
#include<cstring>
#include<map> 
using namespace std;
int getid(char s[])
{
	int res=0;
	for(int i=0;i<3;i++)
	{
		res =(s[0]-'A') + res*26;
	}
	res =  (s[3]-'0') + res*10;
	return res;
}
vector <int> T[26*26*26*10+10];
int main()
{
	int studentnum,coursenum;
	int courseID,snum;
	int id; 
	scanf("%d %d",&studentnum,&coursenum);
	for(int i=0;i<coursenum;i++)
	{
		scanf("%d %d",&courseID,&snum);
		for(int j=0;j<snum;j++)
		{
			char x[5];
			scanf("%s",x);
			id=getid(x);
			T[id].push_back(courseID);
		}
	}
	for(int i=0;i<studentnum;i++)
	{
		char x[5];
		scanf("%s",x);
		id = getid(x);
		sort(T[id].begin(),T[id].end());
		printf("%s ",x);
		printf("%d",T[id].size());
		for(int j=0;j<T[id].size();j++)
		{
			printf(" %d",T[id][j]);
		}
			printf("\n");
	}
}




