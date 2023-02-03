/*
	Task	: ex01m2
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 26 January 2023 [10:16]
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > a,b;
int cnt = 0;
void mergeSort(int l,int r){
	if(l == r)	return ;
	int mid = (l+r)/2;
	mergeSort(l,mid);
	mergeSort(mid+1,r);
	int i=l,j=mid+1,k=l;
	while(i<=mid && j<=r){
		//count inversion
		if(a[i]>a[j]){
			cnt += mid-i+1;
			b[k++] = a[j++];
		}else{
			b[k++] = a[i++];
		}
	}
	while(i<=mid)	b[k++] = a[i++];
	while(j<=r)		b[k++] = a[j++];
	for(int i=l;i<=r;i++)
		a[i] = b[i];
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n;
	cin >> n;
	a.resize(n),b.resize(n);
	for(auto &x:a)
		cin >> x;
	mergeSort(0,n-1);
	cout << cnt << '\n';
	return 0;
}