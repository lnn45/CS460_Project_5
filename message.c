#include "message.h"

bool sendMessage( int socket_var, const char message[ MAX_STD_LEN ] )
{
    //Initialize variables

    //connects to server using property file info
    send( socket_var, message, sizeof(message) );

    //returns true for success, sets flag and returns false for errors
    return EXIT_SUCCESS
}


bool receiveMessage( Message* receive, int socket_var )
{
    char buffer[ MAX_STD_LEN ];

    //passes message on to receiver_handler recieve_message() function
    read( socket_var, buffer, sizeof(buffer) );

    receive = (Message *)malloc(sizeof(Message));

    strcpy(receive->content, buffer );

    return EXIT_SUCCESS;
}

