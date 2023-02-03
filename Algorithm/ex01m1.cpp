/*
	Task	: ex01m1
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 26 January 2023 [10:23]
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
	int type,i,j;
};
vector<A > ans;
bool containHole(int i,int j,int sz,int hi,int hj){
	return (i<=hi && hi<i+sz && j<=hj && hj<j+sz);
}
void divide(int uli,int ulj,int sz,int hi,int hj){
	if(sz == 1)	return ;
	int uri = uli,urj = ulj+sz/2;
	int dli = uli+sz/2,dlj = ulj;
	int dri = uli+sz/2,drj = ulj+sz/2;
	if(containHole(uli,ulj,sz/2,hi,hj)){
		// printf("0 %d %d %d %d %d\n",uli,ulj,sz,hi,hj);
		ans.push_back({0,dri-1,drj-1});
		divide(uli,ulj,sz/2,hi,hj);
		divide(uri,urj,sz/2,dri-1,drj);
		divide(dli,dlj,sz/2,dri,drj-1);
		divide(dri,drj,sz/2,dri,drj);

	}else if(containHole(uri,urj,sz/2,hi,hj)){
		// printf("1 %d %d %d %d %d\n",uli,ulj,sz,hi,hj);
		ans.push_back({1,dri-1,drj-1});
		divide(uli,ulj,sz/2,dri-1,drj-1);
		divide(uri,urj,sz/2,hi,hj);
		divide(dli,dlj,sz/2,dri,drj-1);
		divide(dri,drj,sz/2,dri,drj);
	
	}else if(containHole(dli,dlj,sz/2,hi,hj)){
		// printf("2 %d %d %d %d %d\n",uli,ulj,sz,hi,hj);
		ans.push_back({2,dri-1,drj-1});
		divide(uli,ulj,sz/2,dri-1,drj-1);
		divide(uri,urj,sz/2,dri-1,drj);
		divide(dli,dlj,sz/2,hi,hj);
		divide(dri,drj,sz/2,dri,drj);
	
	}else{
		// printf("3 %d %d %d %d %d\n",uli,ulj,sz,hi,hj);
		ans.push_back({3,dri-1,drj-1});
		divide(uli,ulj,sz/2,dri-1,drj-1);
		divide(uri,urj,sz/2,dri-1,drj);
		divide(dli,dlj,sz/2,dri,drj-1);
		divide(dri,drj,sz/2,hi,hj);
	}
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,hj,hi;
	cin >> n >> hj >> hi;
	divide(0,0,n,hi,hj);
	cout << ans.size() << '\n';
	for(auto x:ans)
		cout << x.type << ' ' << x.j << ' ' << x.i << '\n';
	return 0;
}