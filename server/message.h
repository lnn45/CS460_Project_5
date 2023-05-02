//Protect from multiple compiling
#ifndef message_h
#define message_h

//headers
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "chat_node.h"
#include <unistd.h>

//COMMAND_TYPE
typedef enum {JOIN, LEAVE, NOTE, SHUTDOWN, SHUTDOWN_ALL} commandType;

//function prototypes
void sendMessage( int client_id, char *message );

#endif // message_h
