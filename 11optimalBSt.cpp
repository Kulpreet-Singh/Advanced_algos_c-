#include<bits/stdc++.h>
using namespace std;

void tracer(int **root, int i, int j, int n){
	if(i>j){
		cout<<"d"<<j;
		return;
	}
	cout<<root[i][j]<<" (";
	tracer(root, i, root[i][j]-1,n);
	cout<<", ";
	tracer(root, root[i][j]+1, j,n);
	cout<<")";
}

float optimalBST(float* p, float* q, int n){
	float** e = new float*[n+2];
	float** w = new float*[n+2];
	int** root = new int*[n+2];
	
	for(int i=1;i<n+2;i++){
		e[i] = new float[n+1];
		w[i] = new float[n+1];
		root[i] = new int[n+1];
		for(int j=0;j<n+1;j++){
			root[i][j] = -1;
			if(i-1==j){
				e[i][j] = q[i-1];
				w[i][j] = q[i-1];
			}
			else{
				e[i][j] = INT_MAX;
				w[i][j] = INT_MAX;
			}
		}
	}
	

	for(int l=1;l<=n;l++){
		for(int i=1;i<=n-l+1;i++){
			int j = i+l-1;
			w[i][j] = w[i][j-1] + p[j] + q[j];
			for(int r = i;r<=j;r++){
				float t = e[i][r-1] + e[r+1][j] + w[i][j];
				if(t<e[i][j]){
					e[i][j] = t;
					root[i][j] = r;
				}
			}
		}
	}
	
//	for(int i=1;i<=n+1;i++){
//		for(int j=0;j<=n;j++){
//			cout<<w[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	cout<<endl;
//	
//	for(int i=1;i<=n+1;i++){
//		for(int j=0;j<=n;j++){
//			cout<<e[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	cout<<endl;
//	
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<root[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	
	tracer(root, 1, n, n);
	return e[1][n];
}


int main(){
	int n = 5;
	float p[] = {0, 0.15, 0.10, 0.05, 0.10, 0.20};
	float q[] = {0.05, 0.10, 0.05, 0.05, 0.05, 0.10};
	float ans = optimalBST(p,q,n);
	cout<<"\n"<<ans<<endl;
	return 0;
}
