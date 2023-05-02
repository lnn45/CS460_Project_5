//Protect from multiple compiling
#ifndef SENDER_HANDLER_H
#define SENDER_HANDLER_H

//headers
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <sys/socket.h>
#include <pthread.h>

#define MAX_STR_LEN 128
#define MIN_STR_LEN 64
#define SPACE ' '
#define NULL_CHAR '\0'

extern volatile sig_atomic_t stopFlag;
extern int leaveFlag;

typedef struct Client_Node
{
    char name[64];
    int socket;
} Client;

//function prototypes
void* handle_sender( void* arg );
void modifyString( char *message, int lenOfString );
void setStopFlag( int sig );
void setLeaveFlag();
void getSubString( char *destStr, const char *sourceStr,
                            int startIndex, int endIndex );

#endif //SENDER_HANDLER_H