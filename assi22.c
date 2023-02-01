#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    time_t t;
    srand((unsigned) time(&t));
    int number = rand() % 100 +1;
    //printf("%d \n", number);
    int numc = 0;  
    printf("Type the number\n");
    scanf("%d", &numc);
    while(numc != number){
        if(numc < number){
            printf("n<x\n");
        }
        else{
            printf("n>x\n");
        }
        printf("Re-type the number:\n");
        scanf("%d", &numc);
    } 
    printf("Correct!\n");
    return(0);
}