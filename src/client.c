/**************************************************************************************************/
/**
* \file
* \brief Client agent implementation
*/
/**************************************************************************************************/

#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

#include "client.h"

/**************************************************************************************************/

mummy_err_t run_client(int socket, mummy_agent_config_t config)
{
    int buf;
    struct sockaddr_in sock_addr;


    // Start to listen all from informed port
    memset(&sock_addr, 0, sizeof(sock_addr));
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(config.port);
    sock_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(socket, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) < 0) {
        perror("Error binding socket");
        return MUMMY_ERR_INIT;
    }

    // Receive messages
    while (1) {
        struct sockaddr_in rcvd_addr;
        socklen_t addr_len = sizeof(rcvd_addr);

        memset(&rcvd_addr, 0, sizeof(rcvd_addr));

        ssize_t rcvd_size
            = recvfrom(socket, &buf, sizeof(buf), 0, (struct sockaddr*) &rcvd_addr, &addr_len);

        printf("Message received\r\n");
    }

    return MUMMY_ERR_NONE;
}
