//
//  main.cpp
//  NelivaSDK
//
//  Created by Bitmain on 2020/11/5.
//  Copyright © 2020年 AnBaolei. All rights reserved.
//

#include <iostream>
#include <chrono>
#include <mutex>
#include <thread>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <opencv2/opencv.hpp>
#include <sys/time.h>
#include "face_detection.hpp"

using namespace std;
using namespace cv;

int main(int argc, const char * argv[]) {
  if (argc < 3) {
    cout << "USAGE:" << endl;
    cout << "  " << argv[0] << " <image_path> <bmodel path> " << endl;
    exit(1);
  }

  string image_path = argv[1];
  string bmodel_folder_path = argv[2];
  int device_id = 0;

  shared_ptr<FaceDetection> face_detection_share_ptr(
                    new FaceDetection(bmodel_folder_path, device_id));
  FaceDetection* face_detection_ptr = face_detection_share_ptr.get();
  Mat img = imread(image_path, cv::IMREAD_COLOR);
  if (img.empty()) {
    cout << "read image " << image_path << "error!" << endl;
    exit(1);
  }
  
  struct timeval tpstart, tpend;
  float timeuse = 0.f;
  gettimeofday(&tpstart, NULL);
  vector<cv::Mat> batch_imgs;
  batch_imgs.push_back(img);
  std::vector<std::vector<stFaceRect> > results;
  face_detection_ptr->run(batch_imgs, results);
  gettimeofday(&tpend, NULL);
  timeuse = 1000000 * (tpend.tv_sec - tpstart.tv_sec) + tpend.tv_usec - tpstart.tv_usec;
  timeuse /= 1000;

  cout << results[0].size() << " faces have been detected!"<< endl;
  for (size_t i = 0; i < results[0].size(); i++) {
    Rect rc;
    rc.x = results[0][i].left;
    rc.y = results[0][i].top;
    rc.width = results[0][i].right - results[0][i].left + 1;
    rc.height = results[0][i].bottom - results[0][i].top + 1;
    cv::rectangle(img, rc, cv::Scalar(0, 0, 255), 2, 1, 0);
    for (size_t k = 0; k < 5; k++) {
      cv::circle(img, Point(results[0][i].points_x[k],
            results[0][i].points_y[k]), 1, cv::Scalar(255, 0, 0), 3);
    }
  }
  cout << "used Time: " << timeuse << " ms" << endl;
  cv::imwrite("result.jpg", img);
  return 0;
}
