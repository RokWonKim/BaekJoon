#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N, M;
int arr[302][302];

struct info {
	int i;
	int j;
	int zero;
};

int zero_confirm(int i, int j) {

	int zero = 0;

	if (i-1 >= 0 && arr[i-1][j] == 0)	zero++;
	if (i+1 < N && arr[i+1][j] == 0)	zero++;
	if (j-1 >= 0 && arr[i][j-1] == 0)	zero++;
	if (j+1 < M && arr[i][j+1] == 0)	zero++;

	return zero;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	
	int ans = 0;

	while(1) {
		bool check[301][301] = {false, };
		int zero_count = 0;
		int count = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if ( check[i][j] == true)
					continue;
				else if (arr[i][j] == 0) {
					zero_count++;
					check[i][j] = true;
					continue;
				}

				int zero = 0;
				queue< info > q;
				if (i-1 >= 0 && arr[i-1][j] == 0)	zero++;
				if (i+1 < N && arr[i+1][j] == 0)	zero++;
				if (j-1 >= 0 && arr[i][j-1] == 0)	zero++;
				if (j+1 < M && arr[i][j+1] == 0)	zero++;

				q.push({i,j, zero});

				
				while( !q.empty() ) {
					
					int top_i = q.front().i;
					int top_j = q.front().j;
					zero = q.front().zero;
					q.pop();
					
					
					if (check[top_i][top_j] != true) {
						check[top_i][top_j] = true;
							
						if (top_i-1 >= 0 && arr[top_i-1][top_j] != 0)
							q.push({top_i-1, top_j, zero_confirm(top_i-1, top_j)});
						if (top_i+1 < N && arr[top_i+1][top_j] !=0)
							q.push({top_i+1, top_j, zero_confirm(top_i+1, top_j)});
						if (top_j-1 >= 0 && arr[top_i][top_j-1] != 0)
							q.push({top_i, top_j-1, zero_confirm(top_i, top_j-1)});
						if (top_j+1 < M && arr[top_i][top_j+1] != 0)
							q.push({top_i, top_j+1, zero_confirm(top_i, top_j+1)});


						if (arr[top_i][top_j]-zero > 0)
							arr[top_i][top_j] -= zero;
						else
							arr[top_i][top_j] = 0;
					}
				}
				
		
				
				count++;
			}
		}
		
		ans++;

		if (count > 1) {
			cout << ans-1;
			break;
		}
		if (zero_count >= N*M ) {
			cout << 0;
			break;
		}
		
	}

	return 0;
}