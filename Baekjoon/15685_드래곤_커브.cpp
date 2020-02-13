#include<iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;
int arr[101][101];

int xm[4] = {1,0,-1,0};
int ym[4] = {0,-1,0,1};

void fill(int x, int y, int d, int g) { 
	vector<int> general;
	arr[y][x] = 1;

	int m= 0;

	for (int i = 0; i <= g; i++) {
		if (i == 0)
			general.push_back(d);
		else {
			int len = general.size();
			for (int i = len-1; i >= 0; i--)
				general.push_back( (general[i]+1)%4 );
		}
	}

	for (int i = 0; i < general.size(); i++) {
		m = general[i];
		y += ym[m];
		x += xm[m];
		arr[y][x] = 1;
	}


}

int main() {

	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	int x,y,d,g;
	int count = 0;

	cin >> N;

	for(int i = 0; i < N; i++) {
		cin >> x >> y >> d >> g;
		fill(x,y,d,g);
	}

	for (int i = 100; i >= 1; i--) {
		for (int j = 100; j >= 1; j--) {
			if (arr[i][j] == 1 && arr[i-1][j-1] == 1 && arr[i-1][j] == 1 && arr[i][j-1] == 1 ) {
				count++;
			}
		}
	}

	cout << count;
	
	return 0;
}