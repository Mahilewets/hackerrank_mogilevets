#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    stack<pair<int, int> > s;
    int n; cin >> n;

    for(int i = 0 ; i < n; ++i)
    {
        int t; cin >> t;
        if(1 == t)
        {
            int x; cin >> x;
            pair<int,int> p;
            p.first = x;
            p.second = s.empty() ? x : max(x, s.top().second);
            s.push(p);
        }
        else if(2 == t)
        {
            s.pop();
        }
        else if(3 == t)
        {
            cout << s.top().second << endl;
        }
    }
    return 0;
}
