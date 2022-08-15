/*
    Task	: d57_q0_remove_even
    Author	: Phumipat C. [MAGCARI]
    Language: C++
    Created	: 15 August 2022 [10:30]
*/
#include <iostream>
#include <vector>
using namespace std;
void remove_even(vector<int> &v,int a,int b) {
    //write your code only in this function
    vector<int >::iterator it = v.begin();
    for(int i=b;i>=a;i--){
        if(i%2) continue;
        v.erase(it+i);
    }
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
    remove_even(v,a,b);
    //display content of the vector
    for (auto &x : v) {
        cout << x << " ";
    }
    cout << endl;
}
