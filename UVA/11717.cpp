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
	int kases; cin>>kases;
	for (int k=1; k<=kases; k++) {
		int N,I,K,ac;
		cin>>N>>I>>K;
		int lastActive = 0,totIn=0,totDrop=0;
		for (int i=0; i<N ; i++) {
			cin>>ac;
			if (lastActive+I<=ac) {
				totIn++;
				lastActive = ac+K;
			}
			else if(ac < lastActive){
				totDrop++;
			}
			else {
				lastActive = ac;
			}
		}
		cout<<"Case "<<k<<": "<<totIn<<" "<<totDrop<<endl;
	}
}