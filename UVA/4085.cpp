#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair

string calc(string &a){
	string res=a;
	int ac=res[(int)a.LE-1]-'0';
	int carry=0;
	for (int i=(int)a.LE-2; i>=0; i--) {
		res[i]=a[i]-carry-ac;
		if (res[i]<'0') {
			res[i]+=10;
			carry=1;
		}
		else {
			carry=0;
		}

		ac=res[i]-'0';
	}
	if (res[0]=='0') {
		return "IMPOSSIBLE";
	}
	return res;
}

int main(){
	string s;
	int kases=1;
	while (cin>>s && s!="0") {
		cout<<kases++<<". "<<calc(s)<<endl;
	}
}