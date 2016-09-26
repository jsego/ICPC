#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
int L[10001][2];
int main(){
	int N,M;
	while (cin>>N>>M && (N||M)) {
		int so,de,st,du;
		for (int i=0; i<N ; i++) {
			cin>>so>>de>>L[i][0]>>L[i][1];
			L[i][1]+=L[i][0];
		}
		for (int i=0; i<M; i++) {
			cin>>st>>du;
			du+=st;
			int res=0;
			for (int i=0; i<N ; i++) {
				if ( (L[i][0]>=st && L[i][0]<du) || (L[i][1]<=du && L[i][1]>st) || (L[i][0]<=st && L[i][1]>=du)) {
					res++;
				}
			}
			cout<<res<<endl;
			//printf("%d\n",res);
		}
	}
}