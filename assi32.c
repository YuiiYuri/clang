#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MINUTE 60
#define HOUR 3600

int main(int argc, char *argv[]) {
    int day_count = 0, 
        day_5_15_count = 0, 
        day_16_22_count = 0;
    float day_sum = 0, 
        day_5_15_sum = 0, 
        day_16_22_sum = 0;
    int day, month, year, hour, minute, second;
    float temperature;
    char buffer[100];
    FILE *fp = fopen("temp.txt", "r");
    while (fgets(buffer, 100, fp)) {
        if (sscanf(buffer, "%2d-%2d-%4d %2d:%2d:%2d", &day, &month, &year, &hour, &minute, &second) == 6) {
            if (fgets(buffer, 100, fp)) {
                if (sscanf(buffer, "%f", &temperature) == 1) {
                    day_count++;
                    day_sum += temperature;
                    if (hour >= 5 && hour < 16) {
                        day_5_15_count++;
                        day_5_15_sum += temperature;
                    } else if (hour >= 16 && hour < 22) {
                        day_16_22_count++;
                        day_16_22_sum += temperature;
                    }
                }
            }
        }
    }
    printf("Ngày %d-%d-%d:\n", day, month, year);
    printf("Trung bình nhiệt độ ngày: %.3f\n", (float) day_sum / day_count);
    printf("Trung bình nhiệt độ từ 5h00 đến 15h59: %.3f\n", (float) day_5_15_sum / day_5_15_count);
    printf("Trung bình nhiệt độ từ 16h00 đến 21h59: %.3f\n", (float) day_16_22_sum / day_16_22_count);
    fclose(fp);
    return 0;
}