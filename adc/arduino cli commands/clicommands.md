# open serial monitor

minicom -D /dev/ttyACM0  -b 9600

# arduino-cli compile

arduino-cli compile  -b arduino:avr:mega 

# arduino-cli upload

arduino-cli  upload -b arduino:avr:mega --port /dev/ttyACM1




# git bash commands

## command to stage and commit

 git commit -am " commit message"