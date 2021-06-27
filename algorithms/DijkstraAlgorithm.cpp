// Dijkstra Alogrithm is used to find shortest paths(distance) from source vertex to all other vertices in given graph.
// single source shortest path

#include<iostream>
#include<vector>
#include<climits>
using namespace std;


int findmin_vertex(vector<int>&distance, vector<bool>&visited , int v)
{
	int min_val=INT_MAX,min_vertex;
	for(int i=0;i<v;i++)
	{
		if(visited[i]==false&&distance[i]<min_val)
		{
			min_val=distance[i];
			min_vertex=i;
		}
	}
	return min_vertex;
}


void Dijkstra(int **edges, int v)
{
	vector<int>distance(v,INT_MAX);
	vector<bool>visited(v,false);
	int parent[v];
	distance[0]=0;
	parent[0]=-1;
	for(int count=0;count<v-1;count++)
	{
		int p=findmin_vertex(distance,visited,v);
		visited[p]=true;

		for(int q=0;q<v;q++)
		{
			if(edges[p][q]!=0 &&  visited[q]==false && 
			distance[p]!=INT_MAX && (distance[p]+edges[p][q])<distance[q])
			{
				distance[q]=distance[p]+edges[p][q];
				parent[q]=p;
			}
		}
	}

	for(int i=1;i<v;i++)
	{
		if(parent[i]<i)
		{
			cout<<parent[i]<<" "<<i<<" "<<distance[i]<<endl;
		}
		else{
			cout<<i<<" "<<parent[i]<<" "<<distance[i]<<endl;
		}
	}
}


int main()
{
	int v, e;
	cin>>v>>e;
	int **edges=new int*[v];

	for(int i=0;i<v;i++)
	{
		edges[i]=new int[v];
		for(int j=0;j<v;j++)
		{
			edges[i][j]=0;
		}
	}

	for(int i=0;i<e;i++)
	{
		int f,s,weight;
		cin>>f>>s>>weight;
		edges[f][s]=weight;
		edges[s][f]=weight;
	}

	Dijkstra(edges,v);
	return 0;

}

/* input
6 10
0 1 1
0 2 4
1 2 4
1 4 7
1 3 2
2 4 5
2 3 3
4 3 4
4 5 7
3 5 6
*/

/*
output
0 1 1
0 2 4
1 3 3
3 4 7
3 5 9
*/
