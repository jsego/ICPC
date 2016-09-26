/*
*  Javier Segovia
*  Accepted in 0.124
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

struct player {
	string name;
	int at,df;
	player():name(""),at(0),df(0){};
	player(string &n,int a,int b){name=n; at=a; df=b;}
	bool operator<(const player &p) const{
		return (at < p.at || 
				(at == p.at && (df>p.df ||
								(df == p.df && name>p.name))));
								
	}
};

player A[11];
string ata[6];
string def[6];

int main(){
	int kases=0; scanf("%d",&kases);kases++;
	for (int k=1; k<kases; k++) {
		string name; int at,df;
		for (int i=0; i<10; i++) {
			cin>>name>>at>>df;
			A[i] = player(name,at,df);
		}
		sort(A,A+10);
		printf("Case %d:\n",k);
		for (int i=0; i<5; i++) {
			ata[i] = A[i+5].name;
			def[i] = A[i].name;
		}
		sort(ata,ata+5);
		sort(def,def+5);
		cout<<"("<<ata[0];
		for (int i=1; i<5; i++) {
			cout<<", "<<ata[i];
		}cout<<")"<<endl;
		cout<<"("<<def[0];
		for (int i=1; i<5; i++) {
			cout<<", "<<def[i];
		}cout<<")"<<endl;
	}
}