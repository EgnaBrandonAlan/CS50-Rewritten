#include <stdio.h>

// Max number of candidates
#define MAX 9

typedef char *string;

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
int vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    printf("Number of voters: ");
    int voter_count;
    scanf("%d", &voter_count);

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        printf("Vote: ");
        string name; 
        scanf("%s", &name);

        // Check for invalid vote
        if (vote(name) == 0)
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
int vote(string name)
{
    // Loop through each person in the candidates[x].name array
    for (int i = 0; i < candidate_count; i++)
    {
        // Using strcmp(), if there is a match, increase candidates[x].votes by one and return true
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return 1;
        }
    }
    // If there is no match, return false
    return 0;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // Create a variable called winner of type int
    int winner = 0;
    // Loop through each vote total in the candidates[x].votes array
    for (int i = 0; i < candidate_count; i++)
    {
        // If candidates[x].votes is greater than the current value of winner replace it
        if (candidates[i].votes > winner)
        {
            winner = candidates[i].votes;
        }
    }
    // Loop through the array again and print every candidate with vote total matching the winner variable
    for (int i = 0; i < candidate_count; i++)
    {
        // Print all candidates with a vote value equal to winner
        if (candidates[i].votes == winner)
        {
            printf("%s\n", candidates[i].name);
        }
    }

    return;
}
