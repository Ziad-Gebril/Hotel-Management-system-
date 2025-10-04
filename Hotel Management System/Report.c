#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int ch;

typedef struct
{
    char reservationID[20];
    char room_number[20];
    char status[20];
    char name[50];
    char id_number[20];
    int days;
    char date[20];
    char email[50];
    char phone[20];
} Room;

void check_report(char u[20])
{
    system ("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n");

    Room re[100];
    int k=0,l = 0, i, choice, found = 0, c = 0;
    char line[1000], reservation[100][1000], line1[1000],a[99];

    load_reservation(re,&k);
    enter_date(a);

    for (i = 0; i < k; i++)
    {
        if (strcmp(a,re[i].date)==0&&strcmp("confirmed",re[i].status)==0)
        {
            found=1;
            sprintf(line1, "%s,%s,%s,%s,%s,%d,%s,%s,%s\n",
                    re[i].reservationID, re[i].room_number, re[i].status,
                    re[i].name, re[i].id_number, re[i].days, re[i].date,
                    re[i].email, re[i].phone);
                    l=i;

            strcpy(reservation[c++], line1);

        }
    }

system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    set_color(10,0);
    print_centered("REPORT");
    printf("\n");
    set_color(15,0);
    if(!found)
        print_centered("no reservations found in this date");

    for(i=0; i<c; i++)
    {
        printf("          %s",reservation[i]);
    }



    if (!found)
    {
        set_color(12,0);
        printf("\n\n");
        print_centered("No matching date found.");
        print_centered("Press any key to continue.........");
        set_color(15,0);

        ch=_getch();
        return;
    }
    print_centered("Press any key to continue........");
    ch=_getch();
    return;
}

void report(char u[20])
{
    int selected=0, ch;
    while (1)
    {

        // Menu options
        const char *menu[] =
        {
            "Report",
            "Back to main menu"
        };
        int num_options = sizeof(menu) / sizeof(menu[0]);
        while (1)
        {
            system("cls");
            // Set default color for the welcome message (white text, black background)
            set_color(15, 0);
            printf("\n\n\n\n\n\n\n\n\n\n\n");
            print_centered("---------Report System----------\n");
            // Display menu with color
            for (int i = 0; i < num_options; i++)
            {
                if (i == selected)
                {
                    set_color(10, 0);  // Green text, Black background for selected option

                }
                else
                {
                    set_color(15, 0);  // White text, Black background for other options

                }

                print_centered(menu[i]);
            }

            // Wait for a key press
            ch = _getch();
            switch (ch)
            {
            case 224:  // Handle arrow keys (extended keys)
                ch = _getch();  // Get the actual arrow key code
                if (ch == 72)    // Up arrow
                {
                    selected = (selected - 1 + num_options) % num_options;
                }
                else if (ch == 80)      // Down arrow
                {
                    selected = (selected + 1) % num_options;
                }
                break;
            case 13:
                switch (selected)
                {
                case 0:
                    check_report(u);
                    break;
                case 1:
                    hotel_menu(u);
                    return;
                    break;

                }
            }
        }
    }

}

