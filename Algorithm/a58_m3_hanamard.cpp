/*
	Task	: a58_m3_hanamard
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 11 February 2023 [18:17]
*/
#include<bits/stdc++.h>
using namespace std;
const int N = (1<<18)+5;
int a[N];
vector<int > hanamard(int i,int j,int sz){
	if(sz == 1)	return {a[j]};
	vector<int > ans;
	auto l = hanamard(i,j,sz/2);
	auto r = hanamard(i,j+sz/2,sz/2);
	for(int k=0;k<sz/2;k++)
		ans.push_back(l[k]+r[k]);
	for(int k=0;k<sz/2;k++)
		ans.push_back(l[k]-r[k]);
	return ans;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	auto ans = hanamard(1,1,n);
	for(auto x:ans)
		cout << x << ' ';
	cout << '\n';
	return 0;
}