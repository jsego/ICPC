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
int A[5];
int main(){
	int N;
	while (cin>>N,N) {
		for (int i=0; i<N ; i++) {
			int cant=0,pos=-1;;
			for (int j=0; j<5; j++) {
				cin>>A[j];
				if(A[j]<=127){ cant++; pos=j;}
			}
			if(cant!=1){
				cout<<"*"<<endl;
			}
			else {
				cout<<char('A'+pos)<<endl;
			}
		}
	}
}