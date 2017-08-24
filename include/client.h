/**************************************************************************************************/
/**
* \file
* \brief Client agent implementation
*/
/**************************************************************************************************/

#ifndef __INCLUDE_CLIENT_H__
#define __INCLUDE_CLIENT_H__

#include "defines.h"

/**************************************************************************************************/

/**
 * \brief  Run a client instance
 * \param  socket  Opened socket
 * \param  config  Agent configuration
 * \return MUMMY_ERR_NONE on success, error code otherwise.
 */
mummy_err_t run_client(int socket, mummy_agent_config_t config);

/**************************************************************************************************/

#endif /* __INCLUDE_CLIENT_H__ */
