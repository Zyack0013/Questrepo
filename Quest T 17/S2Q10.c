// Problem 10: Sports Facility Booking System
// Description: Manage bookings for sports facilities using a linked list.Operations:
// Create a booking list.
// Insert a new booking.
// Delete a canceled or completed booking.
// Display all current bookings.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Booking {

    int bookingID;
    char facilityName[50];
    char userName[50];
    struct Booking *next;
    
} Booking;

Booking *first = NULL; 
int totalBookings = 0; 

void createBookingList(int count);
void insertBooking();
void deleteBooking(int bookingID);
void displayAllBookings();

int main() {

    int choice, count, bookingID;

    while (1) {

        printf("\n\t\tWelcome\t\t\n");
        printf("1. Create a booking list (add initial bookings).\n");
        printf("2. Insert a new booking.\n");
        printf("3. Delete a canceled or completed booking.\n");
        printf("4. Display all current bookings.\n");
        printf("5. Exit.\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume newline character

        switch (choice) {

            case 1:
            printf("Enter the number of initial bookings: ");
            scanf("%d", &count);
            getchar();
            createBookingList(count);
            break;

            case 2:
            insertBooking();
            break;

            case 3:
            printf("Enter the Booking ID to delete: ");
            scanf("%d", &bookingID);
            getchar();
            deleteBooking(bookingID);
            break;

            case 4:
            displayAllBookings();
            break;

            case 5:
            printf("Exiting...\n");
            return 0;

            default:
            printf("Invalid choice! Please try again.\n");
            break;
        }
    }

    return 0;
}

void createBookingList(int count) {

    if (count <= 0) {

        printf("Invalid number of bookings.\n");
        return;
    }


    Booking *temp, *last = NULL;
    char facilityName[50], userName[50];

    for (int i = 0; i < count; i++) {

        temp = (Booking *)malloc(sizeof(Booking));

        if (!temp) {

            printf("Memory allocation failed!\n");
            return;
        }

        totalBookings++;
        temp->bookingID = totalBookings;

        printf("Enter details for Booking ID %d:\n", totalBookings);
        printf("Facility Name: ");
        fgets(facilityName, sizeof(facilityName), stdin);
        facilityName[strcspn(facilityName, "\n")] = '\0'; 
        strcpy(temp->facilityName, facilityName);

        printf("User Name: ");
        fgets(userName, sizeof(userName), stdin);
        userName[strcspn(userName, "\n")] = '\0'; 
        strcpy(temp->userName, userName);

        temp->next = NULL;

        if (first == NULL) {

            first = temp;

        } else {

            last->next = temp;
        }
        last = temp;

        printf("Booking ID %d added successfully.\n", totalBookings);
    }
}

void insertBooking() {

    Booking *temp = (Booking *)malloc(sizeof(Booking));

    if (!temp) {

        printf("Memory allocation failed!\n");
        return;
    }

    totalBookings++;
    temp->bookingID = totalBookings;

    printf("Enter details for Booking ID %d:\n", totalBookings);
    printf("Facility Name: ");
    fgets(temp->facilityName, sizeof(temp->facilityName), stdin);
    temp->facilityName[strcspn(temp->facilityName, "\n")] = '\0'; 

    printf("User Name: ");
    fgets(temp->userName, sizeof(temp->userName), stdin);
    temp->userName[strcspn(temp->userName, "\n")] = '\0'; 

    temp->next = NULL;

    if (first == NULL) {

        first = temp;

    } else {
        Booking *ptr = first;

        while (ptr->next != NULL) {

            ptr = ptr->next;
        }
        ptr->next = temp;
    }

    printf("Booking ID %d inserted successfully.\n", totalBookings);
}

void deleteBooking(int bookingID) {

    if (first == NULL) {

        printf("No bookings available to delete.\n");
        return;
    }

    Booking *temp = first, *prev = NULL;

    while (temp != NULL) {

        if (temp->bookingID == bookingID) {

            if (prev == NULL) {

                first = temp->next;

            } else {

                prev->next = temp->next;
            }

            free(temp);
            printf("Booking ID %d deleted successfully.\n", bookingID);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Booking ID %d not found.\n", bookingID);
}

void displayAllBookings() {

    if (first == NULL) {

        printf("No bookings available.\n");
        return;
    }

    Booking *temp = first;

    printf("\nCurrent Bookings:\n");
    printf("Booking ID\tFacility Name\t\tUser Name\n");
    printf("-------------------------------------------------\n");

    while (temp != NULL) {

        printf("%d\t\t%-20s\t%s\n", temp->bookingID, temp->facilityName, temp->userName);
        temp = temp->next;
    }
}
