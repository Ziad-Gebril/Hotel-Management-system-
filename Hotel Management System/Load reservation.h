#ifndef LOAD_H
#define LOAD_H

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

void load_reservation(reservation re[100] , int *i);

#endif

