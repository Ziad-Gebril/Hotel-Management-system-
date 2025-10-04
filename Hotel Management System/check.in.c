#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

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
} Re;

typedef struct
{
    char number[20];
    char status[20];
    char type[20];
    int bill;
} Room;

void check_in()
{
    int ch;
    system("cls");
    char room_number[20];
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    print_centered_with_input("Enter room number: ");
    gets(room_number);
    system("cls");

    Re re[100];
    int l = 0,k=0, i, found = 0;
    char line[1000];
    FILE *ptr;

    load_reservation(re,&k);

    time_t t = time(NULL);
    struct tm tm_today = *localtime(&t);
    char today_date[20];
    strftime(today_date, sizeof(today_date), "%d-%m-%Y", &tm_today);

    for (i = 0; i < k; i++)
    {
        if (strcmp(room_number , re[i].room_number) == 0 && strcmp(re[i].status,"unconfirmed") == 0)
        {
            if (strcmp(today_date,re[i].date) <= 0)
            {
                found = 1;
                strcpy(re[i].status, "confirmed");
                break;
            }
            else
            {
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
                set_color(12,0);
                print_centered("Check-in is not allowed before the check-in date specified in the reservation details.\n");
                print_centered("Press any key to continue");
                ch = _getch();
                set_color(15,0);
                return;
            }
        }
    }

    if (!found)
    {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
        set_color(12,0);
        print_centered("No matching reservation found or the reservation is already confirmed.");
        print_centered("Press any key to continue");
        ch = _getch();
        set_color(15,0);
        return;
    }

    write_reservation(re,&k);

    ptr = fopen("Room.txt", "r");
    if (ptr == NULL)
    {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
       set_color(12,0);
        print_centered("OPPS FILE CANNOT BE OPENED.");
        print_centered("Press any key to continue");
        ch = _getch();
        set_color(15,0);
        return;
    }

    Room ro[100];
    l = 0;
    while (fgets(line, sizeof(line), ptr))
    {
        if (strlen(line) > 1)
        {
            sscanf(line, "%s %s %s %d", ro[l].number, ro[l].status, ro[l].type, &ro[l].bill);
            l++;
        }
    }
    fclose(ptr);

    for (i = 0; i < l; i++)
    {
        if (room_number == atoi(ro[i].number))
        {
            strcpy(ro[i].status, "Reserved");
            break;
        }
    }

    ptr = fopen("Room.txt", "w");
    if (ptr == NULL)
    {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
        set_color(12,0);
        print_centered("OPPS FILE CANNOT BE OPENED.");
        print_centered("Press any key to continue");
        ch = _getch();
        set_color(15,0);
        return;
    }
    for (i = 0; i < l; i++)
    {
        fprintf(ptr, "%s %s %s %d\n", ro[i].number, ro[i].status, ro[i].type, ro[i].bill);
    }
    fclose(ptr);
    set_color(10,0);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    print_centered("check in has been successfully done");
    print_centered("Press any key to continue");
     ch = _getch();
    set_color(15,0);
    return;
}

int checkin(char u[20])
{
    int exit=0;
    int selected=0,ch;

        // Menu options
        const char *menu[] =
        {
            "Check in",
            "Back to main menu"
        };
        int num_options = sizeof(menu) / sizeof(menu[0]);


        while (!exit)
        {
            system("cls");
            // Set default color for the welcome message (white text, black background)
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
            set_color(15, 0);

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
                    check_in();
                    break;
                case 1:
                    hotel_menu(u);
                    return;
                    break;

                }
            }

        }

    }


