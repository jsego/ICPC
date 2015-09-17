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
int M[9] = { 
	(1<<7)|(1<<5),
	(1<<8)|(1<<6)|(1<<4),
	(1<<7)|(1<<3),
	(1<<8)|(1<<4)|(1<<2),
	(1<<7)|(1<<5)|(1<<3)|(1<<1),
	(1<<6)|(1<<4)|(1),
	(1<<5)|(1<<1),
	(1<<4)|(1<<2)|(1),
	(1<<3)|(1<<1)
};
int V[520];
bool seen[520];
int next,countbits=0,ac;

int solve(int i){
	//cout<<"I: "<<i<<endl;
	if(seen[i]) return V[i];
	next = 0;
	for (int j=0; j<9; j++) {
		ac = i&M[j];
		countbits = 0;
		while (ac) {
			if(ac&1) countbits++;
			ac>>=1;
		}
		if(countbits&1)
			next = next|(1<<(8-j));
	}
	V[i] = 1 + solve(next);
	seen[i] = true;
	return V[i];
}

int main(){
	V[0] = -1;
	seen[0] = true;
	for (int i=1; i<512; i++) {
		//cout<<i<<endl;
		solve(i);
	}
	int kases; scanf("%d",&kases);
	while (kases--) {
		char c;
		ac = 0;
		
		for (int i=8; i>=0; i--) {
			cin>>c;
			if(c == '1')
				ac=(ac|(1<<i));
		}
		printf("%d\n",V[ac]);
	}
}