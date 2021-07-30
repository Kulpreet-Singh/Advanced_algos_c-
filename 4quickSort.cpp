#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int partition(int* a, int p, int r){
	int x = r;//pivot last element
	int i = p-1;
	int j = p;
	for(j=p;j<r;j++){
		if(a[j] < a[x]){
			swap(a[i+1],a[j]);
			i++;
		}
	}
	swap(a[i+1], a[x]);
	return (i+1);
}

void quickSort(int *a, int p, int r){
	if(p<r){
		int q = partition(a,p,r);
		quickSort(a,p,q-1);
		quickSort(a,q+1,r);
	}
}

int main(){
	int a[] = {8,3,6,2,7,5,2,9};
	int n = 8;
	quickSort(a,0,n-1);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}	
	return 0;
}
