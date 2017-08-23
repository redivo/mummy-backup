/**************************************************************************************************/
/**
* \file
* \brief Main Client file
*/
/**************************************************************************************************/

#include <stdio.h>

/**************************************************************************************************/

#define PORT_ARG "-p"
#define HELP_ARG "-h"

static void print_help(const char *bin_name)
{
    printf("\r\n");
    printf("Usage:\r\n");
    printf("  %s [OPTIONS]\r\n", bin_name);
    printf("\r\n");
    printf("  Where OPTIONS are:\r\n");
    printf("    %s <PORT>    Inform port to be listened. Default is 8888\r\n", PORT_ARG);
    printf("    %s           Print this help message.\r\n", HELP_ARG);
    printf("\r\n");
}

int main(int argc, char* argv[])
{
    int i;
    int port = 8888;

    /* Parse args */
    for (i = 1; i < argc; i++) {
        // Port
        if (strcmp(argv[i], PORT_ARG) == 0) {
            i++;

            //  If there is no port value, exit
            if (i >= argc) {
                print_help(argv[0]);
                return -1;
            }

            port = atoi(argv[i]);
        }

        // Help
        else if(strcmp(argv[i], HELP_ARG) == 0) {
            print_help(argv[0]);
            return 0;
        }

        // Unknown parameter
        else {
            print_help(argv[0]);
            return -1;
        }
    }

    return run_client(port);
}
