#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
typedef struct{
    char book_name[30];
    char author_name[30];
    char publisher[20];
    int year;
    float price;
}book;

void new_info(int n, book *new_book){
    FILE *fpointer = fopen("HUST.txt","a+");
    for(int i=0; i<n;i++){
        printf("Book's Name?");fflush(stdin);gets(new_book->book_name);
        printf("Author's Name?");gets(new_book->author_name);
        printf("Publisher?");gets(new_book->publisher);
        printf("Year of publication?");scanf("%d",&(new_book->year));
        printf("Price?");scanf("%f",&(new_book->price));

        fprintf(fpointer,"%s\n",new_book->book_name);
        fprintf(fpointer,"%s\n",new_book->author_name);
        fprintf(fpointer,"%s\n",new_book->publisher);
        fprintf(fpointer,"%d\n",new_book->year);
        fprintf(fpointer,"%f\n",new_book->price);
        fprintf(fpointer,"\n");
    }
    fclose(fpointer);
    printf("Done!\n");
}

void prt_sc(){
    FILE *fpointer = fopen("HUST.txt","r");
    int count = 0;
    while(1)
    {
        char info;
        info=getc(fpointer);
        if(info=='\n') count++;
        if(info==EOF) break;
    }
    printf("%d\n", count/6);
    fclose(fpointer);

    fpointer = fopen("HUST.txt","r");
    char line[255];
    int a;
    float b;
    for (int i=0;i<count/6;i++){
        fscanf(fpointer, "%s", line); printf("%-30s ", line);
        fscanf(fpointer, "%s", line); printf("%-30s ", line);
        fscanf(fpointer, "%s", line);
        fscanf(fpointer, "%d", &a); printf("%10d ", a);
        fscanf(fpointer, "%f", &b); printf("%10g \n", b);
    }
    fclose(fpointer);
}

void sort(){
    FILE *fpointer = fopen("HUST.txt","r");
    int count = 0;
    int i, j;
    while(1)
    {
        char info;
        info=getc(fpointer);
        if(info=='\n') count++;
        if(info==EOF) break;
    }
    fclose(fpointer);

    int N = count/6;
    book sort_book[N];
    book temp;

    fpointer = fopen("HUST.txt","r");
    for (i=0; i<N;i++){
        fscanf(fpointer,"%s", sort_book[i].book_name);
        fscanf(fpointer,"%s", sort_book[i].author_name);
        fscanf(fpointer,"%s", sort_book[i].publisher);
        fscanf(fpointer,"%d", &sort_book[i].year);
        fscanf(fpointer,"%f", &sort_book[i].price);
    }
    fclose(fpointer);

    for(i=0;i<N-1;i++)
        for (j=i+1;j<N;j++){
            if (sort_book[i].year<sort_book[j].year){
                temp = sort_book[i];
                sort_book[i] = sort_book[j];
                sort_book[j] = temp;
            }
            else if (sort_book[i].year==sort_book[j].year){
                if (sort_book[i].price<sort_book[j].price){
                    temp = sort_book[i];
                    sort_book[i] = sort_book[j];
                    sort_book[j] = temp;
                }
            }
        }

    FILE *fpointer1 = fopen("HUST2021.txt","w+");
    for (i=0;i<N;i++){
        fprintf(fpointer1,"%s\n", sort_book[i].book_name);
        fprintf(fpointer1,"%s\n", sort_book[i].author_name);
        fprintf(fpointer1,"%s\n", sort_book[i].publisher);
        fprintf(fpointer1,"%d\n", sort_book[i].year);
        fprintf(fpointer1,"%f\n", sort_book[i].price);
        fprintf(fpointer1,"\n");}
    fclose(fpointer1);

    fopen("HUST2021.txt","r");
    char line[255];
    int a;
    float b;
    for (i=0;i<N;i++){
        fscanf(fpointer, "%s", line); printf("%-30s ", line);
        fscanf(fpointer, "%s", line); printf("%-30s ", line);
        fscanf(fpointer, "%s", line);
        fscanf(fpointer, "%d", &a); printf("%10d ", a);
        fscanf(fpointer, "%f", &b); printf("%10g \n", b);
    }
    fclose(fpointer1);
}

void title_search() {
    FILE *fpointer = fopen("HUST.txt","r");
    int count = 0;
    int i, j;
    while(1)
    {
        char info;
        info=getc(fpointer);
        if(info=='\n') count++;
        if(info==EOF) break;
    }
    fclose(fpointer);

    int N = count/6;
    book search_book[N];

    fpointer = fopen("HUST.txt","r");
    for (i=0; i<N;i++){
        fscanf(fpointer,"%s", search_book[i].book_name);
        fscanf(fpointer,"%s", search_book[i].author_name);
        fscanf(fpointer,"%s", search_book[i].publisher);
        fscanf(fpointer,"%d", &search_book[i].year);
        fscanf(fpointer,"%f", &search_book[i].price);
    }
    fclose(fpointer);

    char title[30];
    printf("Enter the book's name: ");
    scanf("%s", title);
    int m = 0;
    for (i=0;i<N;i++){
        if (strcmp(title, search_book[i].book_name)==0){
            printf("%s, %s, %s\n", search_book[i].book_name, search_book[i].author_name, search_book[i].publisher);
            m++;
        }
    }
    if (m==0)
        printf("No book is found!\n");
}

void author_search() {
    FILE *fpointer = fopen("HUST.txt","r");
    int count = 0;
    int i, j;
    while(1)
    {
        char info;
        info=getc(fpointer);
        if(info=='\n') count++;
        if(info==EOF) break;
    }
    fclose(fpointer);

    int N = count/6;
    book search_book[N];

    fpointer = fopen("HUST.txt","r");
    for (i=0; i<N;i++){
        fscanf(fpointer,"%s", search_book[i].book_name);
        fscanf(fpointer,"%s", search_book[i].author_name);
        fscanf(fpointer,"%s", search_book[i].publisher);
        fscanf(fpointer,"%d", &search_book[i].year);
        fscanf(fpointer,"%f", &search_book[i].price);
    }
    fclose(fpointer);

    char author[30];
    printf("Enter the author's name: ");
    scanf("%s", author);
    int m = 0;
    for (i=0;i<N;i++){
        if (strcmp(author, search_book[i].author_name)==0){
            printf("%s, %s\n", search_book[i].author_name, search_book[i].book_name);
            m++;
        }
    }
    if (m!=0)
        printf("%d\n", m);
    else
        printf("Not found this author");
}

int main() {
    while(1)
{
    printf("Book Manager\n============================================\n");
    printf("Welcome! Let's get started.\n");
    printf("Please select one of following options here:\n");
    printf("\t1.\tEnter information of n books of HUST.\n");
    printf("\t2.\tPrint the information of the entered books on the screen.\n");
    printf("\t3.\tSort descending information by year of publication and display.\n");
    printf("\t4.\tSearch for books by title.\n");
    printf("\t5.\tSearch books by author's name.\n");
    printf("\t6.\tExit.\n");
    printf("Your choice is: ");
    int i;
    scanf("%d",&i);
    switch(i){
        case 1:
        {
            int n;
            printf("Enter the number of books you want to add: ");
            scanf("%d",&n);
            book new_book;
            new_info(n, &new_book);
            break;
        }
        case 2:
        {
            prt_sc();
            break;
        }
         case 3:
        {
            sort();
            break;
        }
        case 4:
        {
            title_search();
            break;
        }
        case 5:
        {
            author_search();
            break;
        }
        case 6:printf("Goodbye!");return 0;
    }
    printf("Press any key to continue..");
    getch();
    system("cls");
}
}
