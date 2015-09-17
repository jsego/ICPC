/*
 *  490.cpp
 *  
 *
 *  Created by Javier Segovia on 12/10/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 *	Accepted in 0.012
 */


#include <iostream>
#include<string>
#include<sstream>
#define MAX(a,b) ((a)>(b)?(a):(b))
using namespace std;
string T[105];
int main(){
	string s;
	int cont=0,max=0;
	while( getline(cin,T[cont]) ) {cont++; max = MAX(max,(int)T[cont-1].length()); }//cout<<cont<<endl;}
	//for(int i=0;i<cont;i++) cout<<T[i]<<endl;
	for (int i=0; i<max; i++) {
		for(int j=cont-1;j>=0;j--){
			//cout<<j<<" "<<i<<endl;
			if(i < (int)T[j].length()){
				//cout<<j<<" "<<i<<endl;
				cout<<T[j][i];
			}
			else cout<<" ";
		}cout<<endl;
	}
}