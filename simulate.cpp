#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include <ros/time.h>
#include <sensor_msgs/Range.h>
#include <visualization_msgs/Marker.h>

int main(int argc, char** argv){
 
 ros::init(argc,argv,"simulate_node");
 ros::NodeHandle nh;
 ros::Publisher range_pub = nh.advertise<sensor_msgs::Range>("ranges_topic",100);
 ros::Publisher markers_pub = nh.advertise<visualization_msgs::Marker>("markers_topic",0);
 visualization_msgs::Marker marker;

 // The options/specifications of the markers visualization
 // 1- Reference Frame
  marker.header.frame_id = "/base_link";
 // 2- Unique Identifiers
  marker.ns = "my_namespace";marker.id = 0;
 // 3- Marker Type and action
  marker.type = visualization_msgs::Marker::SPHERE; //the marker type
  marker.action = visualization_msgs::Marker::ADD;
 // 4- The constant positions (X and Z axes)
  marker.pose.position.x = 0; 
  marker.pose.position.z = 0; 
 // 5- The marker quaternion orientations 
  marker.pose.orientation.x = 0.0; marker.pose.orientation.y = 0.0; 
  marker.pose.orientation.z = 0.0; marker.pose.orientation.w = 1.0;
 //6- The marker scale (Volume)
  marker.scale.x = 1; marker.scale.y = 1; marker.scale.z = 1; 
 //7- The marker color in RGB
  marker.color.a = 1.0; //To be visible
  marker.color.r = 0.0; marker.color.g = 1.0; marker.color.b = 0.0;
  
  
 ros::Rate loop_rate(1); //The loop frequency
 sensor_msgs::Range msg;
 msg.header.frame_id = "/base_link";
 msg.min_range = 0;
 msg.max_range = 100;
 msg.radiation_type = sensor_msgs::Range::ULTRASOUND;
 int x = 0;

while(ros::ok()){
 if(x>45) x=0; 
 else x=x+5;
 msg.header.stamp= ros::Time::now();
 marker.header.stamp = ros::Time();
 msg.range = x;
 marker.pose.position.y = x;
 markers_pub.publish(marker);
 range_pub.publish(msg);
 loop_rate.sleep();  
}

}



