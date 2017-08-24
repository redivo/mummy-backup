/**************************************************************************************************/
/**
* \file
* \brief File containing the general structures, types and defines
*/
/**************************************************************************************************/

#ifndef __INCLUDE_DEFINES_H__
#define __INCLUDE_DEFINES_H__

/**************************************************************************************************/

typedef enum {
    MUMMY_ERR_NONE = 0,
    MUMMY_ERR_GENERIC = -1,
    MUMMY_ERR_INIT = -2,
    MUMMY_ERR_INVALID_ARGS = -3,
} mummy_err_t;

/**************************************************************************************************/

typedef enum {
    MUMMY_TYPE_UNKNOWN,
    MUMMY_TYPE_SERVER,
    MUMMY_TYPE_CLIENT,
} mummy_agent_type_t;

/**************************************************************************************************/

typedef struct {
    mummy_agent_type_t type;
    int port;
} mummy_agent_config_t;

/**************************************************************************************************/

//typedef enum {
//};

/**************************************************************************************************/

#endif /* __INCLUDE_DEFINES_H__ */
