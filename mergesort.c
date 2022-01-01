#include <stdio.h>
#include <cs50.h>
#include <math.h>
typedef struct
{
    int valor;
    int posi;
}
teste;
void print_array(int array[],int array_size, int start_point);

int merge_sort(int vector[], int sorted_vector[], int vector_size, int start)
{

    if (vector_size == 1)
    {
        sorted_vector[start] = vector[start];
        return 0;
    }
    else
    {

        // sort left half
        merge_sort(vector, sorted_vector, vector_size / 2, start);

        // sort right half
        merge_sort(vector,sorted_vector, vector_size - (vector_size / 2), start + vector_size / 2);

        //merge right and left
        int left_size = vector_size / 2;
        int right_size = vector_size - left_size;
        int left_start = start, right_start = start + left_size;
        int left_end = left_start + left_size, right_end = right_start + right_size;

        for (int i = start; i < start + vector_size; i++)
        {
            // verify if left has the smallest one and sort if it have
            if (sorted_vector[left_start] > sorted_vector[right_start])
            {
                vector[i] = sorted_vector[left_start];
                left_start++;

                // verify if left half ended, if it have, put the right half in the vector
                if (left_start == left_end)
                {
                    for(int j = i+1; j < start + vector_size; j++)
                    {

                        vector[j] = sorted_vector[right_start];
                        right_start++;

                    }
                    break;
                }
            }
            else
            {

                vector[i] = sorted_vector[right_start];
                right_start++;

                // verify if right half ended, if it have, put the left half in the vector
                if (right_start == right_end)
                {
                    for (int j = i + 1; j < start + vector_size; j++ )
                    {
                        vector[j] = sorted_vector[left_start];
                        left_start++;
                    }
                    break;
                }

            }

        }


    }
    for (int i = 0; i < start + vector_size; i++)
    {
        sorted_vector[i] = vector[i];
    }
    return 0;
}
int main(void)
{
    int n = 5;
    int sorted_vector[n];
    int vector[] = {4,1,3,2,14};
    merge_sort(vector,sorted_vector, n, 0);
    print_array(vector,n,0);
}

void print_array(int array[], int array_size, int start_point)
{
    for(int i = start_point; i < start_point + array_size; i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n");
}