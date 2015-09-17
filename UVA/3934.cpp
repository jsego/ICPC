#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
int main(){
	int A,D;
	while(cin>>A>>D && (A||D)){
		int a=INT_MAX,ac,l1=INT_MAX,l2=INT_MAX;
		for (int i=0; i<A; i++) {
			cin>>ac;
			if (ac<a) {
				a=ac;
			}
		}
		for (int i=0; i<D; i++) {
			cin>>ac;
			if (ac<=l1) {
				l2 = l1; l1 = ac;
			}
			else if(ac<l2) l2 = ac;
		}
		if (a<l2) {
			cout<<"Y"<<endl;
		}
		else {
			cout<<"N"<<endl;
		}

	}
}