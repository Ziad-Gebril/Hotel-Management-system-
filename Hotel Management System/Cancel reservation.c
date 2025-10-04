#include <stdio.h>
#include <stdlib.h>
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

void cancel_rom_num( char u[20])
{
    char a[20];
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    print_centered_with_input("Enter your room number: ");
    scanf("%s", a);
    Room re[100];
    int j=0,k = 0, i, flag = 0, number, bill,c=0,found=0;
    char line1[1000],line[1000], status[100], room_type[99], rooms[100][1000],reservation[100][1000];

    load_reservation(re,&k);
    FILE *ptr1;

    ptr1 = fopen("room.txt", "r");
    if (ptr1 == NULL)
    {
        set_color(12,0);
        print_centered("OPPS FILE CANNOT BE OPENED.");
        print_centered("press Any Key To continue......");
        set_color(15,0);
        ch=_getch();
        cancel_reservation(u);
        return;
    }

    for (i=0; i < k; i++)
    {
        if (strcmp(a, re[i].room_number)==0 )
        {
            found=1;
            if (strcmp(re[i].status,"unconfirmed") == 0)
            {
                found=1;
                set_color(10,0);
                print_centered("Reservation cancelled successfully.");
                print_centered("press Any Key To continue......");
                set_color(15,0);
                ch=_getch();
                flag = 1;
                j=i;
                continue;
            }
            else
            {
                found=1;
                set_color(12,0);
                print_centered("The room is confirmed and the money will not be refunded.");
                print_centered("press Any Key To continue......");
                set_color(15,0);
                ch=_getch();
                cancel_reservation(u);
                return;
            }
        }


        sprintf(line1, "%s,%s,%s,%s,%s,%d,%s,%s,%s\n", re[i].reservationID, re[i].room_number, re[i].status, re[i].name, re[i].id_number, re[i].days, re[i].date, re[i].email, re[i].phone);
        strcpy(reservation[c++], line1);
    }
    FILE *ptr;
    ptr = fopen("Reservation.txt", "w");
    for (i = 0; i < c; i++)
    {
        fputs(reservation[i], ptr);
    }
    fclose(ptr);


    if (!found)
    {
        int selected=0;
        // Menu options
        const char *menu[] =
        {
            "Try again",
            "Back"
        };
        int num_options = sizeof(menu) / sizeof(menu[0]);


        while (1)
        {
            system("cls");
            set_color(12, 0);
            printf("\n\n\n\n\n\n\n\n\n\n\n");
            print_centered("This reservation is not found");
            print_centered("ID number not found.\n");
            // Set default color for the welcome message (white text, black background)
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
                if (selected == 0)  // Try again
                {
                    cancel_rom_num(u);
                    return;  // Exit this menu and re-prompt for room number
                }
                else if (selected == 1)  // Back to main menu
                {
                    return;  // Exit the current function
                }
                break;
            }

        }

    }
    if (flag)
    {
        int count = 0;
        while (fgets(line, sizeof(line), ptr1))
        {
            sscanf(line, "%d %s %s %d", &number, status, room_type, &bill);
            if (a == number && strcmp(status, "Reserved") == 0)
            {
                strcpy(status, "Available");
                sprintf(line, "%d %s %s %d\n", number, status, room_type, bill);
            }
            strcpy(rooms[count++],line);
        }
        fclose(ptr1);

        // Write updated room information back to the file
        ptr1 = fopen("room.txt", "w");
        if (ptr1 == NULL)
        {
            set_color(12,0);
            print_centered("OPPS FILE CANNOT BE OPENED.");
            print_centered("press Any Key To continue......");
            set_color(15,0);
            ch=_getch();
            cancel_reservation(u);
            return;
        }
        for (int i = 0; i < count; i++)
        {
            fputs(rooms[i], ptr1);
        }
        fclose(ptr1);
        cancel_reservation(u);
        return;
    }
}

