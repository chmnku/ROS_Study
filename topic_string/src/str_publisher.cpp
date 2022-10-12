#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char** argv)
{
	ros::init(argc, argv, "str_publisher");
	ros::NodeHandle nh;
	ros::Publisher pub = nh.advertise<std_msgs::String>("myTopic", 100);
	ros::Rate loop_rate(10);

	std_msgs::String msg;

	msg.data = "Hello World"; // Initialize msg.data
	
	while(ros::ok())
	{
		pub.publish(msg);
		loop_rate.sleep;
	}

	return 0;
}
