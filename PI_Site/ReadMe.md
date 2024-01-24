# Embedded Project Pi Website that toggles light


1. Download the files and type in the terminal npm i
  1a. If you don't have node, install it.
2. You will need Python installed. I have Python 3.9.x
  2a. When you install Python, make sure you have PIP as a global variable, it makes running pip commands easier.
3. pip install GPIO (make sure this is on your Raspberry PI)
4. Configure your circuitry:
  4a. https://www.raspberrypi.com/documentation/computers/raspberry-pi.html
5. The simpliest form is setting up an LED with the signal pin (18) connected to the resistor 330 (ohm), the opposite end of the resistor connected to the anode on the LED, and the cathode connected to GND.
  5a. When you feel ready, you can connect this up to a relay, splice the lamp and follow the connection guidelines. 
  5b. https://www.circuitbasics.com/setting-up-a-5v-relay-on-the-arduino/ This can give a good idea. *** For my set up, I didn't use the resistor or the thermometer ***
6. See if it runs!

*** Tips: When you ssh into the Pi and the code is working, I highly recommend you set up the server to launch on boot. ***

7. Open up the rc.local file 
  7a. sudo vim /etc/rc.local 
  7b. ***before*** the "exit 0" clause make sure you put in:
    sudo cd /home/<pi>/<path to your folder>
    node index.js &
  7c. <pi> --> depends on what you name your pi, mine is named voltron
    cd /home/voltron/
  7d. <path to your folder> --> Mine is Documents/Pi_Site
    sudo cd /home/voltron/Documents/Pi_Site
    node index.js &
  7e. The '&' means let it run in the background.


