#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function prototypes
void showLogin();
void loginAdmin();
void showAdminMenu();
void user();
void addRoute();
void detailRoute();
void deleteRoute();
void BookRide();
void cancelRide();
void viewBooking();
void initRoute();
void generateTicket(char bookingID[]);
void addExampleRoute(char busNumber[], char start[], char destination[], char busDepartureTime[]);


// Structures
typedef struct Route {
    char busNumber[10];
    char start[30];
    char destination[30];
    char busDepartureTime[15];
    struct Route *next;
} Route;

typedef struct Bookings {
    char name[30];
    char email[100];
    char bookingID[12];
    char contact[12];
    char busNumber[10];
    char travelDate[20];
    char from[30];
    char to[30];
    char departureTime[15];
    struct Bookings *next;
} Bookings;

// Global variables
Route *route_head = NULL;
Bookings *booking_head = NULL;

int main() {
    initRoute();
    int ch;
    do {
        showLogin();
        printf("Choose: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                loginAdmin();
                break;
            case 2:
                user();
                break;
            default:
                printf("Invalid choice....try again\n");
        }
    } while (1);

    return 0;
}

void showLogin() {
    printf("\t\t\t###########################################################################\n");
    printf("\t\t\t############                                                   ############\n");
    printf("\t\t\t############                      Bus Ticket                    ############\n");
    printf("\t\t\t############                    Booking System                   ############\n");
    printf("\t\t\t############                         in C                         ############\n");
    printf("\t\t\t############                                                   ############\n");
    printf("\t\t\t###########################################################################\n");
    printf("\t\t\t---------------------------------------------------------------------------\n");
    printf("|====================================|\n");
    printf("|             Login Page             |\n");
    printf("|====================================|\n");
    printf("|  1. Admin Login                    |\n");
    printf("|  2. User                           |\n");
    printf("|====================================|\n");
}

void loginAdmin() {
    char uname[30];
    char passwd[40];
    const char USERNAME[] = "admin";
    const char PASSWORD[] = "123";
    do {
        printf("Enter Username: \t");
        scanf("%s", uname);
        printf("Enter Password: \t");
        scanf("%s", passwd);
        if (strcmp(uname, USERNAME) == 0 && strcmp(passwd, PASSWORD) == 0) {
            showAdminMenu();
            return;
        } else {
            printf("Invalid Credentials...\n");
        }
    } while (1);
}

void showAdminMenu() {
    int ch;
    while (1) {
        printf("1. Add Route\n");
        printf("2. Detail Route\n");
        printf("3. Delete Route\n");
        printf("4. Logout\n");
        printf("Choose: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                addRoute();
                break;
            case 2:
                detailRoute();
                break;
            case 3:
                deleteRoute();
                break;
            case 4:
                return;
            default:
                printf("Invalid choice\n");
        }
    }
}

void user() {
    int ch;
    while (1) {
        printf("1. Book a ticket\n");
        printf("2. Cancel Booking\n");
        printf("3. View Booking\n");
        printf("4. Go Back\n");
        printf("Choose: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                BookRide();
                break;
            case 2:
                cancelRide();
                break;
            case 3:
                viewBooking();
                break;
            case 4:
                return;
            default:
                printf("Invalid Choice.....\n");
        }
    }
}

void BookRide() {
    char name[30];
    char email[100];
    char bookingID[12];
    char contact[12];
    char busNo[10];
    char from[30];
    char to[30];
    char departureTime[15];
    char travelDate[20];

    printf("Enter Passenger Name: ");
    scanf(" %[^\n]s", name);

    printf("Enter Email: ");
    scanf(" %[^\n]s", email);

    printf("Enter Contact: ");
    scanf(" %[^\n]s", contact);

    printf("Enter Travel Date (dd/mm/yyyy): ");
    scanf(" %[^\n]s", travelDate);

    detailRoute();
    Route *route_data;
    do {
        printf("Choose Bus Number: ");
        scanf(" %[^\n]s", busNo);
        route_data = searchRoute(busNo);
        if (route_data == NULL) {
            printf("Invalid Bus Number. Please choose again.\n");
        } else {
            break;
        }
    } while (1);

    strcpy(from, route_data->start);
    strcpy(to, route_data->destination);
    strcpy(departureTime, route_data->busDepartureTime);

    srand(time(NULL));
    int randNo = rand() % 10000;
    sprintf(bookingID, "BK%04d", randNo);

    Bookings *ptr = (Bookings *)malloc(sizeof(Bookings));
    strcpy(ptr->name, name);
    strcpy(ptr->email, email);
    strcpy(ptr->contact, contact);
    strcpy(ptr->travelDate, travelDate);
    strcpy(ptr->busNumber, busNo);
    strcpy(ptr->from, from);
    strcpy(ptr->to, to);
    strcpy(ptr->departureTime, departureTime);
    strcpy(ptr->bookingID, bookingID);
    ptr->next = NULL;

    if (booking_head == NULL) {
        booking_head = ptr;
    } else {
        Bookings *temp = booking_head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
    }

    printf("Booking Successful! Your Booking ID is: %s\n", bookingID);
    generateTicket(bookingID);
}

void cancelRide() {
    char bookingID[12];
    printf("Enter Booking ID to cancel: ");
    scanf(" %[^\n]s", bookingID);

    Bookings *prev = NULL;
    Bookings *temp = booking_head;

    while (temp != NULL) {
        if (strcmp(temp->bookingID, bookingID) == 0) {
            if (prev == NULL) {
                booking_head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("Booking with ID '%s' cancelled successfully.\n", bookingID);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Booking ID '%s' not found.\n", bookingID);
}

void viewBooking() {
    char bookingID[12];
    printf("Enter Booking ID to view details: ");
    scanf(" %[^\n]s", bookingID);

    Bookings *temp = booking_head;

    while (temp != NULL) {
        if (strcmp(temp->bookingID, bookingID) == 0) {
            printf("\nBooking ID: %s\n", temp->bookingID);
            printf("Name: %s\n", temp->name);
            printf("Email: %s\n", temp->email);
            printf("Contact: %s\n", temp->contact);
            printf("Travel Date: %s\n", temp->travelDate);
            printf("Bus Number: %s\n", temp->busNumber);
            printf("From: %s\n", temp->from);
            printf("To: %s\n", temp->to);
            printf("Departure Time: %s\n", temp->departureTime);
            return;
        }
        temp = temp->next;
    }
    printf("Booking ID '%s' not found.\n", bookingID);
}

void addRoute() {
    Route *newRoute = (Route *)malloc(sizeof(Route));
    printf("Enter Bus Number: ");
    scanf(" %[^\n]s", newRoute->busNumber);

    printf("Enter Start Location: ");
    scanf(" %[^\n]s", newRoute->start);

    printf("Enter Destination: ");
    scanf(" %[^\n]s", newRoute->destination);

    printf("Enter Departure Time: ");
    scanf(" %[^\n]s", newRoute->busDepartureTime);

    newRoute->next = NULL;

    if (route_head == NULL) {
        route_head = newRoute;
    } else {
        Route *temp = route_head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newRoute;
    }

    printf("Route added successfully!\n");
}

void detailRoute() {
    Route *curr = route_head;
    if (curr == NULL) {
        printf("No routes available.\n");
        return;
    }
    printf("\n");
    while (curr != NULL) {
        printf("Bus Number: %s\n", curr->busNumber);
        printf("From: %s\n", curr->start);
        printf("To: %s\n", curr->destination);
        printf("Departure Time: %s\n\n", curr->busDepartureTime);
        curr = curr->next;
    }
}

void deleteRoute() {
    char busNo[10];
    printf("Enter Bus Number to delete: ");
    scanf(" %[^\n]s", busNo);

    Route *prev = NULL;
    Route *temp = route_head;

    while (temp != NULL) {
        if (strcmp(temp->busNumber, busNo) == 0) {
            if (prev == NULL) {
                route_head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("Route with Bus Number '%s' deleted successfully.\n", busNo);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Bus Number '%s' not found.\n", busNo);
}

void generateTicket(char bookingID[]) {
    printf("\n\n");
    printf("\t\t\t\t*****************************************************\n");
    printf("\t\t\t\t***********                              ************\n");
    printf("\t\t\t\t***********    Bus Ticket Booking System  ************\n");
    printf("\t\t\t\t***********                              ************\n");
    printf("\t\t\t\t*****************************************************\n");
    printf("\n\n");

    Bookings *temp = booking_head;

    while (temp != NULL) {
        if (strcmp(temp->bookingID, bookingID) == 0) {
            printf("Booking ID: %s\n", temp->bookingID);
            printf("Name: %s\n", temp->name);
            printf("Email: %s\n", temp->email);
            printf("Contact: %s\n", temp->contact);
            printf("Travel Date: %s\n", temp->travelDate);
            printf("Bus Number: %s\n", temp->busNumber);
            printf("From: %s\n", temp->from);
            printf("To: %s\n", temp->to);
            printf("Departure Time: %s\n", temp->departureTime);
            printf("\n\n");
            printf("\t\t\t\t\t\t  ****  Have a safe journey  ****");
            return;
        }
        temp = temp->next;
    }
}

void initRoute() {
    // Example routes initialization
    addExampleRoute("R101", "New York", "Boston", "09:00");
    addExampleRoute("R102", "Chicago", "Los Angeles", "10:30");
    addExampleRoute("R103", "San Francisco", "Seattle", "12:00");
}

void addExampleRoute(char busNumber[], char start[], char destination[], char busDepartureTime[]) {
    Route *newRoute = (Route *)malloc(sizeof(Route));
    strcpy(newRoute->busNumber, busNumber);
    strcpy(newRoute->start, start);
    strcpy(newRoute->destination, destination);
    strcpy(newRoute->busDepartureTime, busDepartureTime);
    newRoute->next = NULL;

    if (route_head == NULL) {
        route_head = newRoute;
    } else {
        Route *temp = route_head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newRoute;
    }
}

Route* searchRoute(char busNo[]) {
    Route *temp = route_head;
    while (temp != NULL) {
        if (strcmp(temp->busNumber, busNo) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
