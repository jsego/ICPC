/*
 *  494.cpp
 *  
 *
 *  Created by Javier Segovia on 12/10/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 *	Accepted in 0.008
 */


#include <iostream>
#include<string>
#include<sstream>
using namespace std;
bool isLet(char c){
	if(c>='a' && c<='z' || c<='Z' && c>='A') return true;
	return false;
}
int main(){
	string s;
	while (getline(cin,s)) {
		int cont=0; bool last=false,ac;
		if(isLet(s[0])){cont++; last = true;}
		for (int i=1; i<(int)s.length(); i++) {
			ac = isLet(s[i]);
			if(ac && !last) cont++;
			last = ac;
		}
		cout<<cont<<endl;
	}
}