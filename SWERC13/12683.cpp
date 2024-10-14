// F - Odd and Even Zeroes

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

#define PB push_back
#define LE length()

long long T[26][2];
long long NUM[26];

int main(){
	NUM[0] = 1; for(int i=1;i<26;i++) NUM[i] = NUM[i-1]*5;
	T[0][0] = 1; T[0][1] = 0;
	for(int i=1;i<26;i++){
		if(i&1){
			T[i][0] = T[i-1][0]*5;
			T[i][1] = T[i-1][1]*5;
		}
		else{
			T[i][0] = T[i-1][1]*2 + T[i-1][0]*3;
			T[i][1] = T[i-1][1]*3 + T[i-1][0]*2;
		}
	}
	long long n;
	while(cin>>n, n != -1){
		long long on = 0;
		long long res = 0;
		int c;
		int p = 0;
		for(int i=25;i>0;i--){
			while(on + NUM[i] <= n){
				on += NUM[i]; 
				res += T[i][p&1];
				if(i&1) p = (p+1)&1;
			}
		}
		if(p == 0) res += (n+1-on);
		cout<<res<<endl;
	}

}
