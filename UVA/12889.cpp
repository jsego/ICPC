#include<iostream>
using namespace std;

int main(){
	int kases; cin>>kases;
	while(kases--){
		int p; cin>>p;
		int s1,s2; cin>>s1; p--;
		bool win = false;	
		while(p--){
			cin>>s2;
			if(s2 != s1) 
				win = true;
		}
		if(win) cout<<"Happy Birthday Tutu!"<<endl;
		else cout<<"Better luck next time!"<<endl;
	}
}
