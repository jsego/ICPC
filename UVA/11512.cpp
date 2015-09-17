/*
*  Javier Segovia
*  Accepted in 0.128
*/
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

string s;
int A[1001];

bool op(int a,int b){
	
	if(a == b) return false;
	
	int i=0,maxi = MAX(a,b);
	
	while (s[a+i] == s[b+i]) {
		i++;
		if(maxi+i >= int(s.LE)) 
			return a>b;
	}
	
	return s[a+i]<s[b+i];
}

int main(){
	int N; cin>>N;
	while (N--) {
		cin>>s;
		for (int i=0; i<int(s.LE); i++) {
			A[i] = i;
		}
		sort(A,A+int(s.LE),op);
		
		int rep=-1,ac=0,b1,b2,tam=int(s.LE);
		string res="";
		b1 = tam-A[0];
		for (int i=1; i<int(s.LE); i++) {
			ac=0;
			b2 = tam -A[i];
			for (int j=0; j<MIN(b1,b2); j++) {
				if(s[A[i]+j] == s[A[i-1]+j]) ac++;
				else break;
			}
			if(ac>int(res.LE)){ res=s.substr(A[i],ac); rep=2;}
			else if(ac && ac == int(res.LE) && s.substr(A[i],ac) == res) rep++;
			b1 = b2;
		}
		if(rep == -1) printf("No repetitions found!\n");
		else printf("%s %d\n",res.c_str(),rep);
	}
}