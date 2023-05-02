//Protect from multiple compiling
#ifndef RECEIVER_HANDLER_H
#define RECEIVER_HANDLER_H

//headers
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/socket.h>
#include <string.h>

#include "sender_handler.h"

//function prototypes
void *handle_receiver(void *arg);

#endif //RECEIVER_HANDLER_H