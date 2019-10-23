#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>

#include "enhance_doc/enhance_doc.h"

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        std::cerr << "Usage:\n[this_app] SOURCE_FILE DESTINATION_FILE\n";
        return -1;
    }

    try
    {
        cv::Mat image = imread(argv[1], cv::ImreadModes::IMREAD_GRAYSCALE);
        if (image.data == nullptr)   
        {
            std::cerr <<  "Could not open or find the image" << std::endl ;
            return -1;
        }

        cv::Mat out_image;
        docs_processing::enhance_doc_image(image, out_image);
        imwrite(argv[2], out_image);
        return 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }
}
