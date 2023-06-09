#!/usr/bin/env python3
import rospy
from turtlesim.msg import Pose
from geometry_msgs.msg import Twist

def pose_callback(msg):
    cmd=Twist()
    if msg.x>9.0:
        cmd.linear.x=1
        cmd.angular.z=1.4
    else:
        cmd.linear.x=5
        cmd.angular.z=0
    pub= rospy.Publisher("/turtle1/cmd_vel",Twist,queue_size=10)
    pub.publish(cmd)
if __name__=='__main__':
    rospy.init_node("turtle_control")

    sub= rospy.Subscriber("/turtle1/pose",Pose,callback=pose_callback)

    rospy.spin()