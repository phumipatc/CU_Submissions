/*
	Task	: d63_q1a_multi_insert
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 24 August 2022 [11:40]
*/
#include <iostream>
#include <vector>
using namespace std;
void multiple_add(vector<int> &v, int value, int position, int count) {
    //write your code here
    int n = v.size();
    vector<int > ans;
    for(int i=0;i<n;i++){
        if(i == position){
            for(;count>0;count--)
                ans.emplace_back(value);
        }
        ans.emplace_back(v[i]);
    }
    for(;count>0;count--)
        ans.emplace_back(value);
    v = ans;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,value,position,count;
    cin >> n >> value >> position >> count;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    multiple_add(v,value,position,count);
    cout << "After call multiple_add" << endl << "Size = " << v.size() << endl;
    for (auto &x : v) cout << x << " ";
    cout << endl;
}