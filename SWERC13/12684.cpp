// G - VivoParc

#include<bits/stdc++.h>
using namespace std;
#define LE length()
#define SL size()
#define PB push_back
#define MP make_pair

int N;
int A[105];
int C[16];
set<int> D[105];
int T[105];

int calculate_collisions(){
	int res = 0;
	for(int i=1;i<=N;i++){
		for(set<int>::iterator it = D[i].begin(); it != D[i].end();it++){
			res += (A[i] == A[*it]?1:0);		
		}	
	}
	return res;
}

int main(){
	string s;
	bool first = true;
	while(cin>>N){getline(cin,s);
		if(first)first=false;
		else cout<<endl;
		for(int i=0;i<=N;i++){ A[i] = 15; D[i].clear(); T[i] = 0;}
		int a,b;
		char c;
		while(getline(cin,s) && int(s.LE) > 0){
			istringstream iss(s);
			iss>>a>>c>>b;
			D[a].insert(b); D[b].insert(a);
		}
		for(int i=1;i<=N;i++) A[i] = (rand()%4)+1;
		int collisions = calculate_collisions(),current_col;
		int v, counter = 5;
		while(collisions > 0){
			for(int i=1;i<=N;i++){
				v = A[i]; 
				A[i] = (rand()%4) + 1;
				current_col = calculate_collisions();
				if(current_col < collisions){ collisions = current_col; counter=5; }
				else A[i] = v;
			}
			--counter;
			if(counter == 0){
				for(int i=1;i<=N;i++) A[i] = (rand()%4)+1; // reset
				collisions = calculate_collisions();
			} 
				
		}
		for(int i=1;i<=N;i++) cout<<i<<" "<<A[i]<<'\n';
	}
}

