/*
	Task	: d63_q1a_hiatus
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 22 August 2022 [11:16]
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,m,year,month;
	set<pair<int ,int > > sett;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> year >> month;
		sett.insert({year,month});
	}
	for(int i=1;i<=m;i++){
		cin >> year >> month;
		auto it = sett.lower_bound({year,month});
		if(it != sett.end() && (*it).first == year && (*it).second == month){
			cout << "0 0 ";
			continue;
		}
		if(it == sett.begin()){
			cout << "-1 -1 ";
			continue;
		}
		it--;
		cout << (*it).first << ' ' << (*it).second << ' ';
	}
	return 0;
}