/**************************************************************************************************/
/**
* \file
* \brief Server agent implementation
*/
/**************************************************************************************************/

#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>

#include "client.h"

/**************************************************************************************************/

mummy_err_t run_server(int socket, mummy_agent_config_t config)
{
    while (1) {
        int buf;
        struct sockaddr_in addr;
        socklen_t addr_len = sizeof(addr);
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(config.port);
        addr.sin_addr.s_addr = inet_addr("127.0.0.1");

        addr_len = sendto(socket, &buf, sizeof(buf), 0, (struct sockaddr*) &addr, addr_len);
        if (addr_len != 4) {
            perror("error sending heart beat");
        }

        sleep(3);
    }

    return MUMMY_ERR_NONE;
}
