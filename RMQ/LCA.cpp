//Bismillahir Rahmanir Rahim
/*
    Abdullah Abu Tasneem
    Dept of CSTE, NSTU
*/
//Lowest Common Ancestor using Sparse table

#include<bits/stdc++.h>
using namespace std;
#define mx 100002
#define pb push_back
vector<int>g[mx];
int par[mx];
int level[mx];
int table[mx][22];

void dfs(int from, int u, int depth) //for saving parent of each node
{
	par[u] = from;
	level[u] = depth;
	for(int i=0; i<g[u].size();i++)
	{
		int v = g[u][i];
		if(v==from)continue;
		dfs(u,v,depth+1);
	}
}

int lca_query(int n, int p, int q)
{
	int log;
	if(level[p]<level[q]){
		swap(p,q);
	}
	log=1;
	while(1){
		int next = log+1;
		if((1<<next)>level[p])break;
		log++;
	}
	for(int i=log; i>=0;i--)
	{
		if(level[p]-(1<<i)>=level[q]){
			p = table[p][i];
		}
	}

	if(p==q)return p;
	for(int i=log; i>=0;i--)
	{
		if(table[p][i]!=-1 and table[p][i]!=table[q][i]){
			p = table[p][i];
			q = table[q][i];
		}
	}
	return par[p];
}

void lca_preprocess(int n)
{
	memset(table,-1,sizeof(table));
	for(int i=0; i<n; i++)
	{
		table[i][0] = par[i];
	}
	for(int j=1; (1<<j)<n; j++)
	{
		for(int i=0;i<n;i++)
		{
			if(table[i][j-1]!=-1)
			{
				table[i][j] = table[table[i][j-1]][j-1];
			}
		}
	}
}

int main()
{
	// #ifndef ONLINE_JUDGE
  //        freopen("input.txt","r",stdin);
  //        freopen("output.txt","w",stdout);
  // #endif
	g[0].pb(1);
	g[0].pb(2);
	g[2].pb(3);
	g[2].pb(4);
	dfs(0, 0, 0);
	lca_preprocess(5);
	printf( "%d\n", lca_query(5,3,4) );
	return 0;
}
