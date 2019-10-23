#ifndef ENHANCE_DOC_H
#define ENHANCE_DOC_H

#include <cstdint>

#include <opencv2/core/core.hpp>

#include "enhance_doc/enhance_doc_export.h"

namespace docs_processing
{

/**
 * Sum numbers in a vector.
 *
 * @param src Grayscale OpenCV image
 * @param dst Result image
 * @return 0 in case of success or error code 
 */
int ENHANCE_DOC_EXPORT enhance_doc_image(cv::InputArray src, cv::OutputArray dst);

}

#endif // ENHANCE_DOC_H