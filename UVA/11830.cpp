/*
*  Javier Segovia
*  0.016
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair

int main(){
	string b;
	char a;
	while (cin>>a>>b,b!="0"||a!='0') {
		for (size_t i=0; i<b.LE; i++) {
			if(b[i] == a){ b.erase(b.begin()+i); i--;}
		}
		if(int(b.LE) == 0) b="0";
		while (int(b.LE) > 1 && b[0] == '0') {
			b.erase(b.begin());
		}
		cout<<b<<endl;
	}
}