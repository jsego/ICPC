/*
*  Javier Segovia
*  Accepted in 0.220
*/
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
int S[21];
bool mask[6000000];
int sticks,lim;
bool recur(int pile,int tot,int M){
	if(mask[M]) return false;
	if(tot>lim)return false;
	if(tot == lim){pile++; tot=0;}
	if(pile==3 && !tot)return true;
	mask[M] = true;
	for(int i=sticks-1;i>=0;i--){
		if (!(M&(1<<i))) {
			if (recur(pile,tot+S[i],M|(1<<i))) return true;
		}
	}
	return false;
}

int main(){
	int kases; cin>>kases;
	while (kases--) {
		int total=0; cin>>sticks;
		for(int i=0;i<sticks;i++){
			cin>>S[i];
			total += S[i];
		}
		if(total % 4 != 0){ cout<<"no"<<endl; continue;}
		lim = total>>2;
		memset(mask,false,sizeof(bool)*(1<<sticks));
		sort(S,S+sticks);
		if(recur(0,0,0)) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
}