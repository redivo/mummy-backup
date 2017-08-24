
include_directories(${INCLUDE_SRC_DIR})

add_executable (mummy-backup
    main.c
    agent.c
    client.c
    server.c
)
