#include <stdio.h>
#include <string.h>
//Define the structure of objects
typedef struct
{
    int weight;
    int value;
    char name;
} oj;
//The dynamic programming

int KnapSack(oj object[], int n, int W)
{
    int dp[W+1];
    memset(dp, 0, sizeof(dp));

    for(int i=0; i <= W; i++)
        for(int j=0; j<n; j++)
            if (object[j].weight <= i)
            {
                if (dp[i] >= object[j].value + dp[i- object[j].weight]) dp[i] = dp[i];
                else dp[i] = object[j].value + dp[i- object[j].weight];
            }
    return dp[W];
}
void truyvet(oj object[],int n,int W)
{
    if
}
int main()
{
    FILE *input;
    input = fopen("BAG.INP","r");
    int N,W;
    fscanf(input, "%d %d\n", &N, &W);
    oj object[N];
    //Input the value
    for (int i = 0; i < N; ++i)
         fscanf(input, "%d %d %c\n", &object[i].weight, &object[i].value, &object[i].name);
    printf("%d\n", KnapSack(object,N,W));


}
