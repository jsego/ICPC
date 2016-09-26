/*
*  Javier Segovia
*  Accepted in 0.036
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
	int r,n,kases=1;
	while (cin>>r>>n && (r||n)) {
		int div = r/n - (r%n==0?1:0);
		cout<<"Case "<<kases++<<": ";
		if (div>26) {
			cout<<"impossible"<<endl;
		}
		else {
			cout<<div<<endl;
		}

	}
}