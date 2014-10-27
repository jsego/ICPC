#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void fillv(double p,vector<vector<double> > &v,int s,int w){
	double v1, v2;
	for(int p1 = 0,p2 = s;p1<=s;p1++,p2--){
		if(p1 > 0 && p2 < w) v1 = v[p1-1][p2];
		else v1 = 0.0;
		if(p2 > 0 && p1 < w) v2 = v[p1][p2-1];
		else v2 = 0.0;
		v[p1][p2] = v1*p + v2*(1-p);
	}
}


int main(){
	double p;
	cout.setf(ios::fixed);
	cout.precision(11);
	while(cin>>p, p!=-1){
		vector<vector<double> > G, S, T, M;
		G = S = T = M = vector<vector<double> >(15,vector<double>(15,-1));
		G[0][0] = S[0][0] = T[0][0] = M[0][0] = 1.0;

		//Game operations
		for(int sum = 1;sum<7;sum++) fillv(p,G,sum,4);

		//Deuce equation P[40-40]
		G[3][3] = (G[2][3]*p + G[3][2]*(1-p))/(1-2*p*(1-p));

		//Probability of winning a game
		double pgame = G[4][0] + G[4][1] + G[4][2] + G[3][3]*p*p;

		//Tie break operations
		for(int sum = 1;sum<15;sum++) fillv(p,T,sum,7);
		
		//Deuce equation P[6-6]
		T[6][6] = (T[5][6]*p + T[6][5]*(1-p))/(1-2*p*(1-p));

		//Probability winning tie break
		double ptb = T[7][0]+T[7][1]+T[7][2]+T[7][3]+
					 T[7][4]+T[7][5]+T[6][6]*p*p; 

		//Set operations
		for(int sum = 1;sum<15;sum++) fillv(pgame,S,sum,6);
		S[6][6] = S[5][6]*pgame + S[6][5]*(1-pgame);
		S[7][5] = S[6][5]*pgame;		

		//Probability of winning a set
		double pset = S[6][0]+S[6][1]+S[6][2]+S[6][3]+S[6][4]+S[7][5]+S[6][6]*ptb; 

		//Match operations
		for(int sum = 1;sum<4;sum++)fillv(pset,M,sum,2);

		//Probability of winning the match
		double pmatch = M[2][0] + M[2][1];
						
		cout<<pgame<<" "<<pset<<" "<<pmatch<<endl;
	}
}
