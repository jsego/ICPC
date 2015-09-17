/*
*  Javier Segovia
*  Accepted in 0.420
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
int A[18],N ;
bool ok[40]={false,
	false,true,true,false,true,false,true,false,false,false,
	true,false,true,false,false,false,true,false,true,false,
false,false,true,false,false,false,false,false,true,false,
true,false,false,false,false,false,true,false,false};
bool seen[18];

void recur(int p){
	if (p==N ) {
		if(!ok[A[p-1]+1]) return;
		cout<<1;
		for (int i=1; i<N  ; i++) {
			cout<<" "<<A[i];
		}cout<<endl; return;
	}
	for (int i=1; i<=N ; i++) {
		if (!seen[i] && ok[A[p-1]+i]) {
			A[p] = i; seen[i] = true;
			recur(p+1); seen[i] = false;
		}
	}
}

int main(){
	int kases=1; A[0] = 1; 
	bool first=true; 
	for(int i=0;i<18;i++) seen[i]=false; seen[1] = true;
	while (cin>>N ) { if(!first)cout<<endl; else first=false;
		cout<<"Case "<<kases++<<":"<<endl;		
		recur(1);
		//cout<<endl;
	}
}