import re
import osWORDS = ["I","WANT","MY","BEER"]def isValid(text):
return bool(re.search(r'\bi want my beer\b',text,re.IGNORECASE))def handle(text,mic,profile):
os.system("sudo /home/pi/Desktop/interrupt")
message="I'm coming"
mic.say(message)
