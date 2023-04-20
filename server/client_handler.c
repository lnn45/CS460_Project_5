#include "client_handler.h"

/*
Name: handle_client
Process: handle client's request in seperated thread
Function Parameters/Input: arguments having client socket
Function Parameters/Output: None
Function Output/Device: None
Function Output/Return: None
Dependencies: None
*/
void* handle_client(void* arg)
{
    int client_socket = *((int*)arg);   // the socket connected to the client
    Message *input;
    char messageFromClient[ MAX_STR_LEN ];

    while( input->type != LEAVE || input->type != SHUTDOWN )
    {
        read(client_socket, input, sizeof( Message ));

        switch (input->type)
        {
            case NOTE:
                strcpy( messageFromClient, input->content )
                break;
            
            case SHUTDOWN_ALL:
                strcpy( messageFromClient, "SHUTDOWN ALL" );
                input->type = LEAVE;
                break;
        }

        if( input->type == NOTE )
        {
            sendMessage( input );
        }

    }


    // cleanup
    if ( input->type != LEAVE || input->type != SHUTDOWN && close(client_socket) == -1 ) {
        perror("Error closing socket");
        exit(EXIT_FAILURE);
    } else {
        printf("Closed socket to client, exit");
    }
    
    pthread_exit(NULL);
}
