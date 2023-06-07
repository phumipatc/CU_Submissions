#include <iostream>
#include <vector>
#include<math.h>
using namespace std;
long long lv(long long s, long long a){
    long long cnt = 0;
    long long sum = 0,leaf = 1;
    while(sum<a){
        sum+=leaf*s;
        leaf*=s;
        cnt++;
    }
    return cnt;
}
int relation(long long s, long long a, long long b) {
    if(a == b)  return 4;
    if(lv(s,a) == lv(s,b))  return 4;
    if(a>b){
        if((a-1)/s == b) return 1;
        while(a>b){
            a = (a-1)/s;
        }
        if(a == b){
            return 2;
        }else{
            return 3;
        }
    }else{
        if((b-1)/s == a)    return 1;
        while(b>a){
            b = (b-1)/s;
        }
        if(b == a){
            return 2;
        }else{
            return 3;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    long long S,a,b;
    cin >> n;
    while (n--) {
        cin >> S >> a >> b;
        cout << relation(S,a,b) << " ";
    }
    cout << endl;
}