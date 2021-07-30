#include<bits/stdc++.h>
using namespace std;

void print(vector< vector<int> > s, int i, int j, string a){
	if(i==0 || j==0){
		return;
	}
	if(s[i][j] == 1){
		print(s,i-1,j-1,a);
		cout<<a[i-1];
	}
	else{
		if(s[i][j] == 2){
			print(s,i-1,j,a);
		}
		else{
			print(s,i,j-1,a);
		}
	}
}

int lcs(string a, string b){
	int n = a.length();
	int m = b.length();
	vector< vector<int> > c(n+1,vector<int>(m+1,0));
	vector< vector<int> > s(n+1,vector<int>(m+1,0));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i-1]==b[j-1]){
				c[i][j] = c[i-1][j-1] +1;
				s[i][j] = 1;
			}
			else{
				if(c[i-1][j]>=c[i][j-1]){
					c[i][j] = c[i-1][j];
					s[i][j] = 2;
				}
				else{
					c[i][j] = c[i][j-1];
					s[i][j] = 0;
				}
			}
		}
	}
	print(s,n,m,a);
	cout<<endl;
	return c[n][m];
}

int main(){
	string a,b;
	cin>>a>>b;
	int ans = lcs(a,b);
	cout<<ans<<endl;
	return 0;
}
