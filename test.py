import cv2
cap = cv2.VideoCapture("nvarguscamerasrc ! video/x-raw(memory:NVMM),width=640,height=480,framerate=30/1 ! nvvidconv ! video/x-raw,format=BGRx ! videoconvert ! video/x-raw,format=BGR ! appsink drop=0", cv2.CAP_GSTREAMER)
print(cap.isOpened())

out = cv2.VideoWriter("appsrc ! video/x-raw,format=BGR,width=1920,height=1080,framerate=30/1 ! videoconvert ! video/x-raw,format=BGRx ! nvvidconv ! nvv4l2h264enc insert-vui=1 insert-sps-pps=1 ! h264parse ! rtph264pay ! udpsink host=127.0.0.1 port=5000", cv2.CAP_GSTREAMER, 0, 30, (1920,1080))
print(out.isOpened())

while True:
	ret,frame = cap.read()
	cv2.imshow('frame', frame)
	#out.write(frame)

out.release()
cap.release()