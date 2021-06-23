#include<iostream>
using namespace std;


void dectobinary(int n)
{
	int i=0;
	int binarynumber[32];
	while(n>0)
	{
			binarynumber[i]=n%2;
			n=n/2;
			i++;
	}
	for(int j=i-1;j>=0;j--)
	{
		cout<<binarynumber[j];
	}
	
}

int main()
{
	int n;
	cin>>n;
	dectobinary(n);
	return 0;
}