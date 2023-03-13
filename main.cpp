#include "main.h"
#include "HC_06.h"
#include "ThisThread.h"

HC_06 bt(BT_TX_PIN, BT_RX_PIN, 9600);

DigitalInOut row1(LEDM_ROW1_PIN, PIN_OUTPUT, PullDown, 0);
DigitalInOut row2(LEDM_ROW2_PIN, PIN_OUTPUT, PullDown, 0);
DigitalInOut row3(LEDM_ROW3_PIN, PIN_OUTPUT, PullDown, 0);
DigitalInOut row4(LEDM_ROW4_PIN, PIN_OUTPUT, PullDown, 0);

DigitalInOut col1(LEDM_COL1_PIN, PIN_OUTPUT, PullUp, 1);
DigitalInOut col2(LEDM_COL2_PIN, PIN_OUTPUT, PullUp, 1);
DigitalInOut col3(LEDM_COL3_PIN, PIN_OUTPUT, PullUp, 1);
DigitalInOut col4(LEDM_COL4_PIN, PIN_OUTPUT, PullUp, 1);

uint8_t LED_array[16]{};
Thread led_thread;

void control_LED_array();

int main()
{

    // int count = 0;
    char* tester;
    ssize_t len;
    char test[65] = "helloworldhelloworldhelloworldhelloworldhelloworldhelloworldendz";

    // len = bt.send_packet(test, 64);
    // printf("test string len: %d", len);
    led_thread.start(control_LED_array);
    
    while (true) {

        // if (bt.data_ready()) {
        //     tester = (char*)bt.receive_packet();
        //     len = bt.send_packet(tester, 64);
        //     printf("%d: %s\n", len, tester);
        // }
        ThisThread::sleep_for(DELAY_TIME);
        for (int i = 0; i < 16; i++) {
            LED_array[i] = 1;
            ThisThread::sleep_for(DELAY_TIME);
        }
        for (int i = 0; i < 16; i++) {
            LED_array[i] = 0;
            ThisThread::sleep_for(DELAY_TIME);
        }
    
    }
}

void control_LED_array() {

    while (true) {
        // Set output drains for LED col 1:
        row1 = (LED_array[0])  ? 1 : 0;
        row2 = (LED_array[4])  ? 1 : 0;
        row3 = (LED_array[8])  ? 1 : 0;
        row4 = (LED_array[12]) ? 1 : 0;
        col1 = 1;
        ThisThread::sleep_for(COL_DELAY);
        col1 = 0;


        // Set output drains for LED col 2:
        row1 = (LED_array[1])  ? 1 : 0;
        row2 = (LED_array[5])  ? 1 : 0;
        row3 = (LED_array[9])  ? 1 : 0;
        row4 = (LED_array[13]) ? 1 : 0;
        col2 = 1;
        ThisThread::sleep_for(COL_DELAY);
        col2 = 0;

        // Set output drains for LED col 3:
        row1 = (LED_array[2])  ? 1 : 0;
        row2 = (LED_array[6])  ? 1 : 0;
        row3 = (LED_array[10]) ? 1 : 0;
        row4 = (LED_array[14]) ? 1 : 0;
        col3 = 1;
        ThisThread::sleep_for(COL_DELAY);
        col3 = 0;

        // Set output drains for LED col 4:
        row1 = (LED_array[3])  ? 1 : 0;
        row2 = (LED_array[7])  ? 1 : 0;
        row3 = (LED_array[11]) ? 1 : 0;
        row4 = (LED_array[15]) ? 1 : 0;
        col4 = 1;
        ThisThread::sleep_for(COL_DELAY);
        col4 = 0;
    }

}