/**************************************************************************************************/
/**
* \file
* \brief Generic agent implementation
*/
/**************************************************************************************************/

#ifndef __INCUDE_AGENT_H__
#define __INCUDE_AGENT_H__

#include <stdint.h>
#include "defines.h"

/**************************************************************************************************/

/**
 * \brief  Initialize agent based on the received arguments
 * \param  argc  Argument counter
 * \param  argv  Argument list
 * \return MUMMY_ERR_NONE on success, error code otherwise.
 */
mummy_err_t init_agent(int argc, char* argv[]);

/**************************************************************************************************/

/**
 * \brief  Run agent instance
 * \param  config  Agent configuration
 * \return MUMMY_ERR_NONE on success, error code otherwise.
 */
mummy_err_t run_agent(mummy_agent_config_t config);

/**************************************************************************************************/

#endif /* __INCUDE_AGENT_H__ */
