#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function prototypes
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double power(double base, double exponent);
double square_root(double num);
double factorial(int num);

int main() {
    char operation;
    double num1, num2;
    int num;
    char input[256];

    printf("Complex Console Calculator\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Power\n");
        printf("6. Square Root\n");
        printf("7. Factorial\n");
        printf("8. Exit\n");
        printf("Enter your choice (1-8): ");

        fgets(input, sizeof(input), stdin);
        sscanf(input, "%c", &operation);

        switch (operation) {
            case '1':
                printf("Enter two numbers separated by space: ");
                fgets(input, sizeof(input), stdin);
                sscanf(input, "%lf %lf", &num1, &num2);
                printf("Result: %g\n", add(num1, num2));
                break;
            case '2':
                printf("Enter two numbers separated by space: ");
                fgets(input, sizeof(input), stdin);
                sscanf(input, "%lf %lf", &num1, &num2);
                printf("Result: %g\n", subtract(num1, num2));
                break;
            case '3':
                printf("Enter two numbers separated by space: ");
                fgets(input, sizeof(input), stdin);
                sscanf(input, "%lf %lf", &num1, &num2);
                printf("Result: %g\n", multiply(num1, num2));
                break;
            case '4':
                printf("Enter two numbers separated by space: ");
                fgets(input, sizeof(input), stdin);
                sscanf(input, "%lf %lf", &num1, &num2);
                if (num2 != 0)
                    printf("Result: %g\n", divide(num1, num2));
                else
                    printf("Error: Division by zero\n");
                break;
            case '5':
                printf("Enter base and exponent separated by space: ");
                fgets(input, sizeof(input), stdin);
                sscanf(input, "%lf %lf", &num1, &num2);
                printf("Result: %g\n", power(num1, num2));
                break;
            case '6':
                printf("Enter a number: ");
                fgets(input, sizeof(input), stdin);
                sscanf(input, "%lf", &num1);
                if (num1 >= 0)
                    printf("Result: %g\n", square_root(num1));
                else
                    printf("Error: Cannot compute square root of a negative number\n");
                break;
            case '7':
                printf("Enter a non-negative integer: ");
                fgets(input, sizeof(input), stdin);
                sscanf(input, "%d", &num);
                if (num >= 0)
                    printf("Result: %g\n", factorial(num));
                else
                    printf("Error: Factorial is not defined for negative numbers\n");
                break;
            case '8':
                printf("Exiting calculator...\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a number from 1 to 8.\n");
                break;
        }
    }

    return 0;
}

// Function definitions
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b != 0)
        return a / b;
    else
        return NAN; // Handle division by zero
}

double power(double base, double exponent) {
    return pow(base, exponent);
}

double square_root(double num) {
    return sqrt(num);
}

double factorial(int num) {
    if (num == 0)
        return 1;
    else
        return num * factorial(num - 1);
}
