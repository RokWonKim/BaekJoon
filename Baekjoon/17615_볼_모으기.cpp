#include<iostream>
#include<string>

using namespace std;

int main(void) {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int N;
    string str = "";
    int ans_1 = 0;
    int ans_2 = 0;

    cin >> N;
    cin >> str;

    //R을 우측으로 모을 때
    bool blue_flag = false;
    for(int i = str.size()-1; i >= 0; i--) {
        if(str[i] == 'B' && blue_flag == false) { 
            blue_flag = true;
            continue;
        }
        if (blue_flag == true && str[i] == 'R')
            ans_1++;
    }
    //좌측으로 모을때
    blue_flag = false;
    for(int i = 0; i < str.size(); i++) {
        if( str[i] == 'B' && blue_flag == false) {
            blue_flag = true;
            continue;
        }
        if (blue_flag == true && str[i] == 'R')
            ans_2++;
    }

    int ans_3 = 0;
    int ans_4 = 0;
    //B를 우측으로
    bool red_flag = false;
    for(int i = str.size()-1; i >= 0; i--) {
        if(str[i] == 'R' && red_flag == false) { 
            red_flag = true;
            continue;
        }
        if (red_flag == true && str[i] == 'B')
            ans_3++;       
    }
    //좌측으로 모을때
    red_flag = false;
    for(int i = 0; i < str.size(); i++) {
        if( str[i] == 'R' && red_flag == false) {
            red_flag = true;
            continue;
        }
        if (red_flag == true && str[i] == 'B')
            ans_4++;
    }

    cout << min( min(ans_1, ans_2),min(ans_3,ans_4) );

    return 0;
}