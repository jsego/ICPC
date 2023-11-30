#include <bits/stdc++.h>

using namespace std;

int main(){
	int N, C, B;
	while(cin >> N >> C >> B){
		string s(N, '0');
		if(C&1) s[0] = '1';
		vector<int> broken(B);
		for(int b=0; b<B; b++){
			cin >> broken[b];
		}
		int b_it=B-1, s_it=N-1;
		C--;
		while(C>0){
			//cout << broken[b_it] << " "<< s_it << endl;
			if(broken[b_it] == s_it+1){
				--b_it; --s_it;
			}
			else if(s[s_it+1]=='1'){
				--s_it;
			}
			else{
				s[s_it] = '1'; 
				--s_it;
				C-=2;
			}
		}
		cout << s << "\n";		
	}
}
