#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\objdetect\objdetect.hpp>

using namespace std;
using namespace cv;


int main() {

    CascadeClassifier faceDetection;
    if (!faceDetection.load("C:\\Users\\Avisha Bagdiya\\Downloads\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_default.xml")) {
		cout << "\n XML File not found";
		exit(0);
	}
	char path[100];
	cout << "\n Enter path to image : ";
	cin.getline(path,100);

	Mat img = imread(path, IMREAD_UNCHANGED);

	if (img.empty()) {
		cout << "\n image is not loaded! - ";
	}
	else{
        cout<<"\n image is found ";
        cout<<"\n Processing...";

        vector<Rect> faces;
        faceDetection.detectMultiScale(img, faces);

        for (int i = 0; i < faces.size(); i++) {
            Point pt1(faces[i].x, faces[i].y);
            Point pt2((faces[i].x + faces[i].height), (faces[i].y + faces[i].width));

            rectangle(img, pt1, pt2, Scalar(0, 0, 255), 2, 8, 0);
        }

        imwrite("C:\\ab\\output.jpg",img);

        cout<<"\n Face detected ";


	}


	return 0;
}
