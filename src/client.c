/**************************************************************************************************/
/**
* \file
* \brief Client implementation
*/
/**************************************************************************************************/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "client.h"

/**************************************************************************************************/

int run_client(uint32_t port)
{
    int sock;
    struct sockaddr_in sock_addr;


    // Create socket
    if ((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
        printf("Error creating socket\r\n");
        return -1;
    }

    // Start to listen all from informed port
    memset(&sock_addr, 0, sizeof(sock_addr));
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(port);
    sock_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(sock, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) < 0) {
        printf("Error binding socket\r\n");
        return -1;
    }

    printf("== Running Mummy Backup client on port %d ==\r\n", port);

    // Receive messages
    int buf;
    while (1) {
        if (recvfrom(sock, &buf, sizeof(buf), 0, NULL, 0) >= 0) {
            printf("Message received! (%d)\r\n", buf);
        }
    }
}
