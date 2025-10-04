#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
    char id[20];
    char room_number[20];
    char status[20];
    char name[50];
    char id_number[20];
    int days;
    char date[20];
    char email[50];
    char phone[20];
} Re;

int compare_dates(const void *a, const void *b)
{
    Re *ra = (Re *)a;
    Re *rb = (Re *)b;

    struct tm tm1 = {0}, tm2 = {0};

    // Parse dates into dd-mm-yyyy format
    sscanf(ra->date, "%d-%d-%d", &tm1.tm_mday, &tm1.tm_mon, &tm1.tm_year);
    sscanf(rb->date, "%d-%d-%d", &tm2.tm_mday, &tm2.tm_mon, &tm2.tm_year);

    tm1.tm_mon -= 1; // Adjust months to 0-based
    tm2.tm_mon -= 1;

    tm1.tm_year -= 1900; // Adjust years to the correct value
    tm2.tm_year -= 1900;

    // Return the difference between the two dates
    return mktime(&tm1) - mktime(&tm2);
}

void sortdate()
{
    char line[200];
    Re R[200];  // Fixed array size (for now)
    int l = 0, i;
    FILE *ptr;

    ptr = fopen("Reservation.txt", "r");
    if (ptr == NULL)
    {
        printf("Reservation file does not exist\n");
        return;
    }

    // Read reservations from the file and capture dates
    while (fgets(line, sizeof(line), ptr) != NULL)
    {
        // Parse each line into the structure fields
        if (sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^,\n]",
                   R[l].id, R[l].room_number, R[l].status, R[l].name,
                   R[l].id_number, &R[l].days, R[l].date, R[l].email, R[l].phone) == 9)
        {
            l++;
        }
    }
    fclose(ptr);  // Close the file after reading

    if (l == 0)
    {
        printf("No valid reservations found to sort.\n");
        return;
    }

    // Sort the reservations based on the date
    qsort(R, l, sizeof(Re), compare_dates);

    // Write the sorted reservations back to the file
    ptr = fopen("Reservation.txt", "w");
    if (ptr == NULL)
    {
        printf("Failed to open reservation file for writing\n");
        return;
    }

    for (i = 0; i < l; i++)
    {
        fprintf(ptr, "%s,%s,%s,%s,%s,%d,%s,%s,%s\n", R[i].id, R[i].room_number, R[i].status, R[i].name,
                R[i].id_number, R[i].days, R[i].date, R[i].email, R[i].phone);
    }

    fclose(ptr);  // Close the file after writing
}
