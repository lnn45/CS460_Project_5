//Protect from multiple compiling
#ifndef sender_handler_h
#define sender_handler_h

//headers
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "message.h"
#include "chat_node.h"

//function prototypes
bool handler_sender(Message *messageFromCient);


#endif //SENDER_HANDLER_H