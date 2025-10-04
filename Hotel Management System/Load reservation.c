#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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
} reservation;


void load_reservation(reservation re[100] , int *i)
{
    int l = 0;
    char line[1000];
    FILE *ptr;

    ptr = fopen("Reservation.txt", "r");
    if (ptr == NULL)
    {
        printf("Error couldn't Open Reservation.txt.......\n");
        printf("\n\n");

        printf("Press Any Key to continue......");

        ch=_getch();
        return;
    }

    while (fgets(line, sizeof(line), ptr))
    {
        if (strlen(line) > 1)
        {
            sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^,\n]",
                   re[l].reservationID, re[l].room_number, re[l].status, re[l].name,
                   re[l].id_number, &re[l].days, re[l].date, re[l].email, re[l].phone);
            l++;
        }
    }
    *i=l;
    fclose(ptr);
}
