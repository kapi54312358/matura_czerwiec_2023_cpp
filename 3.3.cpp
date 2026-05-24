#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

int n=1000;

int bintodec(string a){
	int i=0, w=0, pot=1;
	
	for(i=a.size()-1; i>=0; i--){
		if(a[i]=='1'){
			w+=pot;
		}
		pot*=2;
	}
	
	return w;
}

string dectobin(int a){
	string w="";
	while(a>=1){
		if(a%2==1)
			w='1'+w;
		else
			w='0'+w;
		a/=2;
	}
	return w;
}

int main(int argc, char** argv){
	ifstream we("C:/cpp/anagram.txt");
	string Bin[n];
	int Liczby[n];
	int i=0, r=0, najw=0;
	
	for(i=0; i<n; i++){
		we>>Bin[i];
	}
	
	for(i=1; i<n; i++){
		r=abs(bintodec(Bin[i-1])-bintodec(Bin[i]));
		if(r>najw){
			najw=r;
		}
	}
	
	cout<<dectobin(najw);
	
	return 0;
}
