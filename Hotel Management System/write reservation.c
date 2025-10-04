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

void write_reservation(reservation re[100] , int *l)
{
    int i=0;

    char line[1000];
    FILE *f;

    f = fopen("Reservation.txt", "w");
    if (f == NULL)
    {
        printf("Error couldn't Open Reservation.txt.......\n");
        printf("\n\n");

        printf("Press Any Key to continue......");

        ch=_getch();
        return;
    }

        while(i<*l)
    {
    fprintf(f,"%s,%s,%s,%s,%s,%d,%s,%s,%s\n",
                   re[i].reservationID, re[i].room_number, re[i].status, re[i].name,
                   re[i].id_number, &re[i].days, re[i].date, re[i].email, re[i].phone);
                   i++;
    }
    fclose(f);
}
