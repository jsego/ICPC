/*
*  Javier Segovia
*  Accepted in 0.612
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
int A[15];

bool calc(int c,int n){
	vector<int> v(n,0);
	for(int i=0;i<n;i++) v[i] = i;
	int a=n>>1,last = c%(int)v.SL;
	while ((int)v.SL > a) {
		//if(n==4) cout<<"TAM: "<<v.SL<<" POS: "<<last<<" CONT: "<<v[last]<<endl;
		if( v[last] < a) return false;
		v.erase(v.begin()+last);
		last = (last+c)%(int)v.SL;
	}
	return true;
}

int main(){
	int K;
	A[1] = 2;
	for (int i=2; i<14; i++) {
		int cont=i,n=i<<1;
		while (!calc(cont,n)) {
			cont++;
		}
		A[i] = cont+1;
	}
	while (scanf("%d",&K), K) {
		printf("%d\n",A[K]);
	}
}