/*
*  Javier Segovia
*  Accepted in 0.224
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
	int N;
	scanf("%d",&N );
	bool first=false;
	while (N--) {
		if(first)cout<<endl;
		else first = true;
		int a,b;
		scanf("%d %d",&a,&b);
		string s = string(a-b,'0') + string(b,'1');
		cout<<s<<endl;
		while (next_permutation(s.begin(),s.end())) {
			cout<<s<<endl;
		}
	}
}