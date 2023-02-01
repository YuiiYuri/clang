#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    time_t t;
    srand((unsigned) time(&t));
    int tarot[52];
    int a, b;
    int temp;
    for(int i = 0; i < 52; i++){
        tarot[i] = i;
        //printf("%d ", tarot[i]);
    }
    //printf("\n");
    for(int i = 0; i < 100; i++){
        a = rand() % 52;
        b = rand() % 52;
        //printf("%d %d \n", a, b);
        temp = tarot[a];
        tarot[a] = tarot[b];
        tarot[b] = temp;
    }
    for(int i = 0; i < 52; i++){
        printf("%d ", tarot[i]);
    }
    printf("\n");
    int j = 0;
    for(int p = 1; p < 5; p++){
        printf("Card of player %d: \n", p);
        for(int i = 0; i < 13; i++){
        int X = tarot[j] % 13;
        switch(X){
            case 0:
            printf("A");
            break;
            case 1:
            printf("2");
            break;
            case 2:
            printf("3");
            break;
            case 3:
            printf("4");
            break;
            case 4:
            printf("5");
            break;
            case 5:
            printf("6");
            break;
            case 6:
            printf("7");
            break;
            case 7:
            printf("8");
            break;
            case 8:
            printf("9");
            break;
            case 9:
            printf("10");
            break;
            case 10:
            printf("J");
            break;
            case 11:
            printf("Q");
            break;
            case 12:
            printf("K");
            break;
        }
        X = tarot[j] % 4;
        switch(X){
            case 0:
            printf("_Co ");
            break;
            case 1:
            printf("_Ro ");
            break;
            case 2:
            printf("_Tep ");
            break;
            case 3:
            printf("_Bich ");
            break;
        }
        j++;
    }
            printf("\n");          
    }
    int card = 0;
    for(int p = 1; p < 5; p++){
        int the4[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
        int stat = 0;
        for(int i = 0; i < 13; i++){
            int C4 = tarot[card] % 13;
            the4[C4]++;
            card++;
        }
        for(int i = 0; i < 13; i++){
            if(the4[i] == 4){
            printf("Player %d has the 4\n", p);
            stat = 1;
            }
        }
        if(stat == 0){
            printf("Player %d has no the 4\n", p);
        }
    }   
    return 0;
}