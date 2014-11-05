#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main(){
	int K; cin>>K;
	for(int k = 1;k<=K;k++){
		string S, T; cin>>S>>T;
		if(S.length() != T.length()){cout<<"Case "<<k<<": -1"<<endl; continue;}
		int i01 = 0, i10 = 0, i1 = 0, i0 = 0;
		for(int i=0;i<int(S.length());i++){
			if(T[i] == '0'){
				if(S[i] == '1') i10++;
				else if(S[i] == '?') i0++;
			}
			else if(S[i] == '0') i01++;
			else if(S[i] == '?') i1++;
		}
		int mp = min(i10,i01); //swap positions (0-1) <-> (1-0)
		i10-=mp; i01-=mp;
		int res = mp;
		if(i10 > i1 ) res = -1;
		else{
			res += i1 + i0 + i10 + i01;
		}
		cout<<"Case "<<k<<": "<<res<<endl;
	}
}
