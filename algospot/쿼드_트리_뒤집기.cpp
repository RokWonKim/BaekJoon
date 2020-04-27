#include<iostream>
#include<string>

using namespace std;

string str;

string solve(string::iterator& iter) {
    
    char head = *iter;
    iter++;
    if ( head == 'x') {
        string top_left = solve(iter);
        string top_right = solve(iter);
        string down_left = solve(iter);
        string down_right = solve(iter);
        
        return string("x") + down_left + down_right + top_left + top_right;
    }
    return string(1,head);
    
     
}


int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    while (N--) {
        str = "";
        cin >> str;
        auto iter = str.begin();
        cout << solve(iter) << '\n';
    }
    
    return 0;
}
