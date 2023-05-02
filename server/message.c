#include "message.h"

void sendMessage( int client_id, char *message )
{
    int index = 0;
    bool breakFlag = false;

    pthread_mutex_lock( &client_lock );

	while( breakFlag == false && index < 5 )
    {
		if( listOfClients[ index ] )
        {
			if( listOfClients[ index ]->client_id != client_id )
            {
				if( write(listOfClients[ index ]->client_socket, message, strlen( message ) ) < 0){
					perror("ERROR: write to descriptor failed");
					breakFlag = true;
				}
			}
		}

        index++;
	}

	pthread_mutex_unlock( &client_lock );
}
