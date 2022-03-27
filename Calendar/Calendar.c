// Calendar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "commands_list.h"
#include "help.h"

#define MAX_INPUT_CHARACTERS 256

int main()
{
    printf("Calendar app launched!\n");

    // array to store user input
    char input[MAX_INPUT_CHARACTERS];
    bool didQuit = false;
    while (didQuit == false)
    {
        // Prompt the user for what they want to do
        printf("What do you want to do?\n");
        printf("Type '%s' for help\n", HELP_COMMAND);
        printf("> ");
        
        // Read the user input 
        fgets(input, MAX_INPUT_CHARACTERS, stdin);
        input[strlen(input) - 1] = '\0';

        printf("User typed: %s\n", input);

        if (strstr(input, HELP_COMMAND))
        {
            handle_help_command();
        }
        else if (strstr(input, QUIT_COMMAND))
        {
            didQuit = true;
        }
        else if (strstr(input, ADD_COMMAND))
        {
            // TODO: Add input handling
        }

        printf("\n");
    }

    printf("We're done here\n");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
