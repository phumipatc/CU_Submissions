/*
    Task	: ds00_reverse
    Author	: Phumipat C. [MAGCARI]
    Language: C++
    Created	: 15 August 2022 [10:24]
*/
#include <iostream>
#include <vector>

using namespace std;

void reverse(vector<int> &v,int a,int b) {
    //write your code only in this function
    int num = b-a+1;
    vector<int >::iterator st = v.begin();
    for(int i=0;i<num/2;i++)
        swap(*(st+a+i),*(st+b-i));
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
    reverse(v,a,b);
    //display content of the vector
    for (auto &x : v)
        cout << x << " ";
    cout << endl;
}
