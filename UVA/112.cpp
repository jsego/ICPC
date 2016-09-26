/*
*  Javier Segovia
*  Accepted in 0.192
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair

struct Node {
	int p[2];
	int val;
	Node(){val=0;p[0]=p[1]=-1;}
	Node(int v){val = v;  p[0]=p[1]=-1;}
	Node(int v,int a1,int a2){val=v; p[0]=a1; p[1]=a2;}
};

Node A[2000000];
int sum,ac,cont;

void build_tree(string &s,int &p,int padre,bool der){
	int prof=0;bool num=false,lao=false,neg=false;
	for (; p<(int)s.LE && (s[p]!=')' || prof); p++) {
		if(s[p]=='('){ 
			if(num){
				if(!neg) A[cont++] = Node(ac);
				else A[cont++] = Node(ac*-1);
			}
			ac=0; num=neg=false; ++p;
			build_tree(s,p,prof,lao); 
			lao=!lao;
		}
		else if(s[p]==')'){
			if(padre==-1)return;
			if(der)A[padre].p[1] = prof;
			else A[padre].p[0] = prof;
			return;			
		}
		else if(s[p] == '-'){
			neg=true;
		}
		else {
			num=true; prof=cont;
			ac=(ac*10)+(s[p]-'0');
		}
	}
	return;
}

bool recur(int p,int s){
	if (A[p].p[0]==-1 && A[p].p[1]==-1) {
		return (s+A[p].val)==sum;
	}
	if (A[p].p[0]!=-1){
		if(recur(A[p].p[0],s+A[p].val))return true;
	}
	if(A[p].p[1]!=-1){
		return recur(A[p].p[1],s+A[p].val);
	}
	return false;
}

int main(){
	while (cin>>sum) {
		int prof=-1; char c;
		string s="";
		while (cin>>c && (prof || c!=')') ) {
			if(c=='('){
				prof++; 
			}
			if(c==')'){prof--;}
			s.PB(c);
		}s.PB(')');cont=0; int p=1;
		build_tree(s,p,-1,false);
		if(cont && recur(0,0))printf("yes\n");
		else printf("no\n");
	}
}