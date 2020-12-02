//Bismillahir Rahmanir Rahim
/*
    Abdullah Abu Tasneem
    Dept of CSTE, NSTU
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 503;
const int LOG = 9;
int a[N][N];
int table[N][LOG][N];

void preprocess(int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++){
			table[i][0][j] = a[i][j];
		}
	}

	for(int k=1;k<=n;k++)
	{
		for(int j=1;j<LOG;j++)
		{
			for(int i=1; i+(1<<j)-1<=n; i++)
			{
				int x = table[k][j-1][i];
				int y = table[k][j-1][i+(1<<(j-1))];
				table[k][j][i] = max(x,y);
			}
		}
	}
}

int query(int i, int x, int y)
{
	int len = y-x+1;
	int k = log2(len);
	int p=table[i][k][x];
	int q=table[i][k][y-(1<<k)+1];
	return max(p,q);
}

int main()
{
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
	int t;
	scanf("%d",&t);
	for(int tc=1;tc<=t;tc++)
	{
		int n,q;
		scanf("%d%d",&n,&q);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>a[i][j];
			}
		}
		preprocess(n);
		printf("Case %d:\n",tc);
		while(q--)
		{
			int x,y,s;
			scanf("%d%d%d",&x,&y,&s);
			int a=x+s-1;
			int b=y+s-1;
			int ans=0;
			for(int i=x;i<=a;i++)
			{
				ans = max(ans,query(i,y,b));
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
