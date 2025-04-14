#include <stdio.h>

typedef char *string;


long unsigned int strlen(string string);
int count_letters(string user_text);
int count_words(string user_text);
int count_sentences(string user_text);

int main(void){
    // TODO get a string from the user
    string text;
    printf("What is your text? ");
    scanf("%s", &text);
    // TODO Run the string through the three functions that calculate the letters, words, and sentences in the string
    float L = (float) count_letters(text) / count_words(text) * 100;
    float S = (float) count_sentences(text) / count_words(text) * 100;
    // TODO Calculate the Reading level:
    float index = 0.0588 * L - 0.296 * S - 15.8;
    // TODO Print "Grade x" where x is the grade level of the text according to the Coleman-Liau index
    if (round(index) > 1 && round(index) < 16)
    {
        printf("Grade %i\n", (int) round(index));
    }
    else if (round(index) < 1)
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

int count_letters(string user_text){

}

int count_words(string user_text){

}

int count_sentences(string user_text){

}