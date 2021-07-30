#include<bits/stdc++.h>
#include<fstream>
#include<omp.h>
using namespace std;

int main(){
	ifstream temp;
	temp.open("Database.txt");
	
	const int m = 2000;
	const int n = 2000;
	const int p = 6000;
	
	int** a = new int*[m];
	#pragma omp parallel for
	for(int i=0;i<m;i++){
		a[i] = new int[n];
		for(int j=0;j<n;j++){
			temp >> a[i][j];
		}
	}
	int** b = new int*[n];
	#pragma omp parallel for
	for(int i=0;i<n;i++){
		b[i] = new int[p];
		for(int j=0;j<p;j++){
			temp >> b[i][j];
		}
	}
	
	int** c = new int*[m];
	#pragma omp parallel for
	for(int i=0;i<m;i++){
		c[i] = new int[p];
		for(int j=0;j<p;j++){
			c[i][j] = 0;
		}
	}
	#pragma omp parallel for
	for(int i=0;i<m;i++){
		for(int j=0;j<p;j++){
			for(int k=0;k<n;k++){
				c[i][j] += a[i][k] * b[k][j];
			}
			cout<<c[i][j]<<" ";
		}
		cout<<endl;
	}
	
	temp.close();
	
	return 0;
}
