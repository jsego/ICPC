/*
*  Javier Segovia
*  Accepted in 0.026
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<set>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair

int main(){

	int N,M,C; 

	//Input of the number of test cases
	cin>>N;

	//Main loop
	while(N--){
		//Input of the maximum money to spend and number of garments
		cin>>M>>C;
		int p,a,lim;

		//Set of the possible values we can achieve
		set<int> res; 
		res.insert(0);

		//Loop over the types of garments
		for(int c=0;c<C;c++){
			//Input of the number of garments c
			cin>>p;
			set<int> aux;

			//For each new price of garment c
			//we add the value in the case
			//that it is smaller than the max
			//money we can spend
			for(int j=0;j<p;j++){
				cin>>a; 
				lim = M-a+1;
				for(set<int>::iterator it = res.begin();it!=res.end();it++){
					if(*it < lim) aux.insert((*it)+a);
				}
			}
			res = aux;
		}

		//If we can't reach any value there is no solution, otherwise we output the maximum value
		if(int(res.SL) == 0) cout<<"no solution"<<endl;
		else cout<<*(--res.end())<<endl;
	}
}
