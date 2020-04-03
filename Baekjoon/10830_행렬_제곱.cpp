#include<iostream>
#include<vector>

using namespace std;

int N;
long long B;
int arr[6][6];
int rem[6][6];

void calcul() {
    
    vector< vector<int> > part(N, vector<int>(N,0));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int z = 0; z < N; z++)
                part[i][j] += rem[i][z]*rem[z][j];
            part[i][j] %= 1000;
        }
    }
    
    for (int i=0; i<N; i++)
        for (int j = 0; j < N; j++)
            rem[i][j] = part[i][j];
    
}

void diff_calcul() {
    
    vector< vector<int> > part(N, vector<int>(N,0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int z = 0; z < N; z++)
                part[i][j] += arr[i][z]*rem[z][j];
            part[i][j] %= 1000;
        }
    }
    
    for (int i=0; i<N; i++)
        for (int j = 0; j < N; j++)
            arr[i][j] = part[i][j];
}

void print_matrix() {
    
    for (int i=0; i<N; i++) {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << ' ';
        cout << '\n';
    }
    
}

int main(void) {
    
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> B;
    
    for (int i=0; i<N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> rem[i][j];
        }
        arr[i][i] = 1;
    }
    
    
    
    for ( long long value = B; value > 0; value = value/2) {
        if (value % 2 == 1)
            diff_calcul();
        calcul();
    }
    print_matrix();
    
    return 0;
}
