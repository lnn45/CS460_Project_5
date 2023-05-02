#include "main.h"

int main(int argc, char** argv) {
    int server_socket;                // descriptor of server socket
    struct sockaddr_in server_address; // for naming the server's listening socket
    struct sockaddr_in client_address;
    pthread_t client_thread;
    int client_index = 0;

    // sent when client disconnected
    signal(SIGPIPE, SIG_IGN);
    
    // create unnamed network socket for server to listen on
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }
    
    // name the socket (making sure the correct network byte ordering is observed)
    server_address.sin_family      = AF_INET;           // accept IP addresses
    server_address.sin_addr.s_addr = htonl(INADDR_ANY); // accept clients on any interface
    server_address.sin_port        = htons(PORT);       // port to listen on

    // binding unnamed socket to a particular port
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) != 0)
    {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }
    
    // listen for client connections (pending connections get put into a queue)
    if (listen(server_socket, MAX_CONNECTIONS) != 0)
    {
        perror("Error listening on socket");
        exit(EXIT_FAILURE);
    }

    printf("\nWELCOME TO CHAT SERVER\n");
    
    // server loop
    while ( TRUE ) {
        socklen_t client_address_len = sizeof(client_address);

        // accept connection to client
        int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len );

        // create thread to handle the client's request
        // note that this is a naive approach, i.e. there are race conditions
        // for now this is okay, assuming low load
        if ( client_index + 1 == MAX_CONNECTIONS )
        {
            printf("Max clients. Rejected");
            close(client_socket);
        }
        
        Chat_Node *new_client = (Chat_Node *)malloc( sizeof( Chat_Node ) );
        new_client->address = client_address;
        new_client->client_socket = client_socket;
        new_client->client_id = client_index++;

        addElementToList( new_client );

        if (pthread_create(&client_thread, NULL, &handle_client, (void*)new_client) != 0) {
            perror("Error creating thread");
            exit(EXIT_FAILURE);
        }

        sleep(1);        

        if(shutdownServerFlag)
        {

            printf("\nServer Shutdown\n");
            break;
        }
    }

    return EXIT_SUCCESS;
}
