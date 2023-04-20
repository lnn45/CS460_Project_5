// Protect from multiple compiling
#ifndef CHAT_NODE_H
#define CHAT_NODE_H

// Headers
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

// Chat node struct
def struct Chat_Node {
	// Member variables
	char ipAddress[15];
	int port;
	char* name;
	
	// Pointer to next chat node;
	Chat_Node* nextNode;
} Chat_Node;

// Function Prototypes
void addChatNodeToList(Chat_Node* headNode, Chat_Node* newNode);
void addChatNodeToList(Chat_Node* headNode, Chat_Node* newNode, Chat_Node* parentNode);
void removeChatNodeFromList(Chat_Node* headNode, Chat_Node* removeNode);

#endif  // CHAT_NODE_H