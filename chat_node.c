// Header
#include "chat_node.h"

/*
Name: createChatNodeList
Process: Creates a new header node with given member values to start a linked list
Function Parameters/Input: Ip address of head node (char[15]),
                           Port number of head node (int),
						   The logical name for the head chat node (char *)
Function Parameters/Output: None
Function Output/Device: None
Function Output/Return: The newly created head node for the list
Dependencies: None
*/
Chat_Node* createChatNodeList(char[15] ip, int port, char* name)
{
	// Create head node;
	Chat_Node* headNode = (Chat_Node*)malloc(sizeOf(Chat_Node));

	// Initialize values in head node
	headNode->ipAddress = ip;
	headNode->port = port;
	headNode->name = name;

	// Head node has been made, return head node
	return headNode;
}

/*
Name: addChatNodeToList
Process: Adds a new node to the end of the list
Function Parameters/Input: The head node of the list to add the node to (Chat_Node*),
						   The new node to be added to the list (Chat_Node*)
Function Parameters/Output: None
Function Output/Device: None
Function Output/Return: None
Dependencies: None
*/
void addChatNodeToList(Chat_Node* headNode, Chat_Node* newNode)
{
	// Initialize variables

	// Loop to end of list (when local pointer isn't null)

	    // Move to next chat node

	// Assign newNode to the next Node
}

/*
Name: addChatNodeToList
Process: Adds a new node to a specific area of the list if found, 
         otherwise does nothing. This includes creating a new head node for the list.
Function Parameters/Input: The head node of the list to add the node to (Chat_Node*),
						   The new node to be added to the list (Chat_Node*)
						   The node in the list to insert the new node after (Chat_Node*),
						   flag for if new node is a new head node (Bool)
Function Parameters/Output: None
Function Output/Device: None
Function Output/Return: None
Dependencies: None
*/
void addChatNodeToList(Chat_Node* headNode, Chat_Node* newNode, Chat_Node* parentNode, bool newHeadNode)
{
	// Initialize variables

	// Check if new node is a new head node

	    // Assign head node as the new node's next node

	// Otherwise, assume new node isn't a new head node

	    // Loop til parent node is found

	        // Move to next chat node

	    // Check if parent node is in list (not null)
	
	        // Copy parent's old next node

	        // Assign the new node to the parent's next node

	        // Assign parent's old next node to the new node's next node
}

/*
Name: clearChatNodeList
Process: Will clear/free the linked list given from memory
Function Parameters/Input: The head node of the list to clear
Function Parameters/Output: None
Function Output/Device: None
Function Output/Return: None
Dependencies: None
*/
void clearChatNodeList(Chat_Node* headNode)
{
	// Check if given node's next node isn't null

        // Recurse with next node

	// Free given node
}

/*
Name: removeChatNodeFromLIst
Process: Removes the given chat node from the list if found, otherwise 
         does nothing. 
Function Parameters/Input: The head node of the list to add the node to (Chat_Node*),
						   The node to be removed to the list (Chat_Node*)
Function Parameters/Output: None
Function Output/Device: None
Function Output/Return: None
Dependencies: None
*/
void removeChatNodeFromList(Chat_Node* headNode, Chat_Node* removeNode)
{
	// Initialize variables

	// Loop til the node before the desired node to be removed is found

	// Check if desired removed node is found (not null)

	    // Copy the node to be removed's next node

	    // Free the node to be removed

	    // Put copied node into current node's next node. 
}