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
#define X first
#define Y second
pair<int,char> A[300];
int main(){
	string s;
	while (getline(cin,s)) {
		for(int i=(int)'A',j=(int)'a';i<=(int)'Z';i++,j++) {
			A[i] = MP(0,i+'A'); A[j] = MP(0,j+'a');
		}
		int max=0;
		for (int i=0; i<(int)s.LE; i++) {
			if(s[i]>='A' && s[i]<='Z'){
				A[(int)s[i]].X ++;
			}
			else if(s[i]>='a' && s[i]<='z'){
				A[(int)s[i]].X++;
			}
			if(A[(int)s[i]].X > max) max = A[(int)s[i]].X;
		}
		for (char i='A'; i<='Z'; i++) {
			if(A[(int)i].X == max) cout<<i;
		}
		for (char i='a'; i<='z'; i++) {
			if(A[(int)i].X == max) cout<<i;
		}cout<<" "<<max<<endl;
	}
}