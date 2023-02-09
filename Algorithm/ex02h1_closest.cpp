/*
	Task	: ex02h1_closest
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 09 February 2023 [11:39]
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 50010;
struct A{
	int x,y;
};
int calculateDistance(A a,A b){
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}
A a[N];
int closestDistance(int l,int r){
	if(l == r)		return 1e9;
	if(l+1 == r)	return calculateDistance(a[l],a[r]);	
	int mid = (l+r)/2;
	int d = min(closestDistance(l,mid),closestDistance(mid+1,r));
	vector<A> v;
	for(int i=l;i<=r;i++)
		if(abs(a[i].x-a[mid].x) <= d)
			v.push_back(a[i]);
	// sort by y
	sort(v.begin(),v.end(),[](A a,A b){
		return a.y < b.y;
	});
	for(int i=0;i<v.size();i++){
		for(int j=i+1;j<v.size();j++){
			if(v[j].y-v[i].y >= d)	break;
			d = min(d,calculateDistance(v[i],v[j]));
		}
	}
	return d;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i].x >> a[i].y;
	// sort by x
	sort(a+1,a+n+1,[](A a,A b){
		return a.x < b.x;
	});
	cout << closestDistance(1,n) << '\n';
	return 0;
}