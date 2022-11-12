#ifndef __ROSUNIT_INTARRPUB_H__
#define __ROSUNIT_INTARRPUB_H__

#include "HEAR_ROS/ROSUnit_Pub.hpp"
#include "std_msgs/Int32MultiArray.h"

#include <vector>

namespace HEAR{

class ROSUnitIntArrPub : public ROSUnit_Pub{
private:
public:
    ROSUnitIntArrPub(ros::NodeHandle& nh, const std::string& topic_name, int idx){
        pub_ = nh.advertise<std_msgs::Int32MultiArray>(topic_name, 10, true);
        _input_port = new InputPort<std::vector<int>>(idx, 0);
        id_ = idx;
    }

    TYPE getType(){ return TYPE::IntVec;}
    void process(){
        if (_input_port != NULL){
            std_msgs::Int32MultiArray msg;
            ((InputPort<std::vector<int>>*)_input_port)->read(msg.data);
            pub_.publish(msg);
        }
    }
};

}
#endif // __ROSUNIT_INTARRPUB_H__