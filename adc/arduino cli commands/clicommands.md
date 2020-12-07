# arduino-cli commands

## arduino-cli compile

arduino-cli compile  -b arduino:avr:mega 

# arduino-cli upload

arduino-cli  upload -b arduino:avr:mega --port /dev/ttyACM1


## To open serial monitor

`minicom -D /dev/ttyACM0  -b 9600`





# git bash commands

## command to stage and commit

 git commit -am " commit message"


 # git remote init

##  …or create a new repository on the command line


echo "# python-text-to-voice" >> README.md
git init
git add README.md
git commit -m "first commit"
git branch -M main
git remote add origin https://github.com/richu101/python-text-to-voice.git
git push -u origin main
                
 ## …or push an existing repository from the command line

git remote add origin https://github.com/richu101/python-text-to-voice.git
git branch -M main
git push -u origin main