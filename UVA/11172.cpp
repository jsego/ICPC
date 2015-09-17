/*
*  Javier Segovia
*  Accepted in 0.004
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
int main(){
	int kases,a,b; scanf("%d",&kases);
	while (kases--) {
		scanf("%d %d",&a,&b);
		if(a>b) printf(">\n");
		else if(a<b) printf("<\n");
		else printf("=\n");
	}
}