#include <cs50.h>
#include <stdio.h>

// declare un-sorted list of integers
int rand_int[6] = {9,8,5,10,10,6};

int list_len = 6;

int main(void)
{

    int swap_counter = 1;

    while (swap_counter != 0)
    {
        swap_counter = 0;

        for (int i = 0; i < list_len - 1; i++)
        {

            int rand_int_i = rand_int[i];

            int rand_int_i_one = rand_int[i+1];

            if(rand_int[i] > rand_int[i+1])
            {
                rand_int[i] = rand_int_i_one;
                rand_int[i+1] = rand_int_i;
                printf("swapped! \n");
                swap_counter++;
            }

        }

    }
}