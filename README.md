# AZK-MacroKeyboard-Platform (Work in Progress)

Macro Keyboard Platform that allows for programmatically challenged consumers to configure their own keystroke combinations. Uses Serial and EEPROM to configure a keyboard instead of flashing firmware. 

This allows a macro keyboards (based on boards like 32u4) to have their keystroke combinations reconfigured from platforms where toolchains are not avaiable and also allows configuration programs to be made with simple Serial commands

Only problem is that EEPROM on boards like 32u4 can only be written to finite amount of times. So sacrifices will be made on layout customization

Four 8bit EEPROM spaces are allocated to each key to allow for shortcut combinations up to 4 keys

<br><br>

## Instructions -- making a new macro keyboard from scratch (Some Programming and Embedded Exp Required)
1. **Layout_initializer** - *Here we will define how many keys are used and intial keystroke combinations*<br>
2. **Core** - *Map Keys to Pins and loads main firmware onto your board*

<br><br>

## Programmatically Challenged Reconfigure
1. **processingGUIConfigurator** - *Consumers will run the this on their computer, giving them a GUI interface that communicates with the board over serial*<br>
2. **Any Serial Capable Program**


<br><br>

## EEPROM

***N*** - *number of keys*

| EEPROM Address  | Data           |
| --------------- | -------------  |
|  0              | Stores ***N*** |

For (***x*** = 0; ***x*** < ***N***; ***x***++)
| EEPROM Address  | Data           |
| --------------- | -------------  |
| 1+(***x***\*4)  | Stores Key ***x***'s 1st part of the key combination  |
| 2+(***x***\*4)  | Stores Key ***x***'s 2nd part of the key combination  |
| 3+(***x***\*4)  | Stores Key ***x***'s 3rd part of the key combination  |
| 4+(***x***\*4)  | Stores Key ***x***'s 4th part of the key combination  |
