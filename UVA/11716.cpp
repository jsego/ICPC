/*
*  Javier Segovia
*  Accepted in 0.036
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
int V[10001];
int main(){
	int n; string s; 
	for(int i=0;i<10001;i++) V[i] = false;
	for (int i=1; i<101; i++) {
		V[i*i]=i;
	}
	cin>>n; getline(cin,s);
	while (n--) {
		getline(cin,s);
		int C = V[(int)s.LE];
		if (C) {
			for (int i=0; i<C ; i++) {
				for (int j=i ; j<(int)s.LE; j+=C) {
					cout<<s[j];
				}
			}cout<<endl;
		}
		else {
			cout<<"INVALID"<<endl;
		}

	}
}