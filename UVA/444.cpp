/*
*  Javier Segovia
*  Accepted in 0.008
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
	string E[300];
	char D[300];// int ac;
	for (int i='A',j='a'; i<='Z'; i++,j++) {
		ostringstream os1,os2; os1<<i; os2<<j;
		E[i] = os1.str(); E[j] = os2.str();
		reverse(E[i].begin(),E[i].end());
		reverse(E[j].begin(),E[j].end());
		/*
		D[E[i]] = (char)i;
		D[E[j]] = (char)j;*/
	}
	E[32] = "23"; D[23] = ' ';
	E[33] = "33"; D[33] = '!';
	E[44] = "44"; D[44] = ',';
	E[46] = "64"; D[64] = '.';
	E[58] = "85"; D[85] = ':';
	E[59] = "95"; D[95] = ';';
	E[63] = "36"; D[36] = '?';
	string s;
	while (getline(cin,s)) {
		bool isNum = (s[0]>='0' && s[0]<='9');
		if (isNum) {
			for (int i=(int)s.LE-2; i>=0; i-=2) {
				int n=(s[i+1]-'0')*10 + s[i]-'0';
				if(n<20 && i>0){
					n=(n*10)+(s[i-1]-'0'); i--;
				}
				printf("%c",(char)n);
			}printf("\n");
		}
		else {
			for (int i=(int)s.LE-1; i>=0; i--) {
				cout<<E[(int)s[i]];
			}printf("\n");
		}

	}
}