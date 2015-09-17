/*
*  Javier Segovia
*  Accepted in 0.024
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

int p;

int rayCollision(string &s){
	int total=0; //cout<<"ENT: "<<p+1<<endl;
	int origen = p;
	for (int i=p+1; i<int(s.LE);) {
		if(s[i] == '/'){ 
			//cout<<"I: "<<i<<" P: "<<p<<endl; 
			total+=(i-origen); 
			p = i; 
			return total;
		}
		else if(s[i] == '\\'){
			p = i;
			total+=rayCollision(s);
			i = p+1;
		}
		else {// cout<<"I: "<<i<<endl;
			i++;
		}
	}
	p = int(s.LE);
	return total;	
}

int main(){
	int N; cin>>N;
	while (N--) {
		string s;
		cin>>s; //cout<<"S: "<<s<<endl;
		int total = 0;
		for (int i=0; i<int(s.LE); i++) {
			if (s[i]=='\\') {
				p = i;
				total += rayCollision(s);
				i = p;
			}
			//cout<<"TOTAL: "<<total<<endl;
		}
		cout<<total<<endl;
	}
}