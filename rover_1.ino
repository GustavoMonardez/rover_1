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

// receiver
RF24 receiver(10, 9); // CE, CSN
const uint64_t receiver_address = 0x0000000001;


// function prototypes
void receiver_init();

void setup() {
    Serial.begin(9600);
    Serial.println("Initialization started...");
    receiver_init();
    Serial.println("Initialization complete!");
}

uint8_t text[32]; // remove after testing
void loop() {
    if (receiver.available()) {
        receiver.read(&text, sizeof(text));
        Serial.print("byte 1 (j1-left): "); Serial.println(text[0]);
    }
}

void receiver_init() {
    receiver.begin();
    receiver.openReadingPipe(0, receiver_address);
    receiver.setPALevel(RF24_PA_MIN);
    receiver.startListening();
    Serial.println("Receiver initialization complete!");
}
