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
