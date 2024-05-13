#include <stdio.h>

int main() {
    int i, j, n, a[50], frame[10], no, k, avail, count = 0;
    printf("\n ENTER THE NUMBER OF PAGES:\n");
    scanf("%d", &n);
    printf("\n ENTER THE PAGE NUMBERS:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("\n ENTER THE NUMBER OF FRAMES :");
    scanf("%d", &no);
    for(i = 0; i < no; i++) {
        frame[i] = -1;
    }
    j = 0;
    printf("\tref string\t page frames\n");
    for(k = 0; k < n; k++) {
        avail = 0;
        for(i = 0; i < no; i++) {
            if(frame[i] == a[k]) {
                avail = 1;
                break;
            }
        }
        if(avail == 0) {
            frame[j] = a[k];
            j = (j + 1) % no;
            count++;
        }
        printf("%d\t\t", a[k]);
        for(i = 0; i < no; i++) {
            printf("%d\t", frame[i]);
        }
        printf("\n");
    }
    printf("\nPage Fault Is %d", count);
    printf("\nCoded by: Prawina Regmi");
    return 0;
}

