/*
* Javier Segovia
* Accepted in 1.044
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
int v[500000];
int main(){
	int N,Q,kase=1;
	while (cin>>N>>Q && (N||Q)) {
		//vector<int> v(N);
		for (int i=0; i<N ; i++) {
			cin>>v[i];
		}
		sort(v,v+N);
		cout<<"CASE# "<<kase++<<":"<<endl;
		for (int i=0; i<Q; i++) {
			int qr,pos=0; cin>>qr;
			for (int j=0; j<N; j++) {
				if (v[j] == qr) {
					pos = j+1; break;
				}
			}
			if(!pos){
				cout<<qr<<" not found"<<endl;
			}
			else{
				cout<<qr<<" found at "<<pos<<endl;
			}
		}
	}
}