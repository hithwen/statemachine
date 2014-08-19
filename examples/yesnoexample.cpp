#include "Arduino.h"
#include "hithwen/statemachine/statemachine.h"

char input;

StateMachine machine(3, 2);
bool char_is_y() {
	return input == 'y';
}

bool char_is_n() {
	return input == 'n';
}

void status_0() {
    Serial.println(F("Do you like chocolate?"));
}

void status_1() {
    Serial.println(F("Eat chocolate!"));
}

void status_2() {
    Serial.println(F("Don't eat chocolate!"));
}

void setup() {
	Serial.begin(9600);
    Serial.println(F("Welcome to my decision tree!"));
    

	//machine.reset();
	machine.add_transition(0, 1, &char_is_y);
	machine.add_transition(0, 2, &char_is_n);
    
    machine.add_state_function(0, &status_0);
    machine.add_state_function(1, &status_1);
    machine.add_state_function(2, &status_2);
    machine.loop();
}

void loop() {
	//checking data has been sent
	if (Serial.available() > 0) {
		char msg = Serial.read(); //read a message
        input = msg;
        int nustate = machine.loop();
        input = '\0';
    }
}