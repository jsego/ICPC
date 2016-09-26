/*
*  Javier Segovia
*  Accepted in 0.004
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
int main(){
	string s;
	while (getline(cin,s)) {
		int last=0;
		size_t f = s.find(' ');
		while(f != string::npos){
			reverse(s.begin()+last,s.begin()+f);
			last=(int)f+1;
			f = s.find(' ',last);
		}
		if (last<(int)s.LE) {
			reverse(s.begin()+last,s.end());
		}
		cout<<s<<endl;
	}
}