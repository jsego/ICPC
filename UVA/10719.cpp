/*
 *  Javier Segovia
 *  0.180
 */
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<sstream>
#include<algorithm>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
int K;
int P[10005];
int Q[10005];
int main(){
	//bool first=true;
	while (cin>>K) {
		K*=(-1);
		string s;
		getline(cin,s);
		getline(cin,s);
		istringstream iss(s);
		int pos=0;
		while(iss>>P[pos]){pos++;}
		Q[0] = P[0]; //cout<<"POS: "<<pos<<endl;
		for (int i=1; i<pos ; i++) {
			Q[i] = P[i] - (Q[i-1]*K);
		}
		//if(first)first=false;
		//else cout<<endl;
		cout<<"q(x):"; 
		for(int i=0;i+1<pos;i++) cout<<" "<<Q[i]; cout<<endl;
		cout<<"r = "<<Q[pos-1]<<endl;
		cout<<endl;
	}
}