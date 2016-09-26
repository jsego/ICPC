#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int N, M;
	bool first = true;
	while( cin >> N >> M ){
		if( first ) first = false;
		else cout << endl;
		for(int i = min(N,M)+1; i <= max(N,M)+1;i++)
			cout << i << endl;
	}
}
