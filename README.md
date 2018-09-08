# GOTStateMachine
This library implements a light weight basic State Machine. The states are implemented as State functions in your sketch to keep implementation very flexible.

## STATE EXECUTION
State functions will be processed at the time interval specified when the State Machine is instaniated in milliSeconds (mS). It is important to implement the state machine as follows:
1. Instaniate the state machine with a cycle time in milliseconds (mS).
2. The setStartState() function should be called as the setup() function ends to initialise the State Machine parameters and enter the starting state. 
3. The execute() function should be called in the loop() function. State functions will only be executed when the set time interval is complete.

## STATE FUNCTIONS
State functions should be implemented as follows:
1. State functions should first implement the required logic for the state.
2. Following the State logic any required transitions should be implemented. 
3. Where code is required to execute once when entering a new state, the isFirstTime function can be called in the State function. The check will return a boolean true for the first execution of a state.

## TRANSITIONS
Where multiple transitions need to be implemented in a State function, the following should be considered:
1. Consideration should be given to the priority of transitions with the highest priority transition being processed first. 
2. The transition to a new state is completed by calling the changeState function and passing the actual State function name. 
3. Following a changeState a return should be included to end the State function.
4. Where a transition is related to a period period the state has been active the function isDelayComplete(delayPeriod) can be called. The function will return a boolean true if the delay period is completed. delayPeriod should be specified in milliseconds (mS).
5. The State Machine will stay in the same state if changeState is not called.

