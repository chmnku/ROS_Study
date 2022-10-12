#include "ros/ros.h"
#include "std_msgs/String.h"

void msgCallback(const std_msgs::String::ConstPtr& msg)
{
	// Member Function about String class : 
	// c_str() : Return to const char* type (string -> char*) 
	ROS_INFO("Received msg : %s", msg->data.c_str());
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "str_subscriber");
	ros::NodeHandle nh;
	ros::Subscriber sub = nh.subscribe("myTopic",100, msgCallback);
	
	ros::spin();

	return 0;
}
