//Protect from multiple compiling
#ifndef receiver_handler_h
#define receiver_handler_h

//headers
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "message.h"
#include "chat_node.h"

//function prototypes
void main();
bool handle_messages(Message * received_message);

#endif //RECEIVER_HANDLER_H