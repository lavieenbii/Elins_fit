#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

//object
struct login_data
{
    int age;
    char username[30];
    char pass[30];
    char gender;
};

struct user_data
{
    int height;
    int weight;
    float BMI;
};

login_data user[5];   //array of users (max 5 users)
int account_index;    //index to determine which acount to use throughout the program
int user_counter = 0; //user index

char more;       //to determine if they want "more" items or not
char correct;    //to make sure item input is correct
int counter = 0; //item index

//Put all the function declaration
void login_system();
int menu();

int main()
{
    // insert code here...
    cout << "\n";
    cout << "*****************************************************************************************************************\n";
    cout << "Hello, World! Welcome to the ELINSFIT, where we help you start living Healthy and prevent Obesity\n";
    cout << "*****************************************************************************************************************\n";

    cout << "\nStart your  wonderful journey with us by logging in.\n";

    login_system();
    menu();

    return 0;
}

//Login system
void login_system()
{
    char login_choice;
    char account_choice = 'n';
    char new_account;
    char forgot_pass;
    string password_attempt;

    //header of login page
    cout << "Welcome to the Login" << endl;
    cout << "Are you new here? (Create an account) (y/n) ";
    cin >> login_choice; //determines if he/she has an account or not
    cout << endl;

//creating a new login
newLogin:
    while (account_choice == 'n')
    {
        cout << "Enter new username: ";
        cin >> user[user_counter].username;
        cout << "Enter new password: ";
        cin >> user[user_counter].pass;
        cout << endl
             << "Is that correct? y/n ";
        cin >> account_choice;
        cout << "Want to make another account? (y/n) ";
        cin >> new_account;
        /* if new_account == y, then we execute the while loop again and increment user_counter to create new account
       if new_account == n, then we exit the while loop
    */
        if (new_account == 'y')
        {
            cout << endl;
            account_choice = 'n';
            user_counter++; //increments the user Struct index to add more users later on (max 5 users)
            if (user_counter > 5)
            {
                user_counter = 0; //resets index of user Struct because
            }
            continue;
        }
        else if (new_account == 'n')
        {
            continue;
        }
        cout << endl;
    }

//to display all usernames and let users choose which one is their account
accountChoice:
    for (int i = 1; i <= 5; i++)
    {
        cout << i << ". " << user[i - 1].username << endl;
    }

    int attempts = 3; //sets the number of attempts
    cout << " Which one are you? ";
    cin >> account_index;
    account_index -= 1;

    //for loop to ask for password
    for (int i = 0; i < 4; i++)
    {
        /* when the attempts == 0
       then we ask to either forget password or to make a new acccount

       when the attempts are still > 0
       then we keep asking for password*/
        if (attempts == 0)
        {
            cout << " Forgot Password? (y/n)";
            cin >> forgot_pass;
            if (forgot_pass == 'y')
            {
                cout << " Enter new password: ";
                cin >> user[account_index].pass;
                goto accountChoice;
            }
            else if (forgot_pass == 'n')
            {
                cout << " Go make a new account!";
                login_choice = 'y';
                goto newLogin;
            }
        }
        else if (attempts > 0)
        {
            cout << " What is your Password? (" << attempts << "  attempts left) ";
            cin >> password_attempt;
            if (password_attempt == user[account_index].pass)
            {
                cout << endl
                     << " Congrats! You have successfully logged in!" << endl
                     << endl;
                break;
            }
            else
            {
                cout << endl;
            }
            attempts--;
        }
    }
}

//__________________________________________________
// This is the main menu page for the entire program
//__________________________________________________
int bmi();
int ideal_body();
int daily_water();
int daily_calorie();
void logout();

//Display the menu of the program
int menu()
{
    system("clear");
    int option;
    cout << "\t\t######################" << endl;
    cout << "\t\t#       Welcome!     #" << endl;
    cout << "\t\t######################" << endl
         << endl;
    cout << "\n\tSERVICE : " << endl;
    cout << "\n\t1. Calculate my BMI (Body Mass Index) " << endl;
    cout << "\t_________________________" << endl;
    cout << "\t2. Ideal Body Weight" << endl;
    cout << "\t____________________" << endl;
    cout << "\t3. Daily Water Requirement" << endl;
    ;
    cout << "\t____________________________________" << endl;
    ;
    cout << "\t4. Daily Calories require" << endl;
    cout << "\t_____________________________________" << endl;
    cout << "\t5. Logout" << endl;
    cout << "\t_________" << endl;
    cout << "\nWhere would you like to go (1-5)? --> ";
    cin >> option;

    switch (option)
    {
    case 1:
        bmi();
        break;
    case 2:
        ideal_body();
        break;
    case 3:
        daily_water();
        break;
    case 4:
        daily_calorie();
        break;
    case 5:
        logout();
        break;
    default:
        cout << "Enter a number form 1-5";
    }
    return 0;
}

int bmi()
{
    system("clear");
    float bmiHeight, bmiWeight;
    char return_choice;
    cout << "\t ======================================" << endl;
    cout << "  \t           BODY MASS INDEX             " << endl;
    cout << "\t ======================================" << endl;
    cout << endl;
    cout << "\t Enter your height (in m) : ";
    cin >> bmiHeight;
    cout << "\t Enter your weight (in kg) : ";
    cin >> bmiWeight;
    float BMI = bmiWeight / pow(bmiHeight, 2);
    cout << "\t Your Body Mass index: " << BMI;

    cout << endl;
    //Weight is ideal or not
    if (BMI >= 25)
    {
        cout << "\t Your weight is Obesity" << endl;
    }
    else if (BMI >= 23 && BMI <= 24.9)
    {
        cout << "\t You are overweight" << endl;
    }
    else if (BMI >= 18.5 && BMI <= 22.9)
    {
        cout << "\t Your weight is Normal" << endl;
    }
    else
    {
        cout << "\t You are Underweight" << endl;
    }

    cout << "\t======================================" << endl;

    cout << "\t Exit? (y/n)";
    cin >> return_choice;
    if (return_choice == 'n')
        bmi();
    if (return_choice == 'y')
        menu();
    return 0;
}

int ideal_body()
{
    system("clear");
    char gender;
    float ideal;
    int height;
    char return_choice;
    cout << "\t ======================================" << endl;
    cout << " \t           IDEAL BODY                   " << endl;
    cout << "\t ======================================" << endl;
    cout << endl;
    cout << "\t Enter your height (in cm) : ";
    cin >> height;
    cout << "\t Choose Your Gender (M/F) : ";
    cin >> gender;

    if (gender == 'M')
    {
        ideal = (height - 100) - ((height - 100) * 0.10);
    }
    else if (gender == 'F')
    {
        ideal = (height - 100) - ((height - 100) * 0.15);
    }

    cout << "\t Your Ideal weight is :  " << ideal;
    cout << endl;
    cout << "\t ======================================" << endl;

    cout << "\t Exit? (y/n)";
    cin >> return_choice;
    if (return_choice == 'n')
        ideal_body();
    if (return_choice == 'y')
        menu();
    return 0;
}

int daily_water()
{
    system("clear");
    char return_choice;
    char gender;
    int age;
    float water, dailyWater;
    int height, weight;

    cout << "\t ======================================" << endl;
    cout << "  \t              DAILY WATER               " << endl;
    cout << "\t =======================================" << endl;
    cout << endl;
    cout << "\t Enter your height (in cm) : ";
    cin >> height;
    cout << "\t Enter your weight (in kg ) : ";
    cin >> weight;
    cout << "\t Enter your age  : ";
    cin >> age;
    cout << "\t Choose Your Gender (M/F) : ";
    cin >> gender;

    if (gender == 'M')
    {
        water = 2.447 - (0.09145 * age) + (0.1074 * height) + (0.3362 * weight);
    }
    else if (gender == 'F')
    {
        water = -2.097 + (0.1069 * height) + (0.2466 * weight);
    }

    dailyWater = weight * 0.033;
    cout << "\t Your Water in your body is  :   " << water << "L";
    cout << endl;
    cout << "\t Your Ideal daily water is  :  " << dailyWater << "L";
    cout << endl;
    cout << "\t ======================================" << endl;

    cout << "\t Exit? (y/n)";
    cin >> return_choice;
    if (return_choice == 'n')
        daily_water();
    if (return_choice == 'y')
        menu();
    return 0;
}

int daily_calorie()
{
    system("clear");
    char gender_cal;
    int age;
    float calorie;
    int height, weight;
    char return_choice;

    cout << "\t ======================================" << endl;
    cout << "  \t           DAILY Calories             " << endl;
    cout << "\t ======================================" << endl;
    cout << endl;
    cout << "\t Enter your height (in cm) : ";
    cin >> height;
    cout << "\t Enter your weight (in kg ) : ";
    cin >> weight;
    cout << "\t Enter your age  : ";
    cin >> age;
    cout << "\t Choose Your Gender (M/F) : ";
    cin >> gender_cal;

    if (gender_cal == 'M')
    {
        calorie = (88.4 + 13.4 * weight) + (4.8 * height) - (5.68 * age);
    }
    else if (gender_cal == 'F')
    {
        calorie = (447.6 + 9.25 * weight) + (3.10 * height) - (4.33 * age);
    }
    else
    {
        cout << "your input wrong";
    }
    cout << "\t Your Ideal daily calorie is  :  " << calorie;
    cout << endl;
    cout << "\t ======================================" << endl;
    cout << "\t Exit? (y/n)";
    cin >> return_choice;
    if (return_choice == 'n')
        daily_calorie();
    if (return_choice == 'y')
        menu();
    return 0;
}
void logout()
{
    system("clear");
    cout << "Your account is log out" << endl;
    cout << endl;
    cout << "press x to exit the program" << endl;
    system("exit");
}
