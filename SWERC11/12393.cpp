#include<iostream>
#include<algorithm>
using namespace std;
int V[1000005];
int AL[1000005];
int ML[1000005];
int MR[1000005];
int T;
int main(){
	int N;
	while(cin>>N,N){
		// Store the acumulated and min from left to right
		cin>>V[0]; 
		AL[0] = V[0]; 
		ML[0] = V[0]; 
		for(int i=1;i<N;i++){
			cin>>V[i]; 
			AL[i] = AL[i-1] + V[i];
			ML[i] = min(ML[i-1],AL[i]);			
		}
		T = AL[N-1]; //total acumulated
		//save from right to left if there are 
		//negative sequences of numbers
		MR[N-1] = min(0,V[N-1]);
		for(int i = N-2;i>=0;i--){
			MR[i] = min(0, MR[i+1]+V[i]);
		}
		//check each case if there are not negative
		//sequences of numbers from i-th position to
		//the right and checks also if there are not
		//negatives acumulated to the left, in the 
		//case that there are negatives to the left
		//the sum of the values must be higher than
		//the absolute value of the min left
		int res = 0;
		if(ML[N-1] >= 0) res++;
		for(int i = 1; i < N; i++){
			if(MR[i] >= 0){
				if(ML[i-1] >= 0) res++;
				else if(T - AL[i-1] >= -ML[i-1]) res++;
			}
		}
		cout<<res<<endl;
	}
}
