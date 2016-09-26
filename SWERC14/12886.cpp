#include<iostream>
#include<string>
#include<vector>

using namespace std;

#define MODU 1000000007
#define PRIME 179425027
int hp, wp, hm, wm;

long long P[2002][2002]; //Painting
long long M[2002][2002]; //Big painting

string A[2002], B[2002];
long long shsubs; //string hash substraction value
long long vasubs; //value hash substraction

int main(){
	while(cin>>hp>>wp>>hm>>wm){
		shsubs = 1; 
		for(int i=1;i<wp;i++) 
			shsubs = (shsubs << 1)%MODU;

		vasubs = 1;
		for(int i=1;i<hp;i++)
			vasubs = (vasubs * PRIME)%MODU;

		//Building small painting value
		long long V = 0;
		for(int i=0;i<hp;i++){
			cin>>A[i];
			P[i][0] = (A[i][0] == 'x')?1:0;
			for(int j=1;j<wp;j++){
				P[i][j] = (P[i][j-1]*2 + (A[i][j] == 'x'))%MODU;
			}
			V = (V*PRIME + P[i][wp-1])%MODU;
		}

		//Building hash rows
		for(int i=0;i<hm;i++){
			cin>>B[i];
			M[i][0] = (B[i][0] == 'x')?1:0;
			for(int j=1;j<wm;j++){
				if(j >= wp){	
					M[i][j] = ( (M[i][j-1]-(B[i][j-wp]=='x'?shsubs:0)+MODU)*2 + (B[i][j] == 'x'))%MODU;
				}
				else{
					M[i][j] = ( M[i][j-1]*2 + (B[i][j] == 'x') )%MODU;
				} 
			}
		} 

		//Building hash cols
		int res = 0;
		for(int j = wp-1; j < wm;j++){
			long long V2 = 0;
			for(int i = 0; i < hm; i++){
				if(i >= hp){ //substract vasubs the first element to have
					if(V2 == V) res++;
					V2 = ( ((V2 - (vasubs*M[i-hp][j])%MODU + MODU)%MODU)*PRIME + M[i][j] )%MODU;
				}
				else{
					V2 = (V2*PRIME + M[i][j])%MODU;
				}
			} 
			if(V2 == V) res++;
		}
		cout<<res<<endl;		
	}
}
