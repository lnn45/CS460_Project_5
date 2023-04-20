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

#include "properties.h"
#include "receiver_handler.h"
#include "sender_handler.h"

// declare constants
#define INFO_FILE "server_info.conf"
#define SERVER_LINE "Server"
#define PORT_LINE "Port"

#endif