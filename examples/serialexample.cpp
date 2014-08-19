#include "Arduino.h"
#include "hithwen/statemachine/eepromstatemachine.h"

char input;

EEPROMStateMachine machine(3, 3);
bool char_is_a() {
	return input == 'a';
}

void initial_function() {
	Serial.println(F("Initial state!"));
}

void setup() {
	Serial.begin(9600);
	Serial.print(F("Enter 'a' to change state\n"));
	//machine.reset();
	machine.add_transition(0, 1, &char_is_a);
	machine.add_transition(1, 2, &char_is_a);
	machine.add_transition(2, 0, &char_is_a);
	machine.add_state_function(0, &initial_function);
}

void loop() {
	//checking data has been sent
	if (Serial.available() > 0) {
		char msg = Serial.read(); //read a message
		int oldstate = machine.current_state();
		input = msg;
		int nustate = machine.loop();
		if (oldstate != nustate) {
			Serial.print(oldstate);
			Serial.print(F(" -> "));
			Serial.println(nustate);
		}
	}
}