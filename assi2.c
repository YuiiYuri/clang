#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100
#define MAX_W 1000

int N, W;
float value[MAX_N + 1];
char names[MAX_N + 1];
int number[MAX_N + 1];
int vals[MAX_N + 1];
void readfile(){
    FILE* f;
    f = fopen("assi2input.txt", "r");
    fscanf(f, "%d %d", &N, &W);
    for(int i = 0; i < N; i++ ){
        float w = 0;
        float val = 0;
        fscanf(f, "%f %f %c \n", &w, &val ,&names[i]);
        value[i] = val / w;
        number[i] = w;
        vals[i] = val;
        //printf("%c ", names[i]);
        //printf("%f \n", value[i]);
    }
    fclose(f);
}

void merge(){
    for(int i = 0; i < N - 1; i++){
        for(int j = 0; j < N - i - 1; j++){
            if(value[j] < value[j + 1]){
                float temp = value[j];
                value[j] = value[j + 1];
                value[j + 1] = temp;

                char tempname = names[j];
                names[j] = names[j + 1];
                names[j + 1] = tempname;

                int tempnumb = number[j];
                number[j] = number[j + 1];
                number[j + 1] = tempnumb;

                int tempval = vals[j];
                vals[j] = vals[j + 1];
                vals[j + 1] = tempval;
            }
        }
    }
}

void solve(){
    int sum = 0;
    int count[MAX_N +1];
    int running = W;
    for(int i = 0; i < N; i++){
        count[i] = running / number[i];
        running = running % number[i];
        sum = sum + count[i] * vals[i]; 
    }
    printf("%d\n", sum);
    for(int i = 0; i < N; i++){
        printf("%c %d\n", names[i], count[i]);
    }   
}

int main(){
    readfile();
    merge();
    //for(int i = 0; i < N; i++){
    //    printf("%c %d %d %f\n", names[i], number[i], vals[i], value[i]);
    //}  
    solve();
    return 0;
}