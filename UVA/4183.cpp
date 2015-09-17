#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include <climits>
#include <algorithm>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair

int dp[200000],N,data[200000];

int longestIncreasingSequence(){
	dp[0] = INT_MIN;
	for (int i = 1; i <= N; i++)
		dp[i] = INT_MAX;
	for (int i = 1; i <= N; i++)
		*lower_bound(dp, dp+1+N, data[i]) = data[i];
	return lower_bound(dp, dp+1+N, INT_MAX) - dp - 1;
}

int main(){
	while (cin>>N ) {
		for (int i=1; i<=N ; i++) {
			cin>>data[i];
		}
		cout<< longestIncreasingSequence()<<endl;
	}
}