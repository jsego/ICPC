/*
 *  489.cpp
 *  
 *
 *  Created by Javier Segovia on 12/10/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 *	Accepted in 0.760
 */


#include <iostream>
#include<string>
#include<sstream>
#include<climits>
using namespace std;

bool N[500],G[500];

int main(){
	int kases;
	while(cin>>kases && kases!=-1){
		for(int i='a';i<='z';i++){ N[i] = G[i] = false;}
		string need,got; cin>>need>>got;
		int incor=0,cor=0,tot=0;
		bool win = false,lose = false;
		for(int i=0;i<(int)need.length();i++){ 
			if(N[(int)need[i]])continue;
			N[(int)need[i]]=true;
			tot++;
		}
		for (int j=0; j<(int)got.length(); j++) {
			if(G[(int)got[j]])continue;
			else if(N[(int)got[j]]){
				G[(int)got[j]] = true; cor++;
				if(!lose && cor == tot)win=true;
				continue;
			}
			G[(int)got[j]] = true; 
			incor++;
			if(!win && incor >=7) lose = true;
		}
		cout<<"Round "<<kases<<endl;
		if (win) {
			cout<<"You win."<<endl;
		}
		else if(lose){
			cout<<"You lose."<<endl;
		}
		else{
			cout<<"You chickened out."<<endl;
		}
	}
}