#include<iostream>
#include<vector>

using namespace std;

int N;
long long cnt;
vector<int> arr;

void merge_sort(int left, int mid, int right) {
    
    int c_left = left;
    int c_mid = mid+1;
    
    int num = right-left+1;
    vector<int> part_arr(num);
    int index = 0;
    
    while(index < num) {
        
        if (c_left > mid ) // 왼쪽 고갈
            part_arr[index++] = arr[c_mid++];
        else if ( c_mid > right ) // 오른쪽 고갈
            part_arr[index++] = arr[c_left++];
        else {
            if (arr[c_left] < arr[c_mid]) {
                part_arr[index++] = arr[c_left++];
            }
            else if (arr[c_left] > arr[c_mid]) {
                cnt += mid - c_left + 1;
                part_arr[index++] = arr[c_mid++];
            }
            else {
                part_arr[index++] = arr[c_left++];
                part_arr[index++] = arr[c_mid++];
            }
        }
        
    }
    
    index = 0;
    for (int i = left; i <= right; i++)
        arr[i] = part_arr[index++];
    
}

void merge(int left, int right) {
    
    int mid = (left+right)/2;
    if (left != right) {
        merge(left,mid);
        merge(mid+1, right);
        merge_sort(left, mid, right);
    }
    
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    arr.resize(N);
    
    for (int i=0; i<N; i++)
        cin >> arr[i];
    
    merge(0,N-1);
    cout << cnt;
    
    return 0;
}
