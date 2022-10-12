#include "ros/ros.h"
#include "std_msgs/Int32.h"

int main(int argc, char** argv)
{
	ros::init(argc, argv, "topic_publisher");
	ros::NodeHandle nh;
	ros::Publisher pub = nh.advertise<std_msgs::Int32>("TopicName", 100);
	ros::Rate loop_rate(10);

	std_msgs::Int32 msg;
	
	msg.data = 0;
	
	while(ros::ok())
	{
		pub.publish(msg);
		loop_rate.sleep();
		msg.data++;		
	}


	return 0;
}
