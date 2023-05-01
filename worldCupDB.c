//Written by Otis Ding
//Student ID: 251220811
//This Program is a database-like program that will allow users to modify and view the database


//Importing the libraries we'll be using
#include<stdio.h>
#include<string.h>

//Defining some  variables that will represent the length of our various arrays
#define NAME_LEN 24
#define SEEDING_LEN 2
#define MAX_PARTS 32

//Prototyping all our functions
void insert();
void search();
void update();
void print();
int insert_code();
int Insert_Name(int x);
int Insert_Seed(int y);
int Insert_Colour(int z);
const char* Colour_Finder(int w);

//Initializing our global variables
int count = 0;
int arrCodes[32];


//Making the structure
//We will have an array of 32 of these structures stored in database
struct team{

    //Specifying the fields of the structure
    int code;
    char name[NAME_LEN + 1];
    char seed[SEEDING_LEN + 1];
    char colour;
} database[MAX_PARTS];


//Insert function
//Once called, allows the user to insert a new item into the database
void insert(){

    //Initializing some triggers we'll be using for the loops
    int code = -1;
    int nameTrigger = -1;
    int seedTrigger = -1;
    int colourTrigger = -1;
    
    //Checks if count = our available database space, if it is, then the database if full
    if (count == 32){
        printf("Database full; cannot insert any more teams");
        return;
    }


    //While loop that will keep running until the user provides a valid code
    while (code == -1){
        code = insert_code();
    }
    database[code].code = code;

    //While loop that will keep running until the user provides a valid name
    while (nameTrigger == -1){
        nameTrigger = Insert_Name(code);
    }

    //While loop for a valid seed
    while (seedTrigger == -1){
        seedTrigger = Insert_Seed(code);
    }

    //While loop for a valid colour
    while (colourTrigger == -1){
        colourTrigger = Insert_Colour(code);
    }

    //Stores the code of the team that was just inserted into another array that we'll be using for our print function
    arrCodes[count] = code;

    //Updates count
    count = count + 1;
}

//Search function
//Finds a team given a code by the user, and prints its details
void search(){

    //Initalizes the code variable
    int code;

    //Takes in user input to store into the code variable
    printf("Please enter the team code for the team you are looking for: ");
    scanf("%d", &code);


    //Checks if the code asked for exists in the database
    if (database[code].code != code){
        printf("Error: Code not found\n");
        return;
    }

    //Outputs the details of the specified team
    printf("Team Code   Team Name                   Group Seeding   Primary Kit Colour\n");
    printf("%-11d %-27s %-15s %-7s\n", database[code].code, database[code].name, database[code].seed, Colour_Finder(code));

}

//Update function
//Allows the user to specify a team by its code, and update its details
void update(){

    //Initializing some variables
    int code, nameTrigger = -1, seedTrigger = -1, colourTrigger = -1;

    //Asks the user for what team code they'd like to access
    printf("Please enter the team code of the team to update: ");
    scanf("%d", &code);

    //Checks if the code exists
    if (database[code].code != code){
        printf("Error: Team not found\n");
        return;
    }

    //Same things as in the Insert function and updates all the required fields
    while (nameTrigger == -1){
        nameTrigger = Insert_Name(code);
    }

    while (seedTrigger == -1){
        seedTrigger = Insert_Seed(code);
    }

    while (colourTrigger == -1){
        colourTrigger = Insert_Colour(code);
    }

}

//Print function
//Prints out all teams the user has inputed
void print(){

    printf("Team Code   Team Name                   Group Seeding   Primary Kit Colour\n");

    //For loop that iterates through the array that contained all the codes the user inserted
    //Prints everything out in the order they were inserted into the database
    for (int i = 0; i < count; i++){
        printf("%-11d %-27s %-15s %-7s\n", database[arrCodes[i]].code, database[arrCodes[i]].name, database[arrCodes[i]].seed, Colour_Finder(arrCodes[i]));
    }

}

//Insert_code function
//Inserts the user specified code into the database
int insert_code(){
    
    //Initializes the code variable
    int code;

    //Promtps the user for input
    printf("Please enter the team code: ");
    scanf("%d", &code);

    //Checks to see if the code is valid, and if not, outputs the error and continues the while loop that calls this function
    //Checks if code is too large
    if (code > 31){
        printf("Invalid input: Code is greater than 32\n");
        return -1;
    //Checks if code is negative
    } else if (code < 0){
        printf("Invalid input: Code is less than 0\n");
        return -1;
    //Checks if code is already in the database
    } else if (database[code].code == code){
        printf("Error: Code is already in the database\n");
        return -1;
    //If everything's alright, the code is returned
    } else{
        return code;
    }

}

//Insert_Name function
//Prompts for the user to input the name of the team
int Insert_Name(int code){
    
    //Initializes a string
    char str[NAME_LEN + 1];

    //Stores the user's input into the string variable, and only takes in 24 characters
    printf("Please enter the team name: ");
    scanf("%24s", str);

    //Checks if the team name already exists in the database
    for (int i = 0; i < 32; i++){
        if(strcmp(str, database[i].name) == 0){
            printf("Error: Team name already exits\n");
            return -1;
        }
    }

    //Copy's the string in str into the database name field
    strcpy(database[code].name, str);

    return 0;
}

//Insert_Seed function
//Allows the user to insert the seeding of the team
int Insert_Seed(int code){

    //Initializes string variable
    char seed[SEEDING_LEN + 1];

    //Prompts the user for input, only accepting 2 characters
    printf("Please enter the group seeding: ");
    scanf("%2s", seed);

    //Checks if the seed already exists
    for (int i = 0; i < 32; i++){
        if(strcmp(seed, database[i].seed) == 0){
            printf("Error: Seed already exits\n");
           return -1;
       } 
    }


    //Checks of the first character of the seed string is valid or not
    //Breaks if valid
    //Outputs an error statement and -1 to continue the loop
    switch (seed[0]){
    case 'A':
        break;
    case 'B':
        break;
    case 'C':
        break;
    case 'D':
        break;
    case 'E':
        break;
    case 'F':
        break;
    case 'G':
        break;
    case 'H':
        break;
    default:
        printf("Error: Invalid seed 1\n");
        return -1;
        break;
    }

    //Same thing as above only for the second character in seed
    switch (seed[1]){
    case '1':
        break;
    case '2':
        break;
    case '3':
        break;
    case '4':
        break;
    default:
        printf("Error: Invalid seed 2\n");
        return -1;
        break;
    }

    //Copy's the seed string into the correct database field
    strcpy(database[code].seed, seed);
    return 0;
}

//Insert_Colour function
//Allows the user to insert the primary kit colour of their team
int Insert_Colour(int code){

    //Initializes variable for user input
    char colour;

    //Prompts user for input, and stores it
    printf("Please enter the uniform colour: ");
    scanf(" %c", &colour);

    //Checks if the user's input is valid or not
    //Breaks if valid
    //Outputs error statement and -1 to continue the loop if invalid
    switch (colour){
    case 'R':
        break;
    case 'O':
        break;
    case 'Y':
        break;
    case 'G':
        break;
    case 'B':
        break;
    case 'I':
        break;
    case 'V':
        break;
    
    default:
        printf("Error: Invalid colour\n");
        return -1;
        break;
    }

    //Sets the teams colour to the specified one in the database
    database[code].colour = colour;
    return 0;
}

//Colour_Finder function
//outputs the teams colour in string format when provided the team code
const char* Colour_Finder(int code){

    if (database[code].colour == 'R'){
        return "Red";
    } else if (database[code].colour == 'O'){
        return "Orange";
    } else if (database[code].colour == 'Y'){
        return "Yellow";
    } else if (database[code].colour == 'G'){
        return "Green";
    } else if (database[code].colour == 'B'){
        return "Blue";
    } else if (database[code].colour == 'I'){
        return "Indigo";
    } else if (database[code].colour == 'V'){
        return "Violet";
    }
}

//Main function
void main(){

    //Initializes input variable for user input
    char input;

    //Sets the code for database[0] to -1, or else the program will believe it is already present when it is not
    database[0].code = -1;

    //While loop that will continue until the user inputs 'q'
    while (input != 'q'){
        //Prompts the user for input
        printf("Enter Operation Code: ");
        scanf(" %c", &input);

        //Calls the various functions depending on the user input
        //Default is when the input is invalid, and so continues the loop
        switch(input){
            case 'i': insert();
                break;
            case 's': search();
                break;
            case 'u': update();
                break;
            case 'p': print();
                break;
            case 'q': return;
            default: printf("Illegal Code\n");
        }
    }

    printf("\n");
}