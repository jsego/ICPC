/*
*  Javier Segovia
*  Accepted in 0.048
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
	int N; cin>>N;
	while (N--) {
		short s,ac;
		short t1=0,t2=0;
		for (int i=0; i<4; i++) {
			cin>>s;
			t1+=(s/100)%10; t1+=(s%10);
			ac = s/1000; ac<<=1; t2+=(ac/10)+(ac%10);
			ac = (s/10)%10; ac<<=1; t2+=(ac/10)+(ac%10);
		}
		t1+=t2;
		if ( (t1%10) == 0) {
			cout<<"Valid"<<endl;
		}
		else {
			cout<<"Invalid"<<endl;
		}

	}
}