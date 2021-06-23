#include<bits/stdc++.h>
using namespace std;
#define d 256


void rabinKarp(string txt, string pat)
{
	int n=txt.size();
	int m=pat.size();
	int h=1;
	int p=0,t=0;
	int q= 13;  //any prime number

	//calculate h value i.e. pow(d,m-1);
	for(int i=0;i<m-1;i++)
	{
		h=(h*d)%q;
	}
	//calculate hash values for first window of pat and txt
	for(int i=0;i<m;i++)
	{
		p=(p*d +pat[i])%q;
		t=(t*d +txt[i])%q;
	}
	int i,j;
	for(i=0;i<=n-m;i++)
	{
		if(p==t)
		{
			for(j=0;j<m;j++)
			{
				if(pat[j]!=txt[i+j])
				{
					break;
				}
			}
			if(j==m)
			{
				cout<<"pattern found at index "<<i<<endl;
			}
		}
		if(i<n-m){
			t=( (t- txt[i]*h)*d + txt[i+m] )%q;

			if(t<0)
			{
				t=t+q;
			}
		}
		
	}
}














int main()
{
	string txt="aabaacaadaabaaba";
	string pat="aaba";
	rabinKarp(txt,pat);
	return 0;

}