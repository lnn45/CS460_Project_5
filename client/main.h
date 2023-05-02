#ifndef CLIENT_MAIN_HEADER
#define CLIENT_MAIN_HEADER

// should always be there ...
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>

// socket/bind/listen/accept
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// read/write/close
#include <sys/uio.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

#include "properties.h"
#include "receiver_handler.h"
#include "sender_handler.h"

// declare constants
#define INFO_FILE "server.properties"
#define CLIENT_NAME "Client"
#define SERVER_LINE "Server"
#define PORT_LINE "Port"
#define MAX_STR_LEN 128
#define MIN_STR_LEN 64

#endif