/*
*  Javier Segovia
*  Accepted in 0.080
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
int main(){
	int B,V;
	string A[205];
	int T[205];
	while (cin>>B>>V) {
		map<string,unsigned long long> M;
		string s;
		for (int i=0; i<V; i++) {
			cin>>A[i]>>T[i];
		}
		for (int i=0; i<V; i++) {
			unsigned long long ac=0;
			for (int j=0; j<T[i]; j++) {
				cin>>s;
				for (int k=0; k<(int)s.LE; k++) {
					ac<<=1;
					if (s[k]=='1') {
						ac|=1;
					}
				}
			}
			M[A[i]] = ac;
		}
		int Q; cin>>Q;
		map<string,unsigned long long>::iterator it;
		for (int q=0; q<Q; q++) {
			cin>>s;
			cout<<s<<"=";
			it = M.find(s);
			if (it != M.end()) {
				cout<<it->second<<endl;
			}
			else {
				cout<<endl;
			}

		}
	}
}