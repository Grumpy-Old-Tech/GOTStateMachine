//
//    GOTStateMachine.h
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

#ifndef GOTSTATEMACHINE_H
#define GOTSTATEMACHINE_H

#include "Arduino.h"

//#define   STATE_PROCESSING_FREQUENCY   50 // every xxx milliseconds

typedef void (*FUNC_PTR)(); // Funtion pointer type

class GOTStateMachine
{
  public:
    GOTStateMachine(unsigned long processTime);         // Instantiate and set to process current state every processTime - specify in mS
    
    void setStartState(FUNC_PTR newState);              // Call last thing in Setup function
    void changeState(FUNC_PTR newState);                // Change to new state
    void execute();                                     // Process the current state if required
    bool isDelayComplete(unsigned long delayPeriod);    // Check if been in state longer that delayPeriod - specify in mS
    bool isFirstTime();                                 // Check if first time state is processed

  private:
    void (*currentState)();
    unsigned long   executeTime;
    unsigned long   lastStateProcessedTime;
    unsigned long   delayStartTime;
    bool            alreadyProcessed;
    bool            changedState;
};

#endif
