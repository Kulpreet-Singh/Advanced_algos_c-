#include<bits/stdc++.h>
using namespace std;

struct indices{
	int first;
	int last;
};

void insertionSort(int *a, int n){
	for(int i=1;i<n;i++){
		int b = a[i];
		int j = i-1;
		while(j>-1 && a[j]>b){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = b;
	}
}

void recInsertionSort(int *a,int n, int i){
	if(i<n){
		int b = a[i];
		int j = i-1;
		while(j>-1 && a[j]>b){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = b;
		recInsertionSort(a,n,i+1);
	}
}

int findMinIndex(int *a, int n, int i){
	int min = INT_MAX;
	int in = i;
	while(i<n){
		if(a[i]<min){
			min = a[i];
			in = i;
		}
		i++;
	}
	return in;
}

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void selectionSort(int* a, int n){
	for(int i=0;i<n;i++){
		int in = findMinIndex(a,n,i);
		swap(a[i],a[in]);
	}
}

indices findWindow(int *a, int n){
	indices ans;
	int * b = new int[n];
	for(int i=0;i<n;i++){
		b[i] = a[i];
	}
	insertionSort(b,n);
	ans.first = 0;
	ans.last = n-1;
	while(ans.first < n && (a[ans.first] == b[ans.first])){
		ans.first ++;
	}
	while(ans.last > ans.first && (a[ans.last] == b[ans.last])){
		ans.last --;
	}
	
	return ans;
}

int main(){
	int a[] = {2,6,3,8,4,1,5,3};
	int n = 8;
	selectionSort(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	int x[] = {1,2,3,7,5,6,4,8};
	indices ans = findWindow(x,8);
	cout<<ans.first<<" "<<ans.last<<endl;
}

