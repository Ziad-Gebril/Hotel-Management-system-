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

void edit_id( char u[20])
{
    system("cls");
    char a[20];
    int selected=0,ch;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    print_centered_with_input("Enter resrvation ID :");
    fgets(a, sizeof(a), stdin);
    a[strcspn(a, "\n")] = '\0'; // Remove the trailing newline character

    Room re[100];
    int k=0, i, found = 0, c = 0;
    char reservation[100][1000], line1[1000];

    load_reservation(re,&k);

    for (i = 0; i < k; i++)
    {
        if (strcmp( a ,re[i].reservationID)==0)
        {
            found=1;
        // Menu options
        const char *menu[] =
        {
            "Status",
            "Name",
            "ID Number",
            "Days",
            "Date",
            "Email",
            "Phone",
            "Finish",
            "Back to main menu"
        };
        int num_options = sizeof(menu) / sizeof(menu[0]);


        while (1)
        {
            system("cls");
            // Set default color for the welcome message (white text, black background)
          set_color(15, 0);
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
            print_centered("Choose what you want to modify");
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
                    system("cls");
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
                    print_centered_with_input("Edit status:");
                    scanf("%s", re[i].status);
                    break;
                case 1:
                    system("cls");
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
                    print_centered_with_input("Edit name:");
                    getchar();
                    gets(re[i].name);
                    break;
                case 2:
                    system("cls");
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
                    print_centered_with_input("Edit ID number:");
                    scanf("%s", re[i].id_number);
                    break;
                case 3:
                    system("cls");
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
                    print_centered_with_input("Edit number of days:");
                    scanf("%d", &re[i].days);
                    break;
                case 4:
                    system("cls");
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
                    enter_date(re[i].date);
                    printf("\n");
                    break;
                case 5:
                    system("cls");
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
                    print_centered_with_input("Edit email:");
                    scanf("%s", re[i].email);
                    break;
                case 6:
                    system("cls");
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
                    print_centered_with_input("Edit phone number:");
                    scanf("%s", re[i].phone);
                    break;
                case 7:
                     system("cls");
                     printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
                    for (i = 0; i < k; i++)
                    {
                        sprintf(line1, "%s,%s,%s,%s,%s,%d,%s,%s,%s\n",
                                re[i].reservationID, re[i].room_number, re[i].status,
                                re[i].name, re[i].id_number, re[i].days, re[i].date,
                                re[i].email, re[i].phone);
                        if (strlen(line1) > 1)
                        {
                            strcpy(reservation[c++], line1);
                        }
                    }
                    FILE *ptr;
                    ptr = fopen("Reservation.txt", "w");
                    if (ptr == NULL)
                    {
                        set_color(12,0);
                        print_centered("OPPS FILE CANNOT BE OPENED.");
                        print_centered("Press any key to continue");
                       set_color(15,0);
                        return;
                    }
                    for (i = 0; i < c; i++)
                    {
                        fputs(reservation[i], ptr);
                    }
                    fclose(ptr);
                    set_color(10,0);
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
                    print_centered("Finished editing");
                    set_color(15,0);
                    print_centered("Press any key to continue........");
                    ch=_getch();
                    edit_reservation(u);
                    return;
                case 8:
                    system("cls");
                    hotel_menu(u);
                    return;
                    break;

                }
            }
        }
    }
        }



    if (!found)
    {
        set_color(12,0);
        print_centered("No matching reservation found.");
        print_centered("Press any key to continue");
        set_color(15,0);
        ch=_getch();

        return;
    }

}

void edit_room_nom( char u[20])
{
    system("cls");
    char a[20];
    int selected=0,ch;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    print_centered_with_input("Enter your room number :");
      fgets(a, sizeof(a), stdin);
    a[strcspn(a, "\n")] = '\0'; // Remove the trailing newline character

    Room re[100];
    int k=0, i, choice, found = 0, c = 0;
    char line[1000], reservation[100][1000], line1[1000];

    load_reservation(re,&k);

    for (i = 0; i < k; i++)
    {
        if (strcmp(a,re[i].room_number)==0)
        {
            found=1;
        // Menu options
        const char *menu[] =
        {
            "Status",
            "Name",
            "ID Number",
            "Days",
            "Date",
            "Email",
            "Phone",
            "Finish",
            "Back to main menu"
        };
        int num_options = sizeof(menu) / sizeof(menu[0]);


        while (1)
        {
            system("cls");
            // Set default color for the welcome message (white text, black background)
          set_color(15, 0);
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
            print_centered("Choose what you want to modify");
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
                    system("cls");
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
                    print_centered_with_input("Edit status:");
                    scanf("%s", re[i].status);
                    break;
                case 1:
                    system("cls");
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
                    print_centered_with_input("Edit name:");
                    getchar();
                    gets(re[i].name);
                    break;
                case 2:
                    system("cls");
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
                    print_centered_with_input("Edit ID number:");
                    scanf("%s", re[i].id_number);
                    break;
                case 3:
                    system("cls");
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
                    print_centered_with_input("Edit number of days:");
                    scanf("%d", &re[i].days);
                    break;
                case 4:
                    system("cls");
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
                    enter_date(re[i].date);
                    printf("\n");
                    break;
                case 5:
                    system("cls");
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
                    print_centered_with_input("Edit email:");
                    scanf("%s", re[i].email);
                    break;
                case 6:
                    system("cls");
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
                    print_centered_with_input("Edit phone number:");
                    scanf("%s", re[i].phone);
                    break;
                case 7:
                     system("cls");
                     printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
                    for (i = 0; i < k; i++)
                    {
                        sprintf(line1, "%s,%s,%s,%s,%s,%d,%s,%s,%s\n",
                                re[i].reservationID, re[i].room_number, re[i].status,
                                re[i].name, re[i].id_number, re[i].days, re[i].date,
                                re[i].email, re[i].phone);
                        if (strlen(line1) > 1)
                        {
                            strcpy(reservation[c++], line1);
                        }
                    }
                    FILE *ptr;
                    ptr = fopen("Reservation.txt", "w");
                    if (ptr == NULL)
                    {
                        set_color(12,0);
                        print_centered("OPPS FILE CANNOT BE OPENED.");
                        print_centered("Press any key to continue");
                       set_color(15,0);
                        return;
                    }
                    for (i = 0; i < c; i++)
                    {
                        fputs(reservation[i], ptr);
                    }
                    fclose(ptr);
                    set_color(10,0);
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
                    print_centered("Finished editing");
                    set_color(15,0);
                    print_centered("Press any key to continue........");
                    ch=_getch();
                    edit_reservation(u);
                    return;
                case 8:
                    system("cls");
                    hotel_menu(u);
                    return;
                    break;

                }
            }
        }
    }
    }

    if (!found)
    {
        set_color(12,0);
        print_centered("No matching reservation found.");
        print_centered("Press any key to continue");
        set_color(15,0);
        ch=_getch();
        return;
    }
}

int edit_reservation(char u[20])
{
    system("cls");

    int selected=0,ch;
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
         print_centered("Edit your reservation");
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
                edit_id(u);
                break;
            case 1:
                edit_room_nom(u);
                break;
            case 2:
                hotel_menu(u);
                return;
                break;

            }
        }

    }

}

