#ifndef OPENCV_IMGPROC_HAL_INTERFACE_H
#define OPENCV_IMGPROC_HAL_INTERFACE_H

//! @addtogroup imgproc_hal_interface
//! @{

//! @name Interpolation modes
//! @sa mscv::InterpolationFlags
//! @{
#define CV_HAL_INTER_NEAREST 0
#define CV_HAL_INTER_LINEAR 1
#define CV_HAL_INTER_CUBIC 2
#define CV_HAL_INTER_AREA 3
#define CV_HAL_INTER_LANCZOS4 4
//! @}

//! @name Morphology operations
//! @sa mscv::MorphTypes
//! @{
#define CV_HAL_MORPH_ERODE 0
#define CV_HAL_MORPH_DILATE 1
//! @}

//! @name Threshold types
//! @sa mscv::ThresholdTypes
//! @{
#define CV_HAL_THRESH_BINARY      0
#define CV_HAL_THRESH_BINARY_INV  1
#define CV_HAL_THRESH_TRUNC       2
#define CV_HAL_THRESH_TOZERO      3
#define CV_HAL_THRESH_TOZERO_INV  4
#define CV_HAL_THRESH_MASK        7
#define CV_HAL_THRESH_OTSU        8
#define CV_HAL_THRESH_TRIANGLE    16
//! @}

//! @name Adaptive threshold algorithm
//! @sa mscv::AdaptiveThresholdTypes
//! @{
#define CV_HAL_ADAPTIVE_THRESH_MEAN_C     0
#define CV_HAL_ADAPTIVE_THRESH_GAUSSIAN_C 1
//! @}

//! @}

#endif
