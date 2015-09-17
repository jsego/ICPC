/*
*  Javier Segovia
*  Accepted in 1.744
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
int mf[200001];
int val[200001];
int set(int n){
	if(mf[n] == n)return n;
	return mf[n] = set(mf[n]);
}
int main(){
	int kases; cin>>kases;
	while (kases--) {
		int cont=0,links; string A,B;
		map<string,int> M;
		map<string,int>::iterator it1,it2;
		int ac1,ac2,s1,s2;
		cin>>links;
		for (int i=0; i<links; i++) {
			cin>>A>>B;
			it1 = M.find(A); it2 = M.find(B);
			if(it1 == M.end()){M[A] = cont; ac1=cont++; val[ac1] = 1; mf[ac1] =ac1;}
			else ac1=it1->second;
			if(it2 == M.end()){M[B] = cont; ac2=cont++; val[ac2] = 1; mf[ac2]=ac2;}
			else ac2 = it2->second;
			s1 = set(ac1); s2 = set(ac2);
			if (s1!=s2) {
				val[s1] += val[s2];
				mf[s2] = s1;
			}
			cout<<val[s1]<<endl;
		}
	}
}