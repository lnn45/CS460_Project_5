#include "main.h"

int main(int argc, char** argv) {
    int server_socket;                // descriptor of server socket
    struct sockaddr_in server_address; // for naming the server's listening socket
    pthread_t client_threads[NUM_CONNECTIONS];
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
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) != 0) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    printf("SUCCESS Binding Socket\n");
    
    // listen for client connections (pending connections get put into a queue)
    if (listen(server_socket, NUM_CONNECTIONS) != 0) {
        perror("Error listening on socket");
        exit(EXIT_FAILURE);
    }

    printf("SUCCESS Listening Client\n");
    
    // server loop
    while (TRUE) {
        
        // accept connection to client
        int client_socket = accept(server_socket, NULL, NULL);
        printf("\nServer with PID %d: accepted client\n", getpid());

        // create thread to handle the client's request
        // note that this is a naive approach, i.e. there are race conditions
        // for now this is okay, assuming low load
        if (client_index < NUM_CONNECTIONS)
        {
            if (pthread_create(&client_threads[ client_index ], NULL, handle_client, (void*)&client_socket) != 0) {
                perror("Error creating thread");
                exit(EXIT_FAILURE);
            }

            client_index++;
            
            // detach the thread so that we don't have to wait (join) with it to reclaim memory.
            // memory will be reclaimed when the thread finishes.
            if (pthread_detach(client_threads[ client_index ]) != 0) {
                perror("Error detaching thread");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            printf("\nROOM IS FULL\n");
        }
        
    }
}
