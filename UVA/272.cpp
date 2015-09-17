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
	string s;
	bool last=false;
	while(getline(cin,s)){
		for (size_t pos=0; pos<s.LE; pos++) {
			if (s[pos]=='"') {
				if(!last) cout<<"``";
				else cout<<"''";
				last = !last;
			}
			else {
				cout<<s[pos];
			}
		}
		cout<<endl;
	}
}