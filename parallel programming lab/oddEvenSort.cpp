#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void oddEvenSort(int *a, int n){
	for(int i=0;i<n;i++){
		if((i%2)==0){
			for(int j=0;j<=n/2-1;j++){
				if(a[(2*j)]>a[(2*j)+1]){
					swap(a[(2*j)],a[(2*j)+1]);
				}
			}
		}
		else{
			for(int j=0;j<n/2-1;j++){
				if(a[(2*j)+1]>a[(2*j)+2]){
					swap(a[(2*j)+1],a[(2*j)+2]);
				}
			}
		}
	}
}

int main(){
	int a[10000];
	ifstream fin;
	
	fin.open("Database.txt");
	
	for(int i=0;i<10000;i++){
		fin>>a[i];
	}
//	int a[] = {8,3,6,2,7,5,2,9};
	oddEvenSort(a,10000);
	for(int i=0;i<10000;i++){
		cout<<a[i]<<" ";
	}	
	fin.close();
	return 0;
}
