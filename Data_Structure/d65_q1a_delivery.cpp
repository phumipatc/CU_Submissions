/*
	Task	: d65_q1a_delivery
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 07 September 2022 [17:11]
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int > target(m),bs;
    queue<int > food,dot;
    for(auto &x:target)
        cin >> x;
    int opr,a,b,sum = 0;
    while(n--){
        cin >> opr;
        if(opr == 1){
            cin >> a >> b;
            if(a == 1)  food.push(b);
            else        dot.push(b);
        }else{
            if(!food.empty())   a = food.front();
            else                a = 1e9;
            if(!dot.empty())    b = dot.front();
            else                b = 1e9;

            if(a <= b){
                sum+=a;
                bs.push_back(sum);
                food.pop();
            }else{
                sum+=b;
                bs.push_back(sum);
                dot.pop();
            }
        }
    }
    for(auto x:target){
        auto idx = lower_bound(bs.begin(),bs.end(),x);
        if(idx == bs.end()) cout << "-1 ";
        else                cout << idx - bs.begin() + 1 << " ";
    }
    return 0;
}