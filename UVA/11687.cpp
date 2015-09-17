/*
*  Javier Segovia
*  Accepted in 0.072
*/
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<cmath>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair

int digits(int a){
	if(a<10)return 1;
	if(a<100)return 2;
	if(a<1000)return 3;
	if(a<10000) return 4;
	if(a<100000) return 5;
	if(a<1000000) return 6;
	return 7;
}

int main(){
	string s;
	while (cin>>s && s!="END") {
		int x = 0,cont=1,ac=(int)s.LE;
		if(s=="1"){cout<<1<<endl; continue;}
		while(ac != x){
			x = ac;
			ac = digits(ac);
			cont++;
		}
		cout<<cont<<endl;
	}
}