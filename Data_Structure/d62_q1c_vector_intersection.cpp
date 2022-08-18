/*
    Task	: d62_q1c_vector_intersection
    Author	: Phumipat C. [MAGCARI]
    Language: C++
    Created	: 18 August 2022 [17:44]
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n,m;
    cin >> n >> m;
    vector<int > a(n),b(m);
    for(auto &x:a)
        cin >> x;
    for(auto &x:b)
        cin >> x;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    // using unique
    a.resize(unique(a.begin(),a.end())-a.begin());
    b.resize(unique(b.begin(),b.end())-b.begin());

    vector<int >::iterator it = a.begin(),it2 = b.begin();
    while(it != a.end() && it2 != b.end()){
        if(*it == *it2){
            cout << *it << ' ';
            it++,it2++;
        }else if(*it < *it2){
            it++;
        }else{
            it2++;
        }
    }
    return 0;
}