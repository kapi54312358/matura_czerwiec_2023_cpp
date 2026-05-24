#include <iostream>
#include <string>
#include <fstream>
#include <vector>

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

bool czy_nie_wystepuje_0(int a){
	while(a>0){
		if(a%10==0) return false;
		a/=10;
	}
	return true;
}

int suma_roznych_cyfr(int a){
	vector <int> w;
	int i=0, c=0, s=0;
	bool flaga;
	
	while(a>0){
		flaga=true;
		c=a%10;
		for(i=0; i<w.size(); i++){
			if(c==w[i]) flaga=false;
		}
		if(flaga)
			w.push_back(c);
		a/=10;
	}
	
	for(i=0; i<w.size(); i++){
		s+=w[i];
	}
	
	return s;
}

int main(int argc, char** argv){
	ifstream we("C:/cpp/anagram.txt");
	string Bin[n];
	int Liczby[n];
	int i=0, liczby_bez_zer=0, najw_suma=0, liczba_z_najw_sumy=0, najw=0;
	
	for(i=0; i<n; i++){
		we>>Bin[i];
	}
	
	for(i=0; i<n; i++){//a)
		Liczby[i]=bintodec(Bin[i]);
		if(czy_nie_wystepuje_0(Liczby[i]))
			liczby_bez_zer++;
	}
	cout<<liczby_bez_zer;
	
	for(i=0; i<n; i++){//b)
		if(suma_roznych_cyfr(Liczby[i])>najw){
			najw=suma_roznych_cyfr(Liczby[i]);
			liczba_z_najw_sumy=Liczby[i];
		}
	}
	cout<<endl<<liczba_z_najw_sumy;
	
	return 0;
}
