/*
*  Javier Segovia
*  Accepted in 0.008
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

int maxi;

bool connected[30][30];
bool seen[30];
int bfs[100];

int main(){
	int kases; cin>>kases;
	string s;
	getline(cin,s); getline(cin,s);
	bool first=false;
	while (kases--) {
		if(first)printf("\n");
		else first=true;
		getline(cin,s);
		maxi = int(s[0])-'A'+1;
		for (int i=0; i<maxi; i++) {
			seen[i] = false;
			for(int j=0;j<maxi;j++){
				connected[i][j] = false;
			}
		}
		while (getline(cin,s),int(s.LE)>0) {
			connected[s[0]-'A'][s[1]-'A'] = true;
			connected[s[1]-'A'][s[0]-'A'] = true;
		}
		int count=0,ac,tot,num;
		for (int i=0; i<maxi; i++) {
			if(!seen[i]){
				count++;
				ac=tot=0;
				bfs[tot++] = i;
				while (ac<tot) {
					num = bfs[ac++];
					for (int j=0; j<maxi; j++) {
						if(connected[num][j] && !seen[j]){
							seen[j] = true;
							bfs[tot++] = j;
						}
					}
				}
			}
		}
		printf("%d\n",count);
	}
}