#include <opencv2/opencv.hpp>
#include <iostream>
#include <string.h>


using namespace cv;
using namespace std;


int main()
{
    VideoCapture cap("/dev/video0");
	
    if (!cap.isOpened()) {
        cerr <<"VideoCapture not opened"<<endl;
        exit(-1);
    }
    int w = 640;
    int h = 480;

    string gst_out = "appsrc ! videoconvert ! x264enc speed-preset=ultrafast bitrate=600 key-int-max=40 ! rtspclientsink location=rtsp://118.67.132.33:8554/mystream protocols=tcp";

    cv::VideoWriter writer;

    writer.open(gst_out, cv::CAP_GSTREAMER, 0, 30, cv::Size(640,480),true);
        
/*	VideoWriter writer(
		"appsrc ! videoconvert ! video/x-raw,format=YUY2,width=640,height=480,framerate=30/1 ! jpegenc ! rtpjpegpay ! udpsink host=127.0.0.1 port=5000", 
        0,		// fourcc 
		30,		// fps
		Size(640, 480), 
		true);	// isColor
*/
    if (!writer.isOpened()) {
        cerr <<"VideoWriter not opened"<<endl;
        exit(-1);
    }

    while (true) {
        Mat frame;

        cap.read(frame);
        
        writer.write(frame);
    }

    return 0;
}
