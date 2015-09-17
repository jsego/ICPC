/*
 *  10300.cpp
 *
 *  Created by Javier Segovia on 10/10/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 *	Accepted in 0.004
 */

#include <iostream>
using namespace std;
int main(){
	int kases;
	cin>>kases;
	while (kases--) {
		int a,b,nums,sum = 0;
		cin>>nums;
		while (nums--) {
			cin>>a>>b>>b;
			sum+=(a*b);
		}
		cout << sum <<endl;;
	}
}
