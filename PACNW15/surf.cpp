#include <bits/stdc++.h>

using namespace std;

#define SIZE 1000001
long long FUN[SIZE];
long long WAIT[SIZE];

int main(){
	int N; 
	while(cin >> N){
		memset(FUN, 0, SIZE*sizeof(long long));
		memset(WAIT, 0, SIZE*sizeof(long long));
		int minute, fun, wait, max_minute = 0;
		for(int i=0; i < N; i++){
			cin >> minute >> fun >> wait;
			FUN[minute] = fun;
			WAIT[minute] = wait;
			max_minute = max(max_minute, minute);
		}
		
		long long future_fun;
		for(int m = max_minute - 1; m>0; --m){
			if(WAIT[m]){ // inpute wave
				future_fun = ((m+WAIT[m])>=SIZE?0:FUN[m+WAIT[m]]);
				FUN[m] = max(FUN[m+1], FUN[m]+future_fun);
			}
			else{ // no wave
				FUN[m] = FUN[m+1];
			}
		}
		cout << FUN[1] << "\n";
	}
}
