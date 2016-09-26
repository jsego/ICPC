/*
*  Javier Segovia
*  Accepted in 0.124
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
int N;
int C[100][4];
bool seen[10];
int total = -1;

void recur(int comb,int s,int cant){
	if (cant == 3) {
		total = MAX(total,s); return;
	}
	int a,b,c;
	for (int i=comb; i<N; i++) {
		a = C[i][0]; b = C[i][1]; c= C[i][2];
		if (!seen[a] && !seen[b] && !seen[c]) {
			seen[a] = seen[b] = seen[c] = true;
			recur(i+1,C[i][3]+s,cant+1);
			seen[a] = seen[b] = seen[c] = false;
		}
	}
}
int main(){
	int kases=1;
	while (cin>>N && N ) { total = -1;
		for(int j=1;j<10;j++) seen[j] = false;
		for (int n=0; n<N ; n++) {
			for (int j=0; j<4; j++) {
				cin>>C[n][j];
			}
		}
		recur(0,0,0);
		cout << "Case "<<kases++<<": "<<total<<endl;
	}
}