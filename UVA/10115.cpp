/*
*  Javier Segovia
*  Accepted in 0.008
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
string R[10][2];
string orig,rule;
int main(){
	int n;
	string s;
	while (cin>>n && n) { getline(cin,s);
		for (int i=0; i<n; i++) {
			getline(cin,R[i][0]);
			getline(cin,R[i][1]);
		}
		getline(cin,orig);
		for (int i=0; i<n ; i++) {
			rule = R[i][0];
			for (int j=0; size_t(j)+rule.SL<=orig.SL; j++) {
				if(orig.substr(j,rule.SL) == rule){
					orig.replace(j,int(rule.SL),R[i][1]);
					j--;
				}
			}
		}
		cout<<orig<<endl;
	}
	
}