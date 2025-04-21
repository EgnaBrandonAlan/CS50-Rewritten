#include <stdio.h>

typedef char *string;

long unsigned int strlen(string string);
int int_round(float number);
int isalpha(int character);
int count_letters(string user_text);
int count_words(string user_text);
int count_sentences(string user_text);

int main(void){
    // TODO get a string from the user
    char text[65536];
    printf("What is your text? ");
    fgets(text, sizeof(text), stdin);
    // TODO Run the string through the three functions that calculate the letters, words, and sentences in the string
    float L = (float) count_letters(text) / count_words(text) * 100;
    float S = (float) count_sentences(text) / count_words(text) * 100;
    // TODO Calculate the Reading level:
    float index = 0.0588 * L - 0.296 * S - 15.8;
    // TODO Print "Grade x" where x is the grade level of the text according to the Coleman-Liau index
    if (int_round(index) > 1 && int_round(index) < 16)
    {
        printf("Grade %i\n", (int) int_round(index));
    }
    else if (int_round(index) < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
}

long unsigned int strlen(string string){
    int i;
    for (i = 0; string[i] != '\0'; i++){
    }
    return i;
}

int int_round(float number){
    int rounded = (int)(number < 0 ? (number - 0.5) : (number + 0.5));
    return rounded;
}

int isalpha(int character){
    if ((character >= 65 && character <= 90) || (character >= 97 && character <= 122)){
        return 1;
    }
    else{
        return 0;
    }
}

int count_letters(string user_text){
    int letter_amount = 0;
    for (int i = 0; i < strlen(user_text); i++){
        if (isalpha(user_text[i]) == 1){
            letter_amount += 1;
        }
    }

    return letter_amount;
}

int count_words(string user_text){
    int word_amount = 1;
    for (int i = 0; i < strlen(user_text); i++){
        if (user_text[i] == ' '){
            word_amount += 1;
        }
    }

    return word_amount;
}

int count_sentences(string user_text){
    int sentence_amount = 0;

    for (int i = 0; i < strlen(user_text); i++){
        if (user_text[i] == '.' || user_text[i] == '?' || user_text[i] == '!'){
            sentence_amount += 1;
        }
    }
    return sentence_amount;
}