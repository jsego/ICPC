/*
*  Javier Segovia
*  Accepted in 0.016
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<sstream>
#include<list>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
int A[35],B[35];
int x=1;

bool noFinish(){
	for (int i=1; i<x; i++) {
		if(A[i] != B[i]) return true;
	}
	return false;
}

void swapi(int i){
	int last = x-1;
	while (i<last) {
		swap(A[i],A[last]);
		i++; last--;
	}
}
int main(){
	string s;
	while (getline(cin,s)) {
		stringstream ss(s); x=1; cout<<s<<endl;
		while (ss>>A[x]){	B[x] = A[x]; x++;}
		sort(B,B+x); 
		int last = x-1,ini=1;
		while (ini<last) {
			swap(B[ini],B[last]);
			ini++; last--;
		}
		swapi(1);
		list<int> l;
		int ac=B[1],ind=1; bool first=true;
		while (noFinish()&&ac) {
			for (int i=1; i<x; i++) {
				if (A[i]==ac) {
					if(ind==i){ac=B[++ind]; break;}
					else{
						if(i+1<x){
							l.PB(i);
							swapi(i);
						}
						l.PB(ind);
						swapi(ind);
						ac=B[++ind];
						break;
					}
				}
			}
		}
		
		while ((int)l.SL>0) {
			if(!first){cout<<" ";}
			else{first=false;}
			cout<<l.front(); l.pop_front();
		}
		if(first)cout<<0<<endl;
		else cout<<" 0"<<endl;
	}
}