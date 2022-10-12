#include "ros/ros.h"
#include "std_msgs/Int32.h"

void msgCallback(const std_msgs::Int32::ConstPtr& num)
{
	ROS_INFO("Received num : %d", num->data);
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "topic_subscriber");
	ros::NodeHandle nh;
	ros::Subscriber sub = nh.subscribe("TopicName", 100, msgCallback);
	
	ros::spin();

	return 0;
}
