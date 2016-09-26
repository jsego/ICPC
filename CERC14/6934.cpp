#include<iostream>
#include<list>
#include<cmath>

using namespace std;

bool K[10][10];
int x[10] = {1,0,1,2,0,1,2,0,1,2};
int y[10] = {3,0,0,0,1,1,1,2,2,2};
bool V[201];
int R[201];
int main(){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10;j++){
			K[i][j] = ( x[i] <= x[j] && y[i] <= y[j] );
		}
	}
	for(int i = 0; i < 201;i++) 
		V[i] = false;
	list< int > b;
	list< int >::iterator it;
	for(int i = 0; i < 10; i++) {
		b.push_back( i ); 
		V[i] = true;
	}
	it = b.begin();
	while( it != b.end() ){
		it = b.begin();
		int i = *it;
		int m = i%10, next;
		it = b.erase( b.begin() );
		for(int n = 0; n < 10;n++){
			next = i * 10 + n;
			if( next < 201 && K[m][n] && !V[next] ){
				V[next] = true;
				b.push_back( next );
			}
		}	
	}
	for(int i = 1; i < 201; i++){
		int best = 10000000;
		for(int j = 1; j < 201; j++){
			if( V[j] && abs( i - j ) <= best ){
				best = abs( i - j ); 
				R[i] = j;
			}
		}
	}
	int kases; cin >> kases;
	while( kases-- ){
		int n; cin >> n;
		//cout << n << ": " << R[n] << endl;
		cout << R[n] << endl;
	}
	
}
