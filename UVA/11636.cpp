/*
*  Javier Segovia
*  Accepted in 0.012
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
	int N,kases=1;
	while (cin>>N && N>=0) {
		int res=0;
		for (int i=1,cont=0; i<=N; i<<=1,cont++) {
			if (i == N ) {
				//cout<<"IGUAL"<<endl;
				res=cont; break;
			}
			else if(i&N){res=cont+1;}
		}
		printf("Case %d: %d\n",kases++,res);
	}
}