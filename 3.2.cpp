#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int n=1000;

int ile_jedynek(string a){
	int i=0, dl=a.size(), l=0;
	for(i=0; i<dl; i++){
		if(a[i]=='1')
			l++;
	}
	return l;
}

int main(int argc, char** argv){
	ifstream we("C:/cpp/anagram.txt");
	string Bin[n], Bin8[n];
	int i=0, j=0;
	
	for(i=0; i<n; i++){
		we>>Bin[i];
	}
	
	for(i=0; i<n; i++){
		if(Bin[i].size()==8)
			if(ile_jedynek(Bin[i])==5 || ile_jedynek(Bin[i])==4){
				Bin8[j]=Bin[i];
				j++;
			}	
	}
	
	for(i=0; i<j; i++){
		cout<<Bin8[i]<<endl;
	}
	
	return 0;
}
