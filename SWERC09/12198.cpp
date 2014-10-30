#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){
	int N;
	bool first = true;
	while(cin>>N, N){
		if(first)first=false;
		else cout<<endl;		
		string action;
		int d,d1 = 0, d2 = 0;
		for(int i=0;i<N;i++){
			cin>>action>>d;
			if(action[0] == 'D'){ //DROP							
				cout<<"DROP 1 "<<d<<endl;
				d1 += d; 
			}
			else{ //TAKE
				if(d2 >= d){
					cout<<"TAKE 2 "<<d<<endl;
					d2 -= d;
				}
				else{
					if(d2 > 0) cout<<"TAKE 2 "<<d2<<endl;
					cout<<"MOVE 1->2 "<<d1<<endl;
					cout<<"TAKE 2 "<<(d-d2)<<endl;
					d2 = d1-(d-d2); d1 = 0;
				}
			}
		}
	}
}
