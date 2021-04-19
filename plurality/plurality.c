#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
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

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }

    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{

    // loops through each vote
    for (int i = 0; i < candidate_count; i++)
    {
        // add 1 to the candidate's vote total, if the name matches one from the candidates list
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
        // if name does not find a match, return false
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // find the winning number of votes
    int votes_win = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        // update the votes_win variable, if a candidate has more votes than what the varaible was previously set to
        if (candidates[i].votes > votes_win)
        {
            votes_win = candidates[i].votes;
        }
    }

    // find the winner
    for (int i = 0; i < candidate_count; i++)
    {
        // print the name of the winner, if their vote total matches the winning vote total
        if (candidates[i].votes == votes_win)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}

