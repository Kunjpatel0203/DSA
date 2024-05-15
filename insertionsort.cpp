#include<iostream>
using namespace std;
void dis(int arr[],int n=8)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void insertionsort(int arr[],int n)
{
	for(int i=1;i<n;i++)
	{
		int key=arr[i];
		int j=i-1;
		while(arr[j]>key && j>=0)
		{
			arr[j+1]=arr[j];
			j--;
			dis(arr);
		}
		arr[j+1]=key;
		//dis(arr);
	}
}

int main()
{
	int arr[]={4,3,2,10,12,1,5,6};
	insertionsort(arr,8);
	for(int i=0;i<8;i++)
	{
		cout<<arr[i]<<" ";
	}
}