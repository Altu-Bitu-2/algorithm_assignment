include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//가장 마일리지가 적게드는 과목부터 수강
int maxClass(int m, priority_queue<int, vector<int>, greater<>>& pq) {
    int result = 0; //결과값 저장 변수 선언 및 초기화
    while (!pq.empty() && pq.top() <= m) { //더이상 들을 과목이 없거나, 마일리지가 모자르면 반복문 탈출
        m -= pq.top(); //사용하는 마일리지 값만큼 빼기
        pq.pop();   //사용했으므로 최소 힙에서도 삭제
        result++;   //과목 수 추가
    }
    return result; //결과 값 리턴
}

/**
 * [Yonsei TOTO]
 *
 * 수강 인원이 미달일 때 필요한 마일리지는 0이 아니라 1
 * 1. 각 과목을 듣기 위해 필요한 최소 마일리지를 계산 (정렬)
 * 2. 가장 마일리지가 적게 드는 과목부터 수강 신청 (우선순위 큐 or 정렬)
 */
int main() {
    int n, m, p, l;
    priority_queue<int, vector<int>, greater<>> pq; //최소 힙

    cin >> n >> m; //과목 수 n, 마일리지 m 입력받기
    while (n--) { //과목수 n만큼 반복
        //입력
        cin >> p >> l;  //과목에 신청한 사람 p, 과목의 수강인원 l 입력받음
        vector<int> arr(p);  //신청한 사람만큼의 크기의 배열 선언
        for (int i = 0; i < p; i++) { //p만큼 반복
            cin >> arr[i]; //배열에 입력받음
        }

        //연산
        if (p < l) { //수강인원이 미달이라면 마일리지를 1만 넣어도 됨
            pq.push(1); //마일리지 1 추가
            continue; //계속
        }
        sort(arr.begin(), arr.end(), greater<>()); //내림차순 정렬
        pq.push(arr[l - 1]); //l번째로 마일리지를 많이 넣은 사람과 같은 양의 마일리지를 넣어야 수강 가능
    }

    //출력
    cout << maxClass(m, pq); //최대로 들을 수 있는 과목개수 출력
}