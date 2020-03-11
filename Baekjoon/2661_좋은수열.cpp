#include<iostream>
#include<vector>
#include<string>

using namespace std;

int N;
string print_arr;

bool confirm_sequence() {

    int s = print_arr.size();
    int i = 2;
    while (1) {
        if ( i*2 > s )
            break;

        if (print_arr.substr(s-i*2,i) == print_arr.substr(s-i, i) )
            return false;
            
        i++;
    }

    return true;
}

void backtracking(int now) {

    if( print_arr.size() == N) {
        cout << print_arr << '\n';
        exit(0);
    }

    for (int i = 1; i <= 3; i++) {
        if (i == now)
            continue;

        print_arr.push_back('0'+i);
        if ( confirm_sequence() )
            backtracking(i);
        print_arr.pop_back();
    }

}

int main(void) {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    print_arr = "";

    cin >> N;

    backtracking(0);

    return 0;
}