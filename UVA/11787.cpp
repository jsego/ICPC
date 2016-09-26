/*
*  Javier Segovia
*  Accepted in 0.008
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

char A[7] = {'B', 'U', 'S', 'P', 'F', 'T', 'M'};
int C[300];
int P[300];

bool check(string &s){
	for(int i=0;i<7;i++) C[int(A[i])] = 0;
	for (int i=0; i<int(s.SL); i++) {
		if(C[int(s[i])] == 9){return false;}
		if( i && P[int(s[i])]>P[int(s[i-1])]){return false;}
		C[int(s[i])]++;
	}
	return true;
}

string convert(string &s){
	string res = "0000000";
	for (int i=0; i<7; i++) {
		res[i] = C[int(A[6-i])]+'0';
	}
	while (res.SL > size_t(1) && res[0] == '0') {
		res.erase(res.begin());
	}
	return res;
}

int main(){
	for (int i=0; i<7; i++) {
		P[int(A[i])] = i;
	}
	int N; cin>>N;
	string s;
	while (N--) {
		cin>>s; //cout<<s<<endl;
		if(!check(s)){ 
			reverse(s.begin(),s.end());
			if(!check(s)){
				cout<<"error"<<endl; 
				continue;
			}	
		}
		cout<<convert(s)<<endl;
	}
}