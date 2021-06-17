#include<bits/stdc++.h>
using namespace std;


void computeLPSarr(int lps[],string pat, int m)
{
	lps[0]=0;
	int len=0;
	int i=1;
	while(i<m)
	{
		if(pat[i]==pat[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else{
			if(len!=0)
			{
				len=lps[len-1];
			}
			else{
				lps[i]=0;
				i++;
			}
		}
	}
}


void kmpPatternSearch(string txt, string pat)
{
	int n=txt.size();
	int m=pat.size();
	int lps[m];
	computeLPSarr(lps,pat,m);
	int i=0,j=0;
	while(i<n)
	{
		if(txt[i]==pat[j])
		{
			i++;
			j++;
		}
		if(j==m)
		{
			cout<<"Pattern found at index "<<i-j<<" "<<endl;
			j=lps[j-1];
		}
		else if(i<n&&txt[i]!=pat[j])
		{
			if(j!=0)
			{
				j=lps[j-1];
			}
			else{
				i++;
			}
		}
	}
}


int main()
{
	string txt="aabaacaadaabaaba";
	string pat="aaba";
	kmpPatternSearch(txt,pat);
	return 0;
}