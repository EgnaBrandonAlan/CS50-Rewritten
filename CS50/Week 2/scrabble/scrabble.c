#include <stdio.h>

int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

typedef char *string;

long unsigned int strlen(string string);
int toupper(int letter);
int compute_score(string word);

int main(void){
    // Get input words from both players
    string word1;
    printf("Player 1: ");
    scanf("%s", word1);
    string word2;
    printf("Player 2: ");
    scanf("%s", word2);

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner based on the scores of the words
    printf("%s\n", score1 > score2 ? "Player 1 wins!" : (score2 > score1 ? "Player 2 wins!" : "Tie!"));
}

long unsigned int strlen(string string){
    int i;
    for (i = 0; string[i] != '\0'; i++){
    }
    return i;
}

int toupper(int letter){
    if(letter >= 'a' && letter <= 'z'){
        return (letter - 32);
    }
    return letter;
}

int compute_score(string word){
    int sum = 0;
    int n = strlen(word);
    // Loop through each character in the wordt
    for (int i = 0; i < n; i++)
    {
        // Convert lowercase letters to uppercase and get its ASCII value
        int points_per_letter = toupper(word[i]);
        // Use ASCII to figure out what in the points array we must add
        if (points_per_letter >= 65 && points_per_letter <= 90)
        {
            // Add the Scrabble point value of the letter to the total score
            sum += points[(points_per_letter - 65)];
        }
    }
    return sum;
}