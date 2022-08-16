/*
    Task	: d62_q1a_push
    Author	: Phumipat C. [MAGCARI]
    Language: C++
    Created	: 16 August 2022 [20:29]
*/
#include <iostream>
#include <vector>
using namespace std;
vector<string> punch(vector<string> &v, vector<string>::iterator it,int k) {
    v.erase((it-k>=v.begin())?it - k:v.begin(),(it+k<v.end())?it + k+1:v.end());
    return v;
}
int main() {
    int n,j,k;
    cin >> n >> j >> k;
    vector<string> v(n);
    for (int i = 0;i < n;i++) {
        cin >> v[i];
    }
    cout << "Result after punch" << endl;
    vector<string> result = punch(v, v.begin() + j, k);
    for (auto &x : result) {
        cout << x << endl;
    }
}
