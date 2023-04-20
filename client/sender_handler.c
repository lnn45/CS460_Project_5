#include "sender_handler.h"

bool handler_sender(Message *messageFromCient)
{
    //Initialize variables
    char clientInput[MAX_STR_LEN];

    // read command from client
    scanf( "%[^\n]%*c", clientInput );

    while( command != SHUTDOWN || command != SHUTDOWN_ALL)
    {
        //check for message command type (switch statement)
        switch (command)
        {
            //JOIN command
            case JOIN:
                /* code to join the server */
                break;
            
            case LEAVE:
                break;

            case NOTE:
                // create a node for message
                // add to the linked list of chat
                // send the linked list to the server
                break;

            case SHUTDOWN:
                // create new note for message
                // add the message out to the linked list
                // send to the server
                break;

            case SHUTDOWN_ALL:
                // create new note for message
                // add the message out to the linked list
                // send to the server
                break;
        }
    }

    return EXIT_SUCCESS;
}
