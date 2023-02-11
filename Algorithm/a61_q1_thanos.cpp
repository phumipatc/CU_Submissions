/*
	Task	: a61_q1_thanos
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 09 February 2023 [23:42]
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int k;
long long A,B;
int a[N];
int findNumberFounded(int l,int r){
	return upper_bound(a+1,a+k+1,r) - lower_bound(a+1,a+k+1,l);
}
long long divide(int l,int r){
	int num = findNumberFounded(l,r);
	if(num == 0)	return A;
	if(l == r)		return B*num;
	int mid = (l+r)/2;
	return min(divide(l,mid)+divide(mid+1,r),B*num*(r-l+1));
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	// freopen("D:/Code/CU/input.in","r",stdin);
	int p;
	cin >> p >> k >> A >> B;
	for(int i=1;i<=k;i++)
		cin >> a[i];
	sort(a+1,a+k+1);
	cout << divide(1,(1<<p)) << '\n';
	return 0;
}