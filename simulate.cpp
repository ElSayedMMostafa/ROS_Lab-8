#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include <ros/time.h>
#include <sensor_msgs/Range.h>


int main(int argc, char** argv){
 
 ros::init(argc,argv,"simulate_node");
 ros::NodeHandle nh;
 ros::Publisher range_pub = nh.advertise<sensor_msgs::Range>("ranges_topic",100);

  
 ros::Rate loop_rate(1); //The loop frequency
 sensor_msgs::Range msg;
 msg.header.frame_id = "/base_link";
 msg.min_range = 0;
 msg.max_range = 100;
 msg.field_of_view = 0.5;
 msg.radiation_type = sensor_msgs::Range::ULTRASOUND;
 int x = 0;

while(ros::ok()){
 if(x>45) x=0; 
 else x=x+5;
 msg.header.stamp= ros::Time::now();
 msg.range = x;
 range_pub.publish(msg);
 loop_rate.sleep();  
}

}



