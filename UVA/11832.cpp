/*
 *  Javier Segovia
 *  Accepted in 0.244
 */
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair

set<int> A[42];
int B[42];

int main(){
	int N,F;
	A[0].insert(0);
	while (cin>>N>>F, N||F) {
		string res="";
		int ac;
		
		for (int i=1;i<=N ; i++) {
			cin>>B[i]; A[i].clear();
		}
		
		
		for (int i=1; i<N ; i++) {
			ac=B[i];
			for (set<int>::iterator it = A[i-1].begin(); it!=A[i-1].end(); it++) {
				A[i].insert((*it)+ac);
				A[i].insert((*it)-ac);
			}
		}
		
		
		set<int> search;
		bool minus,plus;
		
		search.insert(F);
		
		for (int i=N ; i>0; i--) {
			minus=plus=false;
			set<int> s2;
			for (set<int>::iterator it=search.begin(); it!=search.end(); it++) {
				if( A[i-1].find((*it)+B[i]) != A[i-1].end()){
					minus = true;
					s2.insert((*it)+B[i]);
				}
				if( A[i-1].find((*it)-B[i]) != A[i-1].end()){
					plus = true;
					s2.insert((*it)-B[i]);
				}
			}
			swap(search,s2);
			if(minus && plus) res.PB('?');
			else if(minus) res.PB('-');
			else if(plus) res.PB('+');
			else{res="*"; break;}
		}
		
		reverse(res.begin(),res.end());
		cout<<res<<endl;
		
	}
}