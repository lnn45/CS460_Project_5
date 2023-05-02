// Protect from multiple compiling
#ifndef CHAT_NODE_H
#define CHAT_NODE_H

// Headers
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <pthread.h>

// Chat node struct
typedef struct Chat_Node
{
	// Member variables
	struct sockaddr_in address;
	int client_socket;
	int client_id;
	char name[32];
} Chat_Node;

extern pthread_mutex_t client_lock;
extern Chat_Node *listOfClients[ 5 ];

// Function Prototypes
void addElementToList( Chat_Node *client );
void removeElementFromList( int clientIDRemove );

#endif  // CHAT_NODE_H