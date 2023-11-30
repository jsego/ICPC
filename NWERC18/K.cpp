#include <bits/stdc++.h>

using namespace std;

inline int get_val(char a){
	return int(a-'a');
}

inline char get_char(int v){
	return char('a'+v);
}

int main(){
	int N, M;
	while(cin >> N >> M){
		string last_a, b; // last_a=last N chars of plaintext; b=cipher text
		cin >> last_a >> b; 
		string k = b;
		string a = b;
		
		for(int i=0;i<N;++i){
			a[M-N+i] = last_a[i];
			k[M-N+i] = get_char((get_val(b[M-N+i])+26-get_val(last_a[i]))%26);
		}
		int i = M-N-1;
		while(i>=0){
			a[i] = k[i+N];
			k[i] = get_char((get_val(b[i])+26-get_val(a[i]))%26);
			--i;
		}	
		cout << a << "\n";
	}
}
