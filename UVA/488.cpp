/*
 *  488.cpp
 *  
 *
 *  Created by Javier Segovia on 12/10/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 *	Accepted in 1.416
 */


#include <iostream>
#include<string>
#include<sstream>
#include<climits>
using namespace std;

int main(){
	int kases; cin>>kases;
	for(int k=0;k<kases;k++) {
		if(k)cout<<endl;
		int A,F; cin>>A>>F;
		for (int i=0; i<F; i++) {// cout<<i<<endl;
			if(i)cout<<endl;
			for (int j=1; j<=A; j++) {
				cout<<string(j,(j+'0'))<<endl;
			}
			for (int j=A-1; j>0; j--) {
				cout<<string(j,(j+'0'))<<endl;
			}
		}
		
	}
}