#include <stdio.h>

int main() {
    int arr[5] = { 0, };
    int sum = 0;

    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    printf("%d\n", sum / 5);
    for (int i = 0; i < 5; i++) {
        if (arr[i] <= 10) {
            printf("%d ���α׷��� ���ʹ�", arr[i]);
        }
        else if (arr[i] < 45) {
            printf("%d ���α׷��ֹ�", arr[i]);
        }
        else {
            printf("%d �ٸ� ����� ����", arr[i]);
        }
    }
    return 0;
}