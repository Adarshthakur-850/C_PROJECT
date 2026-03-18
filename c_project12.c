#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
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

typedef struct Route{
    char busNumber[10];
    char start[30];
    char destination[30];
    char busDepartureTime[15];
    struct Route *next;
}Route;

Route* route_head = NULL;
Route* route_tail = NULL;

Route* searchRoute(char val[]);
typedef struct Bookings{
    char name[30];
    char email[100];
    char bookingID[11];
    char contact[11];
    char busNumber[10];
    char travelDate[20];
    char from[20];
    char to[20];
    char departureTime[10];
    struct Bookings* next;
}Bookings;

Bookings* booking_head = NULL;
Bookings* searchBooking(char val[]);
void main(){
    initRoute();
    int ch;
    do{
        showLogin();
        printf("Choose:\t");
        scanf("%d",&ch);
        switch(ch){
        case 1: loginAdmin();break;
        case 2: user();break;
        default:printf("Invalid choice....try again");
        }
    }while(1);
}




void showLogin(){
     printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                      Bus Ticket                    ############");
    printf("\n\t\t\t############                    Booking System                   ############");
    printf("\n\t\t\t############                         in C                         ############");
     printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("|====================================|\n");
    printf("|             Login Page             |\n");
    printf("|====================================|\n");
    printf("|  1. Admin Login                    |\n");
    printf("|  2. User                           |\n");
    printf("|====================================|\n");

}

void loginAdmin(){
    int ch;
    char uname[30];
    char passwd[40];
    char USERNAME[] = {'a','d','m','i','n'};
    char PASSWORD[] = {'1','2','3'};
    do{
        printf("Enter Username: \t");
        scanf("%s",uname);
        printf("Enter Password: \t");
        scanf("%s",passwd);
        printf("\n\t\t\t---------------------------------------------------------------------------\n");
        printf("\n\t\t\t---------------------------------------------------------------------------\n");
        if(strcmp(uname,USERNAME)){
            if(strcmp(passwd ,PASSWORD)){
                showAdminMenu();
                return;
            }
        }
        printf("Invalid Credentials...");
    }while(1);
}


void showAdminMenu(){
    while(1){
        printf("1. Add Route\n");
        printf("2. Detail Route\n");
        printf("3. Delete Route\n");
        int ch ;
        printf("Choose: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: addRoute();break;
            case 2: detailRoute();break;
            case 3: deleteRoute();break;
            default: printf("Invalid choice");
        }
    }
    printf("\n\t\t\t---------------------------------------------------------------------------\n");

}
void user(){
    char bookingId[20];
    while(1){
        printf("1. Book a ticket\n");
        printf("2. Cancel Booking\n");
        printf("3. View Booking\n");
        printf("4. Go Back\n");
        int ch;
        printf("Choose: ");
        scanf("%d",&ch);
         printf("\n\t\t\t---------------------------------------------------------------------------\n");
        switch(ch){
            case 1: BookRide();break;
            case 2: printf("Enter Booking Id: ");scanf("%s",bookingId);cancelRide(bookingId);break;
            case 3: viewBooking();break;
            case 4: return ;
            default: printf("Invalid Choice.....");
        }
    }
}

void BookRide(){
    char BookingID[20];
    char departureTime[10];
    char temp;
    char name[30];
    char busNo[20];
    char email[100];
    char contact[11];
    char travelDate[20];
    char from[20];
    char to[20];
    printf("Passenger Name: ");
    scanf("%c",&temp); // to clear buffer else fgets doesn't work.....don' know why...
    fgets(name,20,stdin);
    printf("Email : ");
    scanf("%s",email);
    printf("Contact : ");
    scanf("%s",contact);
    printf("Travel date (dd/mm/yyyy): ");
    scanf("%s",travelDate);
    detailRoute();
    Route* route_data;
    while(1){
        printf("Choose Bus Number: ");
        scanf("%s",busNo);
        route_data = searchRoute(busNo);
        if(route_data == NULL){
            continue;
        }else{
            break;
        }
    }
    strcpy(from,route_data->start);
    strcpy(to,route_data->destination);
    strcpy(departureTime,route_data->busDepartureTime);

    srand(time(0));
    int randNo = (rand()*rand()+rand());
    char randNo_arr[20];
    itoa(randNo,randNo_arr,10);
    BookingID[0] = 'B';
    BookingID[1] = 'K';
    for(int i = 0 ;  i<10;i++){
        BookingID[i+2] = randNo_arr[i];
    }
    Bookings* ptr = (Bookings* )malloc(sizeof(Bookings));
    strcpy(ptr->name,name);
    strcpy(ptr->email,email);
    strcpy(ptr->contact,contact);
    strcpy(ptr->travelDate,travelDate);
    strcpy(ptr->busNumber,busNo);
    strcpy(ptr->from,from);
    printf("%s\n",ptr->from);
    strcpy(ptr->to,to);
    printf("%s\n",ptr->to);
    strcpy(ptr->bookingID,BookingID);
    strcpy(ptr->departureTime,departureTime);
    ptr->next=NULL;
    if(booking_head == NULL){
        booking_head = ptr;
    }else{
        ptr->next = booking_head;
        booking_head=ptr;
    }
    printf("Your Booking ID is: \'%s\'\n",BookingID);
    generateTicket(BookingID);

     printf("\n\t\t\t---------------------------------------------------------------------------\n");
}
void cancelRide(char bookingId[]){
    Bookings* curr = booking_head;
    Bookings* prev = booking_head;
    while(curr != NULL){
        if(strcmp(curr->bookingID,bookingId)==0){
            if(curr == booking_head){
                booking_head =curr->next;
                free(curr);
            }else{
                prev->next = curr->next;
                free(curr);
            }
            return;
        }else{
            prev = curr;
        }
        curr= curr->next;
    }
    printf("Invalid Booking ID");

     printf("\n\t\t\t---------------------------------------------------------------------------\n");
}
void viewBooking(){
    while(1){
        char bookingID[20];
        printf("Enter BookingID: ");
        scanf("%s",bookingID);
        Bookings * curr = booking_head;
        while(curr != NULL){
            if(strcmp(curr->bookingID,bookingID) == 0){
                printf("BookingID: %s\n",curr->bookingID);
                printf("Name: %s\n",curr->name);
                printf("Email: %s\n",curr->email);
                printf("Contact: %s\n",curr->contact);
                printf("Travel Date: %s\n",curr->travelDate);
                printf("Bus Number: %s\n",curr->busNumber);
                printf("From: %s\n",curr->from);
                printf("Destination: %s\n",curr->to);
                printf("Departure timing: %s\n",curr->departureTime);
                return;
            }
            curr= curr->next;
        }
        printf("BookingID Invalid......\nRe-");
    }
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
}
Route* searchRoute(char val[]){
    printf("%s",val);
    Route* curr = route_head;
    while(curr !=NULL){
        if(strcmp(curr->busNumber,val)==0){
            return curr;
        }
        curr= curr->next;
    }
    return NULL;
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
}

void generateTicket(char bookingID[]){
    Bookings* booking = searchBooking(bookingID);
    if(booking !=NULL){
        FILE *ptr ;
        ptr = fopen(strcat(bookingID,".txt"),"w");
        if(ptr == NULL){
            printf("booking failure");
            cancelRide(bookingID);
        }else{
            fprintf(ptr,"BookingID:\t%s\n",booking->bookingID);
            fprintf(ptr,"Name: \t%s\n",booking->name);
            fprintf(ptr,"Email Id: \t%s\n",booking->email);
            fprintf(ptr,"Contact: \t %s\n",booking->contact);
            fprintf(ptr,"Travel Date: %s\n",booking->travelDate);
            fprintf(ptr,"From: %s\n",booking->from);
            fprintf(ptr,"To: %s\n",booking->to);
            fprintf(ptr,"Bus Number: %s\n",booking->busNumber);
            fprintf(ptr,"Departure Time: %s\n",booking->departureTime);
            fclose(ptr);
        }
    }
    printf("\n\t\t\t---------------------------------------------------------------------------\n");

}
Bookings* searchBooking(char val[]){
    Bookings* curr = booking_head;
    while(curr != NULL){
        if(strcmp(curr->bookingID,val)==0){
            return curr;
        }
        curr=curr->next;
    }
    return NULL;
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
}

void addRoute(){
    char temp;
    char busNumber[20];
    char from[20];
    char to[20];
    char busDepartureTime[20];
    printf("Enter Bus no: ");
    scanf("%s",busNumber);
    printf("From: ");
    scanf("%s",from);
    printf("To: ");
    scanf("%s",to);
    printf("Departure time: ");
    scanf("%c",&temp); // to clear buffer else fgets doesn't work.....don' know why...
    fgets(busDepartureTime,20,stdin); // to include white spaces during input
    Route *ptr = (Route* )malloc(sizeof(Route));
    strcpy(ptr->busNumber , busNumber);
    strcpy(ptr->start , from);
    strcpy(ptr->destination , to);
    strcpy(ptr->busDepartureTime , busDepartureTime);
    ptr->next = NULL;
    if(route_head == NULL){
        route_head = ptr;
        route_tail = ptr;
    }else{
        route_tail->next = ptr;
        route_tail = ptr;
    }
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
}
void detailRoute(){
    Route* curr = route_head;
    while(curr != NULL){
        printf("Bus_no: %s \n",curr->busNumber);
        printf("From: %s \n",curr->start);
        printf("To: %s \n",curr->destination);
        printf("Departure Time: %s \n",curr->busDepartureTime);
        printf("\n------------------------------------------------------\n");
        curr = curr->next;
    }
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
}
void deleteRoute(){
    char temp[20];
    char val[20];
    printf("Enter bus number: ");
    scanf("%s",temp);
    Route* prev = route_head;
    Route* curr = route_head;
    while(curr != NULL){
        if(strcmp(curr->busNumber,temp)==0){
            if(curr == route_head){
                route_head = curr->next;
                free(curr);
            }else if(curr == route_tail){
                route_tail= prev;
                prev->next = NULL;
                free(curr);
            }else{
                prev->next = curr->next;
                free(curr);
            }
            return;
        }else{
            prev = curr;
        }
        curr=curr->next;
    }
    printf("No such route exists.....\n");
    return;

}
void initRoute(){
    char from[20][20] = {
        "DELHI","DELHI","DELHI","DELHI","DELHI",
        "JALANDHAR","JALANDHAR","JALANDHAR","JALANDHAR","JALANDHAR",
        "MEERUT","MEERUT","MEERUT","MEERUT","MEERUT",
        "PHAGWARA","PHAGWARA","PHAGWARA","PHAGWARA","PHAGWARA"
    };
    char to[20][20] = {
        "JALANDHAR","MEERUT","PHAGWARA","DELHI","SURAT",
        "DELHI","MEERUT","PHAGWARA","LUCKNOW","SURAT",
        "JALANDHAR","LUCKNOW","PHAGWARA","DELHI","SURAT",
        "JALANDHAR","MEERUT","LUCKNOW","DELHI","SURAT"
    };
    char BUS_NO[20][20] = {
        "BS01","BS02","BS03","BS04","BS05",
        "BS06","BS07","BS08","BS09","BS10",
        "BS11","BS12","BS13","BS14","BS15",
        "BS16","BS17","BS18","BS19","BS20",
    };
    char departureTime[20][20] = {
        "09:00 AM","09:15 AM","09:30 AM","09:45 AM","10:00 AM",
        "10:05 AM","10:15 AM","10:30 AM","10:45 AM","11:00 AM",
        "01:00 PM","01:15 PM","01:30 PM","01:45 PM","02:00 PM",
        "03:00 PM","03:15 PM","03:30 PM","03:45 PM","04:00 PM",
    };
    for(int i = 0;i<20;i++){
        Route *ptr = (Route* )malloc(sizeof(Route));
        strcpy(ptr->busNumber , BUS_NO[i]);
        strcpy(ptr->start , from[i]);
        strcpy(ptr->destination , to[i]);
        strcpy(ptr->busDepartureTime , departureTime[i]);
        if(route_head == NULL){
            route_head = ptr;
            route_tail = ptr;
            ptr->next = NULL;
        }else{
            route_tail->next = ptr;
            route_tail = ptr;
            ptr->next = NULL;
        }
    }
}
