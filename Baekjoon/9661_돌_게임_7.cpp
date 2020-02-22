#include<iostream>
#include<string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;

	int x = (str[str.size() -1] - '0' ) % 5;

	if (x == 1 || x == 3 ||  x == 4)
		cout << "SK";
	else
		cout << "CY"; 
	

	return 0;
}