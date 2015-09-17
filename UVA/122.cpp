/*
*  Javier Segovia
*  Accepted in 0.012
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<sstream>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
struct Node {
	int v;
	int L,R;
	bool exist;
	Node(){v=L=R=-1; exist=false;}
	Node(int _v){v=_v; L=R=-1; exist=true;}
	Node(int _v,int _L,int _R){v=_v; L=_L; R=_R;exist=true;}
	Node(int _v,int _L,int _R,bool e){v=_v; L=_L; R=_R;exist=false;}
};

Node N[260];
int VAL[260][260];
int T;
bool incorrect;

void insert(int v,string p){ 
	int ac=0;
	for (int i=0; i<(int)p.LE; i++) {
		if(p[i]=='L'){
			if (N[ac].L<0) {
				N[ac].L = ++T; 
				N[T] = Node(-1,-1,-1,false);
				ac = T;
			}
			else {
				ac = N[ac].L;
			}
		}
		else {
			if (N[ac].R<0) {
				N[ac].R = ++T;
				N[T] = Node(-1,-1,-1,false);
				ac = T;
			}
			else {
				ac = N[ac].R;
			}
		}
	} 
	if(N[ac].v != -1) incorrect=true;
	N[ac].v=v; N[ac].exist=true;
}

bool ok(){ 
	int ac=0,CA=0,PR; Node a;
	int A[260]; 
	A[CA++] = 0; A[CA++] = 0; 
	VAL[0][0]++; VAL[0][1] = N[0].v;
	bool SE[260];
	for(int i=0;i<T;i++) SE[i] = false;
	SE[0] = true;
	while (ac<CA) {
		a = N[A[ac++]]; PR = A[ac++];
		if(a.v < 0){ return false;}
		if(a.L > 0 && !SE[a.L]){
			SE[a.L] = true;
			VAL[PR][VAL[PR][0]++] = N[a.L].v;
			A[CA++] = a.L; A[CA++] = PR+1;
		}
		if(a.R > 0 && !SE[a.R]){
			SE[a.R] = true; 
			VAL[PR][VAL[PR][0]++] = N[a.R].v;
			A[CA++] = a.R; A[CA++] = PR+1;
		}
	} 
	
	return (T==CA);
}

int main(){
	string s;
	while (cin>>s) {
		T=0; incorrect = false; 
		for(int i=0;i<260;i++) N[i] = Node();
		while (s!="()") {
			size_t id = s.find_first_of(','),id2 = s.find_last_of(')');
			stringstream ss(s.substr(1,id));
			int a; ss>>a;
			string path = s.substr(id+1,id2-1-id);
			if(!incorrect) insert(a,path);
			cin>>s;
		}
		T++; T<<=1;
		for(int i=0;i<260;i++) VAL[i][0] = 1;
		if(!incorrect && ok()){ //check the tree
			bool first=false;
			for (int i=0; i<260 ; i++) {
				for (int j=1; j<VAL[i][0]; j++) {
					if(first) printf(" %d",VAL[i][j]);
					else{first=true; printf("%d",VAL[i][j]);}
				}
			}
			printf("\n");
		}
		else {
			printf("not complete\n");
		}

	}
}