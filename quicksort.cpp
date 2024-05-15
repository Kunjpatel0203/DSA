#include<iostream>
//#include<vector>
using namespace std;
void swap(int& x,int& y)
{
	int temp=x;x=y;y=temp;
}
void dis(int arr[],int n=10)
{
	for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	cout<<endl;
}
void QuickSort(int arr[],int left,int right)//or int* arr
{
	if(left<right)//TAKE CARE!!!!
	{
	
	int pivot=arr[left];
	int i=left+1;
	int j=right;
	while(i<=j)
	{
		while(arr[i]<=pivot)
		{
			i++;
		}
		while(arr[j]>pivot)
		{
			j--;//TAKE CARE!!!!
		}
		if(i<=j)
		{
			swap(arr[i],arr[j]);
			dis(arr);
		}
	}
	swap(arr[j],arr[left]);
	dis(arr);//TAKE CARE!!!!
	
	//Now partition is over & we have got sorted possion of the pivot.
	QuickSort(arr,left,j-1);
	QuickSort(arr,j+1,right);
	}
}

int main()
{
	int arr[]={19,45,12,14,88,64,11,85,25,15};
	int n=10;
	QuickSort(arr,0,n-1);
	dis(arr,n);
	return 0;
}