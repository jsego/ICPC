/*
*  Javier Segovia
*  Accepted in 0.012
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<climits>
#include<algorithm>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define MAX(a,b) ((a)>(b)?(a):(b))
int S[1001];
int main(){
	for (int i=0; i<1001; i++) {
		S[i] = -1;
	}
	S[1] = 1;
	for (int i = 2; i<1001; i++) {
		int tot=1;
		for (int j=2; j<1001; j++) {
			if (j>i) {
				break;
			}
			if (i%j==0) {
				tot+=j;
			}
		}
		if (tot<1001) {
			S[tot] = i;
		}
	}
	//cout<<tot<<endl;
	int N,kases=1;
	while (cin>>N && N ) {
		cout<<"Case "<<kases++<<": "<<S[N]<<endl;
	}
}