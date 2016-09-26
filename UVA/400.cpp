/*
*  Javier Segovia
*  Accepted in 0.040
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<sstream>
#include<climits>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define MAX(a,b) ((a)>(b)?(a):(b))
string A[105];
int main(){
	int N; string dashes(60,'-');
	while (cin>>N ) {
		cout<<dashes<<endl;
		int maxLen=0;
		for(int n=0;n<N;n++){ cin>>A[n]; maxLen = MAX(maxLen,(int)A[n].LE);}
		sort(A,A+N);
		int C = (60-maxLen)/(maxLen+2);
		int words = N/(C+1),coor; if(N%(C+1))words++;
		for (int i=0; i<words; i++) {
			for (int j=0; j<C ; j++) {
				coor = i+j*words;
				cout<<A[coor]; 
				cout<<string((maxLen+2-(int)A[coor].LE),' ');
			}
			coor = i+C*words;
			if(coor < N){ 
				cout<<A[coor]; 
				if((int)A[coor].LE < maxLen)
					cout<<string(maxLen-(int)A[i+C*words].LE,' ');
			}
			else cout<<string(maxLen,' ');
			cout<<endl;
		}
		
	}
}