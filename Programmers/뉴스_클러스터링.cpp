#include <string>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

map<string, int> m;

bool confirm(char c) {
    return 'a' <= c && c <= 'z';
}

int solution(string str1, string str2) {
    int answer = 0;
    for (int i = 0; i < str1.size(); i++)
        if ('A' <= str1[i] && str1[i] <= 'Z')
            str1[i] += 32;
    
    for (int i = 0; i < str2.size(); i++)
        if ('A' <= str2[i] && str2[i] <= 'Z')
            str2[i] += 32;
    cout << str1 <<' ' << str2;
    int number = 1;
    multiset<int> s1;
    multiset<int> s2;
    for (int i = 0; i < str1.size()-1; i++) {
        if (confirm(str1[i]) && confirm(str1[i+1])){
            string s = str1.substr(i,2);
            if (m[s] == 0)
                m[s] = number++;
            s1.insert(m[s]);
        } 
    }
    
    
    for (int i = 0; i < str2.size()-1; i++) {
        if (confirm(str2[i]) && confirm(str2[i+1])){
            string s = str2.substr(i,2);
            if (m[s] == 0)
                m[s] = number++;
            s2.insert(m[s]);
        }
    }
    
    int sum = 0;
    int gyo = 0;

    for (int i = 1; i < number; i++) {
        int num1 = s1.count(i);
        int num2 = s2.count(i);
        sum += max(num1, num2);
        gyo += min(num1, num2);
    }
    if (sum == 0) answer = 65536;
    else if (gyo == 0) answer = 0;
    else answer = ((double)gyo/sum) * 65536;
    
    
    return answer;
}