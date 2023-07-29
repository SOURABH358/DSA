#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'alternate' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
int validSize(string s, char first, char second){
    string ans = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] == first || s[i] == second){
            if(ans.size() > 0 && ans[ans.size() - 1] == s[i]) return 0;
            else ans+=s[i];
        }
    }
    if(ans.size() < 2) return 0;
    return ans.size();
}
int alternate(string s) {
    int res = 0;
    for(char a = 'a';a<='z';a++)
    {
        for(char b = a+1;b<='z';b++)
        {
            int size = validSize(s, a, b);
            res = max(res, size);
        }
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string s;
    getline(cin, s);

    int result = alternate(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
