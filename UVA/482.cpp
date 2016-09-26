/*
*  Javier Segovia
*  Accepted in 0.084
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<sstream>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define MAX(a,b) ((a)>(b)?(a):(b))
string A[4000000];
int main(){
	string s;
	int kases;
	getline(cin,s); stringstream sa(s); sa>>kases;
	getline(cin,s);
	for (int k=0; k<kases; k++) {
		if(k)cout<<endl;
		getline(cin,s);
		stringstream ss(s);
		getline(cin,s);
		istringstream sb(s);
		int ac,max=-1;
		while(ss>>ac) { max = MAX(max,ac);
			sb>>A[ac];
		}max++; 
		for (int i=1; i<max; i++) {
			cout<<A[i]<<endl;
		} 
		getline(cin,s);
	}
}