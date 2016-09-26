#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int main(){
	int N;
	while( cin >> N ){
		map<string, int > A, B;
		string s;
		for(int n=0;n<N;n++){
			cin >> s;
			A[s]++;
		}
		for(int n=0;n<N;n++){
			cin >> s;
			B[s]++;
		}
		int res = 0;
		for(map<string,int>::iterator it = A.begin(); it != A.end(); it++){
			map<string,int>::iterator it2 = B.find( it->first );
			if( it2 != B.end() ){
				res += min( it->second, it2->second );
			}
		}
		cout << res << endl;
	}
}
