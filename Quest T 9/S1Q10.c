// 10. Drone Path Optimization
// Pointers: Traverse waypoint arrays.
// Arrays: Store coordinates of waypoints.
// Functions:
// double optimize_path(double const *waypoints, int size): Reduces the total path length.
// void add_waypoint(double *waypoints, int *size, double x, double y): Adds a new waypoint.
// Pass Arrays as Pointers: Use pointers to access and modify waypoints.

#include <stdio.h>
#include <math.h>


double optimize_path(double const *waypoints, int size);
void add_waypoint(double *waypoints, int *size, double x, double y);
double calculate_distance(double x1, double y1, double x2, double y2);

int main() {
    
    double waypoints[10] = {0.0, 0.0, 3.0, 4.0, 6.0, 8.0};  
    int size = 3;  
    
    add_waypoint(waypoints, &size, 10.0, 10.0);

    
    double total_distance = optimize_path(waypoints, size);

    
    printf("Optimized total path length: %.2f units\n", total_distance);

    return 0;
}


double calculate_distance(double x1, double y1, double x2, double y2) {

    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

}


double optimize_path(double const *waypoints, int size) {

    double total_distance = 0.0;

    
    for (int i = 0; i < size - 1; i++) {

        total_distance += calculate_distance(waypoints[i * 2], waypoints[i * 2 + 1], waypoints[(i + 1) * 2], waypoints[(i + 1) * 2 + 1]);

    }

    return total_distance;
}


void add_waypoint(double *waypoints, int *size, double x, double y) {

    waypoints[*size * 2] = x;
    waypoints[*size * 2 + 1] = y;
    (*size)++;
    
}
