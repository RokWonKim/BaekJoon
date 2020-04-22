#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct info {
    int x;
    int y;
    int sum;
};

int arr[5001];
int w,n;
vector<info> v;

bool compare(info& a, info& b) {
    return a.sum < b.sum;
}

int main(void) {
    
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    cin >> w >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            v.push_back({i,j,arr[i]+arr[j]});
        }
    }
    
    sort(v.begin(), v.end(), compare);
    int start = 0;
    int end = (int)v.size()-1;
    bool flag = false;
    
    while(start < v.size() && end >= 0 ) {
        int &v1 = v[start].sum;
        int &v2 = v[end].sum;
        
        int x1 = v[start].x;
        int y1 = v[start].y;
        
        int x2 = v[end].x;
        int y2 = v[end].y;
        
        if (v1 + v2 < w)
            start++;
        else if (v1 + v2 > w)
            end--;
        else {
            if (x1 != x2 && x1 != y2 && y1 != x2 && y1 != y2) {
                flag = true;
                cout << "YES";
                break;
            }
            else {
                if (start+1 < v.size() && v1 == v[start+1].sum) {
                    start++;
                }
                else if (end-1 >= 0 && v[end-1].sum == v2) {
                    end--;
                }
                else {
                    start++;
                    end--;
                }
            }
        }
    }
    if (flag == false)
        cout << "NO";
    
    
    return 0;
    
}
