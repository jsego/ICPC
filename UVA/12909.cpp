#include<iostream>
using namespace std;
int main(){
	unsigned long long A[] = {
	8LL,
	49LL,
	288LL,
	1681LL,
	9800LL,
	57121LL,
	332928LL,
	1940449LL,
	11309768LL,
	65918161LL,
	384199200LL,
	2239277041LL,
	13051463048LL,
	76069501249LL,
	443365544448LL,
	2584123765441LL,
	15061377048200LL,
	87784138523761LL,
	511643454094368LL
	};

	unsigned long long x;
	while(cin>>x, x){
		int i;
		for ( i = 0; i < 19 && A[i] <= x; ++i );
		cout << i << endl;
	}
	
}
