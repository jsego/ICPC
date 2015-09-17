/*
*  Javier Segovia
*  0.016
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
	while (cin>>N ) {
		double ac,last; cin>>last;
		int total=1;
		for (int n=1; n<N ; n++) {
			cin>>ac;
			if(last+1.0 <= ac){
				last = ac;
				total++;
			}
		}
		cout<<total<<endl;
	}
}