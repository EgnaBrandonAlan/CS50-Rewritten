#include <stdio.h>

int main(void){
    int height;
    int base = 2;

    do{
        printf("How high is the pyramid (1-8 blocks)?: ");
        scanf("%d", &height);
    }
    while (height < 1 || height > 8);

    for (int i = 0; i < height; i++){
        for (int j = 0; j < height - i - 1; j++){
            printf(" ");
        }

        for (int j = 0; j < base / 2; j++){
            printf("#");
        }

        printf(" ");

        for (int j = 0; j < base / 2; j++)
        {
            printf("#");
        }

        base = base + 2;
        printf("\n");
    }
}