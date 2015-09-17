/*
*  Javier Segovia
*  Accepted in 0.008
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

double sq(double A,double B,double C){
	double inc = B*B - 4*A*C;
	if(inc<0) return -2147647000.0;
	return (-B+sqrt(inc))/(2*A);
}

int main(){
	double U,V,A,S,T;
	int n,kase=1;
	cout.setf(ios::fixed);
	cout.precision(3);
	while (cin>>n && n ) {
		cout<<"Case "<<kase++<<": ";
		if(n==1){
			cin>>U>>V>>T;
			A = (V-U)/T;
			S = U*T + (A*T*T)/2;
			cout<<S<<" "<<A<<endl;
		}
		else if(n==2){
			cin>>U>>V>>A;
			T = (V-U)/A;
			S = U*T + (A*T*T)/2;
			cout<<S<<" "<<T<<endl;
		}
		else if(n==3){
			cin>>U>>A>>S;
			T = sq(A/2,U,-S);
			V = A*T + U;
			cout<<V<<" "<<T<<endl;
		}
		else {
			cin>>V>>A>>S;
			T = sq(-A/2,V,-S);
			U = V - A*T;
			cout<<U<<" "<<T<<endl;			
		}

	}
}