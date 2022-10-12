#include "ros/ros.h"
#include "msg_tutorial/Mymsg.h"

int main(int argc, char** argv)
{
	ros::init(argc, argv, "msg_publisher");
	ros::NodeHandle nh;
	ros::Publisher pub = nh.advertise<msg_tutorial::Mymsg>("msgTopic", 100);
	ros::Rate loop_rate(10);

	msg_tutorial::Mymsg msg;
	int cnt = 0;
		
	while(ros::ok())
	{
		msg.stamp = ros::Time::now();
		msg.data = cnt;
		ROS_INFO("Current Time : %d", msg.stamp.sec);
		ROS_INFO("Send a Sequential Num : %d", msg.data);
		pub.publish(msg);
		cnt++;
		loop_rate.sleep();	
	}

	return 0;
}
