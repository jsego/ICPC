/*
*  Javier Segovia
*  0.016
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

string A[100];

int main(){
	int N=0;
	while (getline(cin,A[N]), A[N]!="#") {
		if(A[N].LE < size_t(36)) 
			A[N] += string(size_t(36)-A[N].LE,' ');
		N++;
	}
	cout<<string(N*2 + 1,'-') <<endl;
	for (int i=0; i<36; i++) {
		cout<<"|";
		for (int j=0; j<N ; j++) {
			cout<<A[j][i]<<"|";
		}cout<<endl;
	}
	cout<<string(N*2 + 1,'-') <<endl;
}