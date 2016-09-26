/*
*  Javier Segovia
*  Accepted in 0.016
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
#define INF 1000000000
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ULL unsigned long long

string A[25];
ULL dist[25][25];

int main(){
	int N,M,kases=1;
	while (cin>>N>>M,N||M) {
		for (int i=1; i<=N ; i++) {
			cin>>A[i];
		}
		for (int i=1; i<=N ; i++) {
			dist[i][i] = 0;
			for (int j=i+1; j<=N ; j++) {
				dist[i][j] = dist[j][i] = INF;
			}
		}
		ULL a,b,c;
		for (int i=0; i<M ; i++) {
			cin>>a>>b>>c;
			dist[a][b] = dist[b][a] = MIN(dist[a][b],c);
		}
		ULL mini = INF,pos=1;
		mini *= 30;
		for (int i=1; i<= N ; i++) {
			for (int j=1; j<= N ; j++) {
				for (int k=1; k<=N ; k++) {
					dist[i][j] = MIN(dist[i][j],dist[i][k]+dist[k][j]);
					dist[j][i] = dist[i][j]; 
				}
			}
		}
		for (int j=1;j<=N ; j++) {
			ULL ac=0;
			for (int k=1; k<= N ; k++) {
				ac+=dist[j][k];
			}
			if(ac<mini){mini = ac; pos=j;}
		}
		cout<<"Case #"<<kases++<<" : "<< A[pos] <<endl;
	}
}