void cancel_ID( char u[20])
{
    char a[20];
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    print_centered_with_input("Enter your ID: ");
    scanf("%s", a);

    Room re[100];
    int j=0,k = 0, i, flag = 0, number, bill,c=0,found=0;
    char line1[1000],line[1000], status[100], room_type[99], rooms[100][1000],reservation[100][1000];

    load_reservation(re,&k);
    FILE *ptr1;

    ptr1 = fopen("room.txt", "r");
    if (ptr1 == NULL)
    {
        set_color(12,0);
        print_centered("OPPS FILE CANNOT BE OPENED.");
        print_centered("press Any Key To continue......");
        set_color(15,0);
        ch=_getch();
        cancel_reservation(u);
        return;
    }

    for (i=0; i < k; i++)
    {
        if ( strcmp (a,re[i].reservationID)==0 )
        {
            found=1;
            if (strcmp(re[i].status,"unconfirmed") == 0)
            {
                found=1;
                set_color(10,0);
                print_centered("Reservation cancelled successfully.");
                print_centered("press Any Key To continue......");
                set_color(15,0);
                ch=_getch();
                flag = 1;
                j=i;
                continue;
            }
            else
            {
                found=1;
                set_color(12,0);
                print_centered("The room is confirmed and the money will not be refunded.");
                print_centered("press Any Key To continue......");
                set_color(15,0);
                ch=_getch();
                cancel_reservation(u);
                return;
            }
        }


        sprintf(line1, "%s,%s,%s,%s,%s,%d,%s,%s,%s\n", re[i].reservationID, re[i].room_number, re[i].status, re[i].name, re[i].id_number, re[i].days, re[i].date, re[i].email, re[i].phone);
        strcpy(reservation[c++], line1);
    }
    FILE *ptr;
    ptr = fopen("Reservation.txt", "w");
    for (i = 0; i < c; i++)
    {
        fputs(reservation[i], ptr);
    }
    fclose(ptr);


    if (!found)
    {
        system("cls");
        int selected=0;
        // Menu options
        const char *menu[] =
        {
            "Try again",
            "Back"
        };
        int num_options = sizeof(menu) / sizeof(menu[0]);


        while (1)
        {
            system("cls");
            set_color(12, 0);
            printf("\n\n\n\n\n\n\n\n\n\n\n");
            print_centered("This reservation is not found.");
            print_centered("ID number not found.");
            // Set default color for the welcome message (white text, black background)
            set_color(15, 0);
            printf("\n\n\n");


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
                if (selected == 0)  // Try again
                {
                    cancel_ID(u);
                    return;  // Exit this menu and re-prompt for room number
                }
                else if (selected == 1)  // Back to main menu
                {
                    return;  // Exit the current function
                }
                break;
            }

        }

    }
    if (flag)
    {
        int count = 0;
        while (fgets(line, sizeof(line), ptr1))
        {
            sscanf(line, "%d %s %s %d", &number, status, room_type, &bill);
            if (a == number && strcmp(status, "Reserved") == 0)
            {
                strcpy(status, "Available");
                sprintf(line, "%d %s %s %d\n", number, status, room_type, bill);
            }
            strcpy(rooms[count++],line);
        }
        fclose(ptr1);

        // Write updated room information back to the file
        ptr1 = fopen("room.txt", "w");
        if (ptr1 == NULL)
        {
            set_color(12,0);
            print_centered("OPPS FILE CANNOT BE OPENED.");
            print_centered("press Any Key To continue......");
            set_color(15,0);
            ch=_getch();
            cancel_reservation(u);
            return;
        }
        for (int i = 0; i < count; i++)
        {
            fputs(rooms[i], ptr1);
        }
        fclose(ptr1);
        cancel_reservation(u);
        return;
    }
}

int cancel_reservation(char u[20])
{
    system("cls");
    int selected=0,ch;
    char a[20];
    // Menu options
    const char *menu[] =
    {
        "Reservation ID",
        "Room number",
        "Back to main menu"
    };
    int num_options = sizeof(menu) / sizeof(menu[0]);


    while (1)
    {
        system("cls");
        set_color(15,0);
        printf("\n\n\n\n\n\n\n\n\n\n");
        print_centered("Cancel your reservation");
        print_centered("Select the choice you want to search with:");
        printf("\n\n\n");

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
                cancel_ID(u);
                break;
            case 1:
                cancel_rom_num(u);
                break;
            case 2:
                hotel_menu(u);
                return;
                break;

            }
        }

    }

    return 0;
}


