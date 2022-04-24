#include "commands_list.h"
#include "help.h"

void handle_help_command(void)
{
    printf("Supported commands\n");
    printf("%s: help\n", HELP_COMMAND);
    printf("%s: quit\n", QUIT_COMMAND);
    printf("%s: add calendar appointment\n", ADD_COMMAND);
}