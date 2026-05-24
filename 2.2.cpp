#include <iostream>
#include <fstream>
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
	if(j<=n)
		return true;
	else
		return false;
}

int main(int argc, char** argv) {
	ifstream we1("C:/cpp/slowa1.txt");
	ifstream we2("C:/cpp/slowa2.txt");
	ifstream we3("C:/cpp/slowa3.txt");
	int n1=0, n2=0, n3=0, k1_1=0, k2_1=0, k1_2=0, k2_2=0, k1_3=0, k2_3=0;
	string s1="", s2="", s3="";
	
	we1>>n1;
	we2>>n2;
	we3>>n3;
	
	we1>>s1;
	we2>>s2;
	we3>>s3;
	
	we1>>k1_1;
	we1>>k2_1;
	we2>>k1_2;
	we2>>k2_2;
	we3>>k1_3;
	we3>>k2_3;
	//cout<<n1<<endl<<s1<<endl<<k1_1<<" "<<k2_1;
	
	if(czy_mniejszy(n1, s1, k1_1, k2_1))
		cout<<"TAK"<<endl;
	else
		cout<<"NIE"<<endl;
	
	if(czy_mniejszy(n2, s2, k1_2, k2_2))
		cout<<"TAK"<<endl;
	else
		cout<<"NIE"<<endl;
	
	if(czy_mniejszy(n3, s3, k1_3, k2_3))
		cout<<"TAK"<<endl;
	else
		cout<<"NIE"<<endl;
		
	return 0;
}
