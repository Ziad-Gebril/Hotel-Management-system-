#include <stdio.h>
#include<windows.h>
#include <conio.h>

// Function to set the color of the text and background
void set_color(int text_color, int background_color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((background_color << 4) | text_color));
}

void hotel_menu(char u[20])
{
    int exit=0;
    int y=1;
    int ch, selected = 0;
    char text[30];

    const char *menu[] =
    {
        "Reserve a Room",
        "Check-in",
        "Cancel Reservation",
        "Check-out",
        "Check Room Availability",
        "View Customer Details",
        "Edit Reservation Details",
        "Query (search)",
        "Reservation Report",
        "Logout",
        "Exit"
    };
    int num_options = sizeof(menu) / sizeof(menu[0]);
    print_centered ("\n\n\n\n\n");

    int i=0;
    while (!exit)
    {
        int k=0;
        system("cls");
        set_color(15, 0);

        print_centered_with_char_array("welcome ",u);

        // Set default color for the welcome message (white text, black background)
        set_color(15, 0);
        print_centered("Welcome to the Hotel Menu Screen!\n\n");


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
        case 13:  // Enter key (Carriage Return)


            switch (selected)
            {
            case 0:
                reservation(u);
                return;
                break;

            case 1:
                checkin(u);
                return;
                break;

            case 2:
                cancel_reservation(u);
                return;
                break;

            case 3:
                checkout(u);
                return;
                break;

            case 4:
                track_availability(u);
                return;
                break;

            case 5:
                view_customer_details(u);
                return;
                break;

            case 6:
                edit_reservation(u);
                return;
                break;

            case 7:
                Quary(u);
                return;
                break;

            case 8:
                report(u);
                return;
                break;

            case 9:
                main();
                k=1;
                return;
                break;

            case 10:
                system("cls");
                printf("\n\n\n\n\n\n\n\n");

                set_color(10,0);
                print_centered("Exiting the program..........\n");
                exit=1;
                ExitProcess(1);
                return;
                break;

            default:
                print_centered("invalid process\n\n\n\n\n\n\n\n");
                y=0;
                break;


            }



        }
        if (k==1)
        {
            break;
        }
    }
}

