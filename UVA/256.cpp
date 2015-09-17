/*
*  Javier Segovia
*  Accepted in 0.008
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<iomanip>
#include<cassert>
#include<algorithm>
#include<climits>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
vector<int> v[10];
int main(){
	int sq,up,down;
	for (int i=0; i*i<100000000; i++) {
		sq = i*i;
		if (sq<100) {
			up=sq/10; down=sq%10;
			if((up+down)*(up+down) == sq) v[2].PB(sq);
		}
		if(sq<10000){
			up=sq/100; down=sq%100;
			if((up+down)*(up+down) == sq) v[4].PB(sq);
		}
		if(sq<1000000){
			up=sq/1000; down=sq%1000;
			if((up+down)*(up+down) == sq) v[6].PB(sq);
		}
		if(sq<100000000) {
			up=sq/10000; down=sq%10000;
			if((up+down)*(up+down) == sq) v[8].PB(sq);
		}
	}
	int N;
	while (cin>>N ) {
		for (int i=0; i<(int)v[N].SL; i++) {
			cout<<setw(N)<<setfill('0')<<v[N][i]<<endl;
		}
	}
}