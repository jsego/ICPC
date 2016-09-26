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
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
//string T[1002][1002];
//int A[1002][1002];
void dp(string &a,string &b,string &res){
	int R[300][2]; res="";
	for (int i=(int)'a'; i<=(int)'z'; i++) {
		R[i][0] = R[i][1] = 0;
	}
	for (int i=0; i<(int)a.LE; i++) {
		R[(int)a[i]][0]++;
	}
	for (int i=0; i<(int)b.LE; i++) {
		R[(int)b[i]][1]++;
	}
	int ac;
	for (int i=(int)'a'; i<=(int)'z'; i++) {
		ac = MIN(R[i][0],R[i][1]);
		string s(ac,(char)i);
		res+= s;
	}
}

int main(){
	string a,b;
	while (getline(cin,a) && getline(cin,b)) {
		string res;
		dp(a,b,res);
		//sort(res.begin(),res.end());
		cout<<res<<endl;
	}
}