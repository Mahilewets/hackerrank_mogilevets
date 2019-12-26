#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    int res = 0;
    set<pair<int,int> > s;
    for(auto &x:obstacles)
    {
        pair<int,int> curr(x[0],x[1]);
        s.insert(curr);  
    }

    int r = r_q, c = c_q;

// left
    while(c>1)
    {
        pair<int,int> next(r,c-1);
        auto it = s.find(next);
        if(it == s.end())
        {
            c -= 1;
            ++res;
        }
        else
        {
            break;
        }
    }

// left up diagonal
    r = r_q, c = c_q;
    while(c > 1 && r < n)
    {
        pair<int,int> next(r+1,c-1);
        auto it = s.find(next);
        if(it == s.end())
        {
            c -= 1;
            r += 1;
            ++res;
        }
        else
        {
            break;
        }      
    }
    
    // up
    r = r_q, c = c_q;
    while(r < n)
    {
        pair<int,int> next(r+1,c);
        auto it = s.find(next);
        if(it == s.end())
        {
            r += 1;
            ++res;
        }
        else
        {
            break;
        }      
    }
// right up diagonal
    r = r_q, c = c_q;
    while(c < n && r < n)
    {
        pair<int,int> next(r+1,c+1);
        auto it = s.find(next);
        if(it == s.end())
        {
            c += 1;
            r += 1;
            ++res;
        }
        else
        {
            break;
        }      
    }

// right
    r = r_q, c = c_q;
    while(c < n)
    {
        pair<int,int> next(r,c+1);
        auto it = s.find(next);
        if(it == s.end())
        {
            c += 1;
            ++res;
        }
        else
        {
            break;
        }      
    }

// right down
    r = r_q, c = c_q;
    while(c <n && r > 1)
    {
        pair<int,int> next(r-1,c+1);
        auto it = s.find(next);
        if(it == s.end())
        {
            c += 1;
            r -= 1;
            ++res;
        }
        else
        {
            break;
        }      
    }

    // down
    r = r_q, c = c_q;
    while(r > 1)
    {
        pair<int,int> next(r-1,c);
        auto it = s.find(next);
        if(it == s.end())
        {
            r -= 1;
            ++res;
        }
        else
        {
            break;
        }      
    }

// left down
    r = r_q, c = c_q;
    while(c > 1 && r > 1)
    {
        pair<int,int> next(r-1,c-1);
        auto it = s.find(next);
        if(it == s.end())
        {
            c -= 1;
            r -= 1;
            ++res;
        }
        else
        {
            break;
        }      
    }

    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

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
