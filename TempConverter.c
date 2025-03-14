#include <stdio.h>

// Function prototypes
double celsius_to_fahrenheit(double celsius);
double fahrenheit_to_celsius(double fahrenheit);

int main()
{
    int choice;
    double temperature, converted;

    do
    {
        printf("\nTemperature Conversion Menu:\n");
        printf("1. Convert Celsius to Fahrenheit\n");
        printf("2. Convert Fahrenheit to Celsius\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &temperature);
                converted = celsius_to_fahrenheit(temperature);
                printf("%.2f°C is equal to %.2f°F\n", temperature, converted);
                break;

            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%lf", &temperature);
                converted = fahrenheit_to_celsius(temperature);
                printf("%.2f°F is equal to %.2f°C\n", temperature, converted);
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please enter 1, 2, or 3.\n");
        }

    } while (choice != 3);

    return 0;
}

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius)
{
    return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit)
{
    return (fahrenheit - 32) * 5 / 9;
}
