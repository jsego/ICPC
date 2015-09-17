/*
 *  116.cpp
 *  Created by Javier Segovia on 10/10/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *	Accepted in 1.312
 */

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<climits>
#include<sstream>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
int A[200][200],B[200][200];//,listi[200];
string from[200][200];

string conv(int a){
	ostringstream os; 
	os<< a;
	//cout<< "Enter: "<<a <<" OUT: "<<os.str()<<endl;
	return os.str();
}

bool comp(string &a,string &b){
	stringstream ssA(a),ssB(b);
	int ia,ib;
	while(ssA>>ia && ssB>>ib){
		if(ia<ib) return true;
		else if(ib<ia) return false;
	}
	return false;
}

int main(){
	int F,C;
	while(cin>>F>>C){
		for(int i=0;i<F;i++)for(int j=0;j<C;j++){
			cin>> A[i][j];
			B[i][j] = 0;
			from[i][j] = "";
		}
		for(int i=0;i<F;i++){
			B[i][0] = A[i][0];
			from[i][0] = conv(i+1);
		}
		int a1,a2,a3,acX; 
		long long res=0;
		for(int j=1;j<C;j++){
			for (int i=0; i<F; i++) {
				B[i][j] = A[i][j];
				if(i>0) a1 = i-1;
				else a1 = F-1;
				a2 = i;
				if(i+1 == F) a3 = 0;
				else a3 = i+1;
				res = B[a1][j-1]; acX = a1;
				if(B[a2][j-1] < res || (B[a2][j-1]==res && comp(from[a2][j-1],from[acX][j-1]) ) ){
					res = B[a2][j-1];
					acX = a2;
				}
				if(B[a3][j-1] < res || (B[a3][j-1]==res && comp(from[a3][j-1],from[acX][j-1]) ) ){
					res = B[a3][j-1];
					acX = a3;
				}				
				B[i][j]+=res;
				from[i][j] = from[acX][j-1]+" "+conv(i+1);
			}
		}
		int min = INT_MAX;
		int pos=-1;
		for(int i=0;i<F;i++){
			//cout<<"FROM "<<i<<": "<<from[i][C-1]<<endl;
			if(B[i][C-1] < min){
				min = B[i][C-1];
				pos = i;
			}
			else if(B[i][C-1] == min && comp(from[i][C-1],from[pos][C-1]) ){
				pos = i;
			}
		}//cout<<"POS:"<<pos<<endl;
		cout<< from[pos][C-1] <<endl;
		cout<<min<<endl;
	}
}