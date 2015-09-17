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

int main(){
	int N,A; cin>>N;
	while (N--) {
		cin>>A;
		int cont=0;
		for (; cont*cont<A ; cont++) {}
		if(cont*cont>A) cont--;
		cout<<cont<<endl;
	}
}