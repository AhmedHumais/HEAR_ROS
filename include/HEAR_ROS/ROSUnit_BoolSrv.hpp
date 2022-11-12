#ifndef ROSUNIT_BOOLSRV_HPP
#define ROSUNIT_BOOLSRV_HPP

#include <ros/ros.h>
#include "std_srvs/SetBool.h"
#include <string>

#include "HEAR_core/ExternalTrigger.hpp"

namespace HEAR{
class ROSUnit_BoolServer {
private:
    ros::NodeHandle nh_;
    ros::ServiceServer m_server;
    UpdateTrigger* ext_trig;
    bool srv_callback(std_srvs::SetBool::Request&, std_srvs::SetBool::Response&);
public:
    ROSUnit_BoolServer(ros::NodeHandle&);
    UpdateTrigger* registerServer(const std::string&);
    
};

}

#endif