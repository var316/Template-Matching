#include <pcl/common/common.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/io/file_io.h>
#include <iostream>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <boost/thread.hpp>

    
int main ()
{
	//*****************************************************************************************************************
	//************************************After the PCD file loads, press 'f' to zoom in*******************************
	//*****************************************************************************************************************
	
	pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZRGBA>);
	pcl::io::loadPCDFile ("3DReconstructPCD.pcd", *cloud);
    
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));

	viewer->setBackgroundColor (0, 0, 0);
	pcl::visualization::PointCloudColorHandlerRGBField<pcl::PointXYZRGBA> rgb(cloud);
	viewer->addPointCloud<pcl::PointXYZRGBA> (cloud, rgb, "sample cloud");
	viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "sample cloud");

	viewer->addCoordinateSystem (1.0);
	viewer->initCameraParameters ();
	viewer->resetCamera();

	while (!viewer->wasStopped ()) { 
    viewer->spinOnce (); 
    } 

    return 0;
}