#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int len=0;
    string input, sub;
    set <string>s;

    cin >> input;
    len = input.length(); //문자열의 길이 저장

    for (int i = 0; i < len; i++) {
        for (int j = 1; j <= len - i; j++) {
            sub = input.substr(i, j); //부분 문자열 구하기
            s.insert(sub); //set에 부분 문자열 저장
        }
    }

    //set의 size출력
    cout << s.size();  

    return 0;
}