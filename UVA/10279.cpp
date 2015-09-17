/*
*  Javier Segovia
*  Accepted in 0.004
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
char A[11][11],B[11][11];
int C[11][11];
int main(){
	int kases; cin>>kases;
	for (int k=0; k<kases; k++) {
		if (k) {
			cout<<endl;
		}
		int N;
		bool bomb = false;
		cin>>N; for(int i=0;i<N ;i++) for(int j=0;j<N;j++) C[i][j] = 0;
		for (int i=0; i<N ; i++) {
			for (int j=0; j<N ; j++) {
				cin>>A[i][j]; 
				if (A[i][j] == '*') {
					for (int q=-1; q<2; q++) {
						for (int p=-1; p<2; p++) {
							if ( (q*q + p*p) ) {
								if ((q+i)>=0 && (q+i)<N && (p+j)>=0 && (p+j)<N ) {
									C[i+q][p+j]++;
								}
							}
						}
					}
				}
			}
		}
		for (int i=0; i<N ; i++) {
			for (int j=0; j<N ; j++) {
				cin>>B[i][j];
				if (B[i][j]=='x' && A[i][j]=='*') {
					bomb = true;
				}
			}
		}
		for (int i=0; i<N ; i++) {
			for (int j=0; j<N ; j++) {
				if (bomb && A[i][j]=='*') {
					cout<<"*"; continue;
				}
				if (B[i][j]=='x') {
					cout<<C[i][j];
				}
				else {
					cout<<".";
				}

			}cout<<endl;
		}
	}
}