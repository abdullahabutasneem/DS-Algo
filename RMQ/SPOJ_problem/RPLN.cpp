#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 100025;
const int LOG = 20;
int a[N];
int table[LOG][N];
 
void preprocess(int n)
{
	for(int i=1;i<=n;i++){
		table[0][i] = a[i];		//building base
	}
	for(int j=1;j<LOG;j++)
	{
		for(int i=1; i+(1<<j)-1<=n; i++)
		{
			int x = table[j-1][i];
			int y = table[j-1][i+(1<<(j-1))];
			table[j][i] = min(x,y);
		}
	}
}
 
int query(int x, int y)
{
	int len = y-x+1;
	int k = log2(len);
	int p=table[k][x];
	int q=table[k][y-(1<<k)+1];
	return min(p,q);
}
 
int main()
{
	int t;
	scanf("%d",&t);
	for(int tc=1;tc<=t;tc++)
	{
		int n,q;
		scanf("%d%d",&n,&q);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		preprocess(n);
		printf("Scenario #%d:\n",tc);
		while(q--)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			int ans=query(x,y);
			printf("%d\n",ans);
		}
	}
	return 0;
}
