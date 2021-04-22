#include <cs50.h>
#include <stdio.h>

// declare un-sorted list of integers
int rand_int[6] = {5,3,2,9,6,1};

int list_len = 6;

int main(void)
{


    for (int i = 0; i < list_len; i++)
    {
        int swap_counter = 1;

       while (swap_counter != 0)
       {
           swap_counter = 0;

           int rand_int_i = rand_int[i];

           int rand_int_i_one = rand_int[i+1];

           if(rand_int[i] > rand_int[i+1])
           {
               rand_int[i] = rand_int_i_one;
               rand_int[i+1] = rand_int_i;
               printf("%i \n", rand_int[i]);
               swap_counter++;
           }
        }


   }
}




