// Krushkal's Algorithm
// for connected undirected weighted graph....for finding Minimum Spanning Tree


#include<iostream>
#include<algorithm>
using namespace std;


class Edge{
	public:
		int src;
		int dest;
		int weight;
};


bool comp(Edge a, Edge b)
{
	return a.weight<b.weight;
}
int findparent(int v, int *parent)
{
	if(parent[v]==v)
	{
		return v;
	}
	return findparent(parent[v], parent);
}

void Krushkal(Edge *edge, int V , int E)
{
		// sort the edge array in increasing order of their weight
		sort(edge,edge + E,comp);
	Edge *output=new Edge[V-1];

	int *parent=new int[V];
	for(int i=0;i<V;i++)
	{
		parent[i]=i;
	}

	int count=0;                                      // to count the no. of edges of mst
	int i=0;                                           // to iterate through all edges
	while(count!=(V-1))
	{
		Edge currEdge= edge[i];
		int sourceparent= findparent(currEdge.src,parent);
		int destparent= findparent(currEdge.dest,parent);

		if(sourceparent != destparent)
		{
			output[count]=currEdge;
			count++;
			parent[sourceparent]= destparent;
		}
		i++;
	}

	for(int i=0;i<V-1;i++)
	{
		if(output[i].src<output[i].dest)
		{
			cout<<output[i].src<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
		}
		else{
			cout<<output[i].dest<<" "<<output[i].src<<" "<<output[i].weight<<endl;
		}
	}

}


int main()
{
	int V,E;
	cin>>V>>E;
	int s,d,w;
	Edge *edge= new Edge[E];
	for(int i=0;i<E;i++)
	{
		cin>>s>>d>>w;
		edge[i].src=s;
		edge[i].dest=d;
		edge[i].weight=w;
	}
	Krushkal(edge,V,E);
	return 0;
}


/* input
6 11 // V,E
// edges
0 1 2
0 3 3
1 3 1
2 3 6
0 2 4
4 5 5
2 4 9
3 5 7
2 5 10
2 1 8
3 4 11
*/

/*
//output
1 3 1
0 1 2
0 2 4
4 5 5
3 5 7
*/