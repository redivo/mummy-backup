
include_directories(${INCLUDE_SRC_DIR})

add_executable (mummy-backup-server
    server_main.c
)

add_executable (mummy-backup-client
    client_main.c
    client.c
)
