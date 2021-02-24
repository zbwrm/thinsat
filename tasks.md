# Tasks
## TODO
times might be way too long, depending on ATmega power consumption

## NOTES
basically just using RTOS to ensure that the melt wires are activated when I want
also to get experience with RTOS

### activate melt wires
priority:     critical
conditions:   over specific location in MA, once a day for four days
info. needed: current time, dipole launch time estimate

### improve time estimate
priority:     c-2
conditions:   twice a minute? maybe?
info. needed: light/dark, time from RTC

### get time from RTC
priority:     c-1
conditions:   pretty often, maybe 4/min
info. needed: RTC data

### write data to SD || send data through downlink
priority:     c-3
conditions:   once a minute or something? depends on amount of storage SD card has || how often downlink wants data
info. needed: sensor data(?), current time

### check if light or dark
priority:     c-1
conditions:   pretty often, 4/min
info. needed: data from photodiodes

### take data from temp. sensors
unclear on this one