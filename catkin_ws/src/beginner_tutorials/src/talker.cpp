#include "ros/ros.h"
#include "std_msgs/String.h"

#include<sstream>

int main(int args, char **argv) {
  ros::init(args, argv, "talker");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
  ros::Rate loop_rate(1.0);
  int count = 0;
  while(ros::ok()) {
    std_msgs::String msg;
    std::stringstream ss;
    ss << "Hello World" <<count;
   
    msg.data = ss.str();
    std::cout<<msg.data<<std::endl;
    ROS_INFO("%s", msg.data.c_str());
    chatter_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }
  return 0;
}