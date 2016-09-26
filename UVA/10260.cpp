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
int main(){
	string s;
	int T[300];
	T[(int)'A']=T[(int)'E']=T[(int)'I']=T[(int)'O']=T[(int)'U']=T[(int)'H']=T[(int)'W']=T[(int)'Y']=0;
	T[(int)'B']=T[(int)'F']=T[(int)'P']=T[(int)'V']=1;
	T[(int)'C']=T[(int)'G']=T[(int)'J']=T[(int)'K']=T[(int)'Q']=T[(int)'S']=T[(int)'X']=T[(int)'Z']=2;
	T[(int)'D']=T[(int)'T']=3;
	T[(int)'L']=4;
	T[(int)'M']=T[(int)'N']=5;
	T[(int)'R']=6;
	while (cin>>s) {
		if(T[(int)s[0]])cout<<T[(int)s[0]];
		for (int i=1; i<(int)s.LE; i++) {
			if (T[(int)s[i]] && T[(int)s[i]]!=T[(int)s[i-1]]) {
				cout<<T[(int)s[i]];
			}
		}cout<<endl;
	}
}