// Header
#include "chat_node.h"

Chat_Node *listOfClients[ 5 ];

pthread_mutex_t client_lock = PTHREAD_MUTEX_INITIALIZER;

void addElementToList( Chat_Node *clientToAdd )
{
	int index= 0 ;
	bool breakFlag = false;

	pthread_mutex_lock( &client_lock );

	while( breakFlag == false && index < 5 )
	{
		if( listOfClients[ index ] == NULL )
		{
			listOfClients[ index ] = clientToAdd;

			breakFlag = true;
		}

		index++;
	}

	pthread_mutex_unlock( &client_lock );
}

void removeElementFromList( int clientIDRemove )
{
	int index = 0;
	bool breakFlag = false;

	pthread_mutex_lock( &client_lock );

	while( breakFlag == false && index < 5 )
	{
		if( listOfClients[ index ] != NULL )
		{
			if( listOfClients[ index ]->client_id == clientIDRemove )
			{
				listOfClients[ index ] = NULL;

				breakFlag = true;
			}
		}

		index++;
	}

	pthread_mutex_unlock( &client_lock );
}
