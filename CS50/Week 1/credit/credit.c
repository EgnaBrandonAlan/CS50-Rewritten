#include <stdio.h>

typedef char *string;

long unsigned int strlen(char *string);

int main(void){
    int i;
    int sum = 0;
    long long creditCard;
    printf("What is your Credit Card Number? ");
    scanf("%lld", &creditCard);
    long long dupeCC = creditCard;
    char str[17];
    sprintf(str, "%lld", creditCard);
    int length = strlen(str);

    for (i = 0; i < length; i++){
        int digit = creditCard % 10;
        creditCard /= 10;
        int add = (i % 2 == 0) ? digit : (2 * digit / 10) + (2 * digit % 10);
        sum += add;
    }

    if (sum % 10 == 0){
        while (dupeCC > 100){
            dupeCC /= 10;
        }
        if ((dupeCC == 34 || dupeCC == 37) && length == 15){
            printf("AMEX\n");
        }
        else if ((dupeCC >= 51 && dupeCC <= 55) && length == 16){
            printf("MASTERCARD\n");
        }
        else if ((dupeCC / 10 == 4 || dupeCC == 4) && (length == 13 || length == 16)){
            printf("VISA\n");
        }
        else{
            printf("INVALID\n");
        }
    }
    else{
        printf("INVALID\n");
    }
}

long unsigned int strlen(char *string){
    int i;
    for (i = 0; string[i] != '\0'; i++){
    }
    return i;
}