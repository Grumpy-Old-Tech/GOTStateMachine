#include <GOTStateMachine.h>

#define   LED_PIN   13

//***** State Machine *****
GOTStateMachine stateMachine(50); // execute every 50 milliseconds

// States
void ledOn();
void ledOff();

void setup() {

  pinMode(LED_PIN, OUTPUT);
  
  stateMachine.setStartState(ledOff); // Initialise state machine
}

void loop() {
  
  stateMachine.execute();             // process the states as required
}


//***** States *****

void ledOff() {

  // State logic
  digitalWrite(LED_PIN, LOW);

  // Transitions
  if (stateMachine.isDelayComplete(1000)) {

    stateMachine.changeState(ledOn);
    return;
  }
}

void ledOn() {

  // State logic
  digitalWrite(LED_PIN, HIGH);

  // Transitions
  if (stateMachine.isDelayComplete(1000)) {

    stateMachine.changeState(ledOff);
    return;
  }
}
