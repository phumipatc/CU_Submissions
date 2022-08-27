/*
	Task	: d63_q1b_list_erase
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 24 August 2022 [11:41]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
void list_erase(vector<int> &v, vector<int> &pos) {
	//write your code here
	sort(pos.begin(),pos.end());
	auto it = pos.begin();
	vector<int > ans;
	int n = v.size();
	for(int i=0;i<n;i++){
		if(i == (*it)){
			it++;
			continue;
		}
		ans.push_back(v[i]);
	}
	v = ans;
}
int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	vector<int> v(n), pos(m);
	for (int i = 0;i < n;i++) cin >> v[i];
	for (int i = 0;i < m;i++) cin >> pos[i];
	list_erase(v,pos);
	cout << "After call list_erase" << endl << "Size = " << v.size() << endl;
	for (auto &x : v) cout << x << " ";
	cout << endl;
}
