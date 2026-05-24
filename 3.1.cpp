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

int	ile_zer(string a){
	int i=0, dl=a.size(), l=0;
	for(i=0; i<dl; i++){
		if(a[i]=='0')
			l++;
	}
	return l;
}

int main(int argc, char** argv){
	ifstream we("C:/cpp/anagram.txt");
	string Bin[n];
	int i=0, zrownowarzone=0, prawie_zrownowarzone=0;
	
	for(i=0; i<n; i++){
		we>>Bin[i];
		if(ile_jedynek(Bin[i])==ile_zer(Bin[i]))
			zrownowarzone++;
		if(ile_jedynek(Bin[i])==ile_zer(Bin[i])+1 || ile_jedynek(Bin[i])==ile_zer(Bin[i])-1)
			prawie_zrownowarzone++;
	}
	
	cout<<zrownowarzone<<endl<<prawie_zrownowarzone;
	
	return 0;
}
