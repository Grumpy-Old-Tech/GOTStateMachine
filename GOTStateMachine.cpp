//
//    GOTStateMachine.cpp
//
//    MIT License
//
//    Copyright (c) Saturday 1st September 2018, Neville Kripp (Grumpy Old Tech)
//
//    Permission is hereby granted, free of charge, to any person obtaining a copy
//    of this software and associated documentation files (the "Software"), to deal
//    in the Software without restriction, including without limitation the rights
//    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//    copies of the Software, and to permit persons to whom the Software is
//    furnished to do so, subject to the following conditions:
//
//    The above copyright notice and this permission notice shall be included in all
//    copies or substantial portions of the Software.
//
//    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//    SOFTWARE.

#include "Arduino.h"
#include "GOTStateMachine.h"

// Instantiate and set to process current state every processTime - specify in mS
GOTStateMachine::GOTStateMachine(unsigned long processTime) {
  
  executeTime = processTime;
  lastStateProcessedTime = 0;
  delayStartTime = 0;
  alreadyProcessed = false;
}

// Call last thing in Setup function
void GOTStateMachine::setStartState(FUNC_PTR newState) {
  
  lastStateProcessedTime = millis();
  changeState(newState);
}

// Change to new state
void GOTStateMachine::changeState(FUNC_PTR newState) {

  currentState = newState;
  alreadyProcessed = false;
  changedState = true;
}

// Process the current state if required
void GOTStateMachine::execute() {
  
  changedState = false;
  unsigned long loopTime = millis();
  
  if ((loopTime - lastStateProcessedTime) > executeTime) {   // Time to process states

    if (!alreadyProcessed) {

      delayStartTime = loopTime;
    }
    
    currentState();
    
    lastStateProcessedTime = loopTime;
    if (!changedState) {
      alreadyProcessed = true;
    }
  }
}

// Check if been in state longer that delayPeriod - specify in mS
bool GOTStateMachine::isFirstTime() {

  if (!alreadyProcessed) {

    return true;
  }
  return false;
}

// Check if first time state is processed
bool GOTStateMachine::isDelayComplete(unsigned long delayPeriod) {

  unsigned long loopTime = millis();

  if ((loopTime - delayStartTime) > delayPeriod) {

    return true; 
  }
  return false;
}

