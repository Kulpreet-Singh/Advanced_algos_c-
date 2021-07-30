#include<bits/stdc++.h>
using namespace std;

void merge(int *a, int p, int q, int r){
	int n1 = q-p+1;
	int n2 = r-q;
	int *a1 = new int[n1];
	int *a2 = new int[n2];
	
	int i=0,j=0;
	for(i=0;i<n1;i++){
		a1[i] = a[p+i];
	}
	for(j=0;j<n2;j++){
		a2[j] = a[q+j+1];
	}
	i=0;j=0;
	int k = p;
	while(i<n1 && j<n2){
		if(a1[i]<=a2[j]){
			a[k] = a1[i];
			k++;
			i++;
		}
		else{
			a[k] = a2[j];
			k++;
			j++;
		}
	}
	while(i<n1){
		a[k] = a1[i];
		k++;i++;
	}
	while(j<n2){
		a[k] = a2[j];
		k++;j++;
	}
	
	delete[] a1;
	delete[] a2;
}

void mergeSort(int *a, int p, int r){
	if(p<r){
		int q = (p+r)/2;
		mergeSort(a,p,q);
		mergeSort(a,q+1,r);
		merge(a, p, q, r);
	}
}

int main(){
	int a[] = {7,2,8,9,3,21};
	int n = 6;
	mergeSort(a,0,n-1);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}
