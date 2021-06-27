// Prims Algorithm for minimum spanning tree using distance array , parent array and visited array

#include<iostream>
#include<climits>
#include<vector>
using namespace std;



int findmin_vertex(vector<int>& distance, vector<bool>&visited ,int n)
{
	int min_val=INT_MAX,min_vertex;
	for(int i=0;i<n;i++)
	{
		if(distance[i]<min_val&&visited[i]==false)
		{
			min_val=distance[i];
			min_vertex=i;
		}
	}
	return min_vertex;
}

void prims(int **edges,int n,int e)
{
	vector<int>distance(n,INT_MAX);
	vector<bool>visited(n,false);
	int parent[n];

	distance[0]=0;
	parent[0]=-1;
	for(int i=0;i<n-1;i++)
	{
	 	int u = findmin_vertex(distance,visited,n);
	 	visited[u]=true;

	 	for(int j=0;j<n;j++)
	 	{
	 		if(edges[u][j]!=0&&visited[j]==false&&distance[j]>edges[u][j])
	 		{
	 			distance[j]=edges[u][j];
	 			parent[j]=u;
	 		}
	 	}
	}

	for(int i=1;i<n;i++)
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
	int n,e;
	cin>>n>>e;
	int **edges=new int*[n];

	for(int i=0;i<n;i++)
	{
		edges[i]=new int[n];
		for(int j=0;j<n;j++)
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
	prims(edges,n,e);
	return 0;
}


/* 
//input
6 9
0 1 4
0 2 6
1 2 6
1 3 3
1 4 4
2 3 1
3 4 2
3 5 3
4 5 7
*/

/*
//output
0 1 4
2 3 1
1 3 3
3 4 2
3 5 3
*/