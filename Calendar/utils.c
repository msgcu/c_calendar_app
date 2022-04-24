#include <stdio.h>
#include <string.h>

#include "utils.h"

void prompt_and_read(char* buffer, int buffer_size, char* prompt)
{
    // Prompt the user for what they want to do
    printf("%s\n", prompt);
    printf("> ");

    // Read the user input
    memset(buffer, 0, buffer_size);     // Clear the input buffer
    fgets(buffer, buffer_size, stdin);  // Read user input into the buffer
    buffer[strlen(buffer) - 1] = '\0';  // Remove the \n newline character from the user input (sanitize input)
}