#pragma once
#include <opencv2/opencv.hpp>

#include "WrapFunction.hpp"

class Answer
{
    private:
        const int _xPos = 55;
        const int _yPos = 395;
        const int _height = 390;
        const int _width = 640;
        cv::Rect _answerBlockRect = cv::Rect(_xPos, _yPos, _width, _height);

        cv::Mat _answerBlock = cv::Mat();

        std::vector<cv::Rect> _answerBounds;
        float _evaluation = 0.f; 
    private:
        void cropAnswerBlock();
        void sharpen();
        void preprocess();
        
    public:
        Answer();
        Answer(cv::Mat& image);
        void setImage(cv::Mat& image);
        void extractAnswerBounds();
        float evaluateAnswer();        
};