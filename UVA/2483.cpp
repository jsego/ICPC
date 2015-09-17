/*
*  Javier Segovia
*  0.016
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

int main(){
	string s,cost;
	int kases=1;
	int a,b,ac;
	while (getline(cin,s),s!="#") {
		if(s[0] == 'C'){
			cout<<"Set "<<kases<<endl;
			kases++;
			istringstream iss(s);
			iss>>cost>>a>>b;
		}
		else {
			istringstream iss(s);
			iss>>ac;
			int total=0;
			while (ac) {
				if(ac&1) total+=b;
				else total+=a;
				ac>>=1;
			}
			cout<<total<<endl;
		}

	}
}