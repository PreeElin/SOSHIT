#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void SCAN(int arr[], int head, int size) {
    int seek_count = 0;
    int distance, cur_track;
    int *left = (int *)malloc(size * sizeof(int));
    int *right = (int *)malloc(size * sizeof(int));
    int *seek_sequence = (int *)malloc(2 * size * sizeof(int));
    int left_size = 0, right_size = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < head)
            left[left_size++] = arr[i];
        else if (arr[i] > head)
            right[right_size++] = arr[i];
    }
    qsort(left, left_size, sizeof(int), compare);
    qsort(right, right_size, sizeof(int), compare);
    for (int i = 0; i < right_size; i++) {
        cur_track = right[i];
        seek_sequence[i] = cur_track;
        distance = abs(cur_track - head);
        seek_count += distance;
        head = cur_track;
    }
    head = 0;
    seek_count += (200 - 1);
    for (int i = 0; i < left_size; i++) {
        cur_track = left[i];
        seek_sequence[i + right_size] = cur_track;
        distance = abs(cur_track - head);
        seek_count += distance;
        head = cur_track;
    }
    printf("Total number of seek operations = %d\n", seek_count);
    printf("Seek Sequence is\n");
    for (int i = 0; i < 2 * size; i++) {
        printf("%d ", seek_sequence[i]);
    }
    printf("\n");
    free(left);
    free(right);
    free(seek_sequence);
}

int main() {
    int arr[] = {176, 79, 34, 60, 92, 11, 41, 114};
    int head = 50;
    int size = sizeof(arr) / sizeof(arr[0]);
    SCAN(arr, head, size);
    return 0;
}
