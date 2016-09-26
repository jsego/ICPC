/*
*	Javier Segovia
*	Accepted in 0.012
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
int C[300];
int main(){
	int kases; cin>>kases;
	C[(int)' ']=0; C[0] = (int)' ';
	C[(int)'.'] = 1; C[1] = (int)'.';
	C[(int)'x'] = 2; C[2] = (int)'x';
	C[(int)'W'] = 3; C[3] = (int)'W';
	bool first = true;
	while (kases--) {
		if(first)first=false;
		else cout<<endl;
		int DNA[10];
		for (int i=0; i<10; i++) {
			cin>>DNA[i];
		}
		string S(40,' '),ac(40,' ');
		S[19] = '.';
		int val;
		for (int i=0; i<50; i++) {
			cout<<S<<endl;
			for (int j=0; j<40; j++) {
				val = 0;
				
				if(j) val = C[(int)S[j-1]];
				val+= C[(int)S[j]];
				if(j < 39) val +=C[(int)S[j+1]];
				
				ac[j] = (char)C[DNA[val]];
			}
			S = ac;
			//swap(S,ac);
		}
	}
}