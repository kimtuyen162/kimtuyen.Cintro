#include <stdio.h>
#include <time.h>
#include <stdbool.h>

int main ()
{
    srand(time(NULL));
    char number[13][3] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    char type [4][10] = {"Hearts","Diamonds","Spades","Clubs"};
    bool check[13][4], hand[13][4];

    //Reset value
    for (int i = 0;i < 13; i++)
        for (int j = 0;j < 4; j++)
        {
            check[i][j] = false;
            hand[i][j] = false;
        }

    //Deal the cards
    for (int k = 0; k < 4;k ++)
    {
        printf("Cards in hand of player number %d are: \n", k+1);
        for (int i = 0; i < 13; i++)
        {
            int x = rand()%52;
            if (check[x/4][x%4] == false)
            {
                check[x/4][x%4] = true;
                hand[x/4][x%4] = true;
            }
            else
            {
                while (check[x/4][x%4] == true)
                {
                    if (x == 51)
                        x = 0;
                    else
                        x++;
                }
                check[x/4][x%4] = true;
                hand[x/4][x%4] = true;
            }
            printf("%s %s\n", number[x/4], type[x%4]);
        }

    //Checking for four cards in hand//
        for (int x = 0;x < 52; x+=4)
            if (hand[x/4][x%4] == true && hand[x/4][x%4 +1] == true && hand[x/4][x%4+2] == true && hand[x/4][x%4+3] == true)
                printf("Player number %d has four cards of %s\n", k+1, number[x/4]);

    //reset bool hand//
        for (int i = 0; i < 13; i++)
            for (int j = 0 ; j < 4; j++)
                hand[i][j] = false;
    printf("\n\n");
    }
    return 0;
}
