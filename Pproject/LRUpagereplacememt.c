#include <stdio.h>
#include <stdlib.h>unction to find the LRU page
int findLRU(int time[], int n) {
    int i, minimum = time[0], pos = 0;
    for(i = 1; i < n; ++i) {
        if(time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}
void simulateLRU(int pages[], int n, int capacity) {
    int *frame = (int *)malloc(capacity * sizeof(int));
    int *time = (int *)malloc(capacity * sizeof(int));
    int frame_count = 0, page_fault = 0, i, j, flag;
    for(i = 0; i < capacity; ++i) {
        frame[i] = -1;
        time[i] = 0;
    }
    printf("Page Reference String: ");
    for(i = 0; i < n; ++i) {
        printf("%d ", pages[i]);
    }
    printf("\n");
    for(i = 0; i < n; ++i) {
        flag = 0;
        for(j = 0; j < capacity; ++j) {
            if(frame[j] == pages[i]) {
                flag = 1;
                time[j] = i + 1;
                break;
            }
        }
        if(flag == 0) {
            if(frame_count < capacity) {
                frame[frame_count++] = pages[i];
            } else {
                int pos = findLRU(time, capacity);
                frame[pos] = pages[i];
            }
            page_fault++;
        }
        printf("After accessing page %d, frames are: ", pages[i]);
        for(j = 0; j < capacity; ++j) {
            printf("%d ", frame[j]);
        }
        printf("\n");
    }
    printf("Number of page faults = %d\n", page_fault);
    printf("Coded by: Prawina Regmi");
    free(frame);
    free(time);
}
int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 3;
    simulateLRU(pages, n, capacity);
    return 0;
}
