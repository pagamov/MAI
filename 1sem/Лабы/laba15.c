#include <stdio.h>

int numberOfTest, maxScale;

int main(void)
{
    scanf("%d", &numberOfTest);
    scanf("%d", &maxScale);
    int array[maxScale][maxScale];
    for (int i = 0; i < maxScale; i++) {
        for (int j = 0; j < maxScale; j++) {
            array[i][j] = 0;
        }
    }
    if (numberOfTest == 0) {
        printf("\n");
    }
    for (int time = 0; time < numberOfTest; time++) {
        int maxWalue = -50000;
        int maxWalueIndex = -1;
        int scale;
        scanf("%d", &scale);
        for (int i = 0; i < scale; i++) {
            for (int j = 0; j < scale; j++) {
                scanf("%d", &array[i][j]);
            }
        }
        for (int i = 0; i < scale; i++) {
            for (int j = 0; j < scale; j++) {
                if (array[j][i] > maxWalue) {
                    maxWalueIndex = i;
                    maxWalue = array[j][i];
                }
            }
        }
        if (scale == 0) {
            printf("\n");
        } else if (scale == 1) {
            for (int i = 0; i < scale; i++) {
                for (int j = 0; j < scale; j++) {
                    printf("%d ", array[i][j]);
                }
                printf("\n");
            }
        } else if (scale % 2 == 0) {
            int iteration = scale / 2;
            int swap;
            for (int i = 0; i < iteration; i++) {
                swap = array[i][maxWalueIndex];
                array[i][maxWalueIndex] = array[scale - 1 - i][maxWalueIndex];
                array[scale - 1 - i][maxWalueIndex] = swap;
            }
            for (int i = 0; i < scale; i++) {
                for (int j = 0; j < scale; j++) {
                    printf("%d ", array[i][j]);
                }
                printf("\n");
            }
        } else if (scale % 2 != 0) {
            int iteration = (scale - 1) / 2;
            int swap;
            for (int i = 0; i < (iteration); i++) {
                swap = array[i][maxWalueIndex];
                array[i][maxWalueIndex] = array[scale - 1 - i][maxWalueIndex];
                array[scale - 1 - i][maxWalueIndex] = swap;
            }
            for (int i = 0; i < scale; i++) {
                for (int j = 0; j < scale; j++) {
                    printf("%d ", array[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
