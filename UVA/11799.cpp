/*
 *  Javier Segovia
 *  Accepted in 0.016
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
#define MAX(a,b) ((a)>(b)?(a):(b))
int main(){
	int T; cin>>T;
	for (int i=1; i<=int(T); i++) {
		int N,s=0,c; cin>>N;
		while (N--) {
			cin>>c; s = MAX(s,c);
		}
		cout<<"Case "<<i<<": "<<s<<endl;
	}
}