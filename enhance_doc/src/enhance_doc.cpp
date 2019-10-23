#include "enhance_doc/enhance_doc.h"

#include <opencv2/opencv.hpp>

using namespace cv;

namespace docs_processing
{

static constexpr int MAX_COLOR{255};

namespace
{


void binarize_image(InputArray input_image, OutputArray output_image)
{
    static constexpr auto adaptive_type{AdaptiveThresholdTypes::ADAPTIVE_THRESH_MEAN_C};
    static constexpr int block_size{21};
    static constexpr double substraction_const{2};

    adaptiveThreshold(input_image, output_image, MAX_COLOR, adaptive_type,
                      ThresholdTypes::THRESH_BINARY_INV, block_size, substraction_const);
}

void remove_dotted_text_background(InputArray input_image, OutputArray output_image)
{
    static constexpr int connectivity{8};
    static constexpr int matrix_return_type{CV_32S};
    static constexpr auto algotithm{ConnectedComponentsAlgorithmsTypes::CCL_WU};
    static constexpr int min_connected_component_size = 20;
    static constexpr int stats_size_index = 4;

    Mat labels;
    Mat stats;
    Mat centroids;

    int nlabels{connectedComponentsWithStats(input_image, labels, stats, centroids, 
                                             connectivity, matrix_return_type, algotithm)};
    

    Mat imageWithoutDots(input_image.rows(), input_image.cols(), CV_8UC1, Scalar(0));
    for (int i = 1; i < nlabels; i++)
    {
        if (stats.at<int>(i, stats_size_index) >= min_connected_component_size)
        {
            for (int j = 0; j < imageWithoutDots.total(); j++) 
            {
                if (labels.at<int>(j) == i) 
                {
                    imageWithoutDots.data[j] = MAX_COLOR;
                }
            }
        }
    }
    cv::bitwise_not(imageWithoutDots, output_image);
}

} // namespace

int enhance_doc_image(cv::InputArray src, cv::OutputArray dst)
{
    try
    {
        binarize_image(src, dst);
        remove_dotted_text_background(dst, dst);
        return 0;
    }
    catch(const cv::Exception& e)
    {
        return e.code;
    }
}
} // docs_processing