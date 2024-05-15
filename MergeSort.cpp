#include<iostream>
using namespace std;

void Merge(int a[],int l,int m,int r)
{
	int result[r-l+1];
	int i=l,j=m+1,k=0;
	while(i<=m && j<=r)
	{
		if(a[i]<a[j])
			result[k++]=a[i++];
		else
			result[k++]=a[j++];	
	}
	while(i<=m)
		result[k++]=a[i++];
	
	while(j<=r)
		result[k++]=a[j++];
	
	for(int i=l;i<=r;i++)           
		a[i]=result[i-l];
}


void MergeSort(int a[],int l,int r)
{
	if(l<r)
	{
		int mid=(l+r)/2;
		//cout<<"l="<<l<<" r="<<r<<" mid="<<mid<<endl;
		MergeSort(a,l,mid);
		MergeSort(a,mid+1,r);
		Merge(a,l,mid,r);	
	}
}

int main()
{
	int size=8;
	int a[]={42,57,68,77,7,15,29,35};
	MergeSort(a,0,size-1);
	for(int i=0;i<size;i++)
	cout<<a[i]<<" "; 
	cout<<endl;
}