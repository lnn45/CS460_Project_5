#ifndef CLIENT_HANDLER_HEADER
#define CLIENT_HANDLER_HEADER

#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <syslog.h>
#include <signal.h>
#include <time.h>
#include <string.h>

#include "message.h"
#include "chat_node.h"

extern volatile sig_atomic_t shutdownServerFlag;

// Functions prototypes
void* handle_client(void* arg);
void setShutDownServer( int sig );

// Declare Constants
    // None

#endif