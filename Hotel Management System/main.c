#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include <conio.h>  // Required for _kbhit() and getch()
#include "login.h"
#include "Hotel menu.h"
#define SCREEN_WIDTH 120

// Function to clear the input buffer
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Loop until the buffer is cleared
    }
}

void get_valid_string(const char *prompt, char *result, int max_length) {
    char input[100];

    while (1) {
        printf("\n");
        print_centered_with_input(prompt);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';  // Remove newline character

        // Check if the input contains only alphabetic characters
        int is_valid = 1;
        for (int i = 0; input[i] != '\0'; i++) {
            if (!isalpha(input[i]) && input[i] != ' ') {  // Allow spaces for multi-word names
                is_valid = 0;
                break;
            }
        }

        if (is_valid && strlen(input) > 0) {
            strncpy(result, input, max_length);  // Copy valid input to the result
            result[max_length - 1] = '\0';      // Ensure null-termination
            return;
        }

        // If invalid, display an error message
        set_color(12, 0);
        print_centered("Invalid input. Please enter alphabetic characters only.");
        set_color(15,0);
    }
}


int isValidPhoneNumber(const char *input) {
    // Check if the length of the number is exactly 11 digits
    if (strlen(input) != 11) {
        return 0; // If not 11 digits, invalid
    }

    // Check if all characters are digits
    for (int i = 0; input[i] != '\0'; i++) {
        if (!isdigit(input[i])) {
            return 0; // If any character is not a digit, invalid
        }
    }

    return 1; // Valid phone number
}

// Function to get and validate the phone number
void validatePhoneNumber(char phoneNumber[50]) {

    while (1) { // Infinite loop to keep asking for valid input
        // Prompt the user to enter the phone number
        print_centered_with_input("Enter a phone number (11 digits): ");
        scanf("%s", phoneNumber);

        // Validate the phone number
        if (isValidPhoneNumber(phoneNumber)) {
            break; // Exit the loop if the phone number is valid
        } else {
            set_color(12,0);
            printf("Invalid phone number! It must be exactly 11 digits.\n");
            set_color(15,0);
        }
    }
}

void get_valid_national_id(char id[15]) {
    char input[100];

    while (1) {
        print_centered_with_input("Enter your 14-digit National ID: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove the newline character

        // Check if the input is exactly 14 characters long
        if (strlen(input) == 14) {
            int is_valid = 1;
            // Check if all characters are digits
            for (int i = 0; i < 14; i++) {
                if (!isdigit(input[i])) {
                    is_valid = 0;
                    break;
                }
            }

            if (is_valid) {
                strncpy(id, input, 15); // Copy the valid input into the provided array
                return; // Exit the function after valid input
            }
        }

        // If invalid, display an error message and prompt again
        set_color(12,0);
        print_centered("Invalid input. Please enter exactly 14 numeric characters.");
        set_color(15,0);
    }
}

int validate_email(char email[100]) {

    int atSymbol, dotSymbol, atPosition, dotPosition;

    // Start a loop to keep asking for a valid email
    while (1) {
        atSymbol = 0;
        dotSymbol = 0;
        atPosition = -1;
        dotPosition = -1;

        print_centered_with_input("Enter an email: ");
        scanf("%s", email);

        int length = strlen(email);
        int isValid = 1;

        // Loop through each character of the email
        for (int i = 0; i < length; i++) {
            if (email[i] == '@') {
                if (atSymbol) {
                    isValid = 0;  // Multiple '@' symbols are not allowed
                    break;
                }
                atSymbol = 1;
                atPosition = i;
            } else if (email[i] == '.') {
                dotSymbol = 1;
                dotPosition = i;
            } else if (!isalnum(email[i]) && email[i] != '.' && email[i] != '@' && email[i] != '-') {
                isValid = 0;  // Invalid character found
                break;
            }
        }

        // Check if '@' comes before '.', and the email is not starting or ending with invalid symbols
        if (atSymbol && dotSymbol && atPosition < dotPosition && atPosition > 0 && dotPosition < length - 1) {
            break;  // Exit the loop if the email is valid
        } else {
            set_color(12,0);
            printf("Invalid email! Please try again.\n");
            set_color(15,0);
        }
    }

    return 0;
}

int get_valid_integer(const char *prompt)
{
    char input[100];
    int valid_integer;

    while (1)
    {
        printf("\n");
        print_centered_with_input(prompt);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        getchar();  // Remove newline character from input

        // Check if the input is a valid integer
        int is_valid = 1;
        for (int i = 0; input[i] != '\0'; i++)
        {
            if (!isdigit(input[i]))
            {
                is_valid = 0;
                break;
            }
        }

        if (is_valid)
        {
            valid_integer = atoi(input);  // Convert the valid string to an integer
            if (valid_integer > 0)       // Ensure the integer is positive
            {
                return valid_integer;
            }
        }

        // If invalid, display an error message
        set_color(12,0);
        print_centered("Invalid input. Please enter a positive integer.");
        set_color(15,0);
    }
}

int get_valid_integer_int(const char *prompt)
{
    char input[100];
    int valid_integer;

    while (1)
    {
        printf("\n");
        print_centered_with_input(prompt);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        getchar();  // Remove newline character from input

        // Check if the input is a valid integer
        int is_valid = 1;
        for (int i = 0; input[i] != '\0'; i++)
        {
            if (!isdigit(input[i]))
            {
                is_valid = 0;
                break;
            }
        }

        if (is_valid)
        {
            valid_integer = input;  // Convert the valid string to an integer
            if (valid_integer > 0)       // Ensure the integer is positive
            {
                return valid_integer;
            }
        }

        // If invalid, display an error message
        set_color(12,0);
        print_centered("Invalid input. Please enter a positive integer.");
        set_color(15,0);
    }
}

void print_centered_with_char_int(char text[20] ,int x) {
    int len = strlen(text);
    int padding = (SCREEN_WIDTH - len) / 2;

    // Print the padding (spaces)
    for (int i = 0; i < padding; i++) {
        printf(" ");  // Use space for more precise centering
    }

    // Print the text
    printf("%s %d\n",text,x);
    fflush(stdout);
}
// Function to hide the console cursor
void hide_cursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    // Get the current cursor information
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = FALSE;  // Set the cursor visibility to false
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);  // Apply the changes
}

void print_centered_with_int_char(int x ,char text[20]) {
    int len = strlen(text);
    int padding = (SCREEN_WIDTH - len) / 2;

    // Print the padding (spaces)
    for (int i = 0; i < padding; i++) {
        printf(" ");  // Use space for more precise centering
    }

    // Print the text
    printf("%d %s\n",x,text);
    fflush(stdout);
}

void print_centered_with_int_4char(int x ,char text0[20],char text1[20],char text2[20],char text3[20]) {
    int len0 = strlen(text0);
    int len1 = strlen(text1);
    int len2 = strlen(text2);
    int len3 = strlen(text3);
    int len=len0+len1+len2+len3;
    int padding = (SCREEN_WIDTH - len) / 2;

    // Print the padding (spaces)
    for (int i = 0; i < padding; i++) {
        printf(" ");  // Use space for more precise centering
    }

    // Print the text
    printf("%d %s %s %s %s\n",x,text0,text1,text2,text3);
    fflush(stdout);
}

void print_centered_with_4char(char text0[20],char text1[20],char text2[20],char text3[20]) {
    int len0 = strlen(text0);
    int len1 = strlen(text1);
    int len2 = strlen(text2);
    int len3 = strlen(text3);
    int len=len0+len1+len2+len3;
    int padding = (SCREEN_WIDTH - len) / 2;

    // Print the padding (spaces)
    for (int i = 0; i < padding; i++) {
        printf(" ");  // Use space for more precise centering
    }

    // Print the text
    printf("%s %s %s %s\n",text0,text1,text2,text3);
    fflush(stdout);
}

void print_centered_with_char_array(const char *text ,char x[20]) {
    int len0 = strlen(text);
    int len1 = strlen(x);
    int len =len0 + len1;
    int padding = (SCREEN_WIDTH - len) / 2;

    // Print the padding (spaces)
    for (int i = 0; i < padding; i++) {
        printf(" ");  // Use space for more precise centering
    }

    // Print the text
    printf("%s %s\n", text,x);
    fflush(stdout);
}

void print_centered(const char *text) {
    int len = strlen(text);
    int padding = (SCREEN_WIDTH - len) / 2;

    // Print the padding (spaces)
    for (int i = 0; i < padding; i++) {
        printf(" ");  // Use space for more precise centering
    }

    // Print the text
    printf("%s\n", text);
    fflush(stdout);
}

void print_centered_with_input(const char *text) {
    int len = strlen(text);
    int padding = (SCREEN_WIDTH - len) / 2;

    // Print the padding (spaces)
    for (int i = 0; i < padding; i++) {
        printf(" ");  // Use space for more precise centering
    }

    // Print the text
    printf("%s", text);
    fflush(stdout);
}

void print_centered_one_char_with_input(const char *text) {
    int len = strlen(text);
    int padding = (SCREEN_WIDTH - len) / 2;

    // Print the padding (spaces)
    for (int i = 0; i < padding; i++) {
        printf(" ");  // Use space for more precise centering
    }

    // Print the text
    printf("%c", text);
    fflush(stdout);
}

void main_menu ()
{

    int ch, selected = 0;
    char u[20];


     // Menu options
    const char *menu[] = {
        "Login",
        "Exit"
    };
    int num_options = sizeof(menu) / sizeof(menu[0]);


     while (1) {
            int k=0;
            system("cls");
        // Set default color for the welcome message (white text, black background)
        set_color(15, 0);
printf("\n\n\n\n\n\n\n\n\n\n");
        print_centered("Welcome to the Login Screen!\n\n");

        // Display menu with color
        for (int i = 0; i < num_options; i++) {
            if (i == selected) {
                set_color(10, 0);  // Green text, Black background for selected option

            } else {
                set_color(15, 0);  // White text, Black background for other options

            }
             print_centered(menu[i]);
        }

        // Wait for a key press
        ch = _getch();
         switch (ch) {
            case 224:  // Handle arrow keys (extended keys)
                ch = _getch();  // Get the actual arrow key code
                if (ch == 72) {  // Up arrow
                    selected = (selected - 1 + num_options) % num_options;
                } else if (ch == 80) {  // Down arrow
                    selected = (selected + 1) % num_options;
                }
                break;
            case 13:  // Enter key (Carriage Return)

    switch(selected)
    {
    case 0:

       if (login(u)==1)
       {
            set_color(10,0);
            printf("\n\n\n\n\n\n\n\n");
            print_centered("Login successful");
            print_centered("Press Enter....");
            ch = _getch();

           hotel_menu(u);
           k=1;
           return;
       }
        else{
            main_menu();
            return;
        }

    case 1:
        system("cls");
        printf("\n\n\n\n\n\n\n\n" );

        set_color(10,0);//green output
        print_centered("Exiting program.......\n");
        k =1;
          return;
        break;



    }

}
if (k==1)
{
    set_color(15,0);
    break;
}
     }
}




void main ()
{
hide_cursor();
main_menu();

    return 0;
}

