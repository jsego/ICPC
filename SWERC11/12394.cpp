#include<iostream>
#include<string>
#include<algorithm>
#include<set>
using namespace std;

int R[1005];
bool OK[1005];
string I[1005];
int P[1005][6];

int main(){
	int K, N;
	while(cin>>K>>N, K||N){N++;
		for(int i=1;i<N;i++){ 
			R[i] = 0; OK[i] = true; 
			cin>>I[i];
			for(int j=0;j<K;j++) cin>>P[i][j];
		}

		for(int i=1;i<N;i++){
			set<int> s;
			for(int j=0;j<K;j++){
				R[P[i][j]]++;
				if(I[i] == I[P[i][j]]) OK[P[i][j]] = false;
				if(s.find(P[i][j]) != s.end()) OK[P[i][j]] = false;
				s.insert(P[i][j]);
			}
		}

		for(int i=1;i<N;i++) OK[i] = (OK[i] && (R[i]==K));

		int res = 0;
		for(int i=1;i<N;i++) res += (!OK[i]?1:0);
		if(res > 1) cout<<res<<" PROBLEMS FOUND"<<endl;
		else if(res == 1) cout<<"1 PROBLEM FOUND"<<endl;
		else cout<<"NO PROBLEMS FOUND"<<endl;
	}
}
