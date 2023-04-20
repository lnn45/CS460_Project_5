//Protect from multiple compiling
#ifndef message_h
#define message_h

//headers
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

//COMMAND_TYPE
typedef enum COMMAND_TYPE {JOIN, LEAVE, NOTE, SHUTDOWN, SHUTDOWN_ALL};

//message struct
typedef struct Message {
    COMMAND_TYPE MessageType;
    char IPAddress[15];
    int portNumber;
    char* content;
}Message;

//function prototypes
bool sendMessage( int socket_var, const char message[MAX_STD_LEN] )
bool receiveMessage( Message* receive, int socket_var )


#endif // message_h

