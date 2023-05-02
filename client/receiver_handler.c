#include "receiver_handler.h"

void *handle_receiver( void *arg )
{
    int client_socket = *((int*)arg);

    char message[2048] = {};

    while( true )
    {
        int receiveFromServer = recv( client_socket, message, 2048, 0 );

        if( receiveFromServer > 0 )
        {
            if( strcmp( message, "SHUTDOWN ALL") == 0 )
            {
                setStopFlag(2);
                break;
            }
            {
                printf( "%s", message );

                printf( "%s", "> " );
                fflush(stdout);
            }
        }
        else if( receiveFromServer == 0 )
        {
            break;
        }
        
        memset( message, 0, sizeof(message) );
    }
}