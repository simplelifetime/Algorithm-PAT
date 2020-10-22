#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
#include<string>
#include <algorithm>
#include<cstring>
#include<set> 
using namespace std;

int main()
{
	int num;
	scanf("%d",&num);
	set <int> T[num];
	int n1,n2,n3;
	for(int i=0;i<num;i++)
	{
		scanf("%d",&n1);
		for(int j=0;j<n1;j++)
		{
			scanf("%d",&n2);
			T[i].insert(n2);
		}
	}
	cin>>num;
	int h,t;
	set<int>::iterator it;
	for(int i=0;i<num;i++)
	{
		int snum=0,dnum=0;
		scanf("%d%d",&h,&t);
		h--;
		t--;
		for(it=T[h].begin();it!=T[h].end();it++)
		{
			if(T[t].find(*it)!=T[t].end())
				snum++;
			else
				dnum++;
		}
		for(it=T[t].begin();it!=T[t].end();it++)
		{
			if(T[h].find(*it)==T[h].end())
				dnum++;
		}
		float res=snum*100.0/(dnum+snum);
		printf("%.1f%\n",res);
	}
}
