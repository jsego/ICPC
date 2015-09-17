/*
*  Javier Segovia
*  Accepted in 0.012
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<sstream>
#include<map>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define INF 1000000000

int A[101][101];
string RO[101][101];
int B[101][101];
int N;
map<string,int> M;
string CI[101];


void floydwarshall(){
	for (int i=0; i<N ; i++) {
		for (int j=0; j<N ; j++) {
			for (int k=0; k<N ; k++) {
				if(A[j][i]+A[i][k] < A[j][k]){
					A[j][k] = A[k][j] = A[j][i]+A[i][k];
					B[j][k] = B[k][j] = i;
				}
			}
		}
	}
}

vector<int> getpath(int i,int j){
	if(B[i][j] == INF) return vector<int>();
	int inter = B[i][j];
	vector<int> v1,v2;
	if(i!=inter)v1 = getpath(i,inter);
	v1.PB(inter);
	if(j!=inter){
		v2 = getpath(inter,j);
		for (int i=0; i<int(v2.SL); i++) {
			v1.PB(v2[i]);
		}
	}
	return v1;
}

int main(){
	string s,a,b,r,val;
	int v,c1,c2;
	map<string,int>::iterator it,it2;
	//grafo
	N=101;
	for(int i=0;i<N;i++){for(int j=0;j<N;j++){ A[i][j] = INF;B[i][j] = INF;} A[i][i] = 0; B[i][i] = i;}
	N=0;
	while (getline(cin,s),s!="") {
		size_t pos,pos2;
		pos = s.find_first_of(',');
		a = s.substr(0,pos);
		pos2 = s.find_first_of(',',pos+1);
		b = s.substr(pos+1,pos2-pos-1);
		pos = pos2;
		pos2 = s.find_first_of(',',pos+1);
		r = s.substr(pos+1,pos2-pos-1);
		val = s.substr(pos2+1);
		istringstream iss(val);
		iss>>v;
		
		it = M.find(a);
		it2 = M.find(b);
		if(it == M.end()){M[a]=N; c1=N; CI[N++] = a;}
		else c1 = it->second;
		if(it2 == M.end()){M[b] = N; c2=N; CI[N++] = b;}
		else c2 = it2->second;
		
		if(v<A[c1][c2]){
			A[c1][c2] = A[c2][c1] = v;
			RO[c1][c2] = RO[c2][c1] = r;
		}
		
	}

	floydwarshall();
	
	//casos
	while (getline(cin,s)) {
		cout<<endl<<endl;
		
		size_t pos = s.find_first_of(',');
		a = s.substr(0,pos);
		b = s.substr(pos+1);
		c1 = M[a]; c2 = M[b];
	//	cout<<"C1: "<<c1<<" "<<a<<endl;
	//	cout<<"C2: "<<c2<<" "<<b<<endl;
		vector<int> v = getpath(c1,c2);
		reverse(v.begin(),v.end());
		v.PB(c1);
		v.insert(v.begin(),c2);
		
		//...backtrack
		int total=0;
		cout<<"From"<<string(17,' ')<<"To"<<string(19,' ')<<"Route"<<string(6,' ')<<"Miles"<<endl;
		cout<<string(20,'-')<<" "<<string(20,'-')<<" "<<string(10,'-')<<" "<<string(5,'-')<<endl;
		for (int i=int(v.SL)-1; i>0; i--) {
			cout<<CI[v[i]]<<string(21-int(CI[v[i]].LE),' ');
			cout<<CI[v[i-1]]<<string(21-int(CI[v[i-1]].LE),' ');
			cout<<RO[v[i]][v[i-1]]<<string(11-int(RO[v[i]][v[i-1]].LE),' ');
			printf("%5d\n",A[v[i]][v[i-1]]);
			total+=A[v[i]][v[i-1]];
		}
		cout<<string(53,' ')<<"-----"<<endl;
		cout<<string(42,' ')<<"Total      "; printf("%5d\n",total);
	}
}