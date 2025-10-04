#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    char room_id[10];
    char status[20];
    char category [20];
    char price[10];
} room;

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
} reservation;

void name(char u[20])
{
    system("cls");
    char customer_name[100];
    int l=0,k=0,found=0,selected=0,ch;
    int continue_searching = 1;
    reservation re[100];

    load_reservation(re,&k);



        print_centered_with_input("Enter customer name: ");
        fgets(customer_name, sizeof(customer_name), stdin);
        customer_name[strcspn(customer_name, "\n")] = '\0';


            while(l<k)
                {

            if (strcmp(customer_name,re[l].name) == 0)
            {

                printf("\n\n\n");
                set_color(10, 0);
                print_centered("--- Reservation Details ---");
                set_color(15, 0);
                print_centered_with_char_array("Reservation ID:", re[l].reservationID);
                print_centered_with_char_array("Room Number:", re[l].room_number);
                print_centered_with_char_array("Room Reservation Status:", re[l].status);
                print_centered_with_char_int("Number of Nights:", re[l].days);
                print_centered_with_char_array("Check In Date:", re[l].date);
                printf("\n");
                set_color(10, 0);
                print_centered("--- Customer Details ---");
                set_color(15, 0);
                print_centered_with_char_array("Customer Name:", re[l].name);
                print_centered_with_char_array("National ID:", re[l].id_number);
                print_centered_with_char_array("Customer Email:", re[l].email);
                print_centered_with_char_array("Mobile Number:", re[l].phone);
                set_color(10, 0);
                print_centered("---------------------");
                found = 1;
                continue_searching=0;
                print_centered("Press any key to continue....");
                ch=_getch();
                // Wait for a key press
                set_color(15, 0);
                break;
            }
            l++;
        }

        if (!found)
        {
            // Menu options
            const char *menu[] =
            {
                "try again",
                "Back "
            };
            int num_options = sizeof(menu) / sizeof(menu[0]);

            while (1)
            {
                system("cls");
                // Set red color
                set_color(12, 0);
                print_centered("Name not found\n");
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
                        name(u);
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



void room_no(char u[20])
{
    system("cls");
    char room_number[100];
    char Customer_Details[100];
    int l=0,k=0,found=0,selected=0,ch;
    int continue_searching = 1;
    reservation re[100];

    load_reservation(re,&k);



       print_centered_with_input("Enter room number: ");
        fgets(room_number, sizeof(room_number), stdin);
        room_number[strcspn(room_number, "\n")] = '\0';

int t=0;
                    int *p=&t;
            while(l<k)
                {


            if (strcmp(room_number,re[l].room_number) == 0)
            {

                printf("\n\n\n");
                set_color(10, 0);
                print_centered("--- Reservation Details ---");
                set_color(15, 0);
                print_centered_with_char_array("Reservation ID:", re[l].reservationID);
                print_centered_with_char_array("Room Number:", re[l].room_number);
                print_centered_with_char_array("Room Reservation Status:", re[l].status);
                print_centered_with_char_int("Number of Nights:", re[l].days);
                print_centered_with_char_array("Check In Date:", re[l].date);
                printf("\n");
                set_color(10, 0);
                print_centered("--- Customer Details ---");
                set_color(15, 0);
                print_centered_with_char_array("Customer Name:", re[l].name);
                print_centered_with_char_array("National ID:", re[l].id_number);
                print_centered_with_char_array("Customer Email:", re[l].email);
                print_centered_with_char_array("Mobile Number:", re[l].phone);
                set_color(10, 0);
                print_centered("---------------------");
                found = 1;
                continue_searching=0;
                print_centered("Press any key to continue....");
                ch=_getch();
                // Wait for a key press
                set_color(15, 0);
                break;
            }
            l++;
        }

        if (!found)
        {
            room rooms[100];
            char room_status[100];
            char room[100];
            FILE *f1 = fopen("room.txt", "r");
            if (f1 == NULL)
            {
                printf("room.txt file not found. Please make sure the file exists.\n");
                return;
            }
            rewind(f1);

            int i=0,found=0;


            while ( fscanf(f1,"%s %s %s %s\n", rooms[i].room_id, rooms[i].status, rooms[i].category, rooms[i].price) !=EOF)
            {
                if (strcmp(room_number,rooms[i].room_id)==0)
                {
                    set_color(10,0);
                    print_centered ("Room is Available ");
                    set_color(15,0);
                    print_centered ( "---------------room details-----------------");
                    *p=1;
                    print_centered_with_4char( rooms[i].room_id, "Available", rooms[i].category, rooms[i].price);
                    printf("\n\n");
                    set_color(10,0);
                    print_centered("Press Any Key to continue......");
                    set_color(15,0);
                    ch=_getch();
                }
                i++;
            }


            fclose(f1);

        }
        if (*p ==1)
        {
            found=1;
        }
        if (!found)
        {
            // Room not found, display menu
            const char *menu[] =
            {
                "Try again",
                "Back "
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
                        room_no(u);// Try again recrusive
                        return; // Exit menu and re-prompt
                    }
                    else if (selected == 1)     // Back to main menu
                    {

                        return; // Exit function
                    }
                }
            }
        }
        else
        {
            continue_searching = 0; // Exit loop if room is found
        }
    }
    fclose(f1);


void room_st(char u[20])
{
    system("cls");
    bool category_selected=false;
    int selected=0,ch;
    room rooms[100];
    char room_status[100];
    char room[100];
    FILE *f1 = fopen("room.txt", "r");
    if (f1 == NULL)
    {
        set_color(12,0);
            print_centered("Error opening room.txt");
            print_centered("Press any key to continue......");
            ch=_getch();
            set_color(15,0);
            return;
    }

    rewind(f1);
     const char *menu[] =
    {
        "Available",
        "Reserved",
        "Back"
    };
    int num_options = sizeof(menu) / sizeof(menu[0]);


    while (!category_selected)
    {
        system("cls");
        // Set default color for the welcome message (white text, black background)

        printf("\n\n\n\n\n\n\n\n\n");

        set_color(15, 0);
        print_centered("Choose Room Status");



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

            switch(selected)
            {

            case 0:
                strcpy(room_status,"Available");
                category_selected = true;
                break;
            case 1:
                strcpy(room_status,"Reserved");
                category_selected = true;
                break;
            case 2:
                return;
                break;
            }
            break;
        }
    }

    int i=0,found=0;
    system("cls");
    printf("\n\n\n");

    while ( fscanf(f1,"%s %s %s %s\n", rooms[i].room_id, rooms[i].status, rooms[i].category, rooms[i].price) !=EOF)
    {
        if (strcmp(room_status,rooms[i].status)==0)
        {
            found=1;

            print_centered_with_4char( rooms[i].room_id, rooms[i].status, rooms[i].category, rooms[i].price);
        }
        i++;
    }
    if(found)
    {

        set_color(10,0);
        print_centered ("---------------room details-----------------");
        printf("\n\n");

        print_centered("Press Any Key to continue......");
        set_color(15,0);
        ch = _getch();
    }



    fclose(f1);
    if(!found)
    {
        selected=0;
        // Room not found, display menu
        const char *menu[] =
        {
            "Try again",
            "Back "
        };
        int num_options = sizeof(menu) / sizeof(menu[0]);

        while (1)
        {
            system("cls");
            set_color(12, 0);
            print_centered_with_char_array("no rooms are",room_status);
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
                    room_st(u);// Try again recursive
                    return; // Exit menu and re-prompt
                }
                else if (selected == 1)     // Back to main menu
                {
                    fclose(f1);

                    return; // Exit function
                }
            }
        }

    }
}

int Quary(char u[20])
{
    system("cls");
    set_color(15,0);
    int selected=0,ch;
    const char *menu[] =
    {
        "Search by customer name",
        "Search by room number",
        "View view all available or reserved rooms",
        "Return to main menu"
    };
    int num_options = sizeof(menu) / sizeof(menu[0]);


    int i=0;
    while (1)
    {
        system("cls");
        printf ("\n\n\n\n\n\n\n\n\n\n");
        // Set default color for the welcome message (white text, black background)
        set_color(15, 0);
        print_centered("Welcome to Query Screen!\n\n");


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
                name(u);
                break;
            case 1:
                room_no(u);
                break;
            case 2:
                room_st(u);
                break;
            case 3:
                hotel_menu(u);
                return ;
                break;
            }
        }
    }
    return 0;
}


