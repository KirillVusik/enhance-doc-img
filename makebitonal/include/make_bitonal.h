#ifndef MAKE_BITONAL_H
#define MAKE_BITONAL_H

#include <cstdint>

#include <opencv2/core/core.hpp>

#include "makebitonal_export.h"

namespace docs_processing
{

/**
 * Sum numbers in a vector.
 *
 * @param src Grayscale OpenCV image
 * @param dst Result image
 * @return 0 in case of success or error code 
 */
int MAKEBITONAL_EXPORT enhance_doc_image(cv::InputArray src, cv::OutputArray dst);

}

#endif // MAKE_BITONAL_H