# Beerrino
 Hi everyone! This is my first real project here on GitHub!
 With this project I won a contest with the italian blog "Elettronica OpenSource"!
 Here's the article: http://it.emcelettronica.com/berrino-il-robot-portabirra#comments
 
 They gifted me an Infineon MotorShield and they sent my article to Infineon Technologies!
 So what is Beerrino? Well, let's take this from the beginning:
 Berrino is a robot which can understand your vocal command, came to you and finally open the can of beer that it carries on!
 The name is a pun mixing together the words Arduino, Raspberry and Beer. Arduino is the platform i used for make it moves 
 (controls steppermotors, brush motor, ultrasound sensor,), Raspberry Pi is the platform i used for controlling his movements
 and for undersanting voice commands ( done with an opensource vocal assistant called "Jasper" https://jasperproject.github.io/)
 
 #How it works
 When you say "Beerrino" the vocal assistan start listening for a command. After that, if you say "I want my beer", the vocal
 assistant on the Raspberry Pi execute the script "interrupt.c" which give a signal to Arduino. Arduino makes the robot moves while
 there aren't obstacle on his track. When the robot arrives in front of an obstacle ( it's better if this obstacle is your feet)
 Arduino, using the stepper motors, begin to open the can that the robot carries, then turn the robotic arm to give it to you.
 And that's it! Thanks for reading and I hope you enjoyed it!
 
