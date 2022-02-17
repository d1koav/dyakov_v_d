#include <opencv2/opencv.hpp>

int main() {

  cv::Mat img(180, 768, CV_8UC1);
  img = 0;
  cv::Rect2d rc = {0, 0, 768, 60 };
  for(int i = 0; i < 768; i++){
    for(int j = 0; j < 180; j++){
      img.at<uchar>(j,i) = i/3;
    }
  }
  rc.y += rc.height;

  double a = 2.2;
  auto start = std::chrono::high_resolution_clock::now();
  cv::Mat second_image{img};
  second_image.convertTo(second_image, CV_64FC1, 1.0f / 255.0f);
  cv::pow(second_image, a, second_image);
  second_image.convertTo(second_image, CV_64FC1, 255.0f);
  second_image(rc).copyTo(img(rc));
  auto finish = std::chrono::high_resolution_clock::now();
  auto second_timing = std::chrono::duration_cast<std::chrono::microseconds>(finish-start);
  std::cout << second_timing.count() << " microseconds" << std::endl;
  rc.y += rc.height;


  double b = 2.4;
  auto start_third = std::chrono::high_resolution_clock::now();
  for(int j = 120; j < 180; j++){
    for (int i = 0; i < 768; i++){
      img.at<cv::uint8_t>(j, i) = cv::saturate_cast<uchar>(cv::pow(img.at<cv::uint8_t>(j, i) / 255.0f, b) * 255.0f);
    }
  }
  auto finish_third = std::chrono::high_resolution_clock::now();
  auto third_timing = std::chrono::duration_cast<std::chrono::microseconds>(finish_third-start_third);
  std::cout << third_timing.count() << " microseconds" << std::endl;

  cv::imwrite("lab01.png", img);
  return 0;
}
