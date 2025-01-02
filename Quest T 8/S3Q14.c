// 14. Maintenance Schedule Update
// Requirements:
// Input: Current and next maintenance dates (string).
// Output: Updated maintenance schedule.
// Function: Accepts pointers to the dates and modifies them.
// Constraints: Ensure next maintenance date is always later than the current date.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void updateMaintenanceSchedule(char *currentDate, char *nextMaintenanceDate);

int main() {
    
    char currentDate[11] = "2025-01-01"; 
    char nextMaintenanceDate[11] = "2025-01-10"; 

    
    printf("Current Maintenance Date: %s\n", currentDate);
    printf("Next Maintenance Date: %s\n", nextMaintenanceDate);

   
    updateMaintenanceSchedule(currentDate, nextMaintenanceDate);

    
    printf("\nUpdated Maintenance Schedule:\n");
    printf("Current Maintenance Date: %s\n", currentDate);
    printf("Next Maintenance Date: %s\n", nextMaintenanceDate);

    return 0;
}

/*

Name : updateMaintenanceSchedule
Return Datatype : void
parameters : char *currentDate, *nextMaintenanceDate
Short discription: Fn that accepts pointers to the dates and modifies them.

*/

void updateMaintenanceSchedule(char *currentDate, char *nextMaintenanceDate) {
    
    int current = atoi(currentDate);
    int next = atoi(nextMaintenanceDate);

    
    if (next <= current) {
        
        next = current + 1;  
        sprintf(nextMaintenanceDate, "%d", next); 
    }

    
}
