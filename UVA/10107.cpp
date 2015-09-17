/*
*  Javier Segovia
*  Accepted in 0.036
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

void binaryInsert(vector<int> &l,int n){
	int pos=0,last=(int)l.SL,mid;
	while (pos<last) {
		mid = pos+(last-pos)/2;
		if (l[mid]>n ) {
			last = mid;
		}
		else {
			pos = mid+1;
		}
	}
	l.insert(l.begin()+pos,n);
}

int main(){
	vector<int> list;
	int total=0,N,sum,mid;
	while (cin>>N ) {
		binaryInsert(list,N);
	//	cout<<"LIST: ";
	//	for(int i=0;i<(int)list.SL;i++) cout<<" "<<list[i]; cout<<endl;
		total++;
		if (total&1) {
			cout<<list[total>>1]<<endl;
		}
		else {
			mid = total>>1;
			sum = list[mid]+list[mid-1]; sum>>=1;
			cout<<sum<<endl;
		}

	}
}