#include "main.h"

/* CLIENT - MAIN FUNCTION */
int main()
{
    // initialize variables
    char* properties_file = "server.properties";
    Properties* properties;
    char* serverAdd;
    char* portNum;
    char* clientName;
    int port, lenOfCommand;
    char clientCommand[ 32 ];
    char firstCommand[ 32 ] = {};
    char secondCommand[ 32 ] = {};
    int client_socket;
    struct sockaddr_in client_address;

/*    int client_socket;
    struct sockaddr_in client_address;*/

    // get input from properties file
    properties = property_read_properties( properties_file );
    clientName = property_get_property( properties, CLIENT_NAME );
    serverAdd = property_get_property( properties, SERVER_LINE );
    portNum = property_get_property( properties, PORT_LINE );
    port = atoi( portNum );

    printf( "==== CLIENT INFORMATION ====\n" );
    printf( "== Client's Name    : %s\n", clientName );
    printf( "== Server Connected : %s\n", serverAdd );
    printf( "== Port Connected   : %d\n", port );
    printf( "============================\n" );

    fgets( clientCommand, 32, stdin );

    while( strcmp( clientCommand, "SHUTDOWN" ) != 0 )
    {
        lenOfCommand = strlen( clientCommand );

        if( lenOfCommand >= 4 )
        {
            /* modifyString( clientCommand, lenOfCommand );

            getSubString( firstCommand, clientCommand, 0, 3 );

            printf("%s\n", firstCommand);
            
            if( strcmp( firstCommand, "JOIN" ) == 0 && lenOfCommand > 4 )
            {
                getSubString( secondCommand, clientCommand, 5, lenOfCommand - 1 );

                port = atoi(secondCommand);

                printf("%s\n", secondCommand);
            } */

            client_address.sin_family = AF_INET;
            client_address.sin_addr.s_addr = inet_addr(serverAdd);
            client_address.sin_port = htons(port);

            client_socket = socket(AF_INET, SOCK_STREAM, 0);

            if (connect(client_socket, (struct sockaddr *)&client_address, sizeof(client_address)) == -1)
            {
                perror("Error connecting to server!\n");
                exit(EXIT_FAILURE);
            }

            send(client_socket, clientName, 32, 0);

            printf("WELCOME TO CHAT ROOM\n");

            // initialize thread for sender and receiver
            pthread_t sendThread, receiveThread;

            Client *client_info = (Client *)malloc( sizeof( Client ) );
            strcpy( client_info->name, clientName );
            client_info->socket = client_socket;

            // call thread for sender
            if (pthread_create( &sendThread, NULL, handle_sender, (void *)client_info ) != 0)
            {
                perror("Error sending thread");
                exit(EXIT_FAILURE);
            }

            // call thread for receiver
            if (pthread_create(&receiveThread, NULL, handle_receiver, (void*)&client_socket) != 0)
            {
                perror("Error receiveing thread");
                exit(EXIT_FAILURE);
            }

            while( true )
            {
                if( stopFlag )
                {
                    printf("\nBye\n");
                    strcpy( clientCommand, "SHUTDOWN" );
                    break;
                }
                else if( leaveFlag == 1 )
                {
                    printf("\nLeave the room\n");
                    strcpy( clientCommand, "LEAVE" );
                    leaveFlag = 0;
                    break;
                }
            }

            close(client_socket);
        }

        if( strcmp( clientCommand, "LEAVE" ) == 0 )
        {
            fgets( clientCommand, 32, stdin );
        }
    }

    // return SUCCESS
    return EXIT_SUCCESS;
}
