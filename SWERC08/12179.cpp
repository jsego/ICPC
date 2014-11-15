#include<iostream>
#include<cmath>
#include<climits>
#include<algorithm>
using namespace std;

int FW[105][105], N, R;
double P[31][105][3005],zero=0.0;

void floydWarshall(){
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			for(int k=1;k<=N;k++){
				FW[j][k] = min(FW[j][k],FW[j][i]+FW[i][k]);
			}
		}
	}
}

void calcProb(){
	//0 paths 100% success
	for(int r=0;r<31;r++)
		for(int b=0;b<3002;b++) 
			P[r][0][b]=1.0;

	for(int r=1;r<31;r++)//random price per path
		for(int n=1;n<102;n++){//num of cities to visit
			for(int b=1;b<3002;b++){//remaining budget
				P[r][n][b] = 0.0;
				//R last values from previous num of cities visited
				for(int k=b-1,q=0;k>=0 && q<r;k--,q++){
					P[r][n][b] += P[r][n-1][k];
				}
				//Each sum is an rth part of the total probability
				P[r][n][b] /= double(r);
			}
		}
}

int main(){
	int kases; cin>>kases;
	cout.setf(ios::fixed);
	cout.precision(6);

	//Calculate probabilities just once
	calcProb();

	for(int k=1;k<=kases;k++){
		if(k>1)cout<<endl;
		cin>>N>>R;
		char t;
		for(int x=1;x<=N;x++) for(int y=1;y<=N;y++){
			cin>>t;
			if(x == y)FW[x][y]=0; //0 paths (x->x)
			else if(t == 'Y') FW[x][y]=1; //1 path (x->y)
			else FW[x][y] = 500; //INF no paths
		}

		floydWarshall();

		//calcProb();

		int C; cin>>C;
		int from_city, to_city, cities, budget; 

		cout<<"Case "<<k<<endl;
		for(int c=0;c<C;c++){
			cin>>from_city>>to_city>>budget;
			//R is the random price per path
			//FW[from_city][to_city] are the number of cities to visit
			cities = FW[from_city][to_city];
			//min(budget, (N-1)*R) is the maximum budget that can be spent
			budget = min(budget, (N-1)*R);
			cout<<P[R][cities][budget]<<endl;
		}
		
	}
}
