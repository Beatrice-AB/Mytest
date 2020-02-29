import sys
import rospy
import time
from hour.srv import *

def temps(x,y):
	rospy.wait_for_service('hour')
	try:
		temps = rospy.ServiceProxy('hour', hour)
		reponse = time()
		return reponse
	except rospy.ServiceException e:
		print "Erreur"

if __name__ == "__main__":
	
	while True:
		print(temps())
		time.sleep(1)
