/*
 *
 *
  task-schedule.h

	Implements a very simple task scheduler, based on input of a count of milliseconds

  Copyright (c) 2020 Mike Pittelko

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/



#ifndef __task_schedule_h
#define __task_schedule_h

#include "stm32utilities.h"


/* Prototypes for tasks
 *
 * There may be at most one function called for each time slot. The function you
 * define can call as many other functions as you like, but be cognizant of the
 * amount of time consumed by each.  For example: calling a functions that takes
 * 32ms to execute every 32ms will not leave any time for the 2ms, 4ms, 8ms, 16ms
 * tasks to execute without causing time to "slip" and tasks *skipped* the next time
 * the scheduler runs to catch up with the time pattern.
 *
 * On a given slot, will call the maximum time, then each match in descending order,
 * For example, at 16ms: the 16ms slot, the 8ms slot, the 4ms slot, and 2ms slot will
 * be called in that order.
 *
 *

void Task2ms(void) { };			// Called every 2ms
void Task4ms(void) { };			// Called every 4ms
void Task8ms(void) { };			// Called every 8ms
void Task16ms(void) { };		// Called every 16ms
void Task32ms(void) { };		// Called every 32ms
void Task64ms(void) { };		// Called every 64ms
void Task128ms(void) { };		// Called every 128ms
void Task256ms(void) { };		// Called every 256ms
void Task512ms(void) { };		// Called every 512ms
void Task1024ms(void) { };		// Called every 1.024s
void Task2048ms(void) { };		// Called every 2.048s
void Task4096ms(void) { };		// Called every 4.096s
void Task8192ms(void) { };		// Called every 8.192s
void Task16384ms(void) { };		// Called every 16.384s
void Task32768ms(void) { };		// Called every 32.768s
void Task65536ms(void) { };		// Called every 65.536s, About 1 minute
void Task131072ms(void) { };	// Called every 131.072s, About 2 minutes
void Task262144ms(void) { };	// Called every 262.144s, About 4 minutes
void Task528288ms(void) { };	// Called every 524.288s, About 9 minutes
void Task1056576ms(void) { };	// Called every 1056.576s, About 17 minutes
void Task2113152ms(void) { };	// Called every 2113.152s, About 35 minutes
void Task4226304ms(void) { };	// Called every 4226.304s, About 70 minutes
void Task8452608ms(void) { };	// Called every 8452.608s, About 140 minutes, About 2.3 hours
void Task16905216ms(void) { };	// Called every 16905.216s, About 281 minutes, About 4.7 hours
void Task33810432ms(void) { };	// Called every 33810.432s, About 563 minutes, About 9.4 hours
void Task67620864ms(void) { };	// Called every 67620.864s, About 1127 minutes, About 18.8 hours
void Task135241728ms(void) { };	// Called every 135241.728s, About 2254 minutes, About 37.6 hours

*/


// For each definition of a task, install your function pointer
// #define EXAMPLE_TASK_DEFINE (Task2ms) // call void Task2ms(void); every 2ms
// #define EXAMPLE_TASK_NOT_USED (0)   // Unused task slots MUST BE ZERO
#define TASK_2MS 		 (0)
#define TASK_4MS 		 (0)
#define TASK_8MS 		 (0)
#define TASK_16MS 		 (0)
#define TASK_32MS 		 (0)
#define TASK_64MS 		 (0)
#define TASK_128MS 		 (0)
#define TASK_2562MS 	 (0)
#define TASK_512MS 		 (0)
#define TASK_1024MS 	 (0)
#define TASK_2048MS 	 (0)
#define TASK_4096MS 	 (0)
#define TASK_8192MS 	 (0)
#define TASK_16384MS 	 (0)
#define TASK_32768MS 	 (0)
#define TASK_65536MS 	 (0)
#define TASK_131072MS 	 (0)
#define TASK_262144MS 	 (0)
#define TASK_528288MS 	 (0)
#define TASK_1056576MS 	 (0)
#define TASK_2113152MS 	 (0)
#define TASK_4226304MS 	 (0)
#define TASK_8452608MS 	 (0)
#define TASK_16905216MS  (0)
#define TASK_33810432MS  (0)
#define TASK_67620864MS  (0)
#define TASK_135241728MS (0)


// Given time in ms, call tasks on powers of 2 ms (2,4,8,16,32,64,128,256,512,1024,2048,4096...)
// On a given slot, will call the maximum time, then in descending order,
// For example, at 16ms, the 16ms slot, the 8ms slot, the 4ms slot, and 2ms slot will be called in
// that order.
void TasksOnPowerOfTwo(uint32_t TimeMs);

// From the LSB, count the number of zero's using black magic.
uint16_t CountZerosFromLSB(uint32_t v);



#endif // __task_schedule_h
