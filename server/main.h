#ifndef MAIN_HEADER
#define MAIN_HEADER

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

#include "client_handler.h"

// Function prototypes
    // None

// Declare Constants
#define NUM_CONNECTIONS 5
#define PORT 23567
#define FALSE 0
#define TRUE !FALSE

#endif
