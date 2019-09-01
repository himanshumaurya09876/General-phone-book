#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void display(void);
void main_menu(void);
void search(void);
void add(void);
void del(void);
void list(void);

char fn[20],name[20],password1[5];
FILE *fp;

struct phonebook
{
    char name[20];
    char number[10];
}p;

COORD coord={0,0};
void gotoxy(int x,int y)
{
    coord.X=y; coord.Y=x;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void display()
{
    int i,j=0,n;
    char password2[5];
    system("cls");
    gotoxy(1,15);
    Sleep(300);
    printf("W");
    Sleep(300);
    printf("E");
    Sleep(300);
    printf("L");
    Sleep(300);
    printf("C");
    Sleep(300);
    printf("O");
    Sleep(300);
    printf("M");
    Sleep(300);
    printf("E");
    printf(" to Phone Book created by HIMANSHU MAURYA\n");
    Sleep(500);
    printf("MENU\n1.New user\n2.Existing user\n3.Exit\n");
    printf("Please enter the corresponding number- ");
    scanf("%d",&n);
    switch(n)
    {
        case 1:system("cls");
               gotoxy(1,15);
               printf("Phone Book created by HIMANSHU MAURYA");
               printf("\nEnter your name\n");
               fflush(stdin);
               gets(fn);
               strcpy(name,fn);
               strcat(fn,".dat");
               fp=fopen(fn,"rb");
               if(fp==0)
               {
                    printf("Set the password of 5 mixed characters\n");
                    for(i=0;i<5;i++)
                    {
                        password1[i]=getch();
                        putch('*');
                    }
                    fp=fopen(fn,"wb");
                    fwrite(password1,sizeof(password1),1,fp);
                    fclose(fp);
                    main_menu();
               }
               else
               {
                    printf("\nThe username already exist or you are an existing user\a\n");
                    fclose(fp);
                    getch();
                    display();
               }
               break;
        case 2:system("cls");
               gotoxy(1,15);
               printf("Phone Book created by HIMANSHU MAURYA");
               printf("\nEnter your name\n");
               fflush(stdin);
               gets(fn);
               strcpy(name,fn);
               strcat(fn,".dat");
               fp=fopen(fn,"rb");
               if(fp==0)
               {
                    printf("\nThe username doesnot exist or you are new user\a\n");
                    getch();
                    display();
               }
               else
               {
                    printf("Enter the password\n");
                    for(i=0;i<5;i++)
                    {
                        password1[i]=getch();
                        putch('*');
                    }
                    fread(password2,sizeof(password2),1,fp);
                    for(i=0;j==0&&i<5;i++)
                        j=password1[i]-password2[i];
                    if(j==0)
                       main_menu();
                    else
                    {
                        printf("\nIncorrect password\a");
                        getch();
                        display();
                    }
                    fclose(fp);
               }
               break;
        case 3:exit(1);
               break;
        default:printf("Invalid input\a");
                getch();
                display();
    }
}

void main_menu()
{
    int n;
    system("cls");
    gotoxy(1,15);
    printf("Hi ");
    gotoxy(1,19);
    printf("%s",name);
    printf(",  Welcome to your Phone book created by HIMANSHU MAURYA\n");
    printf(" MENU\n1.Search contact\n2.Add contact\n3.Delete contact\n4.List of contacts\n5.Delete all contacts\n6.Exit\n");
    printf("Please enter the corresponding number- ");
    scanf("%d",&n);
    switch(n)
    {
        case 1:search();
               break;
        case 2:add();
               break;
        case 3:del();
               break;
        case 4:list();
               break;
        case 5:system("cls");
               gotoxy(1,15);
               printf("This is the Phone Book of %s, created by HIMANSHU MAURYA",name);
               printf("\n%s, do you really want to delete all of your contacts?",name);
               printf("\nIf yes, then press-y ");
               if(getche()=='y')
               {
                   if(remove(fn)==0)
                      printf("\nAll contacts of %s are deleted successfully",name);
                   else
                      printf("\nSorry %s, contact deletion failed",name);
                   getch();
                   main_menu();
               }
               else
                   main_menu();
               break;
        case 6:exit(1);
               break;
        default:
               printf("\nInvalid input\a");
               getch();
               main_menu();
    }
}

void search()
{
  int n,m=0;
  struct phonebook p1;
  system("cls");
  gotoxy(1,15);
  printf("This is the Phone Book of %s, created by HIMANSHU MAURYA",name);
  fp=fopen(fn,"rb");
  rewind(fp);
  printf("\nSearch contact by \n1.Contact Name\n2.Contact Number\n");
  printf("Please enter the corresponding number- ");
  scanf("%d",&n);
  switch(n)
  {
      case 1:system("cls");
             gotoxy(1,15);
             printf("This is the Phone Book of %s, created by HIMANSHU MAURYA",name);
             printf("\nEnter the contact name\n");
             fflush(stdin);
             gets(p1.name);
             rewind(fp);
             fread(password1,sizeof(password1),1,fp);
             while(fread(&p,sizeof(p),1,fp)>0)
             {
                   if(strcmp(p1.name,p.name)==0)
                   {
                       printf("\nContact name- %s",p.name);
                       printf("\nContact number- %s",p.number);
                       m=5;
                       break;
                   }
             }
             if(m==0)
             {
                 printf("\nNot found\a");
             }
             break;
      case 2:system("cls");
             gotoxy(1,15);
             printf("This is the Phone Book of %s, created by HIMANSHU MAURYA",name);
             printf("\nEnter the contact number\n");
             fflush(stdin);
             gets(p1.number);
             rewind(fp);
             fread(password1,sizeof(password1),1,fp);
             while(fread(&p,sizeof(p),1,fp)>0)
             {
                   if(strcmp(p1.number,p.number)==0)
                   {
                       printf("\nContact name- %s",p.name);
                       printf("\nContact number- %s",p.number);
                       m=5;
                       break;
                   }
             }
             if(m==0)
             {
                 printf("\nNot found\a");
             }
             break;
      default:
              printf("\nInvalid input\a");
              getch();
              search();
  }
  fclose(fp);
  printf("\nIf you want to search more contacts press y or to return to main menu press any key- ");
    if(getche()=='y')
        search();
    else
        main_menu();
}

void add()
{
    system("cls");
    fp=fopen(fn,"ab+");
    rewind(fp);
    gotoxy(1,15);
    printf("This is the Phone Book of %s, created by HIMANSHU MAURYA",name);
    fread(password1,sizeof(password1),1,fp);
    while(fread(&p,sizeof(p),1,fp)>0);
    printf("\nEnter the contact name- ");
    fflush(stdin);
    gets(p.name);
    printf("Enter the contact number- ");
    fflush(stdin);
    gets(p.number);
    fwrite(&p,sizeof(p),1,fp);
    fclose(fp);
    printf("\nYour data successfully added");
    printf("\nIf you want to add more contacts press y or to return to main menu press any key- ");
    if(getche()=='y')
        add();
    else
        main_menu();
}

void del()
{
    int n,m=0;
    struct phonebook p1;
    FILE *fp1;
    system("cls");
    gotoxy(1,15);
    printf("This is the Phone Book of %s, created by HIMANSHU MAURYA",name);
    fp1=fopen("Sample.dat","wb");
    fp=fopen(fn,"rb");
    rewind(fp);
    printf("\nDelete contact by \n1.Contact Name\n2.Contact Number\n");
    printf("Please enter the corresponding number- ");
    scanf("%d",&n);
    switch(n)
    {
      case 1:system("cls");
             gotoxy(1,15);
             printf("This is the Phone Book of %s, created by HIMANSHU MAURYA",name);
             printf("\nEnter the contact name\n");
             fflush(stdin);
             gets(p1.name);
             rewind(fp);
             fread(password1,sizeof(password1),1,fp);
             while(fread(&p,sizeof(p),1,fp)>0)
             {
                   if(strcmp(p1.name,p.name)==0)
                   {
                       printf("\nContact name- %s",p.name);
                       printf("\nContact number- %s",p.number);
                       m=5;
                       break;
                   }
             }
             if(m==0)
             {
                 printf("\nNot found\a");
             }
             if(m==5)
             {
                 printf("\nIf you want to delete this contact press y- ");
                 if(getche()=='y')
                 {
                     rewind(fp);
                     fread(password1,sizeof(password1),1,fp);
                     fwrite(password1,sizeof(password1),1,fp1);
                     while(fread(&p,sizeof(p),1,fp)>0)
                     {
                         if(strcmp(p1.name,p.name)!=0)
                         {
                             fwrite(&p,sizeof(p),1,fp1);
                         }
                     }
                     fclose(fp);
                     fclose(fp1);
                     if(remove(fn)==0)
                        if(rename("Sample.dat",fn)==0)
                            printf("\nContact deleted successfully");
                        else
                           printf("\nSorry %s, Contact deletion failed",name);
                     else
                        printf("\nSorry %s, Contact deletion failed",name);
                 }
                 else
                    main_menu();
             }
             break;
      case 2:system("cls");
             gotoxy(1,15);
             printf("This is the Phone Book of %s, created by HIMANSHU MAURYA",name);
             printf("\nEnter the contact number\n");
             fflush(stdin);
             gets(p1.number);
             rewind(fp);
             fread(password1,sizeof(password1),1,fp);
             while(fread(&p,sizeof(p),1,fp)>0)
             {
                   if(strcmp(p1.number,p.number)==0)
                   {
                       printf("\nContact name- %s",p.name);
                       printf("\nContact number- %s",p.number);
                       m=5;
                       break;
                   }
             }
             if(m==0)
             {
                 printf("\nNot found\a");
             }
             if(m==5)
             {
                 printf("\nIf you want to delete this contact press y- ");
                 if(getche()=='y')
                 {
                     rewind(fp);
                     fread(password1,sizeof(password1),1,fp);
                     fwrite(password1,sizeof(password1),1,fp1);
                     while(fread(&p,sizeof(p),1,fp)>0)
                     {
                         if(strcmp(p1.number,p.number)!=0)
                         {
                             fwrite(&p,sizeof(p),1,fp1);
                         }
                     }
                     fclose(fp);
                     fclose(fp1);
                     if(remove(fn)==0)
                        if(rename("Sample.dat",fn)==0)
                           printf("\nContact deleted successfully");
                        else
                           printf("\nSorry %s, Contact deletion failed",name);
                     else
                        printf("\nSorry %s, Contact deletion failed",name);
                 }
                 else
                    main_menu();
             }
             break;
      default:
              printf("\nInvalid input\a");
              getch();
              del();
    }
    fclose(fp);
    printf("\nIf you want to continue with delete press y or to return to main menu press any key- ");
    if(getche()=='y')
        del();
    else
        main_menu();
}

void list()
{
    int i=4;
    system("cls");
    gotoxy(1,10);
    printf("This is the Phone Book of %s, created by HIMANSHU MAURYA",name);
    fp=fopen(fn,"rb");
    rewind(fp);
    fread(password1,sizeof(password1),1,fp);
    gotoxy(2,25);
    printf("List of contacts of %s\n",name);
    gotoxy(3,3);
    printf("S.No.");
    gotoxy(3,20);
    printf("Contact name");
    gotoxy(3,70);
    printf("Contact number");
    while(fread(&p,sizeof(p),1,fp)>0)
    {
        gotoxy(i,3);
        printf("%d",i-3);
        gotoxy(i,20);
        printf("%s",p.name);
        gotoxy(i,70);
        printf("%s",p.number);
        i++;
    }
    printf("\nIf you want to return to main menu press- y");
    if(getche()=='y')
        main_menu();
}

void main()
{
    system("color F0");
    display();
}
