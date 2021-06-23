#include<iostream>
using namespace std;



void swap(int *a, int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}


void selectionsort(int arr[], int n)
{
	int min_index;

	for(int i=0;i<n-1;i++)
	{
		min_index=i;

		for(int j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min_index])
			{
				min_index=j;
			}
		}
		swap(&arr[min_index],&arr[i]);

	}
}

void printarray(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int arr[]={5,8,1,7,6,2,9,19,3};
	int n=sizeof(arr)/sizeof(arr[0]);
	selectionsort(arr,n);
	printarray(arr,n);
	return 0;
}