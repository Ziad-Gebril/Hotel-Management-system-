#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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

void print_res(reservation re[100],int j)
{


                   print_centered_with_char_array("reservation ID : ",re[j].reservationID);
                   print_centered_with_char_array("room number :",re[j].room_number);
                    print_centered_with_char_array("status : ",re[j].status);
                    print_centered_with_char_array( "name : ",re[j].name);
                    print_centered_with_char_array( "phone number : ",re[j].phone);
                   print_centered_with_char_array("national ID : ",re[j].id_number);
                    print_centered_with_char_int("number of days : ",&re[j].days);
                    print_centered_with_char_array("check in date : ",re[j].date);
                    print_centered_with_char_array("email : ", re[j].email);
                   j++;

}
