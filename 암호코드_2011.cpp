#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
    vector<int> v(5001);
    int count = 0;
    string s;
    cin >> s;
    v[0] =1;
    v[1] =1;
    for (int i = 2; i <= s.size(); i++) {
        if(s[i-1] != '0')
            v[i] = v[i-1] % 1000000;
        
        count = (s[i-2]-'0')*10 + (s[i-1]-'0');
        if (count>=10 && count<=26)
            v[i] = (v[i-2] + v[i]) % 1000000;
    }
    if (s.size() == 0)
        cout << 0;
    else if (s[0] == '0') 
        cout << 0;
    else
        cout << v[s.size()];
    return 0;
}
