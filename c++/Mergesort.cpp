#include<iostream>
using namespace std;

void merge(int arr[], int low,int mid, int high)
{
	
	int n1=mid-low+1;
	int n2=high-mid;

	int L[n1],M[n2];

	for(int i=0;i<n1;i++)
	{
		L[i]=arr[low+i];
	}
	for(int i=0;i<n2;i++)
	{
		M[i]=arr[mid+1+i];
	}

	int i=0,j=0;
	int k=low;
	while(i<n1&&j<n2)
	{
		if(L[i]<=M[j])
		{
			arr[k]=L[i];
			i++;
			k++;
		}
		else{
			arr[k]=M[j];
			j++;
			k++;
		}
	}

	while(i<n1)
	{
		arr[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k]=M[j];
		j++;
		k++;
	}

}


void mergesort(int arr[],int low, int high)
{
	if(low<high)
	{
		int mid=low+(high-low)/2;

		mergesort(arr,low,mid);
		mergesort(arr,mid+1,high);
		merge(arr, low, mid,high);
	}
	return ;
}

void printarray(int arr[], int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}



int main()
{
	int arr[]={7,9,0,1,5,3,11,2,8};
	int n=sizeof(arr)/sizeof(arr[0]);
	mergesort(arr,0,n-1);
	printarray(arr,n);
	return 0;
}