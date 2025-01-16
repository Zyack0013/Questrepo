// Problem 13: Sports Event Scheduling
// Description: Use a linked list to manage the schedule of sports events.Operations:
// Create an event schedule.
// Insert a new event.
// Delete a completed or canceled event.
// Display the current event schedule.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Event {

    char name[50];
    char date[20];
    char time[10];
    struct Event *next;

} Event;

void createSchedule(Event **first, const char *name, const char *date, const char *time);
void insertEvent(Event **first, const char *name, const char *date, const char *time);
void deleteEvent(Event **first, const char *name);
void displaySchedule(Event *first);

int main() {

    Event *schedule = NULL;
    int choice;
    char name[50], date[20], time[10];

    while (1) {

        printf("\n\t\tWelcome\t\t\n");
        printf("1. Create Event Schedule\n");
        printf("2. Insert New Event\n");
        printf("3. Delete Event\n");
        printf("4. Display Event Schedule\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {

            case 1:
            printf("Enter event name: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';
            printf("Enter event date (YYYY-MM-DD): ");
            scanf("%s", date);
            printf("Enter event time (HH:MM): ");
            scanf("%s", time);
            createSchedule(&schedule, name, date, time);
            break;

            case 2:
            printf("Enter event name: ");
            getchar(); 
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';
            printf("Enter event date (YYYY-MM-DD): ");
            scanf("%s", date);
            printf("Enter event time (HH:MM): ");
            scanf("%s", time);
            insertEvent(&schedule, name, date, time);
            break;

            case 3:
            printf("Enter the name of the event to delete: ");
            getchar(); 
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';
            deleteEvent(&schedule, name);
            break;

            case 4:
            displaySchedule(schedule);
            break;

            case 5:
            printf("Exiting...\n");
            return 0;

            default:
            printf("Invalid choice!.\n");
            break;
        }
    }
    return 0;
}

void createSchedule(Event **first, const char *name, const char *date, const char *time) {

    if (*first != NULL) {

        printf("Schedule already exists! Use Insert to add new events.\n");
        return;
    }

    Event *newEvent = (Event *)malloc(sizeof(Event));

    if (newEvent == NULL) {

        printf("Memory allocation failed!\n");
        return;
    }

    strcpy(newEvent->name, name);
    strcpy(newEvent->date, date);
    strcpy(newEvent->time, time);
    newEvent->next = NULL;

    *first = newEvent;
    printf("Event schedule created with the first event.\n");
}

void insertEvent(Event **first, const char *name, const char *date, const char *time) {

    Event *newEvent = (Event *)malloc(sizeof(Event));

    if (newEvent == NULL) {

        printf("Memory allocation failed!\n");
        return;
    }

    strcpy(newEvent->name, name);
    strcpy(newEvent->date, date);
    strcpy(newEvent->time, time);
    newEvent->next = NULL;

    if (*first == NULL) {

        *first = newEvent;

    } else {

        Event *temp = *first;

        while (temp->next != NULL) {

            temp = temp->next;
        }
        temp->next = newEvent;
    }
    printf("New event inserted successfully.\n");
}

void deleteEvent(Event **first, const char *name) {

    if (*first == NULL) {

        printf("Event schedule is empty!\n");
        return;
    }

    Event *temp = *first;
    Event *prev = NULL;

    while (temp != NULL && strcmp(temp->name, name) != 0) {

        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {

        printf("Event not found!\n");
        return;
    }

    if (prev == NULL) {

        *first = temp->next;

    } else {

        prev->next = temp->next;
    }

    free(temp);
    printf("Event deleted successfully.\n");
}

void displaySchedule(Event *first) {

    if (first == NULL) {

        printf("No events scheduled.\n");
        return;
    }

    Event *temp = first;
    printf("\nCurrent Event Schedule:\n");
    printf("Name\t\tDate\t\tTime\n");

    while (temp != NULL) {

        printf("%s\t\t%s\t\t%s\n", temp->name, temp->date, temp->time);
        temp = temp->next;

    }
}
