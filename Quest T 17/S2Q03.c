// Problem 3: Athlete Training Log
// Description: Develop a linked list to log training sessions for athletes.Operations:
// Create a training log.
// Insert a new training session.
// Delete a completed or canceled session.
// Display the training log


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TrainingSession {

    int sessionID;
    char athleteName[50];
    char trainingType[50];
    char sessionDate[20];
    char sessionTime[10];
    struct TrainingSession *next;

} TrainingSession;

TrainingSession *trainingLog = NULL;  
static int totalSessions = 0;

void createTrainingLog(int count);
void insertNewTrainingSession();
void deleteTrainingSession(int sessionID);
void displayTrainingLog();

int main() {

    int choice, count, sessionID;

    while (1) {

        printf("\n\t\tWelcome\t\t\n");
        printf("1. Create a training log.\n");
        printf("2. Insert a new training session.\n");
        printf("3. Delete a completed or canceled session.\n");
        printf("4. Display the current training log.\n");
        printf("5. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {

            case 1:
            printf("Enter the number of training sessions to add: ");
            scanf("%d", &count);
            getchar();
            createTrainingLog(count);
            printf("\nTotal training sessions: %d\n", totalSessions);
            break;

            case 2:
            insertNewTrainingSession();
            printf("\nTotal training sessions: %d\n", totalSessions);
            break;

            case 3:
            displayTrainingLog();
            printf("Enter the session ID to delete: ");
            scanf("%d", &sessionID);
            deleteTrainingSession(sessionID);
            printf("\nTotal training sessions: %d\n", totalSessions);
            break;

            case 4:
            displayTrainingLog();
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

void createTrainingLog(int count) {

    if (count <= 0) {

        printf("Invalid number of sessions.\n");
        return;
    }

    TrainingSession *temp, *last = trainingLog;

    while (last != NULL && last->next != NULL) {

        last = last->next;
    }

    for (int i = 0; i < count; i++) {
        
        temp = (TrainingSession *)malloc(sizeof(TrainingSession));
        if (temp == NULL) {

            printf("Memory allocation failed for session entry %d.\n", i + 1);
            return;
        }

        printf("\nEnter details for Training Session %d:\n", i + 1);
        printf("Enter the Session ID: ");
        scanf("%d", &temp->sessionID);
        getchar();

        printf("Enter Athlete Name: ");
        fgets(temp->athleteName, sizeof(temp->athleteName), stdin);
        temp->athleteName[strcspn(temp->athleteName, "\n")] = '\0';

        printf("Enter Training Type: ");
        fgets(temp->trainingType, sizeof(temp->trainingType), stdin);
        temp->trainingType[strcspn(temp->trainingType, "\n")] = '\0';

        printf("Enter the Training Date (DD/MM/YYYY): ");
        fgets(temp->sessionDate, sizeof(temp->sessionDate), stdin);
        temp->sessionDate[strcspn(temp->sessionDate, "\n")] = '\0';

        printf("Enter the Training Time (HH:MM): ");
        fgets(temp->sessionTime, sizeof(temp->sessionTime), stdin);
        temp->sessionTime[strcspn(temp->sessionTime, "\n")] = '\0';

        temp->next = NULL;

        if (trainingLog == NULL) {

            trainingLog = temp;

        } else {

            last->next = temp;
        }

        last = temp;
        totalSessions++;
    }

    printf("%d training sessions added to the log successfully.\n", count);
}

void insertNewTrainingSession() {

    TrainingSession *temp, *last = trainingLog;

    temp = (TrainingSession *)malloc(sizeof(TrainingSession));

    if (temp == NULL) {

        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter the Session ID: ");
    scanf("%d", &temp->sessionID);
    getchar();

    TrainingSession *check = trainingLog;

    while (check != NULL) {

        if (check->sessionID == temp->sessionID) {

            printf("Error: Session ID %d already exists.\n", temp->sessionID);
            free(temp);
            return;
        }
        check = check->next;
    }

    printf("Enter Athlete Name: ");
    fgets(temp->athleteName, sizeof(temp->athleteName), stdin);
    temp->athleteName[strcspn(temp->athleteName, "\n")] = '\0';

    printf("Enter Training Type: ");
    fgets(temp->trainingType, sizeof(temp->trainingType), stdin);
    temp->trainingType[strcspn(temp->trainingType, "\n")] = '\0';

    printf("Enter the Training Date (DD/MM/YYYY): ");
    fgets(temp->sessionDate, sizeof(temp->sessionDate), stdin);
    temp->sessionDate[strcspn(temp->sessionDate, "\n")] = '\0';

    printf("Enter the Training Time (HH:MM): ");
    fgets(temp->sessionTime, sizeof(temp->sessionTime), stdin);
    temp->sessionTime[strcspn(temp->sessionTime, "\n")] = '\0';

    temp->next = NULL;

    if (trainingLog == NULL) {
        trainingLog = temp;
    } else {

        while (last->next != NULL) {

            last = last->next;
        }
        last->next = temp;
    }

    totalSessions++;
    printf("Session ID %d added to the training log successfully.\n", temp->sessionID);
}

void deleteTrainingSession(int sessionID) {

    if (trainingLog == NULL) {

        printf("No sessions in the log.\n");
        return;
    }

    TrainingSession *temp = trainingLog, *prev = NULL;

    if (temp != NULL && temp->sessionID == sessionID) {

        trainingLog = temp->next;
        free(temp);
        printf("Session ID %d deleted successfully.\n", sessionID);
        totalSessions--;
        return;
    }

    while (temp != NULL && temp->sessionID != sessionID) {

        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {

        printf("Session ID %d not found.\n", sessionID);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Session ID %d deleted successfully.\n", sessionID);
    totalSessions--;
}

void displayTrainingLog() {

    if (trainingLog == NULL) {

        printf("No training sessions in the log.\n");
        return;
    }

    TrainingSession *temp = trainingLog;
    int i = 1;
    printf("\n\t\tAthlete Training Log\t\t\n");
    printf("SLNO.\tSession ID\tAthlete Name\tTraining Type\tTraining Date\tTraining Time\n");
    printf("--------------------------------------------------------------------------\n");

    while (temp != NULL) {
        printf("%d\t%d\t\t%-20s\t%-20s\t%-15s\t%s\n", i++, temp->sessionID, temp->athleteName, temp->trainingType, temp->sessionDate, temp->sessionTime);
        temp = temp->next;
    }

    printf("--------------------------------------------------------------------------\n");
}
