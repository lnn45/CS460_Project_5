#include "sender_handler.h"

volatile sig_atomic_t stopFlag = 0;
int leaveFlag = 0;

void* handle_sender( void* arg )
{
    int client_socket = *((int*)arg);

    char message[ 2048 ] = {};
    char buffer[ 2048 + 32 ] = {};

    Client *client = (Client *)arg;

    while( true )
    {
        printf( "%s", "> " );
        fflush(stdout);

        fgets( message, 2048, stdin );
        modifyString( message, 2048 );

        if( strcmp( message, "SHUTDOWN" ) == 0 )
        {
            sprintf( buffer, "%s", message );
            send( client->socket, buffer, strlen(buffer), 0 );
            setStopFlag( 2 );
            break;
        }
        else if( strcmp( message, "LEAVE" ) == 0 )
        {
            sprintf( buffer, "%s", message );
            send( client->socket, buffer, strlen(buffer), 0 );
            setLeaveFlag();
            break;
        }
        else if( strcmp( message, "SHUTDOWN ALL" ) == 0 )
        {
            sprintf( buffer, "%s", message );
            send( client->socket, buffer, strlen(buffer), 0 );
            setStopFlag( 2 );
            break;
        }
        else
        {
            sprintf( buffer, "%s: %s\n", client->name, message );
            send(client->socket, buffer, strlen(buffer), 0);
        }

        bzero(message, 2048);
        bzero(buffer, 2048 + 32);
    }

    free( client );
}

void modifyString( char *message, int lenOfString )
{
    int index;

    for( index = 0; index < lenOfString; index++ )
    {
        if( message[ index ] == '\n' )
        {
            message[ index ] = '\0';
            break;
        }
    }
}

void setStopFlag( int sig )
{
    stopFlag = 1;
}

void setLeaveFlag()
{
    leaveFlag = 1;
}

/*
Name: getSubString
Process: captures sub string within larger string
         between 2 inclusive indices.
         returns empty string if either index is out of range,
         assumes enough memory in destination string
Function Input/Parameters: c-style source string (char *),
                          start and end indices (int)
Function Output/Parameters: c-style destination string (char *)
Function Output/Returned: none
Device Input/Keyword: none
Device Output/Monitor: none
Dependencies: getStringLength, malloc, copyString, free
*/
void getSubString( char *destStr, const char *sourceStr,
                            int startIndex, int endIndex )
{
 	// initialize function/variables

		// set length of source string
		   // function: getStringLength
		int sourceStrLen = strlen( sourceStr );

		// initialize the destination index to zero
		int destIndex = 0;

		// initialize source index to start index (parameter)
		int sourceIndex = startIndex;
		
		// create pointer for temp string
		char *tempStr;

	// check for indices within limits
	if( startIndex > 0 && startIndex <= endIndex
					&& endIndex < sourceStrLen )
	{
		// create temporary string
		   // function: malloc, copyString
		tempStr = (char *)malloc( sourceStrLen + 1 );
		strcpy( tempStr, sourceStr );

		// loop across requested substring (indices)
		while( sourceIndex <= endIndex )
		{
			// assign source character to destination element
			destStr[ destIndex ] = sourceStr[ sourceIndex ];

			// increment indices
			destIndex++; sourceIndex++;

			// set temporary end of destination string
			destStr[ destIndex ] = NULL_CHAR;
		}
		// end loop

		// return memory for temporary string
		   // function: free
		free( tempStr );
	}
}
