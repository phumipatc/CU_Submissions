/*
	Task	: d64_q1b_password
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 01 September 2022 [21:30]
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,m,l;
	cin >> n >> m >> l;
	vector<int > k(l);
	for(auto &x:k)
		cin >> x;
	map<string ,bool > mapp;
	string str;
	for(int i=1;i<=n;i++){
		cin >> str;
		mapp[str] = true;
	}
	for(int i=1;i<=m;i++){
		cin >> str;
		for(int j=0;j<l;j++)
			str[j] = ((str[j] - 'a' + k[j])%26) + 'a';
		cout << (mapp[str]?"Match\n":"Unknown\n");
	}
	return 0;
}