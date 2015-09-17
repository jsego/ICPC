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
int B[8],A[25][3];
int main(){
	int N,M;
	while (cin>>N>>M && (N||M)) {
		for(int i=0;i<M;i++) for(int j=0;j<3;j++) A[i][j] = -1;
		for(int i=0;i<N;i++) B[i] = i;
		int cont=0;
		for(int m=0;m<M;m++){ 
			for(int j=0;j<3;j++) cin>>A[m][j];
		}
		int d1,d2; bool ok;
		do{
			ok=true;
			//chekear si es valido como estan colocados
			for (int m=0; m<M ; m++) {
				d2 = abs(B[A[m][0]]-B[A[m][1]]);
				d1 = A[m][2];
				if(d1<0){ if(d2<abs(d1)){ok=false;break;}}
				else {
					if(d2>d1){ok=false;break;}
				}

			}
			if(ok)cont++;
		}while(next_permutation(B,B+N));
		cout<<cont<<endl;
	}
}