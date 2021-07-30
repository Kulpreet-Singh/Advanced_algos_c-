#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void heapify(int *a, int n, int i){
	int largest = i;
	int l = 2*i+1;
	int r = 2*i+2;
	
	if(l<n && a[l]>a[largest]){
		largest = l;
	}
	if(r<n && a[r] > a[largest]){
		largest = r;
	}
	if(largest != i){
		swap(a[i],a[largest]);
		heapify(a,n,largest);
	}
}

void buildMaxHeap(int *a, int n){
	//parent elements in a tree are always one less than the leaf nodes
	for(int i=n/2-1;i>=0;i--){
		heapify(a, n, i);
	}
}

void heapSort(int *a, int n){
	buildMaxHeap(a, n);
//	for(int i=0;i<n;i++){
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
	for(int i = n-1;i>0;i--){
		swap(a[0], a[i]);
		heapify(a,i,0);
//		for(int i=0;i<n;i++){
//			cout<<a[i]<<" ";
//		}
//		cout<<endl;
	}
}

int main(){
	int a[] = {8,3,4,0,2,6};
	int n = 6;
	heapSort(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
