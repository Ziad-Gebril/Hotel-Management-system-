#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void room(char u[20])
{
    int i=0,k=0,selected = 0, ch;
    char room_number[100];
    char Customer_Details[100];
    Re re[100];

    system("cls");
    print_centered_with_input("Enter room number: ");
    gets(room_number);
    int found = 0;

    load_reservation(re,&k);

    while(i<k)
    {
        if (strcmp(room_number, re[i].room_number) == 0)
        {
            // Customer details found
            printf("\n\n\n");
            set_color(10, 0);
            print_centered("--- Customer Details ---");

            set_color(15, 0);
            print_res(re,i);

            found = 1;
            print_centered("Press any key to continue....");
            ch=_getch(); // Wait for a key press
            set_color(15, 0);
            break;
        }
        i++;
    }

    if (!found)
    {
        // Room not found, display menu
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
            print_centered("Room number not found.\n");
            set_color(15, 0);

            // Display menu with color
            for (int i = 0; i < num_options; i++)
            {
                if (i == selected)
                {
                    set_color(10, 0);  // Green text for selected option
                }
                else
                {
                    set_color(15, 0);  // White text for others
                }
                print_centered(menu[i]);
            }

            // Handle key press
            ch = _getch();
            if (ch == 224)   // Arrow keys
            {
                ch = _getch();
                if (ch == 72)   // Up arrow
                {
                    selected = (selected - 1 + num_options) % num_options;
                }
                else if (ch == 80)     // Down arrow
                {
                    selected = (selected + 1) % num_options;
                }
            }
            else if (ch == 13)     // Enter key
            {
                if (selected == 0)
                {
                    room(u);  // Try again
                    return; // Exit menu and re-prompt
                }
                else if (selected == 1)     // Back
                {

                    return; // Exit function
                }
            }
        }
    }
}



void id(char u[20])
{
        int i=0,k=0,selected = 0, ch;
    char reservation_id[100];
    char Customer_Details[100];
    int continue_searching = 1;
    Re re[100];

    system("cls");
    print_centered_with_input("Enter reservation ID : ");
    gets(reservation_id);
    int found = 0;

    load_reservation(re,&k);

    while(i<k)
    {
        if (strcmp(reservation_id,re[i].reservationID)==0)
           {
            // Customer details found
            printf("\n\n\n");
            set_color(10, 0);
            print_centered("--- Customer Details ---");

            set_color(15, 0);
            print_res(re,i);

            found = 1;
            print_centered("Press any key to continue....");
            ch=_getch(); // Wait for a key press
            set_color(15, 0);
            break;
        }
        i++;
    }

        if (!found)
        {

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
                        id(u);
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
    }



int view_customer_details(char u[20])
{
    int selected=0,ch;


    // Menu options
    const char *menu[] =
    {
        "View customer details using reservation id",
        "View customer details using room number",
        "Back to main menu"
    };
    int num_options = sizeof(menu) / sizeof(menu[0]);


    while (1)
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n");
        // Set default color for the welcome message (white text, black background)
        set_color(10, 0);
        print_centered("Customer's data System\n");
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
                id(u);
                break;
            case 1:
                room(u);
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


