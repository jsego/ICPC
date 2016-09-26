/*
 *  414.cpp
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
#include<climits>
using namespace std;

int main(){
	string s;
	while (getline(cin,s) && s!="0") {
		stringstream ss(s); 
		int N,min,sum=0,cant; ss>>N; min = INT_MAX;
		size_t posI,posL;
		for (int i=0; i<N ; i++) {
			getline(cin,s);
			posI = s.find_first_of(' ');
			posL = s.find_last_of(' ');
			if(posI == string::npos){min=0;continue;}
			cant = (int)(posL+1-posI);
			if(cant<min)min=cant;
			sum+=cant;
		}
		cout<<sum-(N*min)<<endl;
	}
}