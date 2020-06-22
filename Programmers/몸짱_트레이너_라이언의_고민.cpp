#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int table[1321];
int arr[10][10];

bool check(int x, int y, int mid, int n) {
    
    for (int next_x = 0; next_x < n; next_x++) {
        for (int next_y = 0; next_y < n; next_y++) {
            if (x == next_x && y == next_y) return false;
            if (abs(x - next_x) + abs(y - next_y) >= mid) continue;
            
            else {
                if (arr[next_x][next_y] == 1)
                    return true;
            }
        }
    }
    
    return false;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> timetable) {
    int answer = 1;
    int num = 0;
    memset(table, 0, sizeof(table));
    if (n == 0 || m == 0) return 0;
    
    for (int i = 0; i < m; i++) {
        table[timetable[i][0]]++;
        table[timetable[i][1]+1]--;
    }
    for (int i = 600; i <= 1320; i++) {
        table[i] += table[i-1];
        num = max(num, table[i]);
    }
    
    if (num <= 1) return 0;
    else if (num == 2) return 2*n-2;
    
    int left = 1;
    int right = 2*n-2;
    
    while (left <= right) {
        
        int mid = (left+right)/2;
        int count = 0;
        
        // 미드의 거리로 만들 수 있는지 확인
        for (int i = 0; i < n; i++) {
            int part_count = 0;
            memset(arr, 0, sizeof(arr));

            // 각 인덱스에서 순회하면 미드거리보다 안에 드는거 있는지 확인
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    if (x == 0 && y < i) continue;
                    if (!check(x,y,mid,n)) {
                        arr[x][y] = 1;
                        part_count++;
                    }
                }
            }
            count = max(count, part_count);
        }
            
        
        if (count >= num) left = mid+1;
        else right = mid-1;
    }
    
    return right;
}