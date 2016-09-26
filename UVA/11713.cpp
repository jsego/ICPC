/*
*  Javier Segovia
*  Accepted in 0.012
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
bool vowel(char c){
	return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}
int main(){
	string a,b; int n;
	cin>>n;
	for (int i=0; i<n; i++) {
		cin>>a>>b;
		bool ok=a.LE == b.LE,ba,bb;
		for (int i=0; i<(int)a.LE && ok; i++) {
			ba = vowel(a[i]); bb = vowel(b[i]);
			ok = ba==bb;
			if(ok){ 
				if(!ba && !bb) ok= a[i]==b[i];
			}

		}
		if(ok)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}