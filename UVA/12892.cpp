#include<iostream>
#include<vector>
using namespace std;
int P[10001];
int N;

struct Node{
	int p;
	vector<int> c;
	int sum;
	Node(){ p = -1; sum = 0;}
	Node(int _n){ p = _n; sum = 0;}
	void parent(int _n){ p = _n; }
	void addChild(int _n){ c.push_back(_n); }
	void clean(){ c.clear(); p = -1; sum = 0;}
};

Node B[10001];

int calc_sums(int n){
	if(B[n].c.size() == size_t(0))
		return 0;
	for(int i = 0; i < int(B[n].c.size()); i++){
		B[n].sum += 1 + calc_sums(B[n].c[i]);
	}
	return B[n].sum;
} 

long long compute_comb(int n){
	long long res = B[n].sum;
	long long total_childs = B[n].sum;
	for(int sn = 0; sn < int(B[n].c.size());sn++){
		total_childs -= (1+B[B[n].c[sn]].sum);
		res += (1+B[B[n].c[sn]].sum)*total_childs;
	}
	return res;
}

int main(){
	int T; cin>>T;
	for(int t=1;t<=T;t++){
		cin>>N;
		for(int n=0;n<N;n++) {
			B[n].clean();
		}

		for(int n=0;n<N;n++){
			cin>>P[n]; P[n]--;
			if(P[n] != -1){				
				B[n].parent(P[n]);
				B[P[n]].addChild(n);
			}
		}
		for(int n=0;n<N;n++){
			if(B[n].p == -1){
				calc_sums(n);
			}
		}
		cout<<"Forest#"<<t<<":";
		for(int n=0;n<N;n++){
			cout<<" "<<compute_comb(n);
		}
		cout<<endl;

	}
}
