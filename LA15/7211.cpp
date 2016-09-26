#include<iostream>

using namespace std;

int main(){
	int T;
	while( cin >> T ){
		int ac, res = 0;
		for( int i = 0; i < 5; i++ ){
			cin >> ac;
			res += (ac == T );
		}
		cout << res << endl;
	}
}
