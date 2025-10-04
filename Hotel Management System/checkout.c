#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void check_out(char u[20])
{
    int ch;
    system("cls");
    int room_number;
     printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
       // Input loop to handle invalid inputs
    while (1) {
        print_centered_with_input("Enter room number: ");
        if (scanf("%d", &room_number) == 1) {
            clear_input_buffer(); // Clear the buffer to avoid leftover data
            break; // Exit the loop if input is valid
        } else {
            clear_input_buffer(); // Clear invalid input
            set_color(12, 0);
            print_centered("Invalid input. Please enter a valid room number.");
            set_color(15, 0);
        }
    }

    system("cls");

    FILE *ptrr, *ptr;
    char line[256],status[100], room_type[100],rooms[100][256],reservations[100][256];

    int number, bill,found = 0,room_count = 0,reservation_count = 0;
    int *k=&found;


    // Read the reservation file into  // Read the room file into memory
    ptrr = fopen("Reservation.txt", "r");
    if (ptrr == NULL)
    {
        set_color(12,0);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("Error: Could not open Reservation.txt\n");
        print_centered("Press any key to continue.....");
        set_color(15,0);
        ch=_getch();
        return;
    }
    ptr = fopen("Room.txt", "r");
    if (ptr == NULL)
    {

         set_color(12,0);
         printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
        print_centered("Error: Could not open Room.txt");
        print_centered("Press any key to continue.....");
        set_color(15,0);
        ch=_getch();
        return;
    }

    while (fgets(line, sizeof(line), ptrr))
    {
        sscanf(line, "%*[^,],%d,%99[^,]", &number, status);
        if (number == room_number && strcmp(status, "confirmed") == 0)
        {
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
            print_centered_with_char_int("Reservation confirmed for room number:", number);
            found = 1;
        }
        else
        {
            strcpy(reservations[reservation_count++], line);
        }
    }

    while (fgets(line, sizeof(line), ptr))
    {
        sscanf(line, "%d %s %s %d", &number, status, room_type, &bill);
        if (number == room_number && found && strcmp(status, "Reserved") == 0)
        {
            print_centered_with_char_int("Room number:",number);
            print_centered_with_char_array("Status:",status);
            print_centered_with_char_array("Room type:",room_type);
            print_centered_with_char_int("Bill:",bill);
            strcpy(status,"Available");
            sprintf(line, "%d %s %s %d\n", number,status,room_type,bill);
            *k=1;
        }
        strcpy(rooms[room_count++],line);

    }

    fclose(ptrr);
    fclose(ptr);

    // Write the updated reservations back to the file // Write the updated rooms back to the file
    ptrr= fopen("Reservation.txt", "w");
    ptr = fopen("Room.txt", "w");
    for (int i = 0; i < reservation_count; i++)
    {
        fputs(reservations[i], ptrr);
    }
    for (int i = 0; i < room_count; i++)
    {
        fputs(rooms[i], ptr);
    }
    fclose(ptrr);
    fclose(ptr);

    if (found)
    {
        set_color(10,0);
        print_centered_with_char_int("Check-out successful for room number", room_number);
        print_centered("Press any key to continue......");
        set_color(15,0);
        ch=_getch();
        return;
    }
    else
    {
        set_color(12,0);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
        print_centered_with_char_int("No confirmed reservation found for room number", room_number);
        set_color(15,0);
        ch=_getch();
        return;
    }
}


void checkout(char u[20])
{
    int selected=0,ch,exit=0;
    system ("cls");
     // Menu options
        const char *menu[] =
        {
            "Check out",
            "Back to main menu",
            "Exit"
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
                    check_out(u);
                    break;
                case 1:
                    hotel_menu(u);
                    return;
                    break;
                     case 2:
                        system("cls");  // Exit option
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
                set_color(12, 0);
                print_centered("Exiting... Thank you!");
                set_color(15, 0);
                exit = 1;  // Set exit flag to break the loop
                break;

                }
            }

        }
}
