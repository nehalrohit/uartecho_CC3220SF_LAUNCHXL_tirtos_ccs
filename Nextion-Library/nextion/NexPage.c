#include <Nextion-Library/nextion/NexPage.h>
#include <Nextion-Library/util/Utilities.h>
#include <string.h>

uint8_t buffer[4];
extern char cmd[64];

uint8_t NexPage_show(struct NexObject *page)
{

  //  ClearString(buffer);
    memset(buffer,NULL, sizeof(buffer));
    if (!page->__name)
    {
        return 0;
    }

    ClearString(cmd);
    strcat(cmd, "page ");
    strcat(cmd, page->__name);
    sendCommand(cmd);
    return recvRetCommandFinished();
}



