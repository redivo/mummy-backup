/**************************************************************************************************/
/**
* \file
* \brief Tests for main.c
*/
/**************************************************************************************************/

#include <gtest/gtest.h>
//#include <gmock/gmock.h>

#include "defines.h"

extern "C" {
#include "agent.h"
#include "client.h"
#include "server.h"
}

/**************************************************************************************************/
/* Mock client and server */
class ClientAndServerWraper {
public:
  virtual mummy_err_t run_server(int socket, mummy_agent_config_t config) = 0;
  virtual mummy_err_t run_client(int socket, mummy_agent_config_t config) = 0;
};

class MockClientAndServer {
   public:
//    MOCK_METHOD2(run_server, mummy_err_t(int socket, mummy_agent_config_t config));
};

mummy_err_t run_server(int socket, mummy_agent_config_t config) {
    return MUMMY_ERR_NONE;
}
mummy_err_t run_client(int socket, mummy_agent_config_t config) {
    return MUMMY_ERR_NONE;
}

/**************************************************************************************************/

TEST(AgentInit, ServerOK) {
    char *args[2];
    char binName[15] = "test-mummy-bkp";
    char typeArg[3] = "-s";

    args[0] = binName;
    args[1] = typeArg;

    ASSERT_EQ(init_agent(sizeof(args) / sizeof(char *), (char **)args),
              MUMMY_ERR_NONE);
}

/**************************************************************************************************/

TEST(AgentInit, ServerAndPortOK) {
    char *args[4];
    char binName[15] = "test-mummy-bkp";
    char typeArg[3] = "-s";
    char portArg[3] = "-p";
    char portVal[5] = "6547";

    args[0] = binName;
    args[1] = typeArg;
    args[2] = portArg;
    args[3] = portVal;

    ASSERT_EQ(init_agent(sizeof(args) / sizeof(char *), (char **)args),
              MUMMY_ERR_NONE);
}

/**************************************************************************************************/

TEST(AgentInit, ClientOK) {
    char *args[2];
    char binName[15] = "test-mummy-bkp";
    char typeArg[3] = "-c";

    args[0] = binName;
    args[1] = typeArg;

    ASSERT_EQ(init_agent(sizeof(args) / sizeof(char *), (char **)args),
              MUMMY_ERR_NONE);
}

/**************************************************************************************************/

TEST(AgentInit, ClientAndPortOK) {
    char *args[4];
    char binName[15] = "test-mummy-bkp";
    char typeArg[3] = "-c";
    char portArg[3] = "-p";
    char portVal[5] = "6547";

    args[0] = binName;
    args[1] = typeArg;
    args[2] = portArg;
    args[3] = portVal;

    ASSERT_EQ(init_agent(sizeof(args) / sizeof(char *), (char **)args),
              MUMMY_ERR_NONE);
}

/**************************************************************************************************/

TEST(AgentInit, HelpOK) {
    char *args[2];
    char binName[15] = "test-mummy-bkp";
    char help[3] = "-h";

    args[0] = binName;
    args[1] = help;

    ASSERT_EQ(init_agent(sizeof(args) / sizeof(char *), (char **)args),
              MUMMY_ERR_NONE);
}

/**************************************************************************************************/

TEST(AgentInit, HelpAndOthersOK) {
    char *args[3];
    char binName[15] = "test-mummy-bkp";
    char help[3] = "-h";
    char typeArg[3] = "-c";

    args[0] = binName;
    args[1] = help;
    args[2] = typeArg;

    ASSERT_EQ(init_agent(sizeof(args) / sizeof(char *), (char **)args),
              MUMMY_ERR_NONE);
}

/**************************************************************************************************/

TEST(AgentInit, NoArgsERR) {
    char *args[1];
    char binName[15] = "test-mummy-bkp";

    args[0] = binName;

    ASSERT_EQ(init_agent(sizeof(args) / sizeof(char *), (char **)args),
              MUMMY_ERR_INVALID_ARGS);
}

/**************************************************************************************************/

TEST(AgentInit, UnknownArgsERR) {
    char *args[2];
    char binName[15] = "test-mummy-bkp";
    char wrong[3] = "-x";

    args[0] = binName;
    args[1] = wrong;

    ASSERT_EQ(init_agent(sizeof(args) / sizeof(char *), (char **)args),
              MUMMY_ERR_INVALID_ARGS);
}

/**************************************************************************************************/

TEST(AgentInit, DoubleTypeERR) {
    char *args[3];
    char binName[15] = "test-mummy-bkp";
    char client[3] = "-c";
    char server[3] = "-c";

    args[0] = binName;
    args[1] = client;
    args[2] = server;

    ASSERT_EQ(init_agent(sizeof(args) / sizeof(char *), (char **)args),
              MUMMY_ERR_INVALID_ARGS);
}

/**************************************************************************************************/

TEST(AgentInit, NoPortArgAtTheEndERR) {
    char *args[3];
    char binName[15] = "test-mummy-bkp";
    char client[3] = "-c";
    char portArg[3] = "-p";

    args[0] = binName;
    args[1] = client;
    args[2] = portArg;

    ASSERT_EQ(init_agent(sizeof(args) / sizeof(char *), (char **)args),
            MUMMY_ERR_INVALID_ARGS);
}

/**************************************************************************************************/

TEST(AgentInit, NoPortArgAtTheMiddleERR) {
    char *args[3];
    char binName[15] = "test-mummy-bkp";
    char client[3] = "-c";
    char portArg[3] = "-p";

    args[0] = binName;
    args[1] = portArg;
    args[2] = client;

    ASSERT_EQ(init_agent(sizeof(args) / sizeof(char *), (char **)args),
            MUMMY_ERR_INVALID_ARGS);
}

