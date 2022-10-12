#include "ros/ros.h"
#include "msg_tutorial/Mymsg.h"

void msgCallback(const msg_tutorial::Mymsg::ConstPtr& msg)
{
	ROS_INFO("Received msg: %d", msg->stamp.sec);
	ROS_INFO("Recevied msg: %d", msg->data);
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "msg_subscriber");
	ros::NodeHandle nh;
	ros::Subscriber sub = nh.subscribe("msgTopic", 100, msgCallback);
	
	ros::spin();

	return 0;
}
