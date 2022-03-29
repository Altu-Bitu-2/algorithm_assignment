#include <iostream>
#include <vector>

using namespace std;

vector<int> findPattern(int num) {
    vector<int> pattern = { num }; //num으로 초기화

    int temp = num; //temp을 num으로 초기화
    while (num != (temp * num) % 10) { //똑같은 수로 반복되기(돌아오기) 전까지 
        temp *= num; //a는 제곱되므로 a를 다시 곱함
        temp %= 10;  //그 수의 일의 자리 계산
        pattern.push_back(temp); //vector에 추가
    }
    return pattern; //패턴을 리턴
}

/**
 * [분산처리]
 *
 * - a^b의 일의 자리를 구하는 문제
 * - 일의 자리는 0 ~ 9 중 하나 이므로, 어떤 수를 계속 곱해 나가면 일의 자리는 패턴을 가지게 되어 있음
 *     ex) 2 -> 4 -> 8 -> 6 -> 2 ...
 * - 0 ~ 9까지 일의 자리 패턴을 미리 구한 후, a의 일의 자리에 대한 (b - 1 % 패턴의 길이)번째 수를 출력하면 된다.
 * - 0이 나올 경우 10번 컴퓨터가 처리하므로, 0이 출력되지 않도록 예외처리
 */

int main() {
    int t, a, b;

    //0 ~ 9까지 일의 자리 패턴 미리 구하기
    vector<vector<int>> last_digit(10, vector<int>(0)); //a의 일의 자리에 대한 패턴 저장 변수
    vector<int> pattern_size(10, 1);  
    for (int i = 0; i < 10; i++) { //0~9까지 반복되는 패턴 찾기
        last_digit[i] = findPattern(i); //패턴 찾는 함수 호출
        pattern_size[i] = last_digit[i].size(); //패턴의 크기 저장
    }

    //입력
    cin >> t;
    while (t--) { //테스트 개수 t만큼 반복
        cin >> a >> b; //a와 b 입력 받기
        a %= 10; //a의 일의 자리 계산

        if (a == 0) { //a가 10의 배수라면
            cout << "10\n"; //10을 출력
            continue; //다음 테스트 케이스로 이동
        }
        //인덱스가 0부터 시작하므로 (b - 1)로 계산해야 함을 주의
        cout << last_digit[a][(b - 1) % pattern_size[a]] << '\n';
    }
    return 0;
}