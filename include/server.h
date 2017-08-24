/**************************************************************************************************/
/**
* \file
* \brief Server agent implementation
*/
/**************************************************************************************************/

#ifndef __INCLUDE_SERVER_H__
#define __INCLUDE_SERVER_H__

#include "defines.h"

/**************************************************************************************************/

/**
 * \brief  Run a server instance
 * \param  socket  Opened socket
 * \param  config  Agent configuration
 * \return MUMMY_ERR_NONE on success, error code otherwise.
 */
mummy_err_t run_server(int socket, mummy_agent_config_t config);

/**************************************************************************************************/

#endif /* __INCLUDE_SERVER_H__ */
