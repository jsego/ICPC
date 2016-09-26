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
#define X first
#define Y second
pair<int,int> A[300];
int main(){
	string s; bool first=true;
	while (getline(cin,s)) {
		if(!first)cout<<endl;
		else first=false;
		for(int i=32;i<129;i++) A[i] = MP(0,-i);
		for (int i=0; i<(int)s.LE; i++) {
			A[(int)s[i]].X ++;
		}
		sort(A+32,A+129);
		int i=32;
		while (!A[i].X) {
			i++;
		}
		for (; i<=128; i++) {
			cout<<-A[i].Y<<" "<<A[i].X<<endl;
		}
	}
}