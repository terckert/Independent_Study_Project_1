#ifndef _HC_06_H
#define _HC_06_H

#include "mbed.h"
#include "UnbufferedSerial.h"
#include "mbed_retarget.h"




class HC_06 {

private: 

    UnbufferedSerial bt;
    char buffer[10][64];
    ssize_t ohead, otail, ihead;


public:
    HC_06(PinName tx, PinName rx, uint32_t baud);
    bool data_ready();
    void* receive_packet();
    ssize_t send_packet(char*, ssize_t);

private:
    void on_rx_interrupt();


};


#endif  // _HC_06_H