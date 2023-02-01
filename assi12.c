#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    time_t t;
    int N;
    srand((unsigned) time(&t));
    printf("Enter N:\n");
    scanf("%d", &N);
    int array[N];
    for(int i = 0; i < N; i++){
        array[i] = rand() % 10;
    }
    for(int i = 0; i < N; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    int stat = 0;
    int suml = 0;
    int sumr = 0;
    for(int i = 0; i < N; i++){
        for(int l = 0; l < i; l++){
            suml = suml + array[l];
        }
        for(int r = N - 1; r > i; r--){
            sumr = sumr + array[r];
        }
        //printf("%d %d\n", suml, sumr);
        if(suml == sumr){
            //printf("YES, that is N[%d]:%d\n", i + 1, array[i]);
            printf("YES\n");
            stat = 1;
        }
        suml = sumr = 0;
    }
    if(stat == 0){
        printf("NO\n");
    }
    return(0);
}