/*
*	Javier Segovia
*	Accepted in 0.080
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<set>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
int main(){
	int Z,I,M,L,kase=1;
	while (cin>>Z>>I>>M>>L && (Z || I || M || L) ) {
		long long first = (((Z*L)+I)%M), ac,last;
		last = first;
		//int count=0;
		set<long long> S; //S.insert(last);
		//cout<<"CAPT: "<<Z<< " "<<L <<" "<<I<<" "<<M<<endl;
		do {
			S.insert(last);
			ac = (((last*Z)+I)%M);
			//cout<< ac<<endl;
			last = ac;
			//count++;
		} while (S.find(ac) == S.end());
		cout<<"Case "<<kase++<<": "<<S.size()<<endl;
	}
}