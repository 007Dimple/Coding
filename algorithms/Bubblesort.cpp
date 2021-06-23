#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void bubblesort(int arr[], int n)
{
	for(int i=0;i<n-1;i++)
	{

		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
			}
		}
	}
}


void printarray(int arr[], int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}


int main(){
	int arr[]={4,7,3,1,9,8,0,13};
	int n=sizeof(arr)/sizeof(arr[0]);
	bubblesort(arr,n);
	printarray(arr,n);
	return 0;

}