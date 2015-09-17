/*
*  Javier Segovia
*  Accepted in 0.008
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

int power(int b,int e){
	int res=1;
	while (e) {
		e--;
		res*=b;
	}
	return res;
}

int main(){
	int kases; cin>>kases;
	while (kases--) {
		int ac;
		vector<int> V;
		while (cin>>ac,ac) {
			V.PB(ac);
		}
		sort(V.rbegin(),V.rend());
		int val=0;
		
		for (int expo=1; expo<=int(V.SL); expo++) {
			ac = power(V[expo-1],expo);
			val+=ac;
		}
		
		if(val <= 2500000)cout<<val*2<<endl;
		else cout<<"Too expensive"<<endl;
	}
}