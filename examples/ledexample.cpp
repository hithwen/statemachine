#include "Arduino.h"
#include "hithwen/statemachine/eepromstatemachine.h"
#include "hithwen/button/button.h"
#include "hithwen/led/led.h"


EEPROMStateMachine machine(4, 4);
LED led = LED(13);                 //initialize the LED

void ledOn() { led.on();}
void ledOff() {led.off();}
void ledFadeIn() {led.fadeIn(500);}
void ledFadeOut() { led.fadeOut(500); }

Button button = Button(12,PULLUP); //initialize the button (wire between pin 12 and ground)

bool button_pressed() {
    return button.uniquePress();
}

void setup() {
	Serial.begin(9600);
	machine.add_transition(0, 1, &button_pressed);
	machine.add_transition(1, 2, &button_pressed);
	machine.add_transition(2, 3, &button_pressed);
	machine.add_transition(3, 0, &button_pressed);
    machine.add_state_function(0, &ledOn);
    machine.add_state_function(1, &ledOff);
    machine.add_state_function(2, &ledFadeIn);
    machine.add_state_function(3, &ledFadeOut);

}

void loop() {
    int oldstate = machine.current_state();
    int nustate = machine.loop();
    if (oldstate != nustate) {
        Serial.print(oldstate);
        Serial.print(F(" -> "));
        Serial.println(nustate);
    }
}
