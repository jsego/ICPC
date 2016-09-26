/*
*  Javier Segovia
*  0.016
*/
#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
int main(){
	int kases;
	scanf("%d",&kases);
	string s;
	while (kases--) {
		cin>>s;
		int val=0;
		for (int i=0; i<int(s.LE); i++) {
			val+= MIN(s[i]-'A','Z'-s[i]+1);
		}
		
		int maxi=INT_MAX,t1,t2;
		size_t lasti = s.find_last_not_of('A');
		size_t firsti = s.find_first_not_of('A',1);
		if(lasti != string::npos) maxi = int(lasti);
		//cout<<maxi<<endl;
		if(firsti != string::npos) maxi = MIN(maxi,int(s.LE-firsti));
		//cout<<maxi<<endl;
		
		if(s.LE > size_t(1)){
			firsti = s.find_first_not_of('A',1);
			while((lasti = s.find_first_not_of('A',firsti+1))!=string::npos){
				//cout<<firsti<<" "<<lasti<<endl;
				t1 = int(firsti);
				t2 = int(s.LE - lasti);
				maxi = MIN(maxi,MIN(t1*2+t2,t1+t2*2));
				firsti = lasti;
				//cout<<maxi<<endl;
			}
		}
		if(maxi != INT_MAX) val+=maxi;
		//cout<<maxi<<endl;
		printf("%d\n",val);
	}
}