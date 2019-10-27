#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
void menu();

int i,j;
int menu_exit;

struct date{
    int day, month, year;
};

struct student{

    char id[50];
    double phone;
    char first_name[50], last_name[50];
    char citizenship[100];
    struct date birthday;

}add,rme,check ,display;

void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

void close()
{
    system("color 2");
    printf("\n\n\n\tThis program designed and created by ASHIKUR RAHAMAN\n\n\n\n\n");
}

void add_profile()
{
            FILE *ptr;
            ptr = fopen("student_record.txt", "a+");

    printf("\t\t\t\xB2\xB2\xB2\xB2 ADD RECORD  \xB2\xB2\xB2\xB2");
    printf("\n\n\tEnter Student\'s First Name: ");
    scanf("%s",add.first_name);
    printf("\n\tEnter Student\'s Last Name: ");
    scanf("%s", add.last_name);
    try_anther:
    printf("\n\tEnter Student ID: ");
    scanf("%s", check.id);

    while(fscanf(ptr, "%s %s %s %d%d%d %s %lf\n", check.first_name, check.last_name, add.id, &add.birthday.day, &add.birthday.month, &add.birthday.year, add.citizenship, &add.phone) != EOF)
    {
        if(strcmp(check.id, add.id) == 0) // 0 = true and 1 = false;
        {
            printf("\tThis id already taken!! Try anther one....\n");
            fordelay(1000000000);
            goto try_anther;
        }
    }

    strcpy(add.id, check.id);

    printf("\n\tEnter your Barth Date(day): ");
    scanf("%d", &add.birthday.day);
    printf("\n\tEnter your Barth Date(month): ");
    scanf("%d", &add.birthday.month);
    printf("\n\tEnter your Barth Date(year): ");
    scanf("%d", &add.birthday.year);
    printf("\n\tEnter Student Citizenship: ");
    scanf("%s",add.citizenship);
    printf("\n\tEnter Student Phone Number: ");
    scanf("%lf", &add.phone);

       fprintf(ptr, "\n%s %s %s %d-%d-%d %s %.0lf\n", add.first_name, add.last_name, add.id, add.birthday.day, add.birthday.month, add.birthday.year, add.citizenship, add.phone);

       fclose(ptr);

    printf("\n\n\tACCOUNT CREATED SUCCESSFULLY!!\n");
    try_another:
    printf("\tpress \"1\" for Main Menu and \"0\" for Exit: ");
    scanf("%d", &menu_exit);
    if(menu_exit == 1)
    {
        menu();
    }

    else if(menu_exit == 0)
    {
        system("cls");
        close();
    }
    else
    {
        printf("\n\tYour input is invalid");
        for(i=0; i<=6; i++)
        {
            fordelay(100000000);
        }
        system("cls");
        goto try_another;
    }
}

void view_list()
{
    double a, b;
        FILE *view;
        view = fopen("student_record.txt", "r");
    int test = 0;
    system("cls");
    printf("\n\tNAME\t\t\tID\t\t\tCITIZENSHIP\n");

    while(fscanf(view, "%s %s %s %d%d%d %s %lf\n",add.first_name, add.last_name, add.id, &add.birthday.day, &add.birthday.month, &add.birthday.year, add.citizenship, &add.phone) != EOF)
    {
        printf("\n  %s %s\t\t%s\t\t%s", add.first_name, add.last_name, add.id, add.citizenship);
        test++;
    }

        fclose(view);

     if (test==0)
        {   system("cls");
            printf("\nNO RECORDS!!\n");}

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&menu_exit);
        system("cls");
        if (menu_exit==1)
            menu();
        else if(menu_exit==0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}

void update()
{
    int test = 0, count = 0;
    int cmp;
        FILE *old, *upd;

        old = fopen("student_record.txt", "r");
        upd = fopen("updated_record.txt", "w");

    printf("\n\t\t\t\xB2\xB2\xB2\xB2UPDATE INFORMATION\xB2\xB2\xB2\xB2");
    printf("\n\nEnter the student ID who\'s information you want to update: ");
    scanf("%s", rme.id);

    while(fscanf(old, "%s %s %s %d%d%d %s %lf\n", add.first_name, add.last_name, add.id, &add.birthday.day, &add.birthday.month, &add.birthday.year, add.citizenship, &add.phone) != EOF)
    {
      cmp = strcmp(rme.id, add.id); //if strcmp function return 0. it's means those variable's data are same and it will return 0 ;/
      if(cmp == 0)
      {
            count = 1;
            update_info:

            printf("\nwhich information you want to update: \n1. Citizen\n2. Phone Number\n");
            printf("Enter your choice: ");
            scanf("%d", &test);
            system("cls");
                if(test == 1)
                {
                    printf("Citizen: ");
                    scanf("%s", rme.citizenship);
                        fprintf(upd, "%s %s %s %d%d%d %s %.0lf",add.first_name, add.last_name, add.id, add.birthday.day, add.birthday.month, add.birthday.year, rme.citizenship, add.phone);
                    printf("Update Successfully!!");
                }

                else if( test == 2)
                {
                    system("cls");
                    printf("New Phone Number:");
                    scanf("%lf", &rme.phone);
                        fprintf(upd, "%s %s %s %d%d%d %s %.0lf",add.first_name, add.last_name, add.id, add.birthday.day, add.birthday.month, add.birthday.year, add.citizenship, rme.phone);
                    printf("Update Successfully!!");
                }
                else
                {
                    printf("your input is Invalid!!");
                    fordelay(1000000000);
                    system("cls");
                    goto update_info;
                }

           }

       else
       {
           fprintf(upd, "%s %s %s %d%d%d %s %.0lf", add.first_name, add.last_name, add.id, add.birthday.day, add.birthday.month, add.birthday.year, add.citizenship, add.phone);
       }
    }
            fclose(old);
            fclose(upd);

            remove("student_record.txt");
            rename("updated_record.txt", "student_record.txt");

    if(count != 1)
    {
         printf("ID doesn\'t exist!!");

        view_list_invalid:
        printf("\n\nEnter 1 to try again!  2 to go to the main menu and 0 to exit:");
        scanf("%d",&menu_exit);
        system("cls");
        if (menu_exit==1)
        {
             update();
        }
        else if(menu_exit == 2)
        {
            menu();
        }
        else if(menu_exit==0)
        {
            close();
        }

        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
    }
    else
    {
        printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&menu_exit);
        system("cls");
        if (menu_exit==1)
            menu();
        else
            close();
    }

}

void check_information()
{

    int test = 0;
    int cmp;

        FILE *old;
        old = fopen("student_record.txt", "r");

    printf("\n\t\t\t\xB2\xB2\xB2\xB2 Details \xB2\xB2\xB2\xB2");
    printf("\n\n\tEnter student ID: ");
    scanf("%s", rme.id);
    system("cls");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2 Details \xB2\xB2\xB2\xB2");
    while(fscanf(old, "%s %s %s %d%d%d %s %lf\n", display.first_name, display.last_name, display.id, &display.birthday.day, &display.birthday.month, &display.birthday.year, display.citizenship, &display.phone) != EOF)
    {
        cmp = strcmp(rme.id, display.id); //if strcmp function return 0. it's means those variable's data are same and it will return 0 ;/
        if(cmp == 0)
        {
            test++;
            printf("\n\n\n\n\tNO- %d\n\tFull Name: %s %s \n\tStudent ID: %s\n\tBirth Date: %d%d%d\n\tCitizen: %s\n\tPhone Number: %.0lf", test, display.first_name, display.last_name, display.id, display.birthday.day, display.birthday.month, display.birthday.year, display.citizenship, display.phone);
        }
    }

            fclose(old);

    if(test == 0)
    {
        printf("\n\n\tID doesn\'t found!!");

        view_invalid:
        printf("\n\nEnter 1 to try again!  2 to go to the main menu and 0 to exit:");
        scanf("%d",&menu_exit);
        system("cls");
        if (menu_exit==1)
        {
             check_information();
        }
        else if(menu_exit == 2)
        {
            menu();
        }
        else if(menu_exit==0)
        {
            close();
        }

        else
        {
            printf("\nInvalid!\a");
            goto view_invalid;
        }
    }
    else
    {
        printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&menu_exit);
        system("cls");
        if (menu_exit==1)
            menu();
        else
            close();
    }

}

void remove_acc()
{
    int test = 0;
    int cmp;
        FILE *old, *newrec;
        old = fopen("student_record.txt", "r");
        newrec = fopen("new_record.txt", "w");

    system("cls");
    system("color 4");

    printf("\n\t\t\t\xB2\xB2\xB2\xB2REMOVE ACCOUNT\xB2\xB2\xB2\xB2");
    printf("\n\n  Enter Student ID: ");
    scanf("%s", rme.id);
    while(fscanf(old, "%s %s %s %d%d%d %s %lf\n", add.first_name, add.last_name, add.id, &add.birthday.day, &add.birthday.month, &add.birthday.year, add.citizenship, &add.phone) != EOF)
    {
        cmp = strcmp(rme.id, add.id); //if strcmp function return 0. it's means those variable's data are same and it will return 0 ;/
        if(cmp != 0)
        {
            fprintf(newrec, "%s %s %s %d%d%d %s %.0lf",add.first_name, add.last_name, add.id, add.birthday.day, add.birthday.month, add.birthday.year, add.citizenship, add.phone);

        }
        else
        {
            test = 1;
            printf("  %s ID\'s all information has been deleted!!\n", rme.id);
        }
    }

            fclose(old);
            fclose(newrec);

            remove("student_record.txt");
            rename("new_record.txt", "student_record.txt");

    if(test != 1)
    {
         printf("\n  ID doesn\'t exist!!");

        view_list_invalid:
        printf("\n\nEnter 1 to try again!  2 to go to the main menu and 0 to exit:");
        scanf("%d",&menu_exit);
        system("cls");
        if (menu_exit==1)
        {
             remove_acc();
        }
        else if(menu_exit == 2)
        {
            menu();
        }
        else if(menu_exit==0)
        {
            close();
        }

        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
    }
    else
    {
        printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&menu_exit);
        system("cls");
        if (menu_exit==1)
            menu();
        else
            close();
    }

}

void menu()
{
    int choice;
    system("cls");
    system("color 9");
    printf("\n\n\n\n\t\t\t\t\t***Student Management System***\n");
    printf("\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2JIANGXI NORMAL UNIVERSITY\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\t\t\t\t\t\t Batch CSE18");
    printf("\n\n\t\t\t\t\t1.Create a student profile");
    printf("\n\t\t\t\t\t2.Update information ");
    printf("\n\t\t\t\t\t3.Check student details");
    printf("\n\t\t\t\t\t4.Remove student");
    printf("\n\t\t\t\t\t5.View student list");
    printf("\n\t\t\t\t\t6.Exit");
    printf("\n\n\n\t\t\t\t\tEnter your choice: ");
    scanf("%d",&choice);
    if(choice > 6 ||  choice == 0)
    {
        printf("\n\n\t\t\t\t    Invalid Choice!!Try again");
         for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(".");
        }
                system("cls");
         menu();
     }

     else
     {
         system("cls");
         switch(choice)
         {
            case 1: add_profile();
            break;

            case 2: update();
            break;

            case 3: check_information();
            break;

            case 4: remove_acc();
            break;

            case 5: view_list();
            break;

            case 6: close();
            break;

         }
     }

}

void gen_password(char pass[])
{
    int i=0 ;
    char x;
    while(1)
    {
        x = getch();
        if(x == 13)
            break;
        putchar('*');
        pass[i++] = x;
    }
    pass[i] = '\0';
}


int main()
{
    char inpt_password[20];
    const char password[20] ="1234";
    try_login:
    printf("\n\n\t\t\tEnter your password:  ");
    gen_password(inpt_password);

     if(strcmp(inpt_password, password) == 0)
        {
            printf("\n\n\t\t\tPassword Match!\n\t\t\tLOADING");
            for(i=0;i<=6;i++)
            {
                fordelay(100000000);
                printf(".");
            }
                    system("cls");
             menu();
        }

     else
     {
        printf("\n\t\t\tpassword doesn\'t match!! try again....\n\n");

        try_again:
        printf("\n\t\t\tpress \"1\" for Try Again and \"0\" for Exit: ");
        scanf("%d", &menu_exit);
        if(menu_exit == 1)
        {
            system("cls");
            goto try_login;

        }

        else if(menu_exit == 0)
        {
            system("cls");
            close();
        }
        else
        {
            printf("\n\t\t\tYour input is invalid");
            system("cls");
            goto try_again;
        }


      }

    return 0;
}
