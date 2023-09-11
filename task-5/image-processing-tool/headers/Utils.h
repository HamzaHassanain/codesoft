#pragma once
#include <wx/wx.h>
#include <opencv2/opencv.hpp>

wxImage wx_from_mat(cv::Mat &img);
cv::Mat mat_from_wx(wxImage &wx);