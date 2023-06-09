#!/usr/bin/env python3
import rospy
from turtlesim.msg import Pose
from geometry_msgs.msg import Twist

rospy.init_node("heart")

def straight_line(msg): 
    i=0
    while i==0:
        cmd.linear.x=1
        cmd.angular.z=0
        pub.publish(cmd)
        print(i)
        if (msg.x==5.544342041015625):
            i=1
    

cmd=Twist()
pub=rospy.Publisher("/turtle1/cmd_vel",Twist,queue_size=10)
def left_heart(msg):
    if msg.y<11.5:
        cmd.linear.x=1.3
        cmd.angular.z=2
    if msg.x<=4.37:
        cmd.linear.x=0
        cmd.angular.z=1
        if msg.theta>=-1.4143706560134888 and msg.theta<0:
            cmd.linear.x=0  
            cmd.angular.z=1
            if msg.theta==-0.8863705992698669 and msg.theta<0:
                straight_line(msg)
            
        
        

def pose_callback(msg):
    rospy.loginfo("("+ str(msg.x) +","+str(msg.y) +","+str(msg.theta)+")")
    if msg.x<5.544444561004639:
        if msg.x<=5.544342041015625 and msg.y==6.916368007659912:
            cmd.linear.x=0
            cmd.angular.z=-1
            if msg.theta<=2.0 and msg.theta>0:
                cmd.linear.x=1
                cmd.angular.z=0.5

        else:
            print("err")
            left_heart(msg)
        # else:
        #     rospy.loginfo("x")
        #     cmd.linear.x=1
        #     cmd.angular.z=0.5
        #     if msg.y>=7.376871109008789:
        #         rospy.loginfo(msg.theta)
        #         cmd.linear.x=0
        #         cmd.angular.z=0.5
        #         if msg.theta>-2.2271852493286133 and msg.theta<0:
        #             cmd.linear.x=1
        #             cmd.angular.z=0.5
        #         else:
        #             rospy.loginfo("err")
                    
    else:

        if msg.theta>0.95:
            cmd.angular.z=0
            cmd.linear.x=1
            if msg.y>6.8:
                cmd.linear.x=1
                cmd.angular.z=3
        elif msg.theta<0:
            cmd.linear.x=1
            cmd.angular.z=1.5
        else:
            cmd.linear.x=0
            cmd.angular.z=1

   
    pub.publish(cmd)


sub = rospy.Subscriber("/turtle1/pose",Pose,callback=pose_callback)
rospy.spin()

