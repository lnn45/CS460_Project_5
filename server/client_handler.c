#include "client_handler.h"

volatile sig_atomic_t shutdownServerFlag = 0;

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
    char buffer[ 2048 ];
    char client_name[ 32 ];
    bool leaveFlag = false;

    Chat_Node *client = (Chat_Node *)arg;

    if( recv(client->client_socket, client_name, 32, 0 ) <= 0 ||
        strlen(client_name) < 2 ||
        strlen(client_name) >= 31 )
    {
        printf("Didn't enter the name.\n");

        leaveFlag = true;
    }
    else
    {
        strcpy( client->name, client_name );
        sprintf( buffer, "%s has joined\n", client->name );
        printf( "%s", buffer );
        sendMessage( client->client_id, buffer );
    }

    bzero(buffer, 2048);

    while( leaveFlag != true )
    {
        int messageFromClient = recv( client->client_socket, buffer, 2048, 0 );

        if( strcmp( buffer, "LEAVE" ) == 0 || strcmp( buffer, "SHUTDOWN" ) == 0 )
        {
            sprintf(buffer, "%s has left\n", client->name);
			printf("%s", buffer);
			sendMessage( client->client_id, buffer );
			leaveFlag = true;
        }
        else if( strcmp( buffer, "SHUTDOWN ALL" ) == 0 )
        {
            printf("SHUTDOWN ALL from %s", client->name );
            sprintf( buffer, "SHUTDOWN ALL" );
            sendMessage( client->client_id, buffer );
            setShutDownServer( 2 );
            leaveFlag = true;
        }
        else
        {
            if( strlen( buffer ) > 0 )
            {
                sendMessage( client->client_id, buffer );
                printf( "%s", buffer );
            }
        }
        
        bzero(buffer, 2048);
    }

    close( client->client_socket );
    removeElementFromList( client->client_id );
    free( client );

    pthread_detach( pthread_self() );

    return NULL;
}

void setShutDownServer( int sig )
{
    shutdownServerFlag = 1;
}
