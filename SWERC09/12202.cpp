#include<iostream>
#include<vector>
using namespace std;

#define INF 1000000000
#define X first
#define Y second
#define MP make_pair
#define SZ size()

typedef pair<pair<int,int>,int> P; // pair nodes - costs
int N;                             // number of nodes
vector<P> v;                       // edges representation


int bellmanford(int a, int b) {
  vector<int> d(N, INF);
  d[a] = 0;
  for (int i = 1; i < N; i++)
    for (int j = 0; j < (int)v.SZ; j++)
      if (d[v[j].X.X] < INF && d[v[j].X.X] + v[j].Y < d[v[j].X.Y])
        d[v[j].X.Y] = d[v[j].X.X] + v[j].Y;
  
  for (int j = 0; j < (int)v.SZ; j++)
    if (d[v[j].X.X] < INF && d[v[j].X.X] + v[j].Y < d[v[j].X.Y])
			return -INF; //check if there is a negative cycle

	return d[b];
}

int main(){
	int W,H,G,E; 
	int M[35][35];
	while(cin>>W>>H, W||H){
		N = W*H; 
		v.clear();
		for(int i=0;i<W;i++) for(int j=0;j<H;j++)M[i][j] = 0;
		int x,y,x2,y2,t,n1,n2,n;

		//Reading gravestones
		cin>>G;
		for(int g=0;g<G;g++){
			cin>>x>>y;
			M[x][y] = 2;
		}

		//Reading Haunted Holes
		cin>>E;
		for(int ed = 0; ed < E; ed++){
			cin>>x>>y>>x2>>y2>>t;
			n1 = x*H+y; n2 = x2*H+y2;//hash nodes
			M[x][y] = 1; //only 1 direction for haunted holes
			v.push_back(MP(MP(n1,n2),t));
		}

		M[W-1][H-1] = 1; //no output links from last position

		//Creating the graph
		for(int i=0;i<W;i++) for(int j=0;j<H;j++){
			if(M[i][j]!=0)continue;
			n = i*H + j;
			if(i && M[i-1][j] < 2){
				v.push_back(MP(MP(n,n-H),1));		
			}
			if(i+1<W && M[i+1][j] < 2){
				v.push_back(MP(MP(n,n+H),1));					
			}
			if(j && M[i][j-1] < 2){
				v.push_back(MP(MP(n,n-1),1));
			}
			if(j+1<H && M[i][j+1] < 2){
				v.push_back(MP(MP(n,n+1),1));
			}
		}

		//Call bellmanford from (0,0) to (W-1,H-1)
		int res = bellmanford(0,N-1); 
		if(res == -INF) cout<<"Never"<<endl;
		else if(res == INF) cout<<"Impossible"<<endl;
		else cout<<res<<endl;
	}
}
