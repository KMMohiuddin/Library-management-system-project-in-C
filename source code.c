
#include <string.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>

void firstbox(char text[40]);
void box(char text[40]);
void Password();
void ChangePassword();
void login();
void mainmenu();
void newpassword();
void Addbooks();
void Searchbook();
void deletebooks();
void addmember();
void editbooks();
void memberlist();
void memberdata();
void changenewpassword();


struct PassWord
{
    char userid[10];
    char userpass[10];
} user;
FILE *PASSWORD;

struct books
{
    char id[10];
    char category[20];
    char name[20];
    char Author[20];
    char quantity[10];
    char Price[10];
    char count[10];
    char rackno[10];
    char stname[20];


} book;
FILE *BOOKS,*temp;
struct members
{
    char name[20];
    char id[10];
    char date[10];
    char number[11];

} member;
FILE *MEMBER;

COORD coord = {0, 0};
void gotoxy (int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void firstbox(char text[40])
{
    int i;

    for(i=40; i<70; i++)
    {
        gotoxy(i,5);
        Sleep(10);
        printf("\xdb");
        gotoxy(i,7);
        Sleep(10);
        printf("\xdb");
    }

    gotoxy(40,6);
    for(i=0; i<30; i++)
    {
        Sleep(20);
        printf("%c",text[i]);
    }


    for(i=8; i<18; i++)
    {
        Sleep(20);
        gotoxy(40,i);
        printf("\xdb\xdb\n");
        gotoxy(68,i);
        printf("\xdb\xdb\n");
    }


    for(i=40; i<70; i++)
    {
        gotoxy(i,16);
        Sleep(10);
        printf("\xdb");
        gotoxy(i,18);
        Sleep(10);
        printf("\xdb");
    }

}
void box(char text[40])
{
    int i;
    for(i=40; i<70; i++)
    {
        gotoxy(i,5);

        printf("\xdb");
        gotoxy(i,7);

        printf("\xdb");
    }

    gotoxy(40,6);
    for(i=0; i<30; i++)
    {
        Sleep(20);
        printf("%c",text[i]);
    }

    gotoxy(40,8);
    for(i=8; i<18; i++)
    {

        gotoxy(40,i);
        printf("\xdb\xdb\n");
        gotoxy(68,i);
        printf("\xdb\xdb\n");
    }

    for(i=40; i<70; i++)
    {
        gotoxy(i,16);

        printf("\xdb");
        gotoxy(i,18);

        printf("\xdb");
    }

    gotoxy(40,17);
    printf ("\xdb\xdb                          \xdb\xdb\n");
    gotoxy(40,16);
    printf ("\xdb\xdb                          \xdb\xdb\n");
    gotoxy(40,15);
    printf ("\xdb\xdb                          \xdb\xdb\n");
    gotoxy(40,14);
    printf ("\xdb\xdb                          \xdb\xdb\n");
    gotoxy(40,13);
    printf ("\xdb\xdb                          \xdb\xdb\n");
    gotoxy(40,12);
    printf ("\xdb\xdb                          \xdb\xdb\n");
    gotoxy(40,11);
    printf ("\xdb\xdb                          \xdb\xdb\n");
    gotoxy(40,10);
    printf ("\xdb\xdb                          \xdb\xdb\n");
    gotoxy(40,9);
    printf ("\xdb\xdb                          \xdb\xdb\n");
    gotoxy(40,8);
    printf ("\xdb\xdb                          \xdb\xdb\n");

}
void Password()
{

    char text[40]= {"\xdb\xdb         PASSWORD         \xdb\xdb"};
    firstbox(text);
    gotoxy(40,8);
    printf ("\xdb\xdb                          \xdb\xdb\n");
    gotoxy(40,9);
    printf ("\xdb\xdb   1    -->     Login     \xdb\xdb\n");
    gotoxy(40,10);
    printf ("\xdb\xdb   2    -->Change Password\xdb\xdb\n");
    gotoxy(40,11);
    printf ("\xdb\xdb   3    --> New Register  \xdb\xdb\n");
    gotoxy(40,12);
    printf ("\xdb\xdb                          \xdb\xdb\n");
    gotoxy(40,13);
    printf ("\xdb\xdb                          \xdb\xdb\n");
    gotoxy(40,14);
    printf ("\xdb\xdb                          \xdb\xdb\n");
    gotoxy(40,15);
    printf ("\xdb\xdb   0    -->   Return      \xdb\xdb\n");
    gotoxy(40,17);
    printf ("\xdb\xdb      press Choice :      \xdb\xdb\n");

    gotoxy(63,17);
    switch(getch())
    {
    case '0':
    {
        return;
        break;
    }
    case '1':
    {
        login();
        break;
    }
    case '2':
    {
        ChangePassword();
        break;
    }
    case '3':
    {
        newpassword();
        break;
    }
    default:
    {
        Password();

    }

    }
}


void ChangePassword()
{

    char preid[10],prepass[10];
    char userid[10],userpass[10];
    char text[40]= {"\xdb\xdb     CHANGE PASSWORD      \xdb\xdb"};
    box(text);
    gotoxy(40,16);
    printf ("\xdb\xdb                          \xdb\xdb\n");
    gotoxy(40,17);
    printf ("\xdb\xdb                          \xdb\xdb\n");
    gotoxy(40,9);
    printf ("\xdb\xdb Enter previous name :    \xdb\xdb\n");
    gotoxy(43,10);
    scanf("%s",&preid);
    gotoxy(40,12);
    printf ("\xdb\xdb Enter previous password: \xdb\xdb\n");
    gotoxy(43,13);
    scanf("%s",&prepass);

    PASSWORD = fopen("NEWPASSWORD.bin","rb");

    fscanf(PASSWORD,"%s %s",&user.userid,&user.userpass);
    fclose(PASSWORD);
    if((strcmp(user.userid,preid)==0)&&(strcmp(user.userpass,prepass)==0))
    {
        gotoxy(40,16);
        printf ("\xdb\xdb      Password Match      \xdb\xdb\n");
        Sleep(1000);

        changenewpassword();
    }

    else
    {

        gotoxy(40,16);
        printf ("\xdb\xdb Wrong Password Try Again \xdb\xdb\n");

        Sleep(1000);
        Password();


    }
}



void login()
{
    int i=0;
    char preid[10],prepass[10],ch;
    char text[40]= {"\xdb\xdb          LOGIN           \xdb\xdb"};
    box(text);

    PASSWORD = fopen("NEWPASSWORD.bin","rb");
    if ( PASSWORD == NULL )

                {
                    gotoxy(43,9);
                    printf("THE FILE DOES NOT EXISTS");
                    gotoxy(43,10);
                    printf("PRESS ANY KEY TO LOG IN ");
                    gotoxy(43,11);
                     printf("AS NEW REGISTER");
                    getch();
                    newpassword();

                }


    gotoxy(40,16);
    printf ("\xdb\xdb                          \xdb\xdb\n");
    gotoxy(40,17);
    printf ("\xdb\xdb                          \xdb\xdb\n");
    gotoxy(40,9);
    printf ("\xdb\xdb Enter Name :             \xdb\xdb\n");
    gotoxy(43,10);
    scanf("%s",&preid);
    gotoxy(40,12);
    printf ("\xdb\xdb Enter Password:          \xdb\xdb\n");
    gotoxy(43,13);
    while(ch!=13)
    {
        ch=getch();

        if(ch!=13 && ch!=8)
        {
            putch('*');
            prepass[i] = ch;
            i++;
        }
    }

    int r;


    fscanf(PASSWORD,"%s %s",&user.userid,&user.userpass);
    fclose(PASSWORD);
    if((strcmp(user.userid,preid)==0)&&(strcmp(user.userpass,prepass)==0))
    {
        system("COLOR 27");
        gotoxy(40,16);
        printf ("\xdb\xdb      Password Match      \xdb\xdb\n");
        Sleep(500);
        mainmenu();
    }

    else
    {
        system("COLOR FC");

        gotoxy(40,16);
        printf ("\xdb\xdb Wrong Password Try Again \a\xdb\xdb\n");
        Sleep(500);


        Password();


    }
}

void changenewpassword()
{

    PASSWORD = fopen("NEWPASSWORD.bin","rb");
    char text[40]= {"\xdb\xdb     NEW PASSWORD         \xdb\xdb"};
    char check_id[10];
    int c;

    box(text);


    gotoxy(40,9);
    printf ("\xdb\xdb Enter new Name :         \xdb\xdb\n");
    gotoxy(43,10);
    scanf("%s",&user.userid);
    gotoxy(40,12);
    printf ("\xdb\xdb Enter new password:      \xdb\xdb\n");
    gotoxy(43,13);
    scanf("%s",&user.userpass);
    gotoxy(40,15);
    printf ("\xdb\xdb  Now press any key       \xdb\xdb\n");


    fprintf(PASSWORD,"%s %s",user.userid,user.userpass);
    fclose(PASSWORD);

    gotoxy(45,17);
    switch(getch())
    {

    default:
    {
        Password();

    }

    }
}


void newpassword()
{

    PASSWORD = fopen("NEWPASSWORD.bin","wb");
    char text[40]= {"\xdb\xdb     NEW REGISTER         \xdb\xdb"};
    char check_id[10];
    int c;

    box(text);


    gotoxy(40,9);
    printf ("\xdb\xdb Enter new Name :         \xdb\xdb\n");
    gotoxy(43,10);
    scanf("%s",&user.userid);
    gotoxy(40,12);
    printf ("\xdb\xdb Enter new password:      \xdb\xdb\n");
    gotoxy(43,13);
    scanf("%s",&user.userpass);
    MEMBER = fopen("NEWMEMBER.txt","w");
    fprintf(MEMBER," ");
    fclose(MEMBER);
    BOOKS=fopen("BOOKS.txt","w");
    fprintf(BOOKS," ");
    fclose(BOOKS);
    gotoxy(43,14);
    printf("All info of previous");
    gotoxy(43,15);
    printf("ID is Erased");
    gotoxy(40,16);
    printf ("\xdb\xdb  Now press any key       \xdb\xdb\n");


    fprintf(PASSWORD,"%s %s",user.userid,user.userpass);
    fclose(PASSWORD);

    gotoxy(45,17);
    switch(getch())
    {

    default:
    {
        Password();

    }

    }
}

void mainmenu()
{

    system("cls");
    system("COLOR F3");
    char text[40]= {"\xdb\xdb         main menu        \xdb\xdb"};
    box(text);

    int choice;


    while(1)
    {
        gotoxy(40,8);
        printf ("\xdb\xdb                          \xdb\xdb\n");
        gotoxy(40,9);
        printf ("\xdb\xdb   1    -->  Add Books    \xdb\xdb\n");
        gotoxy(40,10);
        printf ("\xdb\xdb   2    -->  Search Books \xdb\xdb\n");
        gotoxy(40,11);
        printf ("\xdb\xdb   3    -->  Delete Books \xdb\xdb\n");
        gotoxy(40,12);
        printf ("\xdb\xdb   4    -->  Display Books\xdb\xdb\n");
        gotoxy(40,13);
        printf ("\xdb\xdb   5    -->  Edit Record  \xdb\xdb\n");
        gotoxy(40,14);
        printf ("\xdb\xdb   6    -->  Member Data  \xdb\xdb\n");
        gotoxy(40,15);
        printf ("\xdb\xdb   0    -->  EXIT         \xdb\xdb\n");
        gotoxy(40,17);
        printf ("\xdb\xdb      Enter Choice :      \xdb\xdb\n");
        gotoxy(63,17);

        switch(getch())
        {
        case '1':
        {
            Addbooks();
            break;
        }
        case '2':
        {
            Searchbook();
            break;
        }
        case '3':
        {
            deletebooks();
            break;
        }
        case '4':
        {
            display();
            break;
        }
        case '5':
        {
            editbooks();
            break;
        }
        case '6':
        {
            memberdata();
            break;
        }
        case '0' :
        {
            return 0;
            break;
        }
        default :
        {
            mainmenu();
        }

        }

    }

    system("cls");
    gotoxy(1,50);
    return 0;

}


void Addbooks()
{
    int choice;
    char text[40]= {"\xdb\xdb         ADD BOOKS        \xdb\xdb"};
    box(text);
    BOOKS=fopen("BOOKS.txt","a+");
    do
    {
        gotoxy(40,8);
        printf ("\xdb\xdb Enter Id:       ");

        gotoxy(40,9);
        printf ("\xdb\xdb Category:      ");

        gotoxy(40,10);
        printf ("\xdb\xdb name    :          ");

        gotoxy(40,11);
        printf ("\xdb\xdb Author  :         ");

        gotoxy(40,12);
        printf ("\xdb\xdb price   :         ");

        gotoxy(40,13);
        printf ("\xdb\xdb quantity: ");

        gotoxy(40,14);
        printf("\xdb\xdb rack no :");
        gotoxy(53,8);
        scanf("%s",&book.id);

        gotoxy(53,9);
        scanf("%s",&book.category);

        gotoxy(53,10);
        scanf("%s",&book.name);

        gotoxy(53,11);
        scanf("%s",&book.Author);

        gotoxy(53,12);
        scanf("%s",&book.Price);

        gotoxy(53,13);
        scanf("%s",&book.quantity);

        gotoxy(53,14);
        scanf("%s",&book.rackno);

        gotoxy(40,16);
        printf ("\xdb\xdb   RETURN 0 AddAnother 1  \xdb\xdb\n");
        gotoxy(40,17);
        printf ("\xdb\xdb      Enter Choice :      \xdb\xdb\n");
        gotoxy(63,17);


        fprintf(BOOKS,"%s %s %s %s %s %s %s",book.id,book.category,book.name,book.Author,book.Price,book.quantity,book.rackno);
        fprintf(BOOKS,"\n");
        fclose(BOOKS);

        scanf("%d",&choice);
        if(choice==1)
        {
            Addbooks();
        }

    }
    while(choice!=0);


    system("cls");
    mainmenu();
}

void Searchbook()
{
    system("cls");
    char d[10];
    char text[40]= {"\xdb\xdb     SEARCH               \xdb\xdb "};

    box(text);
    gotoxy(40,10);
    printf("\xdb\xdb 1. Search By ID");
    gotoxy(40,12);
    printf("\xdb\xdb 2. Search By Name");
    gotoxy(40,17);
    printf("\xdb\xdb Enter Your Choice ");

    switch(getch())
    {
    case '1':
    {

        char id[15],f[10];
        int found=0;
        system("cls");
        char text[40]= {"\xdb\xdb     SEARCH BY ID         \xdb\xdb "};
        box(text);

        BOOKS=fopen("BOOKS.txt","r");
        rewind(BOOKS);

        gotoxy(40,8);
        printf ("\xdb\xdb Enter ID: ");
        scanf("%s",id);

        while(!feof(BOOKS)&& found==0)
            fscanf(BOOKS,"%s %s %s %s %s %s %s",book.id,book.category,book.name,book.Author,book.Price,book.quantity,book.rackno);

        if(strcmp(id,book.id)==0)
        {
            gotoxy(43,6);
            printf("The Book is available");
            gotoxy(43,8);
            printf("Book ID :                ");
            gotoxy(53,8);
            printf("%s",book.id);
            gotoxy(40,9);
            printf ("\xdb\xdb Category:           ");
            gotoxy(53,9);
            printf("%s",book.category);
            gotoxy(40,10);
            printf ("\xdb\xdb Title   :          ");
            gotoxy(53,10);
            printf("%s",book.name);
            gotoxy(40,11);
            printf ("\xdb\xdb Author  :         ");
            gotoxy(53,11);
            printf("%s",book.Author);
            gotoxy(40,12);
            printf ("\xdb\xdb price   :         ");
            gotoxy(53,12);
            printf("%s",book.Price);
            gotoxy(40,13);
            printf ("\xdb\xdb quantity: ");
            gotoxy(53,13);
            printf("%s",book.quantity);
            gotoxy(40,14);
            printf("\xdb\xdb rack no :");
            gotoxy(53,14);
            printf("%s",book.rackno);
            gotoxy(40,16);
            printf ("\xdb\xdb  Now press any key       \xdb\xdb\n");
            found=1;
            int c;
            getch();

        }


        else if(!found)
        {
            system("cls");
            char text[40]= {"\xdb\xdb     ERROR                \xdb\xdb "};
            box(text);
            gotoxy(40,10);
            printf("\xdb\xdb No Record Found\a");
            gotoxy(40,16);
            printf ("\xdb\xdb  Now press any key       \xdb\xdb\n");
            int c;
            getch();

        }

        fclose(BOOKS);


        mainmenu();
        break;
    }
    case '2':
    {
        char name[15],f[10];
        int found=0;
        system("cls");
        char text[40]= {"\xdb\xdb     SEARCH BY NAME       \xdb\xdb "};
        box(text);

        BOOKS=fopen("BOOKS.txt","r");
        rewind(BOOKS);

        gotoxy(40,8);
        printf ("\xdb\xdb Enter Name: ");
        scanf("%s",name);

        while(!feof(BOOKS)&& found==0)
            fscanf(BOOKS,"%s %s %s %s %s %s %s",book.id,book.category,book.name,book.Author,book.Price,book.quantity,book.rackno);

        if(strcmp(name,book.name)==0)
        {
            gotoxy(43,6);
            printf("The Book is available");
            gotoxy(43,8);
            printf("Book ID :             ");
            gotoxy(53,8);
            printf("%s",book.id);
            gotoxy(40,9);
            printf ("\xdb\xdb Category:      ");
            gotoxy(53,9);
            printf("%s",book.category);
            gotoxy(40,10);
            printf ("\xdb\xdb Title   :          ");
            gotoxy(53,10);
            printf("%s",book.name);
            gotoxy(40,11);
            printf ("\xdb\xdb Author  :         ");
            gotoxy(53,11);
            printf("%s",book.Author);
            gotoxy(40,12);
            printf ("\xdb\xdb price   :         ");
            gotoxy(53,12);
            printf("%s",book.Price);
            gotoxy(40,13);
            printf ("\xdb\xdb quantity:        ");
            gotoxy(53,13);
            printf("%s",book.quantity);
            gotoxy(40,14);
            printf("\xdb\xdb rack no :             ");
            gotoxy(53,14);
            printf("%s",book.rackno);
            gotoxy(40,16);
            printf ("\xdb\xdb  Now press any key       \xdb\xdb\n");
            found=1;
            int c;
            getch();

        }


        else if(!found)
        {
            system("cls");
            char text[40]= {"\xdb\xdb     ERROR                \xdb\xdb "};
            box(text);
            gotoxy(40,10);
            printf("\xdb\xdb No Record Found \a");
            gotoxy(40,16);
            printf ("\xdb\xdb  Now press any key       \xdb\xdb\n");
            int c;
            getch();

        }

        fclose(BOOKS);


        mainmenu();
        break;
    }
    }
}

void deletebooks()
{
    system("cls");
    char id[10];
    char text[40]= {"\xdb\xdb     DELETE               \xdb\xdb"};

    box(text);



    gotoxy(40,8);
    printf ("\xdb\xdb Enter ID: ");
    scanf("%s",id);

    BOOKS=fopen("BOOKS.txt","r");
    rewind(BOOKS);
    while(!feof(BOOKS))
        fscanf(BOOKS,"%s %s %s %s %s %s %s",book.id,book.category,book.name,book.Author,book.Price,book.quantity,book.rackno);
    fclose(BOOKS);

    if(strcmp(id,book.id)==0)
    {
        gotoxy(43,6);
        printf("The Book is available");
        gotoxy(43,8);
        printf("Do you want to delete it?");
        gotoxy(43,9);
        printf("yes(1) NO(0)");
        int c;
        gotoxy(63,9);
        switch(getch())
        {
        case '1' :
        {
            /*BOOKS=fopen("BOOKS.txt","w+");
            fprintf(BOOKS,"\n");
            fclose(BOOKS);*/
            gotoxy(43,12);
            printf("The record is can not be deleted");
            gotoxy(43,14);
            printf("Delete another record?");
            gotoxy(43,15);
            printf("yes(1) NO(0)");
            int c;
            gotoxy(63,9);
            switch(getch())
            {
            case '1' :
            {
                deletebooks();
                break;
            }
            case '0' :
            {
                mainmenu();
                break;
            }
            default :
            {
                gotoxy(43,18);
                printf("Wrong Choice \a");
                mainmenu();
            }

            }

        }

        case '0' :
        {
            mainmenu();
        }
        default :
        {
            gotoxy(43,18);
            printf("Wrong Choice \a");
            mainmenu();
        }

        }

    }
    else
    {
        gotoxy(43,6);
        printf("The Book is not available \a");
        gotoxy(43,8);
        printf("Search again?");
        gotoxy(43,9);
        printf("yes(1) NO(0)");
        int c;
        switch(getch())
        {
        case '1' :
        {
            deletebooks();
            break;
        }
        case '0' :
        {
            mainmenu();
            break;
        }
        default :
            mainmenu();
        }

    }


}

void display()
{
    char f;
    int i=0,j;
    system("cls");
    gotoxy(1,1);
    printf("*-* *-* *-* *-* *-* *-* *-* *-* Book List*-* *-* *-* *-* *-* *-* *-* *-*");
    gotoxy(2,2);
    printf("ID   CATEGORY   BOOK NAME     Author    quantity     Price     RackNo \n");
    j=4;
    BOOKS=fopen("BOOKS.txt","r");

    while((f=fgetc(BOOKS))!=EOF)
    {
        printf("%c",f);

    }

    int c;
    gotoxy(35,25);
    printf("return");

    getch();
    mainmenu();
}



void memberdata()
{
    system("cls");
    system("COLOR F5");
    char text[40]= {"\xdb\xdb         MEMBERS          \xdb\xdb"};
    box(text);
    gotoxy(40,8);
    printf ("\xdb\xdb                          \xdb\xdb");

    gotoxy(40,9);
    printf ("\xdb\xdb   1    -->  Add Members  \xdb\xdb");
    gotoxy(40,10);
    printf ("\xdb\xdb   2    -->  Member List  \xdb\xdb");
    gotoxy(40,11);
    printf ("\xdb\xdb   0    -->  Main Menu    \xdb\xdb");
    int c;
    gotoxy(40,14);
    printf ("\xdb\xdb Enter Choice : ");
    switch(getch())
    {
    case '1':
    {
        addmember();
        break;
    }
    case '2':
    {
        memberlist();
        break;
    }
    case '3' :
    {
        mainmenu();
        break;
    }
    default:
        memberdata();
    }



}
void addmember()
{

    system("cls");
    MEMBER = fopen("NEWMEMBER.txt","a+");
    char text[40]= {"\xdb\xdb     New Member           \xdb\xdb"};
    char check_id[10];

    box(text);

    gotoxy(40,16);
    printf ("\xdb\xdb                          \xdb\xdb\n");
    gotoxy(40,17);
    printf ("\xdb\xdb                          \xdb\xdb\n");
    gotoxy(40,8);
    printf ("\xdb\xdb Enter  name  :           \xdb\xdb\n");

    gotoxy(40,10);
    printf ("\xdb\xdb Enter new id :           \xdb\xdb\n");

    gotoxy(40,12);
    printf ("\xdb\xdb joining date :           \xdb\xdb\n");

    gotoxy(40,14);
    printf ("\xdb\xdb Phone Number :           \xdb\xdb\n");
    gotoxy(43,9);
    scanf("%s",&member.name);
    gotoxy(43,11);
    scanf("%s",&member.id);
    gotoxy(43,13);
    scanf("%s",&member.date);
    gotoxy(43,15);
    scanf("%s",&member.number);

    gotoxy(40,16);
    printf ("\xdb\xdb Add another(1)main menu(0)\xdb\n");
    gotoxy(40,17);
    printf ("\xdb\xdb Member list (2)");
    int c;

    fprintf(MEMBER,"%s\t%s\t%s\t%s\n",member.name,member.id,member.date,member.number);
    fclose(MEMBER);

    switch(getch())
    {
    case '1':
    {
        addmember();
        break;
    }
    case '2':
    {
        memberlist();
        break;
    }
    default:
        mainmenu();
    }
}
void memberlist()
{
    char f;
    int i=0,j;
    system("cls");
    gotoxy(1,1);
    printf("*-* *-* *-* *-* *-* *-* *-* *-* Member List*-* *-* *-* *-* *-* *-* *-* *-*");
    gotoxy(2,2);
    printf(" ID\tNAME\tJoin Date\tPhone Number \n");
    j=4;
    MEMBER = fopen("NEWMEMBER.txt","r");

    while((f=fgetc(MEMBER))!=EOF)
    {
        printf("%c",f);

    }

    int c;
    gotoxy(35,25);
    printf("return");

    getch();
    mainmenu();
}


void editbooks()
{
    system("cls");
    system("COLOR F3");
    char d[10];
    char text[40]= {"\xdb\xdb     EDIT BOOKS           \xdb\xdb "};

    box(text);
    gotoxy(40,10);
    printf("\xdb\xdb 1. Search By ID");
    gotoxy(40,12);
    printf("\xdb\xdb 2. Search By Name");
    gotoxy(40,17);
    printf("\xdb\xdb Enter Your Choice ");

    switch(getch())
    {
    case '1':
    {

        char id[15],f[10];
        int found=0;
        system("cls");
        char text[40]= {"\xdb\xdb     SEARCH BY ID         \xdb\xdb "};
        box(text);



        gotoxy(40,8);
        printf ("\xdb\xdb Enter ID: ");
        scanf("%s",id);
        BOOKS=fopen("BOOKS.txt","r");

        rewind(BOOKS);
        while(!feof(BOOKS)&& found==0)


            fscanf(BOOKS,"%s %s %s %s %s %s %s",book.id,book.category,book.name,book.Author,book.Price,book.quantity,book.rackno);
        fclose(BOOKS);

        if(strcmp(id,book.id)==0)
        {
            gotoxy(43,6);
            printf("The Book is available");
            BOOKS=fopen("BOOKS.txt","a+");
            gotoxy(40,8);
            printf ("\xdb\xdb  Id     :       ");
            gotoxy(40,9);
            printf ("\xdb\xdb Category:      ");
            gotoxy(40,10);
            printf ("\xdb\xdb name    :          ");
            gotoxy(40,11);
            printf ("\xdb\xdb Author  :         ");
            gotoxy(40,12);
            printf ("\xdb\xdb price   :         ");
            gotoxy(40,13);
            printf ("\xdb\xdb quantity: ");
            gotoxy(40,14);
            printf("\xdb\xdb rack no :");
            gotoxy(43,16);
            printf("Edit Book Info");

            gotoxy(53,8);
            printf("%s",book.id);
            gotoxy(53,9);
            scanf("%s",&book.category);
            gotoxy(53,10);
            scanf("%s",&book.name);
            gotoxy(53,11);
            scanf("%s",&book.Author);
            gotoxy(53,12);
            scanf("%s",&book.Price);
            gotoxy(53,13);
            scanf("%s",&book.quantity);
            gotoxy(53,14);
            scanf("%s",&book.rackno);
            gotoxy(40,16);
            printf ("\xdb\xdb  RETURN(0)EditAnother(1) \xdb\xdb\n");
            gotoxy(40,17);
            printf ("\xdb\xdb      Enter Choice :      \xdb\xdb\n");
            gotoxy(63,17);

            fprintf(BOOKS,"%s %s %s %s %s %s %s",book.id,book.category,book.name,book.Author,book.Price,book.quantity,book.rackno);
            fprintf(BOOKS,"\n");
            fclose(BOOKS);
            int choice;
            scanf("%d",&choice);
            if(choice==1)
            {
                editbooks();
            }
            else
                mainmenu();

        }


        else if(!found)
        {
            system("cls");
            char text[40]= {"\xdb\xdb     ERROR                \xdb\xdb "};
            box(text);
            gotoxy(40,10);
            printf("\xdb\xdb No Record Found \a");
            gotoxy(40,16);
            printf ("\xdb\xdb  Now press any key       \xdb\xdb\n");
            int c;
            getch();

        }

        fclose(BOOKS);


        mainmenu();
        break;
    }
    case '2':
    {
        char name[15],f[10];
        int found=0;
        system("cls");
        char text[40]= {"\xdb\xdb     SEARCH BY NAME       \xdb\xdb "};
        box(text);

        BOOKS=fopen("BOOKS.txt","r");
        rewind(BOOKS);


        gotoxy(40,8);
        printf ("\xdb\xdb Enter Name: ");
        scanf("%s",name);
        BOOKS=fopen("BOOKS.txt","r");

        rewind(BOOKS);
        while(!feof(BOOKS)&& found==0)

            fscanf(BOOKS,"%s %s %s %s %s %s %s",book.id,book.category,book.name,book.Author,book.Price,book.quantity,book.rackno);
        fclose(BOOKS);

        if(strcmp(name,book.name)==0)
        {
            gotoxy(43,6);
            printf("The Book is available");
            BOOKS=fopen("BOOKS.txt","a+");
            gotoxy(40,8);
            printf ("\xdb\xdb Id      :       ");
            gotoxy(40,9);
            printf ("\xdb\xdb Category:      ");
            gotoxy(40,10);
            printf ("\xdb\xdb name    :          ");
            gotoxy(40,11);
            printf ("\xdb\xdb Author  :         ");
            gotoxy(40,12);
            printf ("\xdb\xdb price   :         ");
            gotoxy(40,13);
            printf ("\xdb\xdb quantity: ");
            gotoxy(40,14);
            printf("\xdb\xdb rack no :");
            gotoxy(43,16);
            printf("Edit Book Info");
            gotoxy(53,8);
            printf("%s",book.id);
            gotoxy(53,9);
            scanf("%s",&book.category);
            gotoxy(53,10);
            scanf("%s",&book.name);
            gotoxy(53,11);
            scanf("%s",&book.Author);
            gotoxy(53,12);
            scanf("%s",&book.Price);
            gotoxy(53,13);
            scanf("%s",&book.quantity);
            gotoxy(53,14);
            scanf("%s",&book.rackno);
            gotoxy(40,16);
            printf ("\xdb\xdb  RETURN(0)EditAnother(1) \xdb\xdb\n");
            gotoxy(40,17);
            printf ("\xdb\xdb      Enter Choice :      \xdb\xdb\n");
            gotoxy(63,17);

            fprintf(BOOKS,"%s %s %s %s %s %s %s",book.id,book.category,book.name,book.Author,book.Price,book.quantity,book.rackno);
            fprintf(BOOKS,"\n");
            fclose(BOOKS);
            int choice;
            scanf("%d",&choice);
            if(choice==1)
            {
                editbooks();
            }
            else
                mainmenu();

        }



        else if(!found)
        {
            system("cls");
            char text[40]= {"\xdb\xdb     ERROR                \xdb\xdb "};
            box(text);
            gotoxy(40,10);
            printf("\xdb\xdb No Record Found");
            gotoxy(40,16);
            printf ("\xdb\xdb  Now press any key       \xdb\xdb\n");
            int c;
            getch();

        }

        fclose(BOOKS);


        mainmenu();
        break;
    }
    }




}




int main()
{

    system("COLOR F2");
    Password();
    system("cls");
    gotoxy(1,1);
    printf("Thank You (^-^)\n");
    char curr_time[10];
    char curr_date[12];
    int std_c;

    strcpy(curr_time, __TIME__);
    strcpy(curr_date, __DATE__);
    printf("TIME : %s \nDATE : %s\n", curr_time, curr_date);
    printf("This is line %d\n", __LINE__);
    std_c = __STDC__;
    printf("STDC is %d", std_c);


    return 0;
}
