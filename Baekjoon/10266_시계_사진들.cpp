#include<iostream>
#include<vector>

using namespace std;

int fail[360001];

void fail_func(const vector<int> &s) {
    int j = 0;
    fail[0] = 0;

    for (int i = 1; i < s.size(); i++) {
        while (j > 0 && s[i] != s[j])
            j = fail[j-1];
        
        if ( s[i] == s[j] )
            fail[i] = ++j;
    }
}

void kmp(const int arr1[],const vector<int> &arr2) {
    int j = 0;
    int size_2 = arr2.size();

    for (int i = 0; i < 720000; i++) {
        while ( j > 0 && arr1[i] != arr2[j])
            j = fail[j-1];

        if ( arr1[i] == arr2[j] ) {
            j++;

            if (j == size_2) {
                cout << "possible";
                return;
            }
        }
    }

    cout << "impossible";
}



int main(void) {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int N, value;
    cin >> N;

    int arr1[720001] = {0,};
    int arr2[360001] = {0,};

    
    for (int i = 0; i < N; i++) {
        cin >> value;
        arr1[value] = 1;
    }
    
    for (int i = 0; i < N; i++) {
        cin >> value;
        arr2[value] = 1;
    }
    
    for (int i = 360000; i < 720000; i++)
        arr1[i] = arr1[i-360000];

    
    bool flag = false;
    vector<int> find_arr2;

    for(int i = 0; i < 360000; i++) {
        if (flag == true) {
            find_arr2.push_back(arr2[i]);
        }
        else {
            if (arr2[i] == 1) {
                find_arr2.push_back(arr2[i]);
                flag = true;
            }
        }
    }

    
    fail_func(find_arr2);
    kmp(arr1, find_arr2);

    return 0;
}