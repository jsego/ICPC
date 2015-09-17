/*
*  Javier Segovia
*  Accepted in 0.016
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<map>
#include<set>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define EPSILON 0.000000001
#define MAX(a,b) ((a)>(b)?(a):(b))
int main(){
	int N;
	string s,country,love;
	while (scanf("%d",&N)==1) {
		getline(cin,s);
		map<string,set<string> > MS;
		for (int i=0; i<N ; i++) {
			getline(cin,s);
			size_t pos = s.find_first_of(' ');
			country = s.substr(0,pos);
			love = s.substr(pos+1);
			(MS[country]).insert(love);
		}
		for (map<string,set<string> >::iterator it=MS.begin(); it!=MS.end(); it++) {
			cout<<(it->first)<<" "<<(it->second).SL<<endl;
		}
	}
}