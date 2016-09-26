#include<iostream>
#include<cmath>
#include<climits>
using namespace std;
#define MIN(a,b) ((a)<(b)?(a):(b))
//char T[101][101];
int FW[105][105];
char T[105][105];
double prob[105][3005],zero=0.0;
int N,R;

void floydWarshall(){
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			for(int k=1;k<=N;k++){
				//if(T[k][j]=='Y' && T[i][k]=='Y')
				FW[j][k] = MIN(FW[j][k],FW[j][i]+FW[i][k]);
			}
		}
	}
}

void calcProb(){
	//0 saltos 100% de acierto
	for(int n=0;n<=3001;n++) prob[0][n]=1.0;
	for(int n=1;n<=N;n++){//longitud del salto
		for(int j=1;j<=3001;j++){//dinero q tenemos
			prob[n][j] = 0.0;
			for(int k=j-1,q=0;k>=0 && q<R;k--,q++){//R anteriores valores del salto anterior
				prob[n][j] += prob[n-1][k];///R;///R;
			}
			//Cada suma es una r-esima parte de la probabilidad total
			prob[n][j]/=(double)(R+0.000000001);
		}
	}
}

int main(){
	int kases; cin>>kases;
	cout.setf(ios::fixed);
	cout.precision(6);
	for(int k=1;k<=kases;k++){
		if(k>1)cout<<endl;
		cin>>N>>R;
		for(int x=1;x<=N;x++) for(int y=1;y<=N;y++){
			cin>>T[x][y];
			FW[x][y]=500;
			if(x==y)FW[x][y]=0;
			else if(T[x][y]=='Y') FW[x][y]=1;
		}
		floydWarshall();
		calcProb();
		int C,ini,fin,price=INT_MAX; cin>>C;
		cout<<"Case "<<k<<endl;
		for(int c=0;c<C;c++){
			cin>>ini>>fin>>price;
			// price = MIN(price,(N-1)*R);
			if(FW[ini][fin] >= N) cout<<zero<<endl;
			else cout<<prob[FW[ini][fin]][MIN(price,(N-1)*R)]<<endl;
		}
		
	}
}
