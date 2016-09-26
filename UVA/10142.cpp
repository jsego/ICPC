/*
*  Javier Segovia
*  Accepted in 0.632
*/
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<cmath>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair

string A[25];
int B[1005][25];
int POS[1005];
int C[25];
bool eliminated[25];

int main(){
	int kases; cin>>kases;
	string s;
	getline(cin,s); getline(cin,s);
	int N;
	bool first=false;
	while (kases--) {
		cin>>N;
		if(first) cout<<endl;
		else first = true;
		getline(cin,s);
		for (int i=0; i<N ; i++) {
			getline(cin,A[i]);
			eliminated[i] = false;
			C[i] = 0;
		}
		getline(cin,s);
		int total=0,tam = int(s.LE);
		
		for(int k=0	; tam == int(s.LE);k++){
			istringstream iss(s);
			for (int i=0; i<N ; i++) {
				iss>>B[total][i]; 
				B[total][i]--;
			}
			s="";
			POS[total++] = 0;
			getline(cin,s); 
		}
		

		int rest=N*total,pos;
		
		while (rest) {// cout<<rest<<endl;
			for (int i=0; i<N ; i++) {
				C[i] = 0;
			}
			int maxi=0,mini=100000000,mco=-1;
			
			for (int i=0; i<total ; i++) {
				pos = B[i][POS[i]];
				while (eliminated[pos]) {
					POS[i]++;
					pos = B[i][POS[i]];
					rest--;
				}
				C[pos]++;
			}
			
			for (int i=0; i<N ; i++) {
				if(!eliminated[i]){
					if(C[i]<mini) mini=C[i];
					if(C[i]>maxi) maxi=C[i];
				}
			}
			
			if(maxi <= mini) break;
			
			if(C[mco]*2 > total){
				for (int i=0; i<N ; i++) {
					if(i!=mco) eliminated[i] = true;
					else eliminated[i] = false;
				}
				break;
			}
			for (int i=0; i<N; i++) {
				if(C[i] <= mini){
					eliminated[i] = true;
				}
			}
		}
		for (int i=0; i<N ; i++) {
			if(!eliminated[i]) 
				cout<<A[i]<<endl;
		}
	}
}