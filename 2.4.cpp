#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int const m=10;

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
	ifstream we("C:/cpp/slowa4.txt");
	int i=0, j=0, k=0, miejsce=0, dlugosc=0, n_sufiks=0;
	string s[m];
	string pom="", wynik="";
	int n[m], najm_sufiks[m];
	
	for(i=0; i<m; i++){
		we>>n[i];
		we>>s[i];
	}
	
	for(i=0; i<m; i++){
		dlugosc=n[i];
		int T[dlugosc];
		for(j=0; j<dlugosc; j++){
			T[j]=0;
		}
		
		for(k=0; k<dlugosc; k++){
			miejsce=0;
			for(j=0; j<dlugosc; j++){
				if(k!=j && czy_mniejszy(dlugosc, s[i], j, k))
					miejsce++;
			}
			T[miejsce]=k+1;
		}
		
		najm_sufiks[i]=T[0];
	}
	
	for(i=0; i<m; i++){
		wynik="";
		pom="";
		pom=s[i];
		n_sufiks=najm_sufiks[i]-1;
		for(j=n_sufiks; j<n[i]; j++){
			wynik+=pom[j];
		}
		cout<<wynik<<endl;
	}
	
	return 0;
}
