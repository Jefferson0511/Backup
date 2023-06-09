#!/usr/bin/env python3
import rospy
from std_msgs.msg import String

def chatter_callback(message):
    rospy.loginfo(rospy.get_caller_id()+"I heard %s",message.data)

def listener():
    rospy.init_node('Listener',anonymous=True)
    rospy.Subscriber("Chatter",String,chatter_callback)
    rospy.spin()

if __name__=='__main__':
    listener()