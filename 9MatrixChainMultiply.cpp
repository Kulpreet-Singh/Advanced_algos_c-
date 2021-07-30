#include<bits/stdc++.h>
using namespace std;

void printOrder(int** s, int i, int j){
	if(i==j){
		cout<<" A"<<i<<" ";
	}
	else{
		cout<<"(";
		printOrder(s,i,s[i][j]);
		printOrder(s,s[i][j]+1,j);
		cout<<")";
	}
}

int matrixChainMultiplication(int arr[], int n){
	
	int m[n][n];
	int** s = new int*[n];
	for(int i=0;i<n;i++){
		s[i] = new int[n];
		for(int j=0;j<n;j++){
			m[i][j] = 0;
			s[i][j] = 0;
		}
	}
	for(int l=1;l<n;l++){
		for(int i=0;i<n-l;i++){
			int j = i+l;
			m[i][j] = INT_MAX;
			int y;
			for(int k=i;k<j;k++){
				y = m[i][k] + m[k+1][j] + arr[i]*arr[k+1]*arr[j+1];
				if(y<m[i][j]){
					m[i][j] = y;
					s[i][j] = k;
				}
			}
		}
	}

	printOrder(s, 0,n-1);
	cout<<endl;
	for(int i=0;i<n;i++){
		delete[] s[i];
	}
	delete[] s;
	return m[0][n-1];
}

int main(){
	int n;
	cin>>n;
	int arr[n+1];
	for(int i=0;i<n+1;i++){
		cin>>arr[i];
	}
	int ans = matrixChainMultiplication(arr, n);
	cout<<"Minimum cost of matrix chain multiplication is: "<<ans;
}
