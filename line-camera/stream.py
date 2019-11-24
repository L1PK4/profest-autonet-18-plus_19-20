import cv2
import numpy as np
 
cap = cv2.VideoCapture(0)
 
while(True):
 	ret, frame = cap.read()
	
	timer = cv2.getTickCount()
	fps = cv2.getTickFrequency() / (cv2.getTickCount() - timer);
	
	cv2.putText(frame, "FPS : " + str(int(fps)), (100,50), 
	cv2.FONT_HERSHEY_SIMPLEX, 0.75, (50,170,50), 2);

	cv2.imshow("Stream", frame)
	
	if cv2.waitKey(1) & 0xFF == ord('q'): 
		break

cap.release()
cv2.destroyAllWindows()

#python stream.py
