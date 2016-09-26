#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define X first
#define Y second
typedef pair<pair<int,int>,int> P; // par de nodos + c o s t e
int W,H;
int A[30][30];
int N; // numero de nodos
int LIM=INT_MAX;
vector<P> v ; // r e p r e s e n t a c i o n a r i s t a s
int bellmanford (int a ,int b) {
	vector<int> d(b+1,LIM) ;
	d[a] = 0 ; //cout<<a<<" "<<b;
	for(int i = 1 ; i < N; i++)
		for(int j = 0 ; j < (int)v.SL;j++)
			if(d[v[j].X.X]!=LIM && (d[v[j].X.X]+v[j].Y<d[v[j].X.Y]) )
				d[v[j].X.Y]=d[v[j].X.X]+v[j].Y;
	for(int j = 0 ; j < (int)v.SL ; j++)
	   if(d[v[j].X.X]!=LIM && (d[v[j].X.X] + v[j].Y <d[v[j].X.Y] ) )
				  return -1987654321; // e x i s t e c i c l o neg a t ivo
	return d[b];
}


int main(){
	while(cin>>W>>H && (W||H)){
		int G,x,y,E; v.clear();
		//cout<<W<<" "<<H<<endl;
		for (int j=0; j<H; j++) {
			for (int i=0; i<W ; i++) {
				A[i][j] = 0;
			}
		}
		cin>>G;
		for (int g=0; g<G; g++) {
			cin>>x>>y;
			A[x][y] = 1;
		}
		N = (W*H);
		cin>>E;
		int x1,y1,x2,y2,time;
		while (E--) {
			cin>>x1>>y1>>x2>>y2>>time;
			A[x1][y1] = 2;
			v.PB(MP(MP(x1*31+y1,x2*31+y2),time));
		}
		for (int j=0; j<H; j++) {
			for (int i=0; i<W ; i++) {
				if(j+1==H && i+1==W)break;
				if (A[i][j]) {
					continue;
				}
				if(i>0) v.PB(MP(MP(i*31+j,(i-1)*31+j),1));
				if(j>0) v.PB(MP(MP(i*31+j,i*31+j-1),1));
				if(i+1<W)v.PB(MP(MP(i*31+j,(i+1)*31+j),1));
				if(j+1<H) v.PB(MP(MP(i*31+j,i*31+j+1),1));
			}
		}
		int res = bellmanford(0,(W-1)*31+(H-1));
		if(res == -1987654321) cout<<"Never"<<endl; //printf("Never\n");
		else if(res == LIM) cout<<"Impossible"<<endl; //printf("Impossible\n");
		else cout<<res<<endl;//printf("%d\n",res);;
	}
}