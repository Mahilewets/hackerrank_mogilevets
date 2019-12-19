#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
    vector<int> cnt_a(300,0),cnt_b(300,0);
    for(auto x: a)
    {
        ++cnt_a[x];
    }
    for(auto x: b)
    {
        ++cnt_b[x];
    }
    int res=0;
    for(int i='a';i<='z';++i)
    {
        res+=abs(cnt_a[i] - cnt_b[i]);
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
