#include <iostream>
#include <string>

using namespace std;

bool czy_mniejszy(int n, string s, int k1, int k2){
	int i=k1, j=k2;
	while(i<=n && j<=n){
		if(s[i]==s[j]){
			i++;
			j++;
		}
		else{
			if(s[i]<s[j])
				return true;
			else
				return false;
		}	
	}
	if(i==n){
		if(j<n)
			return true;
		if(i<n)
			return false;
	}
}

int main(int argc, char** argv) {
	string s="mascarpone";
	int i=0, j=0, n=s.size(), miejsce=0;
	int T[n];
	for(i=0; i<n; i++){
		T[i]=0;
	}
	
	for(i=0; i<n; i++){
		miejsce=0;
		for(j=0; j<n; j++){
			if(i!=j && czy_mniejszy(n, s, j, i))
				miejsce++;
		}
		T[miejsce]=i+1;
	}
	
	return 0;
}
