#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<map>
#include<set>

using namespace std;

void printVector(vector<int> &v){
	for(int i=0;i<int(v.size());i++) cout<<" "<<v[i]; cout<<endl;
}

void printList(list<int> &l){
	for(list<int>::iterator it = l.begin(); it != l.end();it++){
		cout<<" "<<*it;	
	}cout<<endl;
}

void printSet(set<int> &s){
	for(set<int>::iterator it = s.begin(); it != s.end(); it++){
		cout<<" "<<*it;	
	}cout<<endl;
}

void printMap(map<int,char> &m){
	for(map<int,char>::iterator it = m.begin(); it != m.end(); it++){
		cout<<" ("<<it->first<<"->"<<it->second<<")";	
	}cout<<endl;
}

int main(){
	/*** Vector example ***/
	cout<<"Vector example:"<<endl;
	vector<int> v;
	v.push_back(3);
	v.push_back(3);
	cout<<"Test 1:"<<endl;
	printVector(v);
	v.insert(v.begin(),1);
	cout<<"Test 2:"<<endl;
	printVector(v);
	v.erase(v.begin()+1);
	cout<<"Test 3:"<<endl;
	printVector(v);
	cout<<endl;

	/*** List example ***/
	cout<<"List example:"<<endl;
	list<int> l;
	l.push_back(3);
	l.push_back(3);
	l.push_back(4);
	cout<<"Test 1:"<<endl;
	printList(l);
	l.insert(l.begin(),1);
	cout<<"Test 2:"<<endl;
	printList(l);
	l.pop_back();
	cout<<"Test 3:"<<endl;
	printList(l);
	l.pop_front();
	cout<<"Test 4:"<<endl;
	printList(l);
	cout<<endl;

	/*** Set example ***/
	cout<<"Set example:"<<endl;
	set<int> s;
	s.insert(3);
	s.insert(3);
	cout<<"Test 1:"<<endl;
	printSet(s);
	s.insert(6);
	s.insert(5);
	cout<<"Test 2:"<<endl;
	printSet(s);
	s.erase(3);
	cout<<"Test 3:"<<endl;
	printSet(s);
	s.erase(s.begin());
	cout<<"Test 4:"<<endl;
	printSet(s);
	cout<<endl;

	/*** Map example ***/
	cout<<"Map example:"<<endl;
	map<int,char> m;
	m[4] = 'a';
	m[5] = 'b';
	m[1] = 'c';
	cout<<"Test 1:"<<endl;
	printMap(m);
	m.erase(4);
	cout<<"Test 2:"<<endl;
	printMap(m);
	m.erase(m.begin());
	cout<<"Test 3:"<<endl;
	printMap(m);
	cout<<endl;
	

}
