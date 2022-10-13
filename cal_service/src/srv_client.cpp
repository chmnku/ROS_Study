#include "ros/ros.h"
#include "cal_service/calSrv.h"
#include <cstdlib>

int main(int argc, char** argv)
{
	ros::init(argc, argv, "srv_client");
		
	if (argc != 3)
	{
		ROS_INFO("ERROR: INVALID VALUE");
	}

	ros::NodeHandle nh;
	ros::ServiceClient clt = nh.serviceClient<cal_service::calSrv>("calculate");
	
	cal_service::calSrv srv;
	srv.request.x = atoi(argv[1]);
	srv.request.y = atoi(argv[2]);
	
	if (clt.call(srv))
	{
		ROS_INFO("x: %d, y: %d", srv.request.x, srv.request.y);
		ROS_INFO("result: %d", srv.response.result);
	}

	else
	{
		ROS_ERROR("FAILED TO CALL SERVICE");
		return 1;
	}
	

	return 0;
}
