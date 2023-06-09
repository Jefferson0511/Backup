#!/usr/bin/env python3
import rospy
from turtlesim.msg import Pose

def pose_callback(msg):
    rospy.loginfo("x position " +str(msg.x))

if __name__=='__main__':
    rospy.init_node("pose_subscriber")
    
    sub = rospy.Subscriber("/turtle1/pose",Pose,callback=pose_callback)

    rospy.loginfo("Node has been started")
    rospy.spin()