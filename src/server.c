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
    int buf;
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(addr);
    memset(&addr, 0, sizeof(addr));

    addr.sin_family = AF_INET;
    addr.sin_port = htons(config.port);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    printf("addr: %d\r\n", (int)addr.sin_addr.s_addr);

    addr_len = sendto(socket, &buf, sizeof(buf), 0, (struct sockaddr*) &addr, addr_len);
    printf("size: %d\r\n", (int)addr_len);

    return MUMMY_ERR_NONE;
}
