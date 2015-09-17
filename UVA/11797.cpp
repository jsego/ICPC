/*
 *  Javier Segovia
 *  Accepted in 0.052
 */
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<list>
#include<cmath>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define MAX(a,b) ((a)>(b)?(a):(b))
int main(){
	int T; cin>>T;
	for (int i=1; i<=int(T); i++) {
		int M,N,k; string s,aux;
		cin>>M>>N>>s;
		list<string> l[5];
		map<string,int> c,p;
		p["Ja"] = 0; p["Sam"] = 1; p["Sha"] = 2;
		p["Sid"] = 3; p["Tan"] = 4;
		c["Ja"] = 0; c["Sam"] = 0; c["Sha"] = 0;
		c["Sid"] = 0; c["Tan"] = 0;
		for (int j=0; j<5; j++) {
			cin>>k;
			for (int q=0; q<k; q++) {
				cin>>aux; l[j].PB(aux);
			}
		}
		int q=0;
		while (q<N) {
			q += M;
			if(q>N){ c[s] += M -(q-N);}
			else c[s] += M;
			q+=2;
			aux = l[p[s]].front();
			l[p[s]].pop_front();
			l[p[s]].PB(aux);
			s = aux;
		}
		cout<<"Case "<<i<<":"<<endl;
		for (map<string,int>::iterator it = c.begin(); it!=c.end(); it++) {
			cout<<it->first<<" "<<it->second<<endl;
		}
	}
}