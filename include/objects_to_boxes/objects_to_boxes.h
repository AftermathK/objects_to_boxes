#ifndef OBJECTS_TO_BOXES
#define OBJECTS_TO_BOXES

#include <ros/ros.h>
#include <ros/console.h>
#include "std_msgs/String.h"
#include <string>
#include <sstream>
#include <jsk_recognition_msgs/BoundingBox.h>
#include <jsk_recognition_msgs/BoundingBoxArray.h>
//#include <jsk_rviz_plugins/Pictogram.h>
//#include <jsk_rviz_plugins/PictogramArray.h>
//#include <autoware_msgs/centroids.h>
#include <objects_to_boxes/CloudCluster.h>
#include <objects_to_boxes/CloudClusterArray.h>
#include <objects_to_boxes/DetectedObject.h>
#include <objects_to_boxes/DetectedObjectArray.h>

class ObjectsToBoxes{
public:
  ObjectsToBoxes(); 
  void detectedObjectsCallback(const objects_to_boxes::DetectedObjectArray::ConstPtr& msg);
  ros::NodeHandle n;
  ros::Publisher dp_pub;
  ros::Subscriber objects_sub; 
};



#endif
