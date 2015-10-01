#include<iostream>
#include<algorithm>

using namespace std;

#define INF 1000000000

int M[50];

int main(){
	int N;
	while( cin >> N ){
		for(int i = 0; i < 50; i++) 
			M[i] = 0;
		int T;
		for(int i = 0; i < N; i++){
			cin >> T;
			T += 11;
			M[ T ]++;
		}
		int res = INF;
		for(int r = 0; r < 24; r++){
			int aux = 0, prev = -1;
			for(int i = r; i < r + 24; i++){
				if( M[i]& 1 ){
					if( prev == -1) 
						prev = i;
					else{
						aux += (i - prev);
						prev = -1;
					}
				}
			} //cout << r << " " << aux << endl;
			M[r+24] = M[r];
			res = min( res, aux );
		}
		cout << res << endl;
	}
}
