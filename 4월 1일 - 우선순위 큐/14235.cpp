#include <iostream>
#include <queue>

using namespace std;

/**
 * [크리스마스 선물] - 단순 구현 문제
 *
 * - 0이 나올 때마다, 가지고 있는 선물 중 가장 가치가 큰 것을 삭제 & 출력 -> 최대 힙 필요
 */

int main() {
    int n, a, input;
    priority_queue<int> pq; //최대 힙

    //입력
    cin >> n; //아이들과 거점지를 방문한 횟수 n
    while (n--) { //n만큼 반복
        cin >> a; //a를 입력받음
        if (!a) { //아이들을 만난 경우
            if (pq.empty()) { //줄 선물이 없다면
                cout << "-1\n"; //-1 출력
            }
            else { //선물의 가치 출력
                cout << pq.top() << '\n'; //가장 큰 값 출력
                pq.pop(); //해당 값 삭제
            }
        }
        else { //선물을 충전하는 경우
            while (a--) { //a만큼 반복
                cin >> input; //선물의 가치를 입력받아
                pq.push(input); //최대 힙에 저장
            }
        }
    }
    return 0;
}