#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

bool check(vector<vector<int>> &key, vector<vector<int>> &arr, int &i, int& j) {

    for (int td = 0; td < arr.size(); td++)
        for (int lr = 0; lr < arr[0].size(); lr++)
            if ( key[i+td][j+lr] + arr[td][lr] != 1 )
                return false;

    return true;
}

void lotate(vector<vector<int>> &key,int M) {
    vector< vector<int> > new_key(M, vector<int> (M));

    int x = 0;
    int y = 0;
    for (int i = 0; i < M; i++) {
        for(int j = M-1; j >= 0; j--)
            new_key[x][y++] = key[j][i];
            
        x++;
        y = 0;
    }
    key = new_key;
}


bool solution(vector<vector<int>> key, vector<vector<int>> lock) {

    bool answer = true;
    int M = key[0].size();
    int N = lock[0].size();

    int left_index = N;
    int right_index = 0;

    int top_index = N;
    int bottom_index = 0;
    int value = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (lock[i][j] == 0) {
                left_index = min(left_index, j);
                right_index = max(right_index, j);   
                top_index = min(top_index, i);
                bottom_index = max(bottom_index, i);
            }
            else
                value++;
        }
    }
    if (value == N*N)   return true;

    int td = bottom_index-top_index;
    int lr = right_index-left_index;

    vector< vector<int> > arr(td+1, vector<int> (lr+1, 0) );

    int new_i = 0;
    int new_j = 0;
    for (int i = top_index; i <= bottom_index; i++) {
        for (int j = left_index; j <= right_index; j++) {
            arr[new_i][new_j] = lock[i][j];
            new_j++;
        }
        new_i++;
        new_j = 0;
    }


    for (int r = 0; r < 4; r++) {
        for (int i = 0; i < M - td; i++)
            for (int j = 0; j < M - lr; j++)
                if(check(key, arr,i,j))
                    return true;

        lotate(key, M);
    }

    return false;
}