#include "Arduino.h"
#include "hithwen/statemachine/eepromstatemachine.h"
#include "hithwen/button/button.h"
#include "hithwen/led/led.h"
#include <LiquidCrystal.h>


StateMachine machine(3, 3);
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
LED led = LED(13);                 //initialize the lcd LED


void hello() {
    lcd.setCursor(0, 0);
    lcd.print("hello, world!");
}

void off() {
    lcd.noDisplay();
    led.off();
}
void counting() {
    lcd.setCursor(0, 1);
    // print the number of seconds since reset:
    lcd.print(millis()/1000);
}

Button button = Button(8,PULLUP); //initialize the button (wire between pin 12 and ground)

bool button_pressed() {
    bool pressed = button.uniquePress();
    if (pressed) {
        lcd.clear();
    }
    return pressed;
}


bool one2two() {
    bool pressed = button_pressed();
    if (pressed) {
        lcd.display();
        led.on();
        lcd.print("Counting!");
    }
    return pressed;
}


void setup() {
	Serial.begin(9600);
    lcd.begin(16, 2);
    led.on();
	machine.add_transition(0, 1, &button_pressed);
	machine.add_transition(1, 2, &one2two);
	machine.add_transition(2, 0, &button_pressed);
    machine.add_state_function(0, &hello);
    machine.add_state_function(1, &off);
    machine.add_state_function(2, &counting);
}

void loop() {
    int oldstate = machine.current_state();
    int nustate = machine.loop();
}
