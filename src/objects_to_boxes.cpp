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

#include "objects_to_boxes.h"

ObjectsToBoxes::ObjectsToBoxes(){
  dp_pub = n.advertise<jsk_recognition_msgs::BoundingBoxArray>("bounding_boxes",1000);
  objects_sub = n.subscribe("detected_objects",1000,&ObjectsToBoxes::detectedObjectsCallback,this);
}

void ObjectsToBoxes::detectedObjectsCallback(const objects_to_boxes::DetectedObjectArray::ConstPtr& msg){
  ROS_INFO("DetectedObjectArray Object Released.\n");
  int bbox_array_size = msg->objects.size();
  
  jsk_recognition_msgs::BoundingBoxArray bbox_array;
  //bbox_array.boxes = (jsk_recognition_msgs::BoundingBox *) malloc(bbox_array_size*(sizeof(jsk_recognition_msgs::BoundingBox)));

  for(int i=0; i<bbox_array_size; i++){
    objects_to_boxes::DetectedObject curr_detected_object = msg->objects[i];
    
    jsk_recognition_msgs::BoundingBox new_msg;
    new_msg.pose = curr_detected_object.pose; 
    new_msg.dimensions = curr_detected_object.dimensions;
    //new_msg.value = curr_detected_object.;
    new_msg.label = curr_detected_object.id;

    bbox_array.boxes.push_back(new_msg); 
  }
  dp_pub.publish(bbox_array);  
  return;
}

int main(int argc, char *argv[]){
  ros::init(argc, argv, "detected_objects_to_bounding_boxes");
  ObjectsToBoxes objs_to_boxes;  
  ros::spin();

  return 0;

}

