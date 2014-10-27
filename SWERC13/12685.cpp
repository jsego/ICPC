#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

char D[100005];
int dp[100005];

string reduct(string &s){
	int p = 0;
	for(int i=0;i<int(s.length());i++){
		if(s[i] != 'U') D[p++] = s[i];
		else if(p > 0) p--;	
	}
	//string res = "R";
	string res = "";
	for(int i=0;i<p;i++) res.push_back(D[i]);
	return res;
}

int DP(string &S, string &T){
	int ir = 0, il = 0;
	int res = 0, modu = 21092013;
	int nu = 0; 
	for(int i=0;i<int(T.length());i++) if(T[i] == 'U') nu++;
	int mb = max(0, int(S.length())-nu);

	for(int i=int(T.length())-1;i>=0;i--){
		if(T[i] == 'U'){
			nu--;
			if(nu < int(S.length())){
				if(S[mb] == 'L') res = (res + 1 + ir)%modu;
				else if(S[mb] == 'R') res = (res+ 1 + il)%modu;
				//res = (res + 1 + ir + il)%modu;
				mb++;
			}
		}
		else if(T[i] == 'L'){
			il = (1 + il + ir)%modu;
		}
		else if(T[i] == 'R'){
			ir = (1 + il + ir)%modu;
		}
		//cout<<"("<<il<<","<<ir<<")"<<endl;
	}
	res = (res + il + ir + 1)%modu;
	return res;
}

int main(){
	int N; cin>>N;
	for(int cases = 1; cases <= N; cases++){
		string S,T,T2; cin>>S>>T;
		S = reduct(S);	//Initial position
		/*int ir = -1, il = -1;
		vector<int> idx;
		T2 = ""; 
		for(int i=0;i<int(T.length());i++) {
			if(T[i] != 'U'){
				T2.push_back(T[i]);
				idx.push_back(i);
			}
		}*/
		//cout<<"S: "<<S<<" T: "<<T<<endl;
		cout<<"Case "<<cases<<": "<<DP(S,T)<<endl;
	}
}
