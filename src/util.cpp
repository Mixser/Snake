#include <cstdio>
#include "header/engine_common.h"


void PrintLog(const char * message, int type) 
{
    const char * label = NULL;
    switch(type) 
    {
        case ERROR_MESSAGE:   label = "Error"; 
                              break;
        case WARNING_MESSAGE: label = "Warning (not danger)";
                              break;
        case INFO_MESSAGE:    label = "Info";
                              break;
        default:              label = "Unknow message:";
    }
    
    fprintf(stderr, "%s: %s\n", label, message);        
}
