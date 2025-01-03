// 3. Weather Data Processing for Aviation
// Pointers: Traverse weather data arrays efficiently.
// Arrays: Store hourly temperature, wind speed, and pressure.
// Functions:
// void calculate_daily_averages(const double *data, int size, double *averages): Computes daily averages for each parameter.
// void display_weather_data(const double *data, int size): Displays data for monitoring purposes.
// Pass Arrays as Pointers: Pass weather data as pointers to processing functions.


#include <stdio.h>


void getData(double data[],int size);
void calculate_daily_averages(double const *data, int size, double *averages);
void display_weather_data(double const *data, int size);

int main() {

    int size;
    printf("Enter(12->12 hrs or 24->24 hrs): ");
    scanf("%d",&size);

    double temperature[size],wind_speed[size],pressure[size],average[3]={0.0};

    printf("Enter the %dhrs reading of Temperature\n",size);
    getData(temperature,size);
    printf("Enter the %dhrs reading of wind speed\n",size);
    getData(wind_speed,size);
    printf("Enter the %dhrs reading of pressure\n",size);
    getData(pressure,size);

    printf("Hourly temperature data\n");
    display_weather_data(temperature,size);
    printf("Hourly wind speed data\n");
    display_weather_data(wind_speed,size);
    printf("Hourly pressure data\n");
    display_weather_data(pressure,size);

    calculate_daily_averages(temperature,size,&average[0]);
    calculate_daily_averages(wind_speed,size,&average[1]);
    calculate_daily_averages(pressure,size,&average[2]);



    printf("\nDaily Averages:\n");
    printf("Temperature: %.2f\n",average[0]);
    printf("Wind Speed: %.2f\n",average[1]);
    printf("Pressure: %.2f\n",average[2]);
    

    return 0;
}


void getData(double data[],int size){

    for(int i = 0;i < size;i++) {

        printf("Enter the reading at %d hrs : ",i+1);
        scanf("%lf",&data[i]);
    }

}

void calculate_daily_averages(double const *data, int size, double *averages){

   double sum = 0.0;
    for (int i = 0; i < size; i++) {

        sum += data[i];

    }
    *averages = sum / size;

}


void display_weather_data(double const *data, int size){

    for (int i = 0; i < size; i++) {

        printf("At hour %d: %.2f\n", i + 1, data[i]);

    }


}