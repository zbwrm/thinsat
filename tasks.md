# Tasks
## TODO
times might be way too long, depending on ATmega power consumption

## NOTES
basically just using RTOS to ensure that the melt wires are activated when I want
also to get experience with RTOS

the clock is a DS3231, has an error of about .25s a day

### Task 1 (determine current light level)
priority:     
conditions:   none
info. needed: photocell data
description:  take a reading from the photodiodes and calculate if it's light or dark
outputs:      change the light/dark value, send a 2-bit event flag indicating its updated and whether it's light/dark

### Task 2 (determine current time)
priority:     
conditions:   should happen a lot
info. needed: RTC data
description:  update the time estimate using data from the RTC
outputs:      mutex locks global time variable, updates it, mutex unlocks

### Task 3 (determine current location)
priority:     
conditions:   needs semaphore for light/dark value
info. needed: light/dark, orbit reference
description:  determine where satellite currently is (might need to break this up?)
outputs:      change the where am i? value, send a semaphore indicating it's updated

### Task 4 (determine planned location)
priority:     
conditions:   unsure
info. needed: needs current time from RTC
description:  take a reading from the photodiodes and calculate if it's light or dark
outputs:      change the light/dark value, send a semaphore indicating it's updated

## Pseudocode
// task 1
int light_values = 4[]
for photodiode:
    add photodiode.getValue() to light_values
avg_value = average(light_values)
if avg_value > 0.5: // or whatever; needs testing
    send light_value semaphore