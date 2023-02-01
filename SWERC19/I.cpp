#include<bits/stdc++.h>

using namespace std;

int main(){
	int n1, n2, n12;
	while(cin >> n1 >> n2 >> n12){
		cout << (int)floor(((double)(n1+1)*(double)(n2+1)/(double)(n12+1))-1.0) << endl;
	}
}
