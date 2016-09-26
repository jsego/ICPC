/*
*  Javier Segovia
*  Accepted in 0.224
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<set>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
int A[1000001],B[1000001];//A == team; 
int T[1001][1001],TC[1001],TA[1001],TF[1001];
int main(){
	int n,kases=1,ac,cant; string s;
	while (cin>>n && n ) {
		cout<<"Scenario #"<<kases++<<endl;
		vector<int> cues;
		int team;
		for (int k=0; k<n ; k++) {
			cin>> cant; TC[k] = TA[k] = TF[k] = 0;
			for (int cc=0; cc<cant; cc++) {
				cin>>ac;
				A[ac] = k; B[ac] = 0;
			}
		}
		while (cin>>s && s[0]!='S') {
			if (s[0]=='D') {
				if((int)cues.SL > 0){
					team = cues[0];
					cout<<T[team][TA[team]]<<endl;
					B[T[team][TA[team]]]--;
					if(!B[T[team][TA[team]]]){
						if(TA[team]!=1000) TA[team]++;
						else TA[team] = 0;
					}
					TC[team]--;
					if (!TC[team]) {
						cues.erase(cues.begin()); 
						TA[team] = TF[team] = 0;
					}
				}
			}
			else {
				cin>>ac;
				team = A[ac];
				if(!TC[team]){
					cues.PB(team);
				}
				TC[team]++;
				T[team][TF[team]] = ac;
				B[ac]++;
				if(B[ac] == 1){
					if (TF[team] != 1000) {
						TF[team]++;
					}
					else {
						TF[team] = 0;
					}				
				}
			}
		}
		cout<<endl;		   
	}
}