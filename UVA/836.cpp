/*
*  Javier Segovia
*  Accepted in 0.012
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define MAX(a,b) ((a)>(b)?(a):(b))

int N;

int main(){
	cin>>N;
	string s;
	getline(cin,s);
	getline(cin,s);
	bool first= false;
	while (N--) {
		if(first) printf("\n");
		else first = true;
		getline(cin,s);
		vector<string> A;
		vector<vector<int> > B;
		while (int(s.LE)>0) {
			A.PB(s);
			getline(cin,s);
		}
		B.clear();
		B.resize(int(A.SL),vector<int> (int(A[0].LE),0));
		int maxi = 0,sq,sq2;
		for (int i=0; i<int(B.SL); i++) {
			for (int j=0; j<int(B[i].SL); j++) {
				B[i][j] = A[i][j]=='1'?1:0;
				if(i) B[i][j]+=B[i-1][j];
				if(j) B[i][j]+=B[i][j-1];
				if (i&&j) {
					B[i][j]-=B[i-1][j-1];
				}
				for (int k=0; k<=i; k++) {
					for (int q=0; q<=j; q++) {
						if(A[k][q] == '1'){
							sq = (j-q+1)*(i-k+1);
							sq2 = B[i][j];
							if(k) sq2 -=B[k-1][j];
							if(q) sq2 -=B[i][q-1];
							if(k&&q) sq2+=B[k-1][q-1];
							if(sq == sq2){
								maxi = MAX(maxi,sq);
								//cout<<"MAXI: "<<maxi<<" ("<<k<<","<<q<<") <-> ("<<i<<","<<j<<")"<<endl;
							}
						}
					}
				}
				//cout<<B[i][j]<<" ";
			}//cout<<endl;
		}
		printf("%d\n",maxi);
	}
}