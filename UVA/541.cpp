/*
*  Javier Segovia
*  Accepted in 0.012
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
int F[101],C[101];
int main(){
	int M;
	while (cin>>M && M) {
		for(int i=0;i<M;i++) C[i] = F[i] = 0;
		int ac;
		for (int i=0; i<M; i++) {
			for (int j=0; j<M; j++) {
				cin>>ac;
				if(ac){ F[i]++; C[j]++;}
			}
		}
		int f1=0,c1=0,ac1,ac2;
		for(int i=0;i<M;i++){
			if(F[i]&1){f1++; ac1=i;}
			if(C[i]&1){c1++; ac2=i;}
		}
		if(f1==0 && c1==0) cout<<"OK"<<endl;
		else if(f1==1 && c1==1)cout<<"Change bit ("<<ac1+1<<","<<ac2+1<<")"<<endl;
		else cout<<"Corrupt"<<endl;
	}
}