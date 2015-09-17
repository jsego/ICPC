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
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MP make_pair
vector<int> F[1001];
int PR[1000],tot=1;
int BF[10000];
void primes(){
	PR[0] = 2;
	for (int i=3; i<1001; i++) {
		bool ok=true;
		for (int j=0; j<tot; j++) {
			if (i%PR[j]==0) {
				ok=false; break;
			}
		}
		if (ok) {
			PR[tot++] = i;
		}
	}
}
void factorize(int a){
	for (int j=0; j<tot; j++) {
		if (PR[j]>=a) {
			break;
		}
		if (a%PR[j]==0) {
			F[a].PB(PR[j]);
		}
	}
}

int bfs(int s,int a){
	int ac=0,val=s,total=1;
	vector<int> va(a+5,10000000); va[s]=0;
	BF[0] = s;
	while (ac<total) {
		val = BF[ac];
		//cout<<"VAL: "<<val<<endl;
		for (int i=0; i<(int)F[val].SL; i++) {
			if (F[val][i]+val<=a && va[F[val][i]+val]==10000000) {
				va[F[val][i]+val] = va[val]+1;
				BF[total++] = F[val][i]+val;
				if (F[val][i]+val==a) {
					ac=total; break;
				}
			}
		}
		ac++;
	}
	if (va[a]<10000000) {
		return va[a];
	}
	return -1;
}

int main(){
	int S,T,kases=1;
	primes();
	for (int i=4; i<1001; i++) {
		factorize(i);
	}
	while (cin>>S>>T && (S||T)) {
		int res = bfs(S,T);
		cout<<"Case "<<kases++<<": "<<res<<endl;
	}
}