/*
*  Javier Segovia
*  Accepted in 0.020
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
	string S,T;
	while (cin>>S>>T ) {
		size_t F,last=0;
		bool ok=true;
		for (int i=0; i<(int)S.LE; i++) {
			F = T.find(S[i],last);
			if (F==string::npos) {
				ok=false; break;
			}
			last = F+1;
		}
		if (ok) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}