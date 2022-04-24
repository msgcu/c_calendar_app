// Calendar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "commands_list.h"
#include "cal_store.h"
#include "help.h"
#include "utils.h"

#define MAX_INPUT_CHARACTERS 256

int main()
{
    init_calendar_store();
    printf("Calendar app launched!\n");

    // Buffer to store user input
    char input[MAX_INPUT_CHARACTERS];
    bool didQuit = false;
    while (didQuit == false)
    {
        //printf("Type '%s' for help\n", HELP_COMMAND);
        prompt_and_read(input, MAX_INPUT_CHARACTERS, "What do you want to do?");
        //printf("User typed: %s\n", input);

        // Compare input with help command to see if user typed help
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
            prompt_and_read(input, MAX_INPUT_CHARACTERS, "What year?");
            int year = atoi(input);
            prompt_and_read(input, MAX_INPUT_CHARACTERS, "What month? (1-12)");
            int month = atoi(input);
            prompt_and_read(input, MAX_INPUT_CHARACTERS, "What day? (1-31)");
            int day = atoi(input);

            prompt_and_read(input, MAX_INPUT_CHARACTERS, "Create free note? (y/n)");
            bool isFreeNote = strstr(input, "y");

            bool didAdd = false;
            if (isFreeNote)
            {
                prompt_and_read(input, MAX_INPUT_CHARACTERS, "Add notes for this appointment");
                didAdd = add_calendar_entry_freenote(day, month, year, input);
            }
            else
            {
                prompt_and_read(input, MAX_INPUT_CHARACTERS, "What is the priority of this appointment? (1-10)");
                int prio = atoi(input);

                prompt_and_read(input, MAX_INPUT_CHARACTERS, "Is this an all day appointment? (y/n)");
                bool isAllDay = strstr(input, "y");

                prompt_and_read(input, MAX_INPUT_CHARACTERS, "What is the name for this appointment?");
                didAdd = add_calendar_entry_meta(day, month, year, prio, isAllDay, input);
            }

            if (didAdd)
            {
                printf("Calendar entry added successfully\n");
            }
            else
            {
                printf("Calendar is full\n");
            }
        }
        else if (strstr(input, PRINT_COMMAND))
        {
            print_calendar_entries();
        }
        else if (strstr(input, REMOVE_COMMAND))
        {
            prompt_and_read(input, MAX_INPUT_CHARACTERS, "Enter the ID of the calendar entry you want to remove");
            int id = atoi(input);

            if (remove_calendar_entry(id))
            {
                printf("Calendar entry removed\n");
            }
            else
            {
                printf("Invalid calendar entry ID\n");
            }
        }

        printf("\n");
    }

    printf("We're done here\n");
}

// Do not forget to implement design for unions and then expose the remaining .c and .h files.

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
