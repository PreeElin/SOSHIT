#include <stdio.h>
#include <stdlib.h>
int findOPR(int pages[], int n, int frames[], int frame_count) {
    int i, j, max_future = 0, pos = 0;
    for(i = 0; i < frame_count; i++) {
        int future = 0;
        for(j = 0; j < n; j++) {
            if(pages[j] == frames[i]) {
                future = 1;
                break;
            }
        }
        if(future == 0) {
            return i;
        }
    }
    return -1;
}
void simulateOPR(int pages[], int n, int capacity) {
    int *frames = (int *)malloc(capacity * sizeof(int));
    int frame_count = 0, page_fault = 0, i, j;
    for(i = 0; i < capacity; ++i) {
        frames[i] = -1;
    }
    printf("Page Reference String: ");
    for(i = 0; i < n; ++i) {
        printf("%d ", pages[i]);
    }
    printf("\n");
    for(i = 0; i < n; ++i) {
        int flag = 0;
        for(j = 0; j < capacity; ++j) {
            if(frames[j] == pages[i]) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            if(frame_count < capacity) {
                frames[frame_count++] = pages[i];
            } else {
                int pos = findOPR(pages, n, frames, capacity);
                frames[pos] = pages[i];
            }
            page_fault++;
        }
        printf("After accessing page %d, frames are: ", pages[i]);
        for(j = 0; j < capacity; ++j) {
            printf("%d ", frames[j]);
        }
        printf("\n");
    }
    printf("Number of page faults = %d\n", page_fault);
    printf("Coded by: Prawina Regmi");
    free(frames);
}

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 3;
    simulateOPR(pages, n, capacity);
    return 0;
}
