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
    for (int time = 0; time < numberOfTest; time++) {
        int printScaleA = 1;
        int printScaleB = 0;
        int scale;
        scanf("%d", &scale);
        if (scale == 0) {
            printf("\n");
            continue;
        }
        for (int i = 0; i < scale; i++) {
            for (int j = 0; j < scale; j++) {
                scanf("%d", &array[i][j]);
            }
        }
        int PointX = scale - 1;
        int PointY = scale - 1;
        for (int iteration = 0; iteration < scale; iteration++) {
            if (iteration == 0) {
                printf("%d ", array[PointX][PointY]);
                PointX--;
                printScaleA++;
                printScaleB++;
            } else if (iteration % 2 != 0) {
                for (int a = 0; a < printScaleA; a++) {
                    printf("%d ", array[PointX][PointY]);
                    if (a != printScaleA - 1) {
                        PointY--;
                    }
                }
                PointX += 1;
                for (int a = 0; a < printScaleB; a++) {
                    printf("%d ", array[PointX][PointY]);
                    if (a != printScaleB - 1) {
                        PointX++;
                    }
                }
                PointY--;
                printScaleA++;
                printScaleB++;
            } else if (iteration % 2 == 0) {
                for (int a = 0; a < printScaleA; a++) {
                    printf("%d ", array[PointX][PointY]);
                    if (a != printScaleA - 1) {
                        PointX--;
                    }
                }
                PointY++;
                for (int a = 0; a < printScaleB; a++) {
                    printf("%d ", array[PointX][PointY]);
                    if (a != printScaleB - 1) {
                        PointY++;
                    }
                }
                PointX--;
                printScaleA++;
                printScaleB++;
            }
        }
        printf("\n");
    }
    return 0;
}
