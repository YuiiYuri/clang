#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE* f;
    FILE* f0;
    int a, b, c;
    long int aCb = 0;

    f = fopen("assi1input.txt", "r");
    f0 = fopen("assi1output.txt", "w");

    if (f == NULL) {
        printf("file can't be opened \n");
    }

    while(!feof(f)){
    fscanf(f, "%d %d\n", &a, &b);
    c = a - b;
    if (c < 0){
        //printf("Error input!  Check file please!\n");
        fprintf(f0, "Error input!  Check file please!\n");
    }
    else {
    long int gt_a = 1;
    long int gt_b = 1;
    long int gt_c = 1;
    for(int i = 1; i<=a; i++){
        gt_a = gt_a * i;
    }
    for(int i = 1; i<=b; i++){
        gt_b = gt_b * i;
    }
    for(int i = 1; i<=c; i++){
        gt_c = gt_c * i;
    }
    aCb = gt_a / (gt_b * gt_c);
    //printf("%d, %d, %d\n", a, b, c);
    //printf("%ld, %ld, %ld\n", gt_a, gt_b, gt_c);
    //printf("%ld\n", aCb);
    fprintf(f0, "%ld\n", aCb);
    //fprintf(f0, "%d, %d\n", a, b);
    }
    }

    fclose(f0);
    fclose(f);
    return 0;
}