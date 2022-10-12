#include "ros/ros.h"
#include "service_tutorial/Add.h"

bool sum(service_tutorial::Add::Request& req,
service_tutorial::Add::Response& res)
{
	res.result = req.a + req.b;
	ROS_INFO("Request: a = %d, b = %d", req.a, req.b);
	ROS_INFO("Response: result = %d", res.result);
	return true;
}


int main(int argc, char** argv)
{
	ros::init(argc, argv, "service_server");
	ros::NodeHandle nh;
	ros::ServiceServer sv = nh.advertiseService("ServiceName", sum);

	ROS_INFO("Service Server READY.");

	ros::spin();

	return 0;
}
