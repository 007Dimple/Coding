#include<bits/stdc++.h>
using namespace std;

void addlist(vector<int>adj[],int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}


void BFS(vector<int>adj[], int s, bool visited[])
{
	queue<int>q;
	visited[s]=true;
	q.push(s);
	while(!q.empty())
	{
		int temp=q.front();
		q.pop();
		cout<<temp<<" ";
		for(int v:adj[temp])
		{
			if(visited[v]==false)
			{
				q.push(v);
				visited[v]=true;
			}
		}
	}
}

void BFSdis(vector<int>adj[],int V)
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
			BFS(adj,i,visited);
		}
	}
}


int main()
{
	int V=6;
	vector<int>adj[V];

	addlist(adj,0,1);
	addlist(adj,0,2);
	addlist(adj,0,5);
	addlist(adj,1,3);
	addlist(adj,2,4);
	addlist(adj,3,5);
	addlist(adj,4,5);
	
	BFSdis(adj, V);

	return 0;
}