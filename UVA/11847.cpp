/*
*  Javier Segovia
*  Accepted in 0.008
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<set>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define INF 1000000000
#define X first
#define Y second

int main(){
	int N;
	while (cin>>N,N ) {
		int count=-1;
		while (N) {
			count++;
			N>>=1;
		}
		cout<<count<<endl;
	}
}