// Floydwarshall is All Pairs Shortest Path problem 
//which is used to find the shortest path between every pair of vertices in given weighted edge directed graph.

#include<iostream>
#include<climits>
#include<vector>
using namespace std;

#define v 4
void floydwarshall(int graph[v][v])
{
	int distance[v][v];

	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			distance[i][j]=graph[i][j];
		}
	}

	for(int k=0;k<v;k++)
	{
		for(int i=0;i<v;i++)
		{
			for(int j=0;j<v;j++)
			{
				if(distance[i][j]>(distance[i][k]+distance[k][j]) && distance[i][k]!=INT_MAX && distance[k][j]!=INT_MAX)
				{
					distance[i][j]=distance[i][k] + distance[k][j];
				}
			}
		}
	}

	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			if(distance[i][j]==INT_MAX)
			{
				cout<<"INT_MAX"<<"   ";
			}
			else{
				cout<<distance[i][j]<<"         ";
			}
		}
		cout<<endl;
	}
}


int main()
{
	int graph[v][v]={ {0,5,INT_MAX,10},
				 {INT_MAX,0,3,INT_MAX},
				 {INT_MAX,INT_MAX,0,1},
				 {INT_MAX,INT_MAX,INT_MAX,0}
				};
	floydwarshall(graph);
	return 0;
}