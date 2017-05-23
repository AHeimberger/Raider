#!/usr/bin/env python2


import sys
import os
import time
import random
import datetime

print(sys.version)

appName = "App"
moduleTypes = ["Modul1", "Module2", "Module3"]
debugTypes = ["Debug", "Warning", "Critical", "Fatal"]
messages = [
"I am so blue I'm greener than purple.",
"I stepped on a Corn Flake, now I'm a Cereal Killer",
"Llamas eat sexy paper clips",
"Banana error.",
"Everyday a grape licks a friendly cow",
"On a scale from one to ten what is your favourite colour of the alphabet.",
"The sparkly lamp ate a pillow then punched Larry.",
"Look, a distraction!",
"Screw world peace, I want a pony",
"What do you think about the magical yellow unicorn who dances on the rainbow with a spoonful of blue cheese dressing?",
"I objectify orangutan mafia blue.",
"What in the name of singing alligators...?",
"My world is where everybody is a pony and we all eat rainbows and poop butterflies",
"If your canoe is stuck in a tree with the headlights on, how many pancakes does it take to get to the moon?",
"There's a purple mushroom in my backyard, screaming Taco's!",
"Oh no, you're one of THEM!!!!",
"When life gives you lemons, chuck them at people you hate",
"\"Buy some soap! It's clean!\" the cat on the TV said.",
"A Zebra licked a DVD",
"A hotdog on a bridge",
"Eat my shorts!!"
]

while True:
	dt = datetime.datetime.now()

	string = dt.strftime("%Y-%m-%d %H:%M:%S.%f")[:-3]
	string += "\t"
	string += appName
	string += "."
	string += moduleTypes[random.randint(0, len(moduleTypes)-1)]
	string += "\t"
	string += debugTypes[random.randint(0, len(debugTypes)-1)]
	string += "\t"
	string += messages[random.randint(0, len(messages)-1)]

	if os.path.exists("test.log"):
		filesize = os.path.getsize("test.log")
		if (filesize > 1000):
			print("- removing test.log")
			os.remove("test.log")
			time.sleep(2)

	f = open("test.log","a+")
	print(string)
	f.write(string + "\n")
	f.close()

	time.sleep(0.5)

