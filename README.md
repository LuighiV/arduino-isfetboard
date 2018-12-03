# Arduino library for ISFET Board

This library is used to read info from ISFET board PCB. This requires the ISFET board hardware which was developed in the *Instituto Nacional de Investigación y Capacitación de Telecomunicaciones* of the *Universidad Nacional de Ingeniería* (INICTEL-UNI), Lima, Perú.

It contains a main function to operate with it. However to operate with the board some preliminar steps are requiered:

## Preliminar Tasks
1. First of all, the board has to be assembled with all its components, which are the ISFET and NTC sensores to measure the pH and temperature.
2. Then, it should be powered with DC voltage, either with 5V or 3.3V.
3. It is recommended to calibrate the sensors before operation. Over all, considering that at different voltage levels, the response will be different. The procedure is explained in [Calibration](Calibration.md).

## Normal operation
After its calibration the device is ready to operate. So, after it is placed in the solution where it will measure the pH, the device is able to acquire data.

The ISFET board must be attached to the Arduino board. Then, you can test the device operation using the [IsfetBoard_librarytester](./examples/IsfetBoard_librarytester/IsfetBoard_librarytester.ino).

The most important parts are the device declaration and the reading process.

### Declaration
The library declaration has the following name:
```C++
#include "isfetboard.h"
```

The libary uses the **SoftwareSerial** library to serve as an interface with the Arduino. To declare it, the following instruction should be added.

```C++
#define RXPIN 10
#define TXPIN 11

IsfetBoard myboard(RXPIN,TXPIN);
```

It creates, internally, the SoftwareSerial object in the RXPIN and TXPIN, declared before which communicates via UART with the ISFET Board.


### Reading process
The main function to acquire the data is `readData()`, which internally iniatilizates the software serial port and read the information from it. After it, data is obtained and stored in internal variables `pHcomp` for compensated pH, `pH` for pH without compensation and `temperature` for temperature acquired from NTC sensor.

A model to obtain this data is depicted as following:

```C++
myboard.readData();
pHcomp = myboard.pHcomp;
pH = myboard.pH;
temperature = myboard.temperature;
```

Is important to highlight that, if there is no communication or if sensors are not connected, the resulting values in internal variables will be NAN.

