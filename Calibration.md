#ISFET board calibration

To calibrate the pH sensor used in the ISFET board, an special setup and a series of steps are required.

##Setup
It requires that the ISFET Board must be powered at the same voltage level at which it will operate. In addition to this, it must be established a communication via the UART protocol with a terminal (PC), using for example, an UART-USB adapter.

The sensors must be connected and you should have at least two buffers of fixed pH value (recommended of pH 4 and pH 7).

After it, you should power the board and open a serial terminal in the PC (ex. PuTTY). A welcome message must appear in the screen regarding the parameters for the ISFET board.

##Procedure

1. Clean the ISFET probe and place in the first pH buffer (ex. pH 4).

2. Wait for at least one minute and you can send several read commands `R 1`, to see if the measurement is steady. The optimal temperature is around 25°C.
3. Once it is steady, send the calibration command with the pH value. In this case it will be:
```
CAL TWO 4.0
```
After this, the message `I: Please, enter the next value`, must be prompted in the terminal console.

4. Clean the ISFET probe and place in the second pH buffer (ex. pH7).
5. Wait for at least one minute and you can send several read commands `R 1`, to see if the measurement is steady. The optimal temperature is around 25°C.

6. Once it is steady, send the calibration command with the pH value. In this case it will be:
```
CAL TWO 7.0
```
After this, the message `I: The newzcal value is ---, sensitivity is ---`, must be prompted in the terminal console, indicating the new calibration parameters and, finally, the message `I: Calibrated` must be issued.

An important condition to identify in this parameters is that if *sensitivity* is lower than 40.0 mVolt/pH, the calibration process was wrong or the ISFET probe must be replaced.
