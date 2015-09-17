/*
*  Javier Segovia
*  Accepted in 0.008
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
int F[1000000],tot=2;
void fib(int a){
	bool ini=false;
	for (int i=tot-1; i>1; i--) {
		if (F[i]<=a) {
			a-=F[i];
			cout << 1; ini=true;
		}
		else if(ini){
			cout<<0;
		}
	}	
	//cout<<endl;
}

int main(){
	F[0] = 0;
	F[1] = 1;
	for (; F[tot-1]<=100000000; tot++) {
		F[tot] = F[tot-1]+F[tot-2];
	}
	int N,ac; cin>>N;
	while (N--) {
		cin>>ac;
		cout<<ac<<" = ";
		fib(ac);
		cout<<" (fib)\n";
	}
}