#include "HC_06.h"
#include "mbed_retarget.h"



HC_06::HC_06(PinName tx, PinName rx, uint32_t baud)
: bt(tx, rx, baud), ohead(0), otail(0), ihead(0) {
    bt.attach(callback(this, &HC_06::on_rx_interrupt), SerialBase::RxIrq);
}



void 
HC_06::on_rx_interrupt() {
    if (bt.read(&buffer[ohead][ihead], 1)) {
        if (((ihead + 1) % 64) == 0){
            ohead = (ohead + 1) % 10;
            ihead = 0;
        } else {
            ihead++;
        }
    }
}

bool 
HC_06::data_ready() {
    return ohead != otail;
}

void*
HC_06::receive_packet() {
    if (!data_ready()) return nullptr;
    ssize_t curr = otail;
    otail = (otail + 1) % 10;
    return buffer[curr];
}

ssize_t
HC_06::send_packet(char *pkt, ssize_t sz) {
    for (int i = 0; i < sz; i++)
        bt.write(&pkt[i], 1);
    return sz;
    // return bt.write(pkt, 128);
}