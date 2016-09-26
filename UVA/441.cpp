/*
*  Javier Segovia
*  Accepted in 0.012
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
int K,S[15],V[6];
void recur(int t,int p){
	if (t==6) {
		cout<<V[0]; for(int i=1;i<6;i++) cout<<" "<<V[i]; cout<<endl;
		return;
	}
	for (int i=p+1; K+t>=6+i; i++) {
		V[t] = S[i];
		recur(t+1,i);
	}
}
int main(){
	bool first=true;
	while (cin>>K && K) {
		if(first)first=false;
		else cout<<endl;
		for (int i=0; i<K; i++) {
			cin>>S[i];
		}
		sort(S,S+K);
		recur(0,-1);
	}
}