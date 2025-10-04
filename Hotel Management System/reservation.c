#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
int ch;
typedef struct
{
    char room_id[10];
    char status[20];
    char category [20];
    char price[10];
} room;

void generate_reservation_id(char *id) {
    // Generate a random 6-digit number (between 100000 and 999999)
    srand(time(NULL));int random_number = rand() % 900000 + 100000;  // This will ensure the number is always 6 digits


    // Convert the integer to a string and store it in 'id'
    snprintf(id, 7, "%d", random_number);
}

int generate_Id(char reservation_id[7]) {
      // Define a string to store the reservation ID (6 digits + null terminator)

    // Initialize random number generator with the current time

    // Generate reservation ID
    generate_reservation_id(reservation_id);

    // Print the generated reservation ID


    return 0;
}


int assign_room(char *category, char *assigned_room)
{
    int i = 0, selected = 0;
    char c1[20] = "Available";
    char text[100][50];  // To hold formatted room text
    room rooms[100];
    FILE *f1 = fopen("room.txt", "r");
    if (f1 == NULL)
    {
        print_centered("Cannot find file");
        return 0;
    }

    // Read room data from file
    while (fscanf(f1, "%s %s %s %s", rooms[i].room_id, rooms[i].status, rooms[i].category, rooms[i].price) != EOF)
    {
        i++;
    }
    fclose(f1);

    int num_rooms = i; // Number of rooms read
    int num_options = 0;

    // Prepare the list of available rooms with category matching
    for (i = 0; i < num_rooms; i++)
    {
        if (strcmp(rooms[i].status, c1) == 0 && strcmp(rooms[i].category, category) == 0)
        {
            sprintf(text[num_options], " %s - %s - %s - %s", rooms[i].room_id, rooms[i].status, rooms[i].category, rooms[i].price);
            num_options++;
        }
    }

    // If no available rooms, show an error message
    if (num_options == 0)
    {
        print_centered("No available rooms in the requested category.");
        return 0;
    }

    // Menu for selecting a room
    while (1)
    {
        system("cls");  // Clears the screen
        printf("\n\n\n\n\n\n\n\n\n");

        // Set default color for the welcome message (white text, black background)
        set_color(15, 0);
        print_centered("Choose an Available Room:\n");

        // Display available rooms
        for (i = 0; i < num_options; i++)
        {
            if (i == selected)
            {
                set_color(10, 0);  // Green text for selected option

            }
            else
            {
                set_color(15, 0);  // White text for unselected options

            }
            print_centered(text[i]);
        }

        // Wait for user input (arrow keys or Enter)
        int ch = _getch();

        if (ch == 224)    // Arrow key detected
        {
            ch = _getch();  // Get the actual arrow key code
            if (ch == 72)    // Up arrow
            {
                selected = (selected - 1 + num_options) % num_options;
            }
            else if (ch == 80)      // Down arrow
            {
                selected = (selected + 1) % num_options;
            }
        }
        else if (ch == 13)      // Enter key to select
        {
            // Find the corresponding room based on selection
            int room_index = selected;  // This will be the index in the available rooms list
            for (i = 0; i < num_rooms; i++)
            {
                if (strcmp(rooms[i].status, c1) == 0 && strcmp(rooms[i].category, category) == 0)
                {
                    if (room_index == 0)
                    {
                        set_color(15, 0);
                        strcpy(assigned_room, rooms[i].room_id);
                        strcpy(rooms[i].status,"Reserved");

                        i=0;
                        FILE *f1 = fopen("room.txt", "w");
                        if (f1 == NULL)
                        {
                            print_centered("Cannot find file");
                            return 0;
                        }
                        while(i<num_rooms)
                        {
                            fprintf(f1,"%s %s %s %s\n",rooms[i].room_id, rooms[i].status, rooms[i].category, rooms[i].price);
                            i++;
                        }

                        return 1;
                    }
                    room_index--;  // Move to the next room in the list
                }
            }
        }
    }


}


void reserve_room(char u[20])
{
    system("cls");
    char customer_name[20];
    char national_id[20];
    char email[20];
    char mobile[20];
    char check_in_date[20];
    int  number_of_nights;
    char room_category[15];
    char reservation_id[7];
    char assigned_room[10];
    int ch,selected=0;
    bool category_selected = false;

    set_color(6,0);
    {
        printf("\n\n\n");
        print_centered("Enter your data");

    }
    set_color(15,0);
    get_valid_string("Enter your name: ", customer_name, sizeof(customer_name));

    get_valid_national_id(national_id);

    validate_email(email);

    validatePhoneNumber(mobile);

    enter_date(check_in_date);
    set_color(15,0);
    number_of_nights = get_valid_integer_int("Enter Number of Nights: ");

    set_color(15,0);

    const char *menu[] =
    {
        "SeaView",
        "LakeView",
        "GardenView",
        "Back"
    };
    int num_options = sizeof(menu) / sizeof(menu[0]);


    while (!category_selected)
    {

        system("cls");
        // Set default color for the welcome message (white text, black background)

        printf("\n\n\n\n\n\n\n\n\n");

        set_color(15, 0);
        print_centered("Choose Room Category");



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
                strcpy(room_category,"SeaView");
                category_selected = true;
                break;
            case 1:
                strcpy(room_category,"LakeView");
                category_selected = true;
                break;
            case 2:
                strcpy(room_category,"GardenView");
                category_selected = true;
                break;
            case 3:
                reservation(u);
                return;
                break;

            }
            break;
        }
    }



    generate_Id(reservation_id);



    if (assign_room(room_category, assigned_room))
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n");
        set_color(10,0);
        print_centered_with_char_array("Room Assigned ID is:", assigned_room);


        FILE *reservations_file = fopen("Reservation.txt", "a");

        if (reservations_file == NULL)
        {
            set_color(12,0);
            print_centered("Error opening Reservation.txt");
            print_centered("Press any key to continue......");
            ch=_getch();
            set_color(15,0);
            return;
        }
        char k[10];
        strcpy(k,assigned_room);
        char co[20] ="unconfirmed";

        fprintf(reservations_file, "%s,%s,%s,%s,%s,%d,%s,%s,%s\n",
                reservation_id, assigned_room, co, customer_name, national_id, number_of_nights, check_in_date, email, mobile);
        fclose(reservations_file);

        print_centered_with_char_array("Reservation Successful! Your Reservation ID is: ", reservation_id);
        sortdate();

    }

    else
    {
        printf("\n\n\n");
        set_color(12,0);
        print_centered("No available rooms in the requested category.\n");
        print_centered("Press any key to continue......");
        ch=_getch();
        set_color(15,0);

    }
    print_centered("Press any key to continue......");
    ch=_getch();

}


int reservation (char u[10])
{

    int selected=0,ch;



    while (1)
    {

        // Menu options
        const char *menu[] =
        {
            "Reserve Room",
            "Back to main menu"
        };
        int num_options = sizeof(menu) / sizeof(menu[0]);


        while (1)
        {
            system("cls");
            // Set default color for the welcome message (white text, black background)
            set_color(15, 0);
            printf("\n\n\n\n\n\n\n\n\n\n\n");
            print_centered("---------Hotel Reservation System----------\n");
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
                    reserve_room(u);
                    break;
                case 1:
                    hotel_menu(u);
                    return;
                    break;

                }
            }
        }
    }

    return 0;
}




