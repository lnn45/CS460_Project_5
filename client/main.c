#include "main.h"

/* CLIENT - MAIN FUNCTION */
int main()
{
    // initialize variables
    Properties* inputValue;
    char clientInput[MAX_STR_LEN];
    char serverAdd[MIN_STR_LEN];
    int portNum;

    int client_socket;
    struct sockaddr_in client_address;

    // get input from properties file
    inputValue = property_read_properties( INFO_FILE );
    serverAdd = property_get_properties( inputValue, SERVER_LINE );
    portNum = property_get_properties( inputValue, PORT_LINE );

    // client - server loop
  while( TRUE )
    {
        // read command from client
        scanf( "%[^\n]%*c", clientInput );

        // initialize thread for sender and receiver
        pthread_t sendThread, receiveThread;

        // call thread for sender
        if (pthread_create(&sendThread, NULL, handle_sender, (void*)&clientInput) != 0) {
            perror("Error creating thread");
            exit(EXIT_FAILURE);
        }
        
        // call thread for receiver
        if (pthread_create(&receiveThread, NULL, handle_receiver, (void*)&clientInput) != 0) {
            perror("Error creating thread");
            exit(EXIT_FAILURE);
        }

        // detach the thread so that we don't have to wait (join) with it to reclaim memory.
        // memory will be reclaimed when the thread finishes.
        if (pthread_detach(sendThread) != 0) {
            perror("Error detaching thread");
            exit(EXIT_FAILURE);
        }

        if (pthread_detach(receiveThread) != 0) {
            perror("Error detaching thread");
            exit(EXIT_FAILURE);
        }
        
    }

    // return SUCCESS
    return EXIT_SUCCESS;

}