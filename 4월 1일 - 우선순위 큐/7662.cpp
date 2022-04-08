#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

vector<bool> is_valid; //유효성 체크하는 배열

//최대 힙에서 top 데이터가 is_valid 할 때까지 pop
void deleteMax(priority_queue<ci>& heap) {//최대 힙에서
    while (!heap.empty() && !is_valid[heap.top().second]) { //top 데이터가 is_valid 할 때까지 
        heap.pop(); //pop 연산
    }
}

//최소 힙에서 top 데이터가 is_valid 할 때까지 pop
void deleteMin(priority_queue<ci, vector<ci>, greater<>>& heap) {//최소 힙에서
    while (!heap.empty() && !is_valid[heap.top().second]) { //top 데이터가 is_valid 할 때까지 
        heap.pop(); //pop 연산
    }
}

/**
 * 우선순위 큐 풀이
 * 최대 힙과 최소 힙을 동시에 관리하면서 각각의 힙에서 삭제된 데이터를 다른 힙에 반영하는 방법
 * -> 각 데이터의 유효성을 체크하는 배열을 만들기
 */
int main() {
    int t, k, n;
    char cmd;

    cin >> t; //test 개수
    while (t--) {
        priority_queue<ci> max_heap; //최대 힙
        priority_queue<ci, vector<ci>, greater<>> min_heap; //최소 힙
        cin >> k; //연산 개수 k
        int idx = 0; //I 연산으로 입력된 숫자의 인덱스
        while (k--) { //연산 시작
            //입력
            cin >> cmd >> n;  //연산을 나타내는 문자, 피연산자 정수 n

            //연산
            switch (cmd) {
            case 'I': //두가지 힙 모두에 값을 넣은 뒤, is_valid 벡터에도 추가
                max_heap.push(ci(n, idx));  //max heap에 n을 넣음
                min_heap.push(ci(n, idx));  //min heap에 n을 넣음
                is_valid.push_back(true);   //유효성 표시
                idx++;  //인덱스 증가
                break;  // 종료
            case 'D': //n에 따라 최대 힙 또는 최소 힙에서 데이터 삭제
                if (n == 1) {   //최대값 삭제
                    deleteMax(max_heap); //D연산 전처리
                    if (!max_heap.empty()) { //D연산
                        is_valid[max_heap.top().second] = false; //해당 값의 유효성 변경
                        max_heap.pop(); //해당 값 삭제
                    }
                }
                if (n == -1) {  //최소값 삭제
                    deleteMin(min_heap); //D연산 전처리
                    if (!min_heap.empty()) { //D연산
                        is_valid[min_heap.top().second] = false; //해당 값의 유효성 변경
                        min_heap.pop(); //해당 값 삭제
                    }
                }
                break;  //종료
            }
        }
        //마지막으로 각 힙의 top이 valid 하도록 처리
        deleteMax(max_heap);
        deleteMin(min_heap);

        //출력
        if (max_heap.empty()) {
            cout << "EMPTY\n";  //Q가 비어있으므로 메세지 출력
        }
        else {
            cout << max_heap.top().first << ' ' << min_heap.top().first << '\n';    //최대값과 최솟값 출력
        }
        is_valid.clear(); //새로운 테스트 케이스 전 is_valid 벡터 초기화
    }
}