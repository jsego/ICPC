/*
*  Javier Segovia
*  Accepted in 0.032
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
	vector<int> v;
	map<int,int> M;
	map<int,int>::iterator it;
	int N;
	while (cin>>N) {
		it = M.find(N);
		if (it == M.end()) {
			v.PB(N); M[N] = 1;
		}
		else {
			(it->second)++;
		}
	}
	for (int i=0; i<(int)v.SL; i++) {
		cout<<v[i]<<" "<<M[v[i]]<<endl;
	}
}