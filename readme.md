State Machine [![Build Status](https://travis-ci.org/hithwen/statemachine.svg?branch=master)](https://travis-ci.org/hithwen/statemachine)
=============
Simple state machine library.
It represents a [Deterministic automaton](http://en.wikipedia.org/wiki/Deterministic_automaton).
In case two or more transitions apply first one found will be the one applied.


The machine is initialized with the number of states and number of transitions it needs.

You can optionally define a `state function` for each state, that will be called before checking state changes.

Then you need to specify each transition. A transition has an origin, a destny and a transition function. Transition functions do not receive parameteres so they must obtain their required info from global variables, input sources etc. If a transition function returns true then the estate is changed to destiny.

You can read about it's differences with the Arduino Playground one in this [blog post](http://web.biicode.com/blog/arduino-day-project-persistent-state-machine).

EEPROMState Machine
===================
It's exactly the same as State machine but it persists the state in Arduino EEPROM in `eeprom_position`.
You can change eeprom position when declaring a EEPROMState machine to avoid colliding with other code that uses EEPROM.

<pre><code>
EEPROMStateMachine machine(3, 3);
machine.eeprom_position = 100;
machine.reset();
</code></pre>

Flash your sketch with machine.reset() in the setup to clear that memory position in first run.
Then reflash it removing that line or the machine will reset each time you restart your arduino;

Examples
========
You can see a few examples in the examples folder.
The easiest one is the serialexample that just prints status update in the serial port.
Then you can have a look at ledexample that uses state machine to control a led in the same way as the [Playground example](http://web.biicode.com/blog/arduino-day-project-persistent-state-machine).
Last you can see lcd example (including schematic) that makes a more advanced use of transition functions to emulate enter and exit functions.
