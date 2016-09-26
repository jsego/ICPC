/*
*  Javier Segovia
*  Accepted in 0.016
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
int main(){
	int T; cin>>T;
	while (T--) {
		int h,m; char c;
		cin>>h>>c>>m;
		
		h = 12 - h;
		m = (60 - m)%60;
		if(m)h--;
		if(h<=0)h+=12;
		if(h<10)cout<<"0";
		cout<<h<<":";
		if(m<10)cout<<"0";
		cout<<m<<endl;
	}
}