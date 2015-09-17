/*
*  Javier Segovia
*  Accepted in 0.668
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
int main(){
	int kases; cin>>kases;
	while (kases--) {
		string s; cin>>s;
		sort(s.begin(),s.end());
		do {
			cout<<s<<endl;
		} while (next_permutation(s.begin(),s.end()));
		cout<<endl;
	}
}