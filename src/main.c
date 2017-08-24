/**************************************************************************************************/
/**
* \file
* \brief Main Mummy Backup file
*/
/**************************************************************************************************/

#include <stdio.h>
#include "defines.h"
#include "agent.h"

/**************************************************************************************************/

#define PORT_ARG   "-p"
#define SERVER_ARG "-s"
#define CLIENT_ARG "-c"
#define HELP_ARG   "-h"

static void print_help(const char *bin_name)
{
    printf("\r\n");
    printf("Usage:\r\n");
    printf("  %s [OPTIONS]\r\n", bin_name);
    printf("\r\n");
    printf("  Where OPTIONS are:\r\n");
    printf("    %s <PORT>    Port to run the service. Default is 8888\r\n", PORT_ARG);
    printf("    %s           Start the agent as a server.\r\n", SERVER_ARG);
    printf("    %s           Start the agent as a client.\r\n", CLIENT_ARG);
    printf("    %s           Print this help message.\r\n", HELP_ARG);
    printf("\r\n");
}

int main(int argc, char* argv[])
{
    int i;
    mummy_agent_config_t cfg;

    /* Initialize config */
    cfg.type = MUMMY_TYPE_UNKNOWN;
    cfg.port = 8888;

    /* Parse args */
    for (i = 1; i < argc; i++) {
        // Port
        if (strcmp(argv[i], PORT_ARG) == 0) {
            i++;

            //  If there is no port value, exit
            if (i >= argc) {
                printf("\r\nERROR: Invalid port value\r\n");
                print_help(argv[0]);
                return MUMMY_ERR_INVALID_ARGS;
            }

            cfg.port = atoi(argv[i]);
        }

        // Client
        else if (strcmp(argv[i], CLIENT_ARG) == 0) {
            // If the type was already set, it's an error
            if (cfg.type != MUMMY_TYPE_UNKNOWN) {
                printf("\r\nERROR: Multiple agent type setting\r\n");
                print_help(argv[0]);
                return MUMMY_ERR_INVALID_ARGS;
            }

            cfg.type = MUMMY_TYPE_CLIENT;
        }

        // Server
        else if (strcmp(argv[i], SERVER_ARG) == 0) {
            // If the type was already set, it's an error
            if (cfg.type != MUMMY_TYPE_UNKNOWN) {
                printf("\r\nERROR: Multiple agent type setting\r\n");
                print_help(argv[0]);
                return MUMMY_ERR_INVALID_ARGS;
            }

            cfg.type = MUMMY_TYPE_SERVER;
        }

        // Help
        else if (strcmp(argv[i], HELP_ARG) == 0) {
            print_help(argv[0]);
            return MUMMY_ERR_NONE;
        }

        // Unknown parameter
        else {
            printf("\r\nERROR: Unknown parameter\r\n");
            print_help(argv[0]);
            return MUMMY_ERR_INVALID_ARGS;
        }
    }

    /* Verify got configuration */
    if (cfg.type == MUMMY_TYPE_UNKNOWN) {
        printf("\r\nERROR: Agent type not set\r\n");
        print_help(argv[0]);
        return MUMMY_ERR_INVALID_ARGS;
    }

    return run_agent(cfg);
}
