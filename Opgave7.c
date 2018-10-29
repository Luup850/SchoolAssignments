#include<stdio.h>
#include<stdlib.h>

/* Prototypes */
int findByteSize(double *array1, double *array2, int arraySize1, int arraySize2);
void sortArray(double *arraySort1, double *arraySort2, double *newArray, int newArraySize, int arraySize1, int arraySize2);


int main(void)
{
    double *combinedArray;
    double array1[] = {-10.5, -1.8, 3.5, 6.3, 7.2};
    double array2[] = {-1.8, 3.1, 6.3};
    int arraySize1 = sizeof(array1) / sizeof(double), arraySize2 = sizeof(array2) / sizeof(double);
    int combinedArraySize = findByteSize(array1, array2, arraySize1, arraySize2) / sizeof(double);

    combinedArray = malloc(findByteSize(array1, array2, arraySize1, arraySize2));
    sortArray(array1, array2, combinedArray, combinedArraySize, arraySize1, arraySize2);

    for(int i = 0; i <= combinedArraySize; i++)
    {
        printf("[%d] %lf\n", i, combinedArray[i]);
    }

    free(combinedArray);
    return 0;
}

int findByteSize(double *array1, double *array2, int arraySize1, int arraySize2)
{
    int a = 0, b = 0, size = 1;
    
    for(int i = 0; i < arraySize1; i++)
    {
        for(int j = 0; j < arraySize2; j++)
        {
            if(array1[i] == array2[j])
                size++;
        }
    }

    return (arraySize1 + arraySize2 - size) * sizeof(double);
}

void sortArray(double *arraySort1, double *arraySort2, double *newArray, int newArraySize, int arraySize1, int arraySize2)
{
    int a = 0, b = 0;

    for(int i = 0; i <= newArraySize; i++)
    {
        if(arraySort1[a] < arraySort2[b] || arraySize2 <= b)
        {
            newArray[i] = arraySort1[a];
            a++;
        }
        else if(arraySort1[a] > arraySort2[b] || arraySize1 <= a)
        {
            newArray[i] = arraySort2[b];
            b++;
        }
        else if(arraySort1[a] == arraySort2[b])
        {
            newArray[i] = arraySort1[a];
            a++;
            b++;
        }

        if(arraySize1 <= a && arraySize2 <= b)
        {
            i = newArraySize + 1;
        }
    }
}