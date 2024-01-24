import RPi.GPIO as GPIO
import json
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)  # Use Broadcom pin numbering
pin_number = 17  # Replace with your desired GPIO pin


GPIO.setup(pin_number, GPIO.IN)

if GPIO.input(pin_number) == GPIO.HIGH:
    print(json.dumps({'status' : 'off'}))

else:
    print(json.dumps({'status' : 'off'}))
