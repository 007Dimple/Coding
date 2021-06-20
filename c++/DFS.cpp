#include<bits/stdc++.h>
using namespace std;


void addlist(vector<int>adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}


void DFSrec(vector<int> adj[], int s, bool visited[])
{
	visited[s]=true;
	cout<<s<<" ";
	for(int x:adj[s])
	{
		if(visited[x]==false)
		{
			visited[x]=true;
			DFSrec(adj,x,visited);
		}
	}

}


void DFS(vector<int>adj[], int V)
{
	bool visited[V];
	for(int i=0;i<V;i++)
	{
		visited[i]=false;
	}
	for(int i=0;i<V;i++)
	{
		if(visited[i]==false)
		{
			DFSrec(adj,i,visited);
		}
	}
}





int main()
{
	int V=6;
	vector<int>adj[V];
	addlist(adj,0,1);
	addlist(adj,0,2);
	addlist(adj,1,3);
	addlist(adj,2,3);
	addlist(adj,1,4);
	addlist(adj,4,5);
	
  DFS(adj,V);

}