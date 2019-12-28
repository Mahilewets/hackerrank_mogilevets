#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

#define MAXN 10 * 1000 * 1000 + 1
long tree[4*MAXN];

void update(int v, int tl, int tr, int l, int r, int add)
{
    if(l > r)
    {
        return;
    }
    if(tl == l && tr == r)
    {
        tree[v] += add;
    }
    else
    {
        int tm = (tl+tr)>>1;
        int nr = min(r,tm);
        int nl = max(l,tm+1);
        int lv = (v<<1);
        int rv = lv+1;

        update(lv, tl, tm, l, nr, add);
        update(rv, tm+1, tr, nl, r, add);
    }

}

long get(int v, int tl, int tr, int pos)
{
    if(tl == tr)
    {
        return tree[v];
    }
    else
    {
        int tm = (tl+tr)>>1;
        if(pos <= tm)
        {
            return get(2*v,tl,tm,pos) + tree[v];
        }
        else
        {
            return get(2*v+1,tm+1,tr,pos) + tree[v];
        }
    }
}

// Complete the arrayManipulation function below.
long arrayManipulation(int n, vector<vector<int>> queries) {
    for(auto &q:queries)
    {
        int a = q[0], b = q[1], k = q[2];

        update(1, 0, n, a, b, k);
    }
    

    long m = LONG_MIN;

    for(int i = 1; i <= n; ++i)
    {
        long c = get(1,0,n,i);
        m = max(c,m);
    }

    return m;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> queries(m);
    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> queries[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = arrayManipulation(n, queries);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
