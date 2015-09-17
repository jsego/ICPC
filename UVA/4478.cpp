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
#define MIN(a,b) ((a)<(b)?(a):(b))
#define INF 1000000000
int A[505][505];
int B[505];
int N,M,L,U,Q;

int search(){
	int maxi = 0,maxdim,izq,der,mid;
	int px,py,nx,ny;
	bool ok=false;
	for (int i=0;i<N ;i++) {
		int l1=0,l2=M-1,lmid=0;
		
		while (l1<l2) {
			lmid = (l1+l2)/2;
			if(A[i][lmid] < L) l1 = lmid+1;
			else l2 = lmid;
		}
		
		B[i] = (A[i][l1] >= L && A[i][l1]<=U? l1:INF);
		
		if(B[i]==INF){ continue;}
		ok=true;
		
		px = B[i];
		py = i;		
		maxdim = MIN(M-B[i],N-i);
		izq = 0;
		der = maxdim-1;
		
		//cout<<"I: "<<i<<" izq: "<<izq<<" der: "<<der<<" maxdim: "<<maxdim<<" hor: "<<hor<<" ver: "<<ver<<endl;
		while (izq<=der) {//cout<<izq<<" "<<der<<" " <<mid<<endl;
			mid = (izq+der)/2;
			nx=px+mid;
			ny=py+mid;
			if(A[ny][nx]<=U){
				izq=mid+1;
			}
			else 
				der = mid-1;
		}
		maxi = MAX(maxi,der);
	}
	if(!ok) return 0;
	
	return maxi+1;
}

int main(){
	while (cin>>N>>M,(N||M)) {
		for (int i=0; i<N ; i++) {
			for (int j=0; j<M ; j++) {
				cin>>A[i][j];
			}
		}
		cin>>Q;
		while (Q--) {
			cin>>L>>U;
			cout<<search()<<endl;
		}
		cout<<"-"<<endl;
	}
}