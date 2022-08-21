/*
	Task	: ds00_reverse2
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 21 August 2022 [20:21]
*/
#include <iostream>
#include <vector>
using namespace std;
void reverse(vector<int> &v,vector<int>::iterator a,vector<int>::iterator b) {
	//write your code only in this function
	for(b--;a<b;a++,b--)
		swap(*a,*b);
}
int main() {
	//read input
	int n,a,b;
	cin >> n;
	vector<int> v;
	for (int i = 0;i < n;i++) {
		int c;
		cin >> c;
		v.push_back(c);
	}
	cin >> a >> b;
	//call function
	reverse(v,v.begin()+a,v.begin()+b+1);
	//display content of the vector
	for (auto &x : v) {
		cout << x << " ";
	}
	cout << endl;
}