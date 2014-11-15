#include<iostream>

using namespace std;

long double DX[11][11], DY[11][11];
long long H[11][11];

int main(){
	cout.setf(ios::fixed);
	cout.precision(8);
	int N; //number of houses N <= 100800
	while(cin>>N){
		for(int i=0;i<10;i++) for(int j=0;j<10;j++) {
			DX[i][j] = DY[i][j] = H[i][j] = 0;
		}
		double x, y;
		//save relative position to the quarters
		for(int n=0;n<N;n++){
			cin>>x>>y;
			DX[int(x)][int(y)] += (x-int(x));
			DY[int(x)][int(y)] += (y-int(y));
			H[int(x)][int(y)]++;
		}
		//compute average for each guild
		for(int i=0;i<10;i++) for(int j=0;j<10;j++) 
			if(H[i][j]){
				DX[i][j] /= double(H[i][j]);
				DY[i][j] /= double(H[i][j]);
			}
		//compute the res using only admissible paths where
		//p>i and q>j, and multiply each result using the
		//total number of combinations for each path
		long double res = 0.0;
		long long combinations = 0;
		long long current_comb = 0;
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				for(int p = i+1;p<10;p++){
					for(int q = j+1;q<10;q++){
						current_comb = H[i][j] * H[p][q];
						res +=  ( (DX[p][q] - DX[i][j] + p - i)
								+ (DY[p][q] - DY[i][j] + q - j) ) 
								* current_comb;
						combinations += current_comb;
					}
				}
			}
		}
		cout<<res/double(combinations)<<endl;
	}
}
