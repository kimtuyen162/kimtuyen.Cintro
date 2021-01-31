#include <stdio.h>

int main()
{
    int k,n;
    FILE *input;
    FILE *output;
    input=fopen("TOHOP.INP","r");
    output=fopen("TOHOP.OUT","w+");

    while(fscanf(input,"%d %d\n",&n,&k) != EOF)
    {
        long long res=1;
        if (k>n) fprintf(output,"0\n");
        else if (2>n || n>30 || k<0) fprintf(output,"Invalid input.\n");
        else
        {
            for(int i=n, j=1; i>k, j<=n-k;i--,j++)
            res=res*i/j;
            fprintf(output,"%lld\n", res);
        }
    }

    fclose(input);
    fclose(output);
    return 1;
}
