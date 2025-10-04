#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
char name[100];
char password[100];
}users;

bool check_user (char *username ,char *password )
{
    users usernames[100];
    int i=0;

    FILE *s;
    s = fopen("users.txt","r");

if(!s)
{
    print_centered ("Error,couldn't reach users data");
    return false;
}
rewind(s);
i=0;
    while(fscanf(s, "%s %s", usernames[i].name, usernames[i].password) == 2)
    {

        if ( strcmp(username,usernames[i].name) == 0)
            {



              if ( strcmp (password , usernames[i].password)==0)
              {

                  fclose(s);
                  return true;
              }
            }

        i++;
    }
    fclose(s);
    return false;
}





int login(char u[20])
{
    int ch;
    system("cls");
    char p[30];
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    print_centered_with_input("Enter your username :");
    gets(u);
    print_centered_with_input("Enter your Password :");
    gets(p);

if (check_user(u,p))
{
    system("cls");
    return 1;

}

 set_color(12,0);//red output
            print_centered("invalid username or password\n");
print_centered("Login failed\n");
print_centered("Press any key to continue.....");
ch=_getch();

return 0;
}




