/*
*  Javier Segovia
*  Accepted in 0.152
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<sstream>
#include<climits>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
int A[2000000],B[2000000];
int main(){
	string s; int ac;
	while (getline(cin,s)) {
		stringstream ss(s);
		int pos=0;
		bool ok=true;
		while (ss>>ac) {
			if(ac<0){
				A[pos] = ac; B[pos] = ac;
				if (pos) {
					A[pos-1]-=ac;
					if(A[pos-1]>=0){ok=false;break;}
				}
				pos++;
			}
			else {
				//cout<<pos<<endl;
				if (pos) {
					if (ac!=B[pos-1]*-1) {
						ok=false; break;
					}
				}
				else {
					ok=false; break;
				}
				pos--;
			}
		}
		if(ok && !pos) printf(":-) Matrioshka!\n");
		else printf(":-( Try again.\n");
	}
}