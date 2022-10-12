#include "ros/ros.h"
#include "service_tutorial/Add.h"
#include <cstdlib>

int main(int argc, char** argv)
{
	ros::init(argc, argv, "service_client");
	
	if (argc != 3)
	{
		ROS_INFO("Command: rosrun <PackageName> <NodeName>");
		ROS_INFO("arg1, arg2 : Int32 type");
		return 1;
	}	

	ros::NodeHandle nh;
	ros::ServiceClient clt = nh.serviceClient<service_tutorial::Add>("ServiceName");
	
	service_tutorial::Add srv;

	srv.request.a = atoi(argv[1]);
	srv.request.b = atoi(argv[2]);

	if (clt.call(srv))
	{
		ROS_INFO("Send srv: srv.request.a = %d, srv.request.b = %d", srv.request.a, srv.request.b);
		ROS_INFO("Receive srv: srv.response.result = %d", srv.response.result);
	}
	
	else
	{
		ROS_ERROR("Failed to call service");
		return 1;
	}

	return 0;
}
