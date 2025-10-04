#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void room_availability()
{
    system("cls");
    char room_info[100];
    char room_number[100];
    int flag1=1;
    int found=0;
    int ch,selected=0;
    FILE *f1 = fopen("room.txt","r");
    if (f1 == NULL)
    {
        set_color(12, 0);
        print_centered("Room.txt file not found. Please make sure the file exists.");
        print_centered("Press any key to continue");
        ch=_getch();
        set_color(15,0);
        return;
    }
    while(flag1)
    {
        system("cls");
        print_centered_with_input("enter room number: ");
        gets(room_number);
        rewind(f1);
        while(fgets(room_info, 100, f1) != NULL)
        {
            char *room_num = strtok(room_info, " ");
            char *status = strtok(NULL, " ");
            if(strcmp(room_num,room_number)==0)
            {
                set_color(10, 0);
                printf("\n");
                print_centered("--------------------");
                print_centered_with_char_array("status:",status);
                print_centered("--------------------");
                found=1;
                printf("\n\n");
                print_centered("Press any key to continue....");
                ch = _getch();

                break;
            }

        }
        if(!found)
        {

            // Menu options
            const char *menu[] =
            {
                "try again",
                "Back"
            };
            int num_options = sizeof(menu) / sizeof(menu[0]);

            while (1)
            {
                system("cls");
                // Set red color
                set_color(12, 0);
                print_centered("room not found\n");
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

                room_availability();
                return;  // Exit this menu and re-prompt for room number
            }
            else if (selected == 1)  // Back to main menu
            {
                fclose(f1);
                return;  // Exit the current function
            }
            break;
                }
            }
        }
        if(found)
        {
            break;
        }
    }
    fclose(f1);
}

int track_availability(char u[20])
{
    int ch,selected=0;




    // Menu options
    const char *menu[] =
    {
        "check if room avalibile",
        "Back to main menu"
    };
    int num_options = sizeof(menu) / sizeof(menu[0]);


    while (1)
    {
        system("cls");
        // Set default color for the welcome message (white text, black background)
        printf("\n\n\n\n\n\n\n\n\n\n");
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
                room_availability(u);
                break;
            case 1:
                hotel_menu(u);
                return;
                break;

            }
        }

    }
    return 0;
}






