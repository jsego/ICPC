#include<iostream>
#include<vector>
using namespace std;
#define SL size()
#define PB push_back
short W[1000][1000],M[1000][1000],wP[1001],mP[1001],aux,coW[1001],listing[50000];
int N;

void stableMarriage(){
	int ac = 0,total=0,ws; 
	for(int i=0;i<N;i++){
		listing[total++] = i;
		coW[i] = 0;
	}
	while(ac<total){
		ws = listing[ac]; 
		if(wP[ws]!=-1)continue;
		//cout<<"WS: "<<ws<<" ac: "<<ac<<" tt:"<<total<<endl;
		for(;coW[ws]<N;coW[ws]++){
			if (mP[W[ws][coW[ws]]]==-1) {
				wP[ws]=W[ws][coW[ws]];
				mP[W[ws][coW[ws]]] = ws; 
				break;
			}
			else {
				if(M[W[ws][coW[ws]]][mP[W[ws][coW[ws]]]] > M[W[ws][coW[ws]]][ws]){
					listing[total++] = mP[W[ws][coW[ws]]];
					wP[mP[W[ws][coW[ws]]]] = -1;
					mP[W[ws][coW[ws]]] = ws;
					wP[ws] = W[ws][coW[ws]];
					break;
				}
			}
		}
		ac++;
	}
}

int main(){
	int kases; cin>>kases;
	for(int k=0;k<kases;k++){
		if(k)cout<<endl;
		cin>>N;
		for(int i=0;i<N;i++) for(int j=0;j<N;j++){ cin>>W[i][j]; W[i][j]--;}
		for(int i=0;i<N;i++) for(int j=0;j<N;j++){ cin>>aux; M[i][aux-1]=j;}
		for(int i=0;i<N;i++){
			wP[i] = mP[i] = -1;
		}
		stableMarriage();
		for(int i=0;i<N;i++) cout<<wP[i]+1<<endl;
	}
}