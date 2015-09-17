/*
*  Javier Segovia
*  Accepted in 0.008
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<sstream>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
int main(){
	string a,b;
	int kases; cin>>kases; getline(cin,a);
	for (int k=1; k<=kases;k++) {
		cout<<"Case "<<k<<": ";
		getline(cin,a); getline(cin,b);
		if (a==b) {
			cout<<"Yes"<<endl; continue;
		}
		size_t ca=0,cb=0;
		bool ok=true;
		while (ca<a.LE && cb<b.LE) {
			while (ca<a.LE && a[ca]==' ' && a[ca]!=b[cb]) {
				ca++;
			}
			if (ca<a.LE && cb<b.LE) {
				if (a[ca]==b[cb]) {
					ca++; cb++;
				}
				else {
					ok=false; break;
				}
			}
		}
		while(ca<a.LE && a[ca]==' '){ca++;}
		if(ok) ok = (ca==a.LE && cb==b.LE);
		if (ok) {
			cout<<"Output Format Error"<<endl;
		}
		else {
			cout<<"Wrong Answer"<<endl;
		}

	}
}