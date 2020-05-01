#include<iostream>
#include<string.h>

using namespace std;

const long long INF = -10000000000000;

int n,m;
long long A[105];
long long B[105];

//a_size,b_size
long long cache[103][103];

long long solve(int a_size, int b_size, long long pre) {


    long long &value = cache[a_size][b_size];
    if (value != INF)
        return value;

    value = 0;
    for (int i = a_size; i < n; i++) {
        if (pre < A[i])
            value = max(solve(i+1, b_size, A[i])+1, value);
    }
    for (int i = b_size; i < m; i++) {
        if (pre < B[i])
            value = max(solve(a_size, i+1, B[i])+1, value);
    }
    
    return value;
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {

        for(int i = 0; i < 103; i++)
            for (int j = 0; j < 103; j++)
                cache[i][j] = INF;
    
        cin >> n >> m;
        for(int i = 0; i < n; i++) 
            cin >> A[i];
        for(int i = 0; i < m; i++) 
            cin >> B[i];
        
        cout <<solve(0,0,INF) << '\n';
    }

    return 0;
}