#include<iostream>
#include<string>

using namespace std;

string str;
int ans;
int size;
int fail[5001];

void make_fail(int start) {
    
    int j = start;
    fail[start] = start;
    
    for (int i = start+1; i < size; i++) {
        fail[i] = start;
        
        while (j != start && str[i] != str[j])
            j = fail[j-1];
        
        if (str[i] == str[j]) {
            fail[i] = ++j;
            ans = max(ans, fail[i] - start);
        }
    }
    
}


int main(void) {
    
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    cin >> str;
    
    size = (int)str.size();
    
    for (int i = 0; i < size-1; i++)
        make_fail(i);
    
    cout << ans;
    
    return 0;
}
