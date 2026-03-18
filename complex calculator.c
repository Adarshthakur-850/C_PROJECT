#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

int main() {
    char operation;
    double num1, num2;
    char input[256];

    printf("Simple Console Calculator\n");

    while (1) {
        printf("Menu:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");

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
                printf("Exiting calculator...\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a number from 1 to 5.\n");
                break;
        }
    }

    return 0;
}
