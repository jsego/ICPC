#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int C[300];

int test(string &s,vector<int> &v,int &p){
	if(p>=int(s.length()))return 0;

	int a = 0,b = 0,op = 0;

	//Get the first element and advance its position
	if(C[int(s[p])] != -1){
		a = v[C[int(s[p])]];
		p++;
	}
	else{
		p++;
		a = test(s,v,p);
	}

	//Return the value in case of the end of string (single operation)
	if(p >= int(s.length())) return a;

	//Get the operation and advance position
	if(s[p] == '+')op=0;
	else if(s[p] == '-') op=1;
	else op = 2;
	p++;

	//Get second value and advance its position and the ')' symbol
	if(C[int(s[p])] != -1){
		b = v[C[int(s[p])]];	
		p++; p++;
	}
	else{
		p++;
		b = test(s,v,p);
		p++;
	}

	//Calculate the related operation
	if(op == 0) return a+b;
	else if(op == 1) return a-b;
	return a*b;
}

int main(){
	int N, V;
	while(cin>>N,N){
		//Read the input
		vector<int> v(N,0);
		for(int i=0;i<N;i++)cin>>v[i];
		cin>>V;
		string exec; 
		cin>>exec; 

		//initialize mapping characters
		for(int i=0;i<300;i++) C[i] = -1;
		for(int i=0, t=0;i<int(exec.length());i++){
			if(exec[i] >= 'a' && exec[i] <= 'z' && C[int(exec[i])] == -1){
				C[int(exec[i])] = t++;
			}
		}
		//order the value vector before permutations
		sort(v.begin(),v.end());
		bool ok = false; int p = 0;
		do{//test each perm until true or fail
			p = 0;
			ok = test(exec,v,p)==V; 
			if(ok) break;
		}while(next_permutation(v.begin(),v.end()));
		cout<<(ok?"YES":"NO")<<endl;
	}
	cin>>N;//last zero
}
