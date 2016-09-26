/*
*  Javier Segovia
*  0.016
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

int main(){
	int N;
	while(cin>>N){
		
		string resname,acname;
		int respro=0,respen=2000000000;
		int pro,pen,ao,ae;
		
		for (int i=0; i<N  ; i++) {
			cin>>acname;
			pro = 0;
			pen = 0;
			
			for (int j=0; j<4; j++) {
				cin>>ao>>ae;
				if(ae>0){
					pro++; 
					pen+=(ae + (ao-1)*20);
				}
			}
			
			if(pro>respro || (pro == respro && pen<respen)){
				respro=pro;
				respen=pen; 
				resname=acname;
			}
			
		//	cout<<acname<< " "<<pro<<" "<<pen<<endl;
		}
		cout<<resname<<" "<<respro<<" "<<respen<<endl;
	}
}