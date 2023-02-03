/*
	Task	: a62_q1b_virus
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 23 January 2023 [09:43]
*/
#include<bits/stdc++.h>
using namespace std;
int a[260];
bool divide(int l,int r){
	if(l+1 == r)	return (a[l] == 0 && a[r] == 1);
	int mid = (l+r)/2;

	bool right = divide(mid+1,r);
	if(!right)	return false;

	bool left = divide(l,mid);
	if(left)	return true;

	for(int i=l,j=mid;i<j;i++,j--)
		swap(a[i],a[j]);
	left = divide(l,mid);
	for(int i=l,j=mid;i<j;i++,j--)
		swap(a[i],a[j]);
	return left;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,k;
	cin >> n >> k;
	k = 1<<k;
	while(n--){
		for(int i=1;i<=k;i++)
			cin >> a[i];
		cout << (divide(1,k)?"yes\n":"no\n");
	}
	return 0;
}