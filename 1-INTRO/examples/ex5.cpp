#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	vector<int> v;
	v.push_back(8);
	v.push_back(13);
	v.push_back(3);
	v.push_back(2);
	v.push_back(5);
	v.push_back(6);
	for(int i=0;i<int(v.size());i++) cout<<" "<<v[i]; cout<<endl;
	reverse(v.begin(),v.end());	
	for(int i=0;i<int(v.size());i++) cout<<" "<<v[i]; cout<<endl;
	swap(v[2],v[5]);	
	for(int i=0;i<int(v.size());i++) cout<<" "<<v[i]; cout<<endl;
	sort(v.begin(),v.end());	
	for(int i=0;i<int(v.size());i++) cout<<" "<<v[i]; cout<<endl;
	next_permutation(v.begin(),v.end());
	for(int i=0;i<int(v.size());i++) cout<<" "<<v[i]; cout<<endl;
}
