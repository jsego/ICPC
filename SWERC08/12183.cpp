#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, S, L, R, X, modu;

long long multiply(vector<long long> &a, vector<long long> &b, int shift){
	long long res = 0;
	for(int j = 0;j<N;j++){
		res = (res + a[(shift+N-j)%N] * b[j])%modu;
	}
	return res;
}

vector<long long> expo(vector<long long> &v){
	vector<long long> res(N, 0); res[0] = 1;
	vector<long long> base(N, 0), aux(N,0);
	base[0] = 1; base[1] = L; base[N-1] = R;
	while(S){
		if(S&1){
			for(int i=0;i<N;i++){
				aux[i] = multiply(res, base, i);
			}
			swap(aux, res);
		}
		for(int i=0;i<N;i++){
			aux[i] = multiply(base, base, i);
		}
		swap(aux,base);
		S>>=1;
	}
	for(int i=0;i<N;i++){
		aux[i] = multiply(res, v, i);
	}
	swap(aux,res);
	return res;
}

int main(){
	int T; cin>>T;
	while(T--){
		cin>>N>>S>>L>>R>>X;
		modu = 1; for(int x=0;x<X;x++) modu*=10;
		vector<long long> v(N, 0);
		for(int i=0;i<N;i++)cin>>v[i];
		vector<long long> m = expo(v);
		for(int i=0;i<N;i++) cout<<(i>0?" ":"")<<m[i]; cout<<endl;
	}
}
