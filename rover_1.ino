/**
 * @file rover_1.ino
 *
 * @brief rover main entry point
 *
 * @author Gustavo Monardez
 *
 */

#include <nRF24L01.h>
#include <RF24.h>
#include "DataIn.h"

// receiver
RF24 receiver(10, 9); // CE, CSN
const uint64_t receiver_address = 0x0000000001;

// Incoming data
DataIn data_in;


// function prototypes
void receiver_init();

void setup() {
    Serial.begin(9600);
    Serial.println("Initialization started...");
    receiver_init();
    Serial.println("Initialization complete!");
    Serial.print("sizeof(data_in): ");
  Serial.println(sizeof(data_in));
}

void loop() {
    if (receiver.available()) {
        receiver.read(&data_in, sizeof(data_in));
        Serial.print("j2-left: "); Serial.println(data_in.j2.left);
        Serial.print("j2-right: "); Serial.println(data_in.j2.right);
        Serial.print("j2-down: "); Serial.println(data_in.j2.down);
        Serial.print("j2-up: "); Serial.println(data_in.j2.up);
        delay(1000);
    }
}

void receiver_init() {
    receiver.begin();
    receiver.openReadingPipe(0, receiver_address);
    receiver.setPALevel(RF24_PA_MIN);
    receiver.startListening();
    Serial.println("Receiver initialization complete!");
}
