#include<iostream>
#include<algorithm>
using namespace std;

#define INF 1000000000

int V[2005];
int R[2005][22];
int P[2005];

int main(){
	int N, D;
	while( cin >> N >> D ){ 
		for(int i=0;i<N;i++){
			cin >> V[i];
		}
		//V[N] = 0;

		for(int i=0;i<N;i++){
			P[i] = V[i];
			if(i) P[i] += P[i-1];
			for(int d = 0; d <= D; d++)
				R[i][d] = INF;
		}	
		
		for(int i = 0; i < N; i++){
			R[i][0] = (P[i]+5 - ((P[i]+5)%10));
		}

		int aux;
		for(int d = 1; d <= D; d++){
			for(int i = 0; i < N; i++){
				for(int mid = 0; mid <= i; mid ++){
					aux = P[i] - P[mid] + R[mid][d-1];
					aux = (aux + 5) - ((aux+5)%10);
					R[i][d] = min( R[i][d] , aux );
				}
			}
		}
		cout << R[N-1][D] << endl;
	}
}
