#include "maindefs.h"
#include <stdio.h>
#include "messages.h"
#include "timer1_thread.h"

void init_timer1_lthread(timer1_thread_struct *tptr) {
    tptr->msgcount = 0;
}

// This is a "logical" thread that processes messages from TIMER1
// It is not a "real" thread because there is only the single main thread
// of execution on the PIC because we are not using an RTOS.

int timer1_lthread(timer1_thread_struct *tptr, int msgtype, int length, unsigned char *msgbuffer) {

    msgbuffer[0] = 0x03;
    msgbuffer[1] = 0x0E;
    msgbuffer[2] = 0x0A;
    msgbuffer[3] = 0x0C;
    ToMainLow_sendmsg(3, MSG_ADC_DATA, msgbuffer );
}