#include<iostream>
#include<vector>
#include<string>

using namespace std;

int R, C;
int ans = 0;
int arr[21][21];
bool check[21][21];

int d[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };


void DFS(bool alpa[], int x, int y, int count){

	int value = arr[x][y];

	if (check[x][y] == true || alpa[value] ==true)
		return;

	ans = max(ans, count+1);
		
	check[x][y] = true;
	alpa[value] = true;
	
	for (int i = 0; i < 4; i++) {
		int new_x = x + d[i][0];
		int new_y = y + d[i][1];

		if (new_x >= 0 && new_x < R && new_y >= 0 && new_y < C ) {
			DFS(alpa, new_x, new_y, count+1);
		}
	}

	check[x][y] = false;
	alpa[value] = false;
		
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;

	string str = "";

	for (int i = 0; i < R; i++) {
		cin >> str;
		for (int j = 0; j < C; j++)
			arr[i][j] = str[j] - 'A';
	}

	bool alpa[26] = {false, };

	DFS(alpa, 0, 0, 0);

	cout << ans;

	return 0;
}