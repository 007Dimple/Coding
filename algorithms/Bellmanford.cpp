// Bellmanford algo is used to detect the -ve edge weight cycle from a directed weighted graph, it can have -ve edges only.
// these things make it different from dijkstra algo
// it can detect the -ve edge weight cycle
//for a undirected weight graph even if one edge is negative then it would surely have -ve ege weight cycle 

#include<iostream>
#include<climits>
#include<vector>
using namespace std;

class Edges{
public:
	int src;
	int dest;
	int weight;

};


void Bellmanford(vector<Edges>&edge,int v, int e)
{
	vector<int>distance(v,INT_MAX);
	int parent[v];
	distance[0]=0;
	parent[0]=-1;
	bool updated;
	for(int count=0;count<v-1;count++)
	{
		updated=false;
		for(int i=0;i<e;i++)
		{
			int u=edge[i].src;
			int v=edge[i].dest;
			int wt=edge[i].weight;
			if(distance[u]!=INT_MAX&& distance[u]+wt<distance[v])
			{
				distance[v]=distance[u]+wt;
				parent[v]=u;
				updated=true;
			}

		}
		if(updated==false)
		{
			break;
		}
	}

	for(int i=0;i<e && updated==true;i++)
	{
		int u=edge[i].src;
		int v=edge[i].dest;
		int wt=edge[i].weight;
		if(distance[u]!=INT_MAX && distance[u]+wt<distance[v])
		{
			cout<<"graph contains negative edge cycle"<<endl;
			return;
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
	int v,e;
	cin>>v>>e;
	vector<Edges>edge(e);

	for(int i=0;i<e;i++)
	{	int src,dest,wt;
		cin>>src>>dest>>wt;
		edge[i].src=src;
		edge[i].dest=dest;
		edge[i].weight=wt;
	}
	Bellmanford(edge,v,e);
	return 0;

}

/*
input for normal directed graph that contain -ve edge weight only
5 10
0 1 6
0 2 7
1 4 5
1 2 8
2 3 9
2 4 -3
1 3 -4
4 1 -2   
3 0 3
3 4 7

//output
1 4 2
0 2 7
1 3 -2
2 4 4
*/


/*
input for a directed graph which contain -ve edge weight cycle
3 3
0 1 2
1 2 3
2 0 -7

//output
graph contains negative edge cycle

*/