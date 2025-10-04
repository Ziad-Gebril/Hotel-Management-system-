void displayDate(char date[], int position) {
    // Clear the current line and reset the cursor position
    printf("\r");

    // Display the prompt
    printf("                                           ");
    printf("Enter Check-In Date (DD-MM-YYYY): ");

    // Display each character of the date
    for (int i = 0; i < 10; i++) {
        if (i == position) {
            // Highlight the current position with white background and black text
            printf("\033[47;30m%c\033[0m", date[i]);
        } else {
            printf("%c", date[i]); // Default display
        }
    }
}

void enter_date(char date[11]) {
    strcpy(date, "DD-MM-YYYY"); // Initial placeholder with '-' delimiters
    int position = 0;           // Cursor position (0 to 9)
    char key;

    while (1) {
        displayDate(date, position); // Display the current state of the date with highlighting

        key = _getch(); // Get user input

        // Handle arrow keys
        if (key == -32) { // Special key prefix
            key = _getch();
            if (key == 75) { // Left arrow
                if (position > 0 ) position--; // Move left
            } else if (key == 77) { // Right arrow
                if (position < 9 ) position++; // Move right
            }
        }
        // Handle digit entry
        else if (key >= '0' && key <= '9') {
            if ((position >= 0 && position <= 1) ||   // Day
                (position >= 3 && position <= 4) ||   // Month
                (position >= 6 && position <= 9)) {  // Year
                date[position] = key; // Replace placeholder with digit
                position++;            // Move to the next position
                if (position == 2 || position == 5) position++; // Skip dashes
            }
        }
        // Handle backspace
        else if (key == 8) { // Backspace
            if (position > 0) {
                if (position == 3 || position == 6) position--; // Skip dashes
                position--;
                if ((position >= 0 && position <= 1) ||  // Day
                    (position >= 3 && position <= 4) ||  // Month
                    (position >= 6 && position <= 9)) { // Year
                    date[position] = '_'; // Clear the character
                }
            }
        }
        // Exit on Enter key
        else if (key == 13) {
            break; // Finish editing
        }
    }
}
