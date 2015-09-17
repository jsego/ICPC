/*
* Javier Segovia
* Accepted in 0.008
*/

//Codigo bigint (para numeros mayores que 2^64)
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <cassert>
using namespace std;
#define BASE 1000000000
struct bigint{
	vector<int> V;
	bigint():V(1,0){}
	bigint(int n):V(1,n){}
	bigint (const bigint &b):V(b.V){}
	bool operator==(const bigint &b)const{return V==b.V;}
	int &operator[](int i){return V[i];}
	int operator[](int i)const{return V[i];}
	int size()const{return V.size();}
	void resize(int i) {V.resize(i);}
	bool operator<(const bigint &b)const{
		const bigint &a(*this);
		if(a.size()==b.size()){
			for(int i=b.size()-1;i>=0;i--){
				if(a[i]==b[i])continue;
				return a[i]<b[i];
			}
		}
		return (a.size()<b.size());
	}
	void adddigit(int l){
		if(l>0)V.push_back(l);
	}
};

//suma a+b?BASE坘
inline bigint suma(const bigint &a,const bigint &b,int k){
	bigint c;
	int size=max(a.size(),b.size()+k);
	c.resize(size);
	long long l=0;
	for(int i=0;i<size;++i){
		l+=i<a.size()?a[i]:0;
		l+=(k<=i and i<k+b.size())?b[i-k]:0;
		c[i]=l%BASE;
		l/=BASE;
	}
	c.adddigit(int (l));
	return c;
}
inline bigint operator+(const bigint &a,const bigint &b){
	return suma(a,b,0);
}
inline bigint operator+(const bigint &a,int b){return a+bigint(b);}
inline bigint operator+(int b,const bigint &a){return a+bigint(b);}
inline bigint operator-(const bigint &a,const bigint &b){
    assert(b<a or a==b);
    bigint c ;
    c.resize(a.size());
    long long l=0;
    for(int i=0;i<a.size();++i){
		l+=a[i] ;
		l-=(i<b.size())?b[i]:0;
		if(l<0)l+=BASE;
		c [i]=l%BASE;
		l/=BASE ;
    }
    return c ;
}
inline bigint operator-(const bigint &a,int b){return a-bigint(b);}
inline bigint operator*(const bigint &a,int b){
	if(b==0)return bigint(0);
	bigint c ;
	c.resize(a.size());
	long long l=0;
	for(int i=0;i<a.size();++i){
		l+=(long long)(b)*a[i];
		c[i]=l%BASE;
		l/=BASE;
	}
	c.adddigit(int (l));
	return c ;
}
inline bigint operator*(int b,const bigint &a){return a*b;}
inline bigint operator*(const bigint &a,const bigint &b){
    bigint res;
    for(int i=0;i<b.size();++i)
        res=suma(res,a*b[i],i);
	return res;
}
inline void divmod(const bigint &a,int b,bigint &div,int &mod){
	div.resize(a.size());
	long long l=0;
	for(int i=a.size()-1;i>=0;--i){
		l*=BASE;
		l+=a[i];
		div[i]=l/b;
		l%=b;
	}
	if(div[div.size()-1]==0 and div.size()>1)
		div.resize(div.size()-2);
	mod=int(l);
}
inline bigint operator/(const bigint &a,int b){
	bigint div;
	int mod;
	divmod(a,b,div,mod);
	return div ;
}
inline bigint operator%(const bigint &a,int b){
	bigint div;
	int mod;
	divmod(a,b,div,mod);
	return mod;
}
inline istream &operator>>(istream &is,bigint &b){
	string s;
	is>>s;
	int n=s.size();
	b.resize((n-1)/9+1);
	int k=0;
	while(n>0){
		b[k]=0;
		int i=n-9;
		if(i<0)i=0;
		for(;i<n;++i){
            b[k]*=10;
            b[k]+=s[i]-'0';
		}
		++k ;
		n-=9;
	}
	return is;
}

inline bigint operator^(const bigint &a,int b){
	bigint res=a;
	int exp = 1;
	for(;(exp<<1)<b;exp<<=1){
		res=res*res;
	}
	for(;exp<b;exp++) res = res*a;
	return res;
}

inline ostream &operator<<(ostream &os,const bigint &b){
	os<<b[b.size()-1];
	for(int k=b.size()-2;k>=0;--k)
		os<<setw(9)<<setfill('0')<<b[k];
	return os;
}

//10106: sumatorio de bigints
void p10106(){
    bigint a,b;
    while(cin>>a>>b){
        cout<< (a*b)<<endl;
    }
}
int main(){
	p10106();
}