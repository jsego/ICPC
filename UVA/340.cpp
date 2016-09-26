/*
*  Javier Segovia
*  0.012
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
#define MIN(a,b) ((a)<(b)?(a):(b))

int SC[1005]; // secret code
int SCC[10]; // secret code counting
int GC[1005];// guest code
int GCC[10]; // guest code counting

int main(){
	int N;
	int game = 1;
	while (cin>>N, N ) {
		bool zero = false;
		
		cout<<"Game "<<game<<":"<<endl;
		game++;
		for(int i=0;i<10;i++) SCC[i] = 0;
		for (int i=0; i<N ; i++) {
			cin>>SC[i];
			SCC[SC[i]]++;
		}
		do{
			int strong_match=0;
			int weak_match=0;
			zero = false;
			for(int i=0;i<10;i++) GCC[i] = 0;
			for (int i=0; i<N ; i++) {
				cin>>GC[i];
				if(GC[i] == SC[i] ) strong_match++;
				GCC[GC[i]]++;
			}
			if(GCC[0] == N) zero = true;
			else{
				for (int i=1; i<10; i++) {
				//	cout<<GCC[i]<<" "<<SCC[i]<<endl;
					weak_match += MIN(GCC[i],SCC[i]);
				}
				weak_match -= strong_match;
				cout<<"    ("<<strong_match<<","<<weak_match<<")"<<endl;
			}
		}while(!zero);
	}
}