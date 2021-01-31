#include <stdio.h>
//Define the structure of objects
typedef struct
{
    int weight;
    int value;
    float rate;
    char name;
} oj;
//Define the structure of the chosen objects
typedef struct
{
    char name;
    int amount;
} ojchosen;
//Swap two structures
void swap(oj *x1, oj *x2)
{
    oj tmp;
    tmp = *x1;
    *x1 = *x2;
    *x2 = tmp;
}
int main()
{
    FILE *input;
    input = fopen("BAG.INP","r");
    int N,W;
    fscanf(input, "%d %d\n", &N, &W);
    oj object[N];
    ojchosen object_chosen[N];
    //Input the value
    for (int i = 0; i < N; ++i)
    {
        fscanf(input, "%d %d %c\n", &object[i].weight, &object[i].value, &object[i].name);
        object[i].rate = ((float)object[i].value) / object[i].weight; //Calculate the rating of objects
    }
    //Sort the rating of objects
    for (int i = 0; i < N; ++i)
        for (int j = i+1; j<N; j++)
            if (object[i].rate < object[j].rate)
                swap(&object[i], &object[j]);

    int count=0, sum=0;
    //Find the best way(Greedy thesis)//
    for (int i = 0; i < N; ++i)
    {
        if (W >= object[i].weight)
        {
            object_chosen[count].name = object[i].name;
            object_chosen[count].amount = W / object[i].weight;
            W = W % object[i].weight;
            sum += object_chosen[count].amount * object[i].value;
            ++count;
        }

        if (W == 0) break;
    }

    printf("%d\n", sum);
    for (int i = 0; i<count; ++i)
        printf("%c %d\n", object_chosen[i].name, object_chosen[i].amount);
    fclose(input);
    return 1;
}
