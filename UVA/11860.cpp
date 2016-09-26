/*
*  Javier Segovia
*  2.064
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<map>
#include<sstream>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define INF 2000000000

//int T[100005];

void breaking(string &s,vector<string> &vs,map<string,int> &se){
	string ac="";
	for (int i=0; i<int(s.LE); i++) {
		if(s[i]>='a' && s[i]<='z') ac.PB(s[i]);
		else if(ac != ""){ vs.PB(ac); se[ac]=0; //cout<<"AC: "<<ac<<endl; 
			ac="";}
	}
	if(ac!=""){ vs.PB(ac); se[ac] = 0;}
}

int main(){
	string s;
	int T; cin>>T;
	getline(cin,s);
	for(int k=1;k<=T;k++) {
		vector<string> vs;
		map<string,int> ses;
		while(getline(cin,s),s!="END"){
			breaking(s,vs,ses);
		}// BREAKING"<<endl;
		int p=-1,q=-1,dif=INF,tot=0;
		map<string,int>::iterator it;
		for (int i=0,j=0;;) {
			if(tot<int(ses.SL)){
				if(i>=int(vs.SL))break;
				it = ses.find(vs[i]); i++;
				if((it->second) == 0){tot++;}
				(it->second)++;
			}
			else {
				if(j>=int(vs.SL)) break;
				it = ses.find(vs[j]); j++;
				if((it->second) == 1){tot--;}
				(it->second)--;
			}
			if(tot == int(ses.SL)){
				if(i<dif+j+1){dif=i-j-1;p=j+1; q=i; }//cout<<"P: "<<p<<" Q: "<<q<<" DIF: "<<dif<<endl;}
			}
			//cout<<"I: "<<i<<" J: "<<j<< " TOT: "<<tot<<endl;
		}
		cout<<"Document "<<k<<": "<<p<<" "<<q<<endl;
	}
}