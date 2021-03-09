# AZK-MacroKeyboard-Platform (Work in Progress)

Macro Keyboard Platform that allows for programmatically challenged consumers to configure their own keystroke combinations. Uses Serial and EEPROM to configure a keyboard instead of flashing firmware. 

This allows a macro keyboards (based on boards like 32u4) to have their keystroke combinations reconfigured from platforms where toolchains are not avaiable and also allows configuration programs to be made with simple Serial commands

Only problem is that EEPROM on boards like 32u4 can only be written to finite amount of times. So sacrifices will be made on layout customization

Four 8bit EEPROM spaces are allocated to each key to allow for shortcut combinations up to 4 keys



## Instructions -- making a new macro keyboard from scratch (Some Programming and Embedded Exp Required)
1. **Layout_initializer** - *Here we will define how many keys are used and intial keystroke combinations*<br>
2. **Core** - *Map Keys to Pins and loads main firmware onto your board*


## Programmatically Challenged Reconfigure
1. 
