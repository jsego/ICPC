/*
*  Javier Segovia
*  Accepted in 0.024
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

bool P[100001];
int A[101][101];
bool okis[101][101];
int R[101],K,N;

void primes(){
	for(int i=0;i<100001;i++) P[i] = true;
	P[0] = P[1] = false;
	for (int i=2; i<100001; i++) {
		for (int j=i+i ; j<100001; j+=i ) {
			P[j] = false;
		}
	}
}

bool isPrime(int n){ return n>0&&P[n];}

int main(){
	int kases; cin>>kases;
	primes();
	for (int q=1; q<=kases; q++) {
		bool ok=false;
		cin>>N>>K;
		for (int j=0; j<N ;j++) {
			cin>>R[j];
			if(R[j] == 42)ok=true;
		}
		
		for (int k=0; !ok && k<N ; k++) {
			A[k][k] = R[k];
			for (int j=k+1; j<N ; j++) {
				A[k][j] = A[k][j-1]+R[j];
			}
		}
		
		if(ok)cout<<"Case "<<q<<": "<<"Soha"<<endl;
		else{
			bool a,b;
			for (int i=0; i<N ; i++) {
				for (int j=0; j+i<N ; j++) {
					okis[j][i+j] = isPrime(A[j][i+j]);
					for (int k=j; !okis[j][i+j] && k<i+j; k++) {
						a = okis[j][k]; 
						b = okis[k+1][i+j];
						if(isPrime(A[j][k])) okis[j][i+j] = a&&!b;
						if(isPrime(A[k+1][i+j])) okis[j][i+j] = okis[j][i+j] || (!a&&b);
					}

				}
			}
			
			cout<<"Case "<<q<<": "<<(okis[0][N-1]?"Soha":"Tara")<<endl;
		}
	}
}