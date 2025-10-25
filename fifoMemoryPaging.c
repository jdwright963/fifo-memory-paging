#include <stdio.h>
#include <stdbool.h>

void FIFO(int size, int pages[], int n) {
    int* memory = (int*)malloc(size * sizeof(int));
    int count = 0;
    int faults = 0;
    int fifoIndex = 0;

    for(int i = 0; i < size; i++) {
        memory[i] = -1;
    }

    printf("FIFO\n");

    for(int i = 0; i < n; i++) {
        int page = pages[i];
        bool pageFound = false;

        for(int j = 0; j < size; j++) {
            if(memory[j] == page) {
                pageFound = true;
                break;
            }
        }

        if(!pageFound) {
            memory[fifoIndex] = page;
            fifoIndex = (fifoIndex + 1) % size;
            faults++;
        }

        printf("Faults = %d, inserting %d, memory = ", faults, page);

        for(int j = 0; j < size; j++) {
            printf("%d ", memory[j]);
        }

        printf("\n");
    }

    printf("%d page faults.\n", faults);
    free(memory);

}

int main() {
    int pages[] = {0, 1, 2, 3, 4, 4, 3, 2, 1, 0, 0, 1, 2, 3, 4, 4, 3, 2, 1, 0};
    int size = 3;

    FIFO(size, pages, sizeof(pages)/sizeof(pages[0]));

    return 0;
}