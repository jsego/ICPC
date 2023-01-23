#include <bits/stdc++.h>

using namespace std;

long long A[2001];
long long B[2001];
long long res[4000001];

int main(){
	int N, M;
	
	while(cin >> N >> M){
		for(int i = 0; i < N; i++)
			cin >> A[i];
		for(int i = 0; i < M; i++)
			cin >> B[i];
		int total_elems = 0;
		long long estimated_cooking_time = 0;
		int max_occurrences = 0;
		for(int b = 0; b < M; b++){
			for(int a = 0; a < N; a++){
				if(A[a] > B[b]) break;
				res[total_elems] = (B[b]-A[a]);
				total_elems++;
			}
		}
		sort(res, res+total_elems);
		estimated_cooking_time = res[0]; 
		int occurrences = 1;
		for(int i = 1; i < total_elems; i++){
			if( res[i] == res[i-1] ) occurrences++;
			else{
				if( occurrences > max_occurrences ){
					max_occurrences = occurrences;
					estimated_cooking_time = res[i-1];
				}
				occurrences = 1;
			}
		}
		cout << estimated_cooking_time << "\n";
	}
}
