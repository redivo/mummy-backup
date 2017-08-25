/**************************************************************************************************/
/**
* \file
* \brief Generic agent implementation
*/
/**************************************************************************************************/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "agent.h"
#include "client.h"
#include "server.h"

#define PORT_ARG   "-p"
#define SERVER_ARG "-s"
#define CLIENT_ARG "-c"
#define HELP_ARG   "-h"

/**************************************************************************************************/
/**
 * \brief  Print the Mummy Backup Agent usage
 * \param  bin_name  Name of ran binary
 */
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

/**************************************************************************************************/

mummy_err_t init_agent(int argc, char* argv[])
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

/**************************************************************************************************/

mummy_err_t run_agent(mummy_agent_config_t config)
{
    int sock;

    // Create socket
    if ((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
        perror("Error creating socket");
        return MUMMY_ERR_INIT;
    }

    printf("== Running Mummy Backup as %s on port %d ==\r\n",
            config.type == MUMMY_TYPE_SERVER ? "Server" :
            config.type == MUMMY_TYPE_CLIENT ? "Client" : "Unknown type",
            config.port);

    // Start specific agent
    switch (config.type) {
        case MUMMY_TYPE_SERVER:
            return run_server(sock, config);

        case MUMMY_TYPE_CLIENT:
            return run_client(sock, config);

        default:
            printf("ERROR: Invalid agent type");
            return MUMMY_ERR_INVALID_ARGS;
    }

    return MUMMY_ERR_NONE;
}
