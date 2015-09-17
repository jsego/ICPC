#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
long long F[55];
int main(){
	F[0] = 1; F[1] = 1;
	for (int i=2; i<51; i++) {
		F[i] = F[i-1]+F[i-2];
	}
	int s; scanf("%d",&s);
	while (s) {
		printf("%lld\n",F[s]);
		scanf("%d",&s);
	}
}