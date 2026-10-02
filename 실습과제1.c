#include <stdio.h>

// 필수 함수 원형 선언
void swap(int *x, int *y);
void selection_sort(int a[], int n);
int binary_search(const int a[], int n, int key);

int main() {
    int scores[5];
    int target_score;
    int n = 5;

    // 1. 5개의 정수 점수 입력
    for (int i = 0; i < n; i++) {
        scanf("%d", &scores[i]);
    }

    // 2. 찾을 점수 입력
    scanf("%d", &target_score);

    // 3. 선택 정렬 수행
    selection_sort(scores, n);

    // 4. 정렬된 배열 출력
    for (int i = 0; i < n; i++) {
        printf("%d ", scores[i]);
    }
    printf("\n");

    // 5. 이진 탐색 수행 및 결과 출력
    int index = binary_search(scores, n, target_score);
    printf("%d\n", index);

    return 0;
}

// 주소를 받아 두 원소의 값을 교환하는 함수
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// 전달받은 배열을 오름차순으로 정렬하는 선택 정렬 함수
void selection_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        // 최솟값의 위치가 바뀌었다면 swap 수행
        if (min_idx != i) {
            swap(&a[i], &a[min_idx]);
        }
    }
}

// 배열에서 키 값을 찾아 인덱스 또는 -1을 반환하는 이진 탐색 함수
int binary_search(const int a[], int n, int key) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (a[mid] == key) {
            return mid; // 값을 찾은 경우 해당 인덱스 반환
        } else if (a[mid] < key) {
            left = mid + 1; // 찾는 값이 더 크면 오른쪽 탐색
        } else {
            right = mid - 1; // 찾는 값이 더 작으면 왼쪽 탐색
        }
    }

    return -1; // 값을 찾지 못한 경우
}