#include "ros/ros.h"
#include "cal_service/calSrv.h"

enum cal_status
{
	PLUS = 1,
	MINUS = 2,
	MULTIPLICATION = 3,
	DIVISION = 4	
}STATUS;

/*
#define PLUS 1
#define MINUS 2
#define MULTIPLICATION	3
#define DIVISION	4
*/

int start = PLUS;

bool calculation(cal_service::calSrv::Request& req,
cal_service::calSrv::Response& res)
{
	switch (start)
	{
		case PLUS:
			res.result = req.x + req.y;
			break;
		case MINUS:
			res.result = req.x - req.y;
			break;
		case MULTIPLICATION:
			res.result = req.x * req.y;
			break;
		// If 4 / 0 "[ERROR] [1665651471.826384329]: FAILED TO CALL SERVICE "
		// Need to exception process
		case DIVISION:
			try
			{
				if (req.y == 0)
				{
					throw req.y;
				}
				res.result = req.x / req.y;
				break;
			}
			catch (int exception)
			{
				ROS_INFO("The Number %d cannot be entered", exception);
			}
		default:
			res.result = req.x + req.y;
			break;			
	}
	ROS_INFO("x: %d, y: %d, result: %d", req.x, req.y, res.result);
	return true;
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "srv_server");
	ros::NodeHandle nh;

	nh.setParam("calculation_method", PLUS);

	ros::ServiceServer sv = nh.advertiseService("calculate", calculation);
	ros::Rate loop_rate(10);

	while(ros::ok())
	{	
		//command : rosparam list
		//rosrun <pkgName> <parameter_Val(1 ~ 4)
		nh.getParam("calculation_method", start);
		ros::spinOnce();
		loop_rate.sleep();
	}

	return 0;
}
