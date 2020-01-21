Includes:
* Added STM32CubIDE files
* Fix for spindle enable
* Fix for stepper_delay > 3.5us
* More segments per line
* More planner stages
* Option for 64k or 128k eeprom (C8 vs CB parts - many C8 parts actually have 128k, some don't.  If yours does not, you need to use teh 64k option to properly save settings.
 
***
Important Options
  * $50=1 -> Enable spindle output, normal mode (0=off, 2=invert)
  * $40=10000 -> Use 10khz base frequency for PWM
***



# grbl32
***
Please refer to [gnea/grbl](https://github.com/gnea/grbl) for the core GRBL codes. Check the [grbl32 WIKI page](https://github.com/thomast777/grbl32/wiki) for more information 
***

