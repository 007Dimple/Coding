#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<vector<int>>interval;
	int n;
	int a,b;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		vector<int>val(2);
		cout<<val.size()<<"@";
		val.push_back(a);
		cout<<val.size()<<"#";
		val.push_back(b);
		cout<<val.size()<<"$";
		cout<<endl;
		interval.push_back(val)	;
		
		
	}
	// for(int i=0;i<n;i++)
	// {
	//  cout<<interval[i][0]<<","<<interval[i][1]<<" ";
	// }
return 0;
}