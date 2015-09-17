/*
*  Javier Segovia
*  Accepted in 0.072
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<climits>
#include<sstream>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair

string sumi(string &c,string &a){
	string res; bool carry=false;
	int i=(int)a.LE-1,j=(int)c.LE-1,cont=0;
	for (; i>=0 && j>=0 ; i--,j--,cont++) { //cout<<"I: "<<i<<" J: "<<j<<endl;
		res.PB(c[j]+a[i]-'0'-'0'+carry);
		if(res[cont] >= 10){res[cont]=(res[cont]-10 +'0'); carry=true;}
		else{res[cont]+='0'; carry = false;}
	}
	while (j>=0) { //cout<<" J: "<<j<<endl;
		res.PB(c[j]-'0'+carry);
		if(res[cont] >= 10){res[cont]=(res[cont]-10 +'0'); carry=true;}
		else{res[cont]+='0'; carry = false;}
		j--; cont++;
	}
	if(carry){res.PB('1');} //cout<<"FINAL"<<endl;
	reverse(res.begin(),res.end());
	return res;
}

string sum(string &c,unsigned long long n){
	ostringstream os; os<<n;
	string a = os.str(); 
	string res;
	if(a.LE > c.LE || (a.LE == c.LE && a>c) ){
		//cout<<"I1"<<endl;
		res = sumi(a,c);
		//cout<<"F1"<<endl;
	}
	else{
		//cout<<"I2"<<endl; cout<<"A: "<<a<<" C: "<<c<<endl;
		res = sumi(c,a);
		//cout<<"F2"<<endl;
	}
	return res;
}
int main(){
	int kases=1;
	long long N;
	while (cin>>N && N>=0 ) {
		string cont = "0";
		for (unsigned long long i=4,j=3,mul=1; j<=(unsigned long long)N; mul<<=1,i<<=1,j<<=1) {
			cont=sum(cont,(N/i)*mul);
			if( (N%i) >= j)cont=sum(cont,(N%i)+1-j);
		}
		cout<<"Case "<<kases++<<": "<<cont<<endl;
	}
}