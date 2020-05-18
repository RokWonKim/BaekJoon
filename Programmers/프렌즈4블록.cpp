#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> arr;
int m ,n;

// 지워지는 블록 체크해서 1로 바꾸는 함수
// 1을 다 지우는 함수(지운 후 0으로 바꿈)
// 0이 된 곳을 메꾸는 함수
int change_check() {
    int ans = 0;
    vector< vector<char> > copy(m, vector<char>(n,0));
    
    for (int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            copy[i][j] = arr[i][j];
    
    
    for (int i = 0; i < m-1; i++) {
        for (int j = 0; j < n-1; j++) {
            if (arr[i][j]==arr[i][j+1] && arr[i+1][j]==arr[i+1][j+1] && arr[i][j] == arr[i+1][j]) {
                if (copy[i][j] == 'z') continue;
                copy[i][j] = 'a';
                copy[i+1][j] = 'a';
                copy[i][j+1] = 'a';
                copy[i+1][j+1] = 'a';
            }       
        }
    }
    
    for (int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if (copy[i][j] == 'a') {
                copy[i][j] = 'z';
                ans++;
            }
        }
        
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = m-1; j >= 0; j--) {
            int z = j;
            while(z+1 <= m-1 && copy[z][i] != 'z' && copy[z+1][i] == 'z' ) {
                swap(copy[z+1][i], copy[z][i]);
                z++;
            }
        }
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = copy[i][j];
        }
    }
    
    return ans;   
}

int solution(int high, int width, vector<string> board) {
    m = high;
    n = width;
    arr = board;
    
    int ans = 0;
    
    while(1) {
        int part = change_check();
        if (part == 0) break;
        ans += part;
    }
    
    return ans;
}