#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(void) {
    double x = 0, y = 0;
    int count = 0, circle = 0, cnt;
    int total_points = 1000000000;
    int report_interval = 10000000;

    srand(time(NULL));

    for (count = 1; count <= total_points; count++) {
        x = (double)rand() / (double)RAND_MAX;
        y = (double)rand() / (double)RAND_MAX;

        if (x * x + y * y <= 1) {
            circle++;
        }

        if (count % report_interval == 0) {
            double pi = (4.0 * circle) / count;
            printf("진행 %.0f%%, 원주율: %f ", (double)count / total_points * 100, pi);
            for (cnt = 0; cnt < (double)count / total_points * 20; cnt++) {
                printf("■");                
            }
            for (cnt = 20; cnt > (double)count / total_points * 20; cnt--) {
                printf("□");
            }
            printf("\n");
        }
    }


    double final_pi = (4.0 * circle) / total_points;
    printf("원주율: %f\n", final_pi);

    return 0;
}