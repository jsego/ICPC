#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define MAX(a,b) ((a)>(b)?(a):(b))
short T[2][5000];
int main(){
	int kases;cin>>kases;
	while (kases--) {
		string s,a,b; cin>>s;
		int tam = (int)s.LE,sol=0;
		for (int j=1; j<tam; j++) {
			T[0][j] = (s[j] == s[0]?1:0);
		}
		for (int i=1; i<tam; i++) {
			for (int j=i+1; j<tam; j++) {
				if (s[i] == s[j]) {
					T[1][j] = T[0][j-1]+1;
				}
				else {
					T[1][j] = 0;
				}
				sol = MAX(sol,T[1][j]);
				swap(T[0][j-2],T[1][j-2]);
			}swap(T[0][tam-1],T[1][tam-1]); swap(T[0][tam-2],T[1][tam-2]);
		
		}	
		cout<<sol<<endl;
	}
}