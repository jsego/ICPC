/*
 *  458.cpp
 *
 *  Created by Javier Segovia on 10/10/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 *	Accepted in 0.108
 */

#include <iostream>
#include<string>
using namespace std;
int main(){
	string s;
	while (getline(cin,s)) {
		for(int i=0;i<(int)s.length();i++)s[i]-=7;
		cout<<s<<endl;
	}
}
