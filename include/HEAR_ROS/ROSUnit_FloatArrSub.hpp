#ifndef __ROSUNIT_FLOATARRSUB_H__
#define __ROSUNIT_FLOATARRSUB_H__

#include "HEAR_ROS/ROSUnit_Sub.hpp"
#include "std_msgs/Float32MultiArray.h"
#include <vector>

namespace HEAR{

class ROSUnitFloatArrSub : public ROSUnit_Sub{
private:
    void callback(const std_msgs::Float32MultiArray::ConstPtr&);
public:
    ROSUnitFloatArrSub(ros::NodeHandle& nh, const std::string& topic, int idx);
    TYPE getType(){ return TYPE::FloatVec;}
};

ROSUnitFloatArrSub::ROSUnitFloatArrSub(ros::NodeHandle& nh, const std::string& topic, int idx){
    sub_ = nh.subscribe<std_msgs::Float32MultiArray>(topic, 10, &ROSUnitFloatArrSub::callback, this);
    _output_port = new OutputPort<std::vector<float>>(idx, 0);
    
    // ((OutputPort<std::vector<float>>*)_output_port)->write();
    id_ = idx;
}
void ROSUnitFloatArrSub::callback(const std_msgs::Float32MultiArray::ConstPtr& msg){
    ((OutputPort<std::vector<float>>*)_output_port)->write(msg->data);
}

}
#endif // __ROSUNIT_FLOATARRSUB_H__