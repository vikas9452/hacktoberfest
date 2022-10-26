#include <stdio.h>
#include <string.h>
int seats = 1;

int incr()
{
    return seats++;
}
struct info
{
    char name[20];
    int age;
    int phone_no;
    int seat_no;
} infoo[5];

void menu();

char fname[] = {"mydb.dat"};
int main()
{
    menu();
    return 0;
}

void menu()
{
    int p, a = 0;

    system("cls");
    printf("\t\t**********WELCOME TO PHONEBOOK*************");

    printf("\n\n\t\t\t MENU\t\t\n\n");
    printf("\t1.Book Ticket \t2.Check Available \t3.Check My Ticket \t4.Cancel Ticket \n");
    FILE *fp;
    switch (getch())
    {
    case '1':

        printf("Enter the number of passenger ");
        scanf("%d", &p);

        printf("%d", seats);
        for (int i = 0; i < p; i++)
        {
            fp = fopen(fname, "ab");
            printf("\nEnter Name of Passenger %d:", a + 1);
            scanf("%s", &infoo[i].name);
            printf("\nEnter age of Passenger %d :", a + 1);
            scanf("%d", &infoo[i].age);
            printf("\nEnter phone of Passenger %d:", a + 1);
            scanf("%d", &infoo[i].phone_no);
            infoo[i].seat_no = seats;
            fwrite(&infoo[i], sizeof(infoo[i]), 1, fp);
            printf("Your seat Number is %d", seats);
            incr();
            fclose(fp);
            a++;
        }

        menu();

        break;
    case '2':
        printf("Available seats are %d", 6 - seats);
        getch();
        menu();
        break;
    case '3':
        int seat_no, found = 0;

        fp = fopen(fname, "rb");

        printf("\nEnter Your seat number:");
        scanf("%d", &seat_no);

        while (1)
        {
            fread(&infoo, sizeof(infoo), 1, fp);

            if (infoo[seat_no - 1].seat_no == seat_no)
            {
                found = 1;
                printf("\n========================================================\n\n");
                printf("\t\t Details of Passenger %d\n\n", infoo[seat_no - 1].seat_no);
                printf("========================================================\n\n");

                printf("Name\tage\tPhone\n\n");

                printf("%s\t", infoo[seat_no - 1].name);
                printf("%d\t", infoo[seat_no - 1].age);
                printf("%d\t\n\n", infoo[seat_no - 1].phone_no);

                printf("========================================================\n\n");
                break;
            }

            else
            {
                break;
            }
        }

        if (found == 0)
        {
            printf("\nSorry No Record Found");
        }
        fclose(fp);
        getch();
        menu();
        break;
    default:
        break;
    }
}
