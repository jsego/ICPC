/*
*  Javier Segovia
*  Accepted in 0.052
*/
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
#define X first
#define Y second
typedef vector<pair<int,pair<int,int> > > V;
int N,mf[501],S,P,D; // numero de nodos N <= 2000
int A[501][2];
V v; // v e c t o r de a r i s t a s
// ( co s t e , ( nodo1 , nodo2 ) )
int set(int n) { // conjunto conexo de n
	if (mf[n] == n) return n;
	return mf[n] = set(mf[n]);
}
int kruskal ( ) {
	int a , b ;
	sort(v.begin(),v.end());
	for(int i = 0 ; i < N; i++)
		mf[i] = i ; // i n i c i a l i z a r conjunto s conexos
	int cont=0;
	for(int i = 0 ; i <(int)v.SL ; i++) {
		a = set(v[i].Y.X) , b = set(v[i].Y.Y) ;
		if( a != b) { // s i conjunto s son d i f e r e n t e s
			mf[b] = a ; // u n i f i c a r l o s conjunto s
			cont++;
			if(cont == D) return v[i].X; // a g r eg a r c o s t e de a r i s t a
		}
	}
	//cout<<"CONT: "<<cont<<" D: "<<D<<endl;
	return 0;
}

int main(){
	int kases; cin>>kases;
	while (kases--) {
		cin>>S>>P; N=P; D = P-S;
		v.clear();
		for (int i=0; i<P ; i++) {
			cin>>A[i][0]>>A[i][1];
		}
		int dif1,dif2;
		for (int i=0; i<P ; i++) {
			for (int j=i+1; j<P ; j++) {
				dif1 = A[i][0] - A[j][0];
				dif2 = A[i][1] - A[j][1];
				v.PB(MP(dif1*dif1 + dif2*dif2,MP(i,j)));
			}
		}
		
		int res = kruskal();
		printf("%.2lf\n",sqrt(double(res + 0.000000001)));
	}
}