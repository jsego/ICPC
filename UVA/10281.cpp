/*
*  Javier Segovia
*  Accepted in 0.012
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<sstream>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair

double dist=0.0;
double speed=0.0,ac_speed=0.0;
int timing=0,last_speed_change=0;
bool change = false;

void extract_data(string &s){
	int a,b,c;
	a = ((s[0]-'0')*10 + s[1]-'0')*3600;
	b = ((s[3]-'0')*10 + s[4]-'0')*60;
	c = ((s[6]-'0')*10 + s[7]-'0');
	last_speed_change = timing;
	timing = a+b+c;
	if(9<int(s.LE)){
		s = s.substr(9);
		istringstream iss(s);
		iss>>ac_speed;
		change = true;
	}
	else {
		change = false;
	}

}

int main(){
	string s;
	while (getline(cin,s)) {
		extract_data(s);
		dist += (timing-last_speed_change)*5*speed/18;
		if(!change){
			printf("%02d:%02d:%02d %.2f km\n",timing/3600,(timing%3600)/60,timing%60,dist/1000);
		}
		speed = ac_speed;
	}
}