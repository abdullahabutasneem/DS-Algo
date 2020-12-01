//Bismillahir Rahmanir Rahim
/*
	Abdullah Abu Tasneem
	Dept of CSTE, NSTU
*/
#include<bits/stdc++.h>
using namespace std;
#define N 10000
int a[N];
int table[24][N];

void preprocess(int n)
{
	for(int i=0;i<n;i++){
		table[0][i] = i;		//building base
	}
	for(int j=1;(1<<j)<n;j++)
	{
		for(int i=0; i+(1<<j)<=n; i++)
		{
			int x = table[j-1][i];
			int y = table[j-1][i+(1<<(j-1))];
			if(a[x]<=a[y]){
				table[j][i] = x;
			}
			else table[j][i]=y;
		}
	}
}

int query(int x, int y)
{
	int len = y-x;
	int k = log2(len);
	int p=table[k][x];
	int q=table[k][y-(1<<k)+1];
	if(a[p]<=a[q])return p;
	else return q;
}

int main()
{
	int n;
	cin>>n; //array size
	for(int i=0;i<n;i++)cin>>a[i];
	preprocess(n);
	int q;
	cin>>q; //number of queries
	while(q--)
	{
		int x,y;
		cin>>x>>y; //0-indexed
		int id=query(x,y);
		cout<<a[id]<<endl;
	}
}
