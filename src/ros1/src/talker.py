#!/usr/bin/env python3
import rospy
from std_msgs.msg import String

def talker():
    pub = rospy.Publisher('Chatter',String,queue_size=10)
    rospy.init_node('Talker',anonymous=True)
    rate = rospy.Rate(1)
    i=0
    while not rospy.is_shutdown():
        hello=" Hi Jeff %s" %i
        rospy.loginfo(hello)
        pub.publish(hello)
        rate.sleep()
        i=i+1
if __name__=='__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass