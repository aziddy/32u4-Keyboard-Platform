# AZK-MacroKeyboard-Platform
Macro Keyboard Platform that uses Serial and EEPROM to configure a keyboard instead of flashing firmware

This allows a macro keyboards (based on boards like 32u4) to be configured from platforms where toolchains are not avaiable and also allows layout configuration programs to be made with simple Serial commands


Only problem is that EEPROM on boards like 32u4 can only be written to finite amount of times. So sacrifices will be made on layout customization
