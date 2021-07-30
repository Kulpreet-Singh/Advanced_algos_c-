#include<bits/stdc++.h>
using namespace std;

int main(){
	char str[] = "Limericks";
	char *s = &str[6]-6;
	while(*s)
		printf("%c",*s++); 
}
