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

// Functions prototypes
void* handle_client(void* arg);

// Declare Constants
    // None

#endif