#include<iostream>
#include<string>
#include<sstream>
using namespace std;

double S[10005];

int main(){
	string may = "The spider may fall!";
	string fall = "The spider is going to fall!";
	string line;
	while(getline(cin,line)){
		istringstream iss(line);
		int D,P,d=0, res = 0;
		iss>>D>>P;		
		while(iss>>S[d++]){} d--; 
		if(d < D) S[D] = P+1;//Reset last value
		if(d < D){
			//S[d-1] = x*S[d-2] + y*S[d-3];
			//S[d-2] = x*S[d-3] + y*S[d-4];
			double x=0.0, y=0.0;
			if(S[d-3]*S[d-3] != S[d-4]*S[d-2]){ //Calculate y if possible
				y = (double)(S[d-2]*S[d-2]-S[d-1]*S[d-3]) / 
					(double)(S[d-4]*S[d-2]-S[d-3]*S[d-3]);
			}
			if(S[d-2] != 0){ //Calculate x if possible
				x = (double)(S[d-1]-y*S[d-3])/(double)(S[d-2]);
			}
			if(x == 0.0 && y == 0.0){ //no dependence, only constants
				for(int i = d;i<D+2;i++){ 
					S[i] = S[i-1]; 
					if(S[i] > P){
						break;
					}
				}
			}
			else{
				for(int i = d;i<D+2;i++){ //linear dependency
					S[i] = x*S[i-1] + y*S[i-2]; 
					if(S[i] > P){ 
						break;
					}
				}
			}
		}
		res = -1;
		for(int i=0;i<D+1;i++){
			if(S[i] <= P) res++;
			else break;
		}
		if(res == -1) cout<<fall<<endl;
		else if(res == D && S[D] <= P) cout<<may<<endl;
		else cout<<D-res<<endl;
	}
	
}
