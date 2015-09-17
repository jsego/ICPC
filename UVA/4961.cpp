/*
*  Javier Segovia
*  0.016
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<sstream>
#include<climits>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair

int T[300];
char P[30];
char L[30][30];
int V[30][30];
int RV[210][210][30];
int N,W;

void dp(string &s){
	for (int i=1; i<=N ; i++) {
		for (int j=0; j<W ; j++) {
			RV[i][i][j] = INT_MAX;
		}
		RV[i][i][T[int(s[i-1])]] = 0;
	}
	int val;
	for (int l=2; l<=int(s.LE); l++) {
		for (int i=1,j; i<=N-l+1; i++) {
			j=i+l-1;
			for(int q=0;q<W;q++){
				RV[i][j][q] = INT_MAX;
			}
			for (int k=i ; k<=j-1; k++) {
				for(int q1=0;q1<W;q1++){
					if(RV[i][k][q1] ==INT_MAX)continue;
					for(int q2=0;q2<W;q2++){
						if(RV[k+1][j][q2] ==INT_MAX)continue;
						val = RV[i][k][q1]+RV[k+1][j][q2]+V[q1][q2];
						if(val < RV[i][j][T[int(L[q1][q2])]]){
							RV[i][j][T[int(L[q1][q2])]] = val;
							
						}
					}
				}
			}
		}
	}
}

int main(){
	bool first=true;
	string s;
	int val;
	char c;
	while (cin>>N,N ) {
		if(first)first=false;
		else cout<<endl;
		
		for (int i=0; i<N ; i++) {
			cin>>c;
			T[int(c)] = i;
			P[i] = c;
		}
		for (int i=0; i<N ; i++) {
			for (int j=0; j<N ; j++) {
				cin>>s;
				istringstream iss(s);
				iss>>val>>c>>c;
				V[i][j] = val;
				L[i][j] = c;
				//cout<<"VAL: "<<val<<" "<<c<<endl;
			}
		}
		int Q; cin>>Q; W=N;
		for (int i=0; i<Q; i++) {
			cin>>s; N = int(s.LE);
			dp(s);
			int v=INT_MAX;
			char sol='0';
			for (int q=0; q<W ; q++) {
				if(RV[1][N][q] < v){ v=RV[1][N][q]; sol = P[q];} 
			}
			cout<<v<<"-"<<sol<<endl;
		}
	}
}