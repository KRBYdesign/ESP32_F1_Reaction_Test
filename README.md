# F1 Reaction Tester

> Esp32
> Basic circuit materials

Created a simulated race start, complete with working race-start lights.

The lights turn on and wait a short period before going out. The first one illuminates, followed by each led in sequence. Once the minimum duration of time has elapsed, as mandated by the FIA, a random delay is applied before the lights go out. This delay is not to exceed more than 3 seconds after the 5th light in the sequence has illuminated.

### Todo:

- Turn this into a reaction test. Catch a user's input and record how long it took them to react and "get off the line."
- Create loop of the GPIO pins to make accessing them easier.
- OOP the LEDs? idk you can make a little race sim outta this too maybe