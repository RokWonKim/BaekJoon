#include<iostream>
#include<algorithm>

using namespace std;

struct info{
    int color;
    int value;
    int index;
};

int color_num_sum[200010];
int same_value[2010];
int print_arr[200010];
info arr[200010];

bool compare_value(const info &i,const info &j) {
    if (i.value == j.value)
        return i.color < j.color;
    return i.value < j.value;
}

int main(void) {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int N;
    int a,b;
    int all_sum = 0;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        arr[i] = {a,b,i};
    }

    sort(arr, arr+N, compare_value);

    for (int i = 0; i < N; i++) {
        if ( i > 0 && arr[i].color == arr[i-1].color && arr[i].value == arr[i-1].value )
            print_arr[arr[i].index] = print_arr[arr[i-1].index];
        else 
            print_arr[arr[i].index] = all_sum - color_num_sum[arr[i].color] - same_value[arr[i].value];

        color_num_sum[ arr[i].color ] += arr[i].value;
        same_value[ arr[i].value ] += arr[i].value;
        all_sum += arr[i].value;
    }

    for (int i = 0; i < N; i++)
        cout << print_arr[i] <<'\n';


    return 0;
}