#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int P[1000000], T = 0;
bool IS[10000001];

//Sieve of Eratosthenes
void primes(){
	//for(int i=0;i<10000001;i+=2) IS[i] = false;
	for(int i=1;i<10000001;i+=2) IS[i] = true;
	IS[0] = IS[1] = false; IS[2] = true;
	P[T++] = 2;
	for(int i=3;i<10000001;i+=2){
		if(!IS[i]) continue;
		P[T++] = i;
		for(int j=i+i;j<10000001;j+=i) IS[j] = false;
	}
}

// Exponentiation O(log(e))
int fastExpo(int b,int e){
	long long res = 1, bb = b;
	int modu = 1000000007;
	while(e){
		if(e&1) res = (res*bb)%modu;
		e>>=1;
		bb = (bb*bb)%modu;
	}
	return (int)res;
}

int main(){
	primes();
	int N;
	while(cin>>N,N){
		long long res = 1;
		for(int t = 0; t < T && (P[t]*2 <= N); t++){
			long long p = P[t];
			int e = 0;
			while(p <= N){
				e += (N/p);
				p*=P[t];
			}
			//only even exponents of the prime number 
			//are allowed, it must be a perfect square
			e -= (e&1); 
			res = (res * fastExpo(P[t], e))%1000000007;
		}
		cout<<res<<endl;
	}
}
