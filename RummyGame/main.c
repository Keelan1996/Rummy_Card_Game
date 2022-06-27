#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define deck_size 52 //Defining deck size.


//Functions to be used in the program.
void instructions();
void create_deck(int*);
void shuffle_deck(int n, int*);
void display_card(int card);


int main()
{
    //Main variables for the program.
    int answer, ans2, n = 0, deck[deck_size], userhand;

    do //Do while loop for question if user wants to play game.
    {
        printf("\nWould you like to play Card Count? (Press 1 if you do or\n");
        printf("anything else to exit.)\n ");
        scanf("%d", &answer);
        if (answer != 1)
        {
            exit(0); //Exit program if user does not want to play.
        }
    } while (answer != 1);

    //Do while loop to run game again if the user chooses to.
    do
    {
        instructions(); //Calls instructions function.
        create_deck(deck); //Calls create deck function.
        shuffle_deck(n, deck); //Calls shuffle deck function.

        //Asks user if he or she wishes to play the game again.
        printf("\n\nWould you like to play again?(Press 1 to play again or anything else to exit)\n");
        scanf("%d", &ans2);
        printf("\n\n-------------------------------------------------------------------------------\n\n");
    } while (ans2 == 1); //End of while loop.

    printf("\n\nTHANKS FOR PLAYING!!!\n\n"); //Comment to the user if he chooses to not play again.
    return 0;
}

void instructions()
{
    //Al print outs to the user explaining the game and point system.
    printf("\nThis is a card game. 5 cards will be dealt to each player\n");
    printf("(User and computer), and the person with the highest amount of points will\n");
    printf("win the round.\n\nPoints are awarded in the following way:\nJack, Queen and King ");
    printf("are worth 10 points.\nAce is 11 points and numbers are their own score.\n\n");
}

void create_deck(int deck[])
{
    int i;

    for (i = 0; i < deck_size; i++) //Creates a card deck of 52 cards
    {
        deck[i] = i; //Deck stored in an array.
    }
}

void shuffle_deck(int n, int deck[])
{
    int card, temp, i;

    srand(time(NULL)); //Shuffles deck with srand and time features.

    for (; n >= 0; n--)
    {
        i = rand() % 52; //Flips the value from i to n by the way of a temporal variable.
        temp = deck[i];
        deck[i] = deck[n];
        deck[n] = temp;
    }

    //Player's 5 card hand is displayed
    printf("\nPlayer's hand:\n\n");
    for (n = 0; n < 5; n++)
    {
        card = rand() % deck_size; //Deals 5 random cards with the rand feature.
        display_card(card); //Calls display card function.
    }

    //Computer's 5 cards are dealt and displayed.
    printf("\nComputer's hand:\n\n");
    for (n = 6; n < 11; n++)
    {
        card = rand() % deck_size; //Deals 5 random cards with the rand feature.
        display_card(card); //Calls display card function.
    }
}

void display_card(int card)
{
    char* deck[4] = { "Spades", " Hearts", "Clubs", "Diamonds" }; //First 4 values of the array deck.
    int a = 0, j = 0, q = 0, k = 0, cardnum = 0, sum;

    switch (card % 13) //Switch statement to identify suite, and face.
    {
    case 0:
        printf("%s", "Ace"); //For case 0 it would be an ace.
        a = 11; //Code done if the case is true.
        break; //Breaks the statement and checks for next number.

    case 10:
        printf("%s", "Jack"); //For case 00 it would be a jack.
        j = 10; //Code done if the case is true.
        break; //Breaks the statement and checks for next number.

    case 11:
        printf("%s", "Queen"); //For case 11 it would be a queen.
        q = 10; //Code done if the case is true.
        break; //Breaks the statement and checks for next number.

    case 12:
        printf("%s", "King"); //For case 12 it would be a king.
        k = 10; //Code done if the case is true.
        break; //Breaks the statement and checks for next number.

    default:
        printf("%d", card % 13 + 1); //If neither of the cases work it would do the default. In this case
        cardnum = card % 13 + 1;     //print the number.

    }

    printf(" of %s\n", deck[card / 13]); //Print the type of face in the case of a case being true.


}