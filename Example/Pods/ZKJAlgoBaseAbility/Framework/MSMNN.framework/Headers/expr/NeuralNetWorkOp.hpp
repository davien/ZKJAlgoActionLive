//
//  NeuralNetWorkOp.hpp
//  MSMNN
//
//  Created by MSMNN on 2019/06/27.
//  Copyright © 2018, Alibaba Group Holding Limited
//

#ifndef MSMNN_NeuralNetWorkOp_HPP
#define MSMNN_NeuralNetWorkOp_HPP
#include <MSMNN/ImageProcess.hpp>

namespace MSMNN {
namespace Express {
enum PaddingMode {CAFFE, VALID, SAME};
enum PoolingMode {MAXPOOL, AVEPOOL};
enum PadValueMode {CONSTANT, REFLECT, SYMMETRIC, EDGE};
MSMNN_PUBLIC VARP _Input(INTS shape = {}, Dimensionformat data_format = NC4HW4, halide_type_t dtype = halide_type_of<float>()) ;
MSMNN_PUBLIC VARP _Clone(VARP source, bool deepCopy = false);

MSMNN_PUBLIC VARP _Scalar(const void* ptr, halide_type_t type);

template <typename T>
VARP _Scalar(T value) {
    return _Scalar(&value, halide_type_of<T>());
}


MSMNN_PUBLIC VARP _Const(float value, INTS shape = {}, Dimensionformat format = NHWC);
MSMNN_PUBLIC VARP _Const(const void* ptr, INTS shape = {}, Dimensionformat format = NHWC,
                       halide_type_t type = halide_type_of<float>());
MSMNN_PUBLIC VARP _TrainableParam(float value, INTS dims, Dimensionformat format);
MSMNN_PUBLIC VARP _TrainableParam(const void* ptr, INTS dims, Dimensionformat format,
                                  halide_type_t type = halide_type_of<float>());
MSMNN_PUBLIC VARP _InnerProduct(std::vector<float>&& weight, std::vector<float>&& bias, VARP x, INTS outputShape);
MSMNN_PUBLIC VARP _Conv(VARP weight, VARP bias, VARP x, PaddingMode pad = VALID, INTS stride = {1, 1},
                      INTS dilate = {1, 1}, int group = 1, INTS pads = {0, 0});

MSMNN_PUBLIC VARP _Conv(float weight, float bias, VARP x, INTS channel, INTS kernelSize, PaddingMode pad = VALID,
                      INTS stride = {1, 1}, INTS dilate = {1, 1}, int group = 1);
MSMNN_PUBLIC VARP _Conv(std::vector<int8_t>&& weight, std::vector<float>&& bias, VARP x, INTS channel, INTS kernelSize,
                      PaddingMode pad = VALID, INTS stride = {1, 1}, INTS dilate = {1, 1}, int group = 1, INTS pads = {0, 0}, bool relu = false, bool relu6 = false, int nbits = 8);
MSMNN_PUBLIC VARP _Conv(std::vector<float>&& weight, std::vector<float>&& bias, VARP x, INTS channel, INTS kernelSize,
                      PaddingMode pad = VALID, INTS stride = {1, 1}, INTS dilate = {1, 1}, int group = 1, INTS pads = {0, 0}, bool relu = false, bool relu6 = false);
MSMNN_PUBLIC VARP _Deconv(VARP weight, VARP bias, VARP x, PaddingMode pad = VALID, INTS stride = {1, 1},
                                INTS dilate = {1, 1}, int group = 1, INTS pads = {0, 0});

MSMNN_PUBLIC VARP _Deconv(std::vector<float>&& weight, std::vector<float>&& bias, VARP x, INTS channel, INTS kernelSize,
PaddingMode pad, INTS stride = {1, 1}, INTS dilate = {1, 1}, int group = 1, INTS pads = {0, 0}, bool relu = false, bool relu6 = false);

MSMNN_PUBLIC VARP _MaxPool(VARP x, INTS kernel, INTS stride = {1, 1}, PaddingMode pad = VALID, INTS pads= {0, 0});
MSMNN_PUBLIC VARP _AvePool(VARP x, INTS kernel, INTS stride = {1, 1}, PaddingMode pad = VALID, INTS pads= {0, 0});
MSMNN_PUBLIC VARP _Reshape(VARP x, INTS shape, Dimensionformat original_format = NCHW);
MSMNN_PUBLIC VARP _Reshape(VARP x, VARP shape);
MSMNN_PUBLIC VARP _Scale(VARP x, int channels, std::vector<float>&& scales, std::vector<float>&& bias);

MSMNN_PUBLIC VARP _Relu(VARP x, float slope = 0.0f);
MSMNN_PUBLIC VARP _Relu6(VARP x, float minValue = 0.0f, float maxValue = 6.0f);
MSMNN_PUBLIC VARP _PRelu(VARP x, std::vector<float> &&slopes);
MSMNN_PUBLIC VARP _Softmax(VARP logits, int axis = -1);
MSMNN_PUBLIC VARP _Softplus(VARP features);
MSMNN_PUBLIC VARP _Softsign(VARP features);
MSMNN_PUBLIC std::vector<VARP> _Split(VARP value, INTS size_splits, int axis = 0);
MSMNN_PUBLIC VARP _Slice(VARP x, VARP starts, VARP sizes);
MSMNN_PUBLIC VARP _StridedSlice(VARP input, VARP begin, VARP end, VARP strided,
                              int32_t beginMask, int32_t endMask, int32_t ellipsisMask,
                              int32_t newAxisMask, int32_t shrinkAxisMask);
MSMNN_PUBLIC VARP _StridedSliceWrite(VARP input, VARP begin, VARP end, VARP strided, VARP write,
                                   int32_t beginMask, int32_t endMask, int32_t ellipsisMask,
                                   int32_t newAxisMask, int32_t shrinkAxisMask);
MSMNN_PUBLIC VARP _Concat(VARPS values, int axis);
MSMNN_PUBLIC VARP _Convert(VARP input, Dimensionformat format);
MSMNN_PUBLIC VARP _Transpose(VARP x, INTS perm);
MSMNN_PUBLIC VARP _Transpose(VARP x, VARP perm);
MSMNN_PUBLIC VARP _ChannelShuffle(VARP x, int group);
MSMNN_PUBLIC VARP _ChangeInputFormat(VARP input, Dimensionformat format);
MSMNN_PUBLIC VARP _Conv2DBackPropFilter(VARP input, VARP inputGrad, INTS kernelSize, PaddingMode pad = VALID, INTS stride = {1, 1}, INTS dilate = {1, 1}, int group = 1, INTS pads = {0, 0});
MSMNN_PUBLIC VARP _PoolGrad(VARP originInput, VARP originOutput, VARP inputGrad, INTS kernel, INTS stride, PoolingMode type, PaddingMode pad = VALID, INTS pads= {0, 0});
// FIXME: move the api to Array Ops
MSMNN_PUBLIC VARP _ReverseSequence(VARP x, VARP y, int batchDim, int seqDim);
// FIXME: move the api to Image Ops
MSMNN_PUBLIC VARP _Crop(VARP images, VARP size, int axis, INTS offset);
MSMNN_PUBLIC VARP _Resize(VARP images, float xScale, float yScale);
MSMNN_PUBLIC VARP _Pad(VARP x, VARP paddings, PadValueMode mode = CONSTANT);
MSMNN_PUBLIC VARP _ExpandDims(VARP input, int axis);
MSMNN_PUBLIC VARP _ExpandDims(VARP input, VARP axis);

MSMNN_PUBLIC VARP _Shape(VARP input, bool nchw = false);
MSMNN_PUBLIC VARP _Stack(VARPS values, int axis=0);
enum InterpolationMethod {BILINEAR, NEAREST};
MSMNN_PUBLIC VARP _CropAndResize(VARP image, VARP boxes, VARP box_ind, VARP crop_size, 
                                InterpolationMethod method, float extrapolation_value = 0.0);
MSMNN_PUBLIC VARP _Fill(VARP dims, VARP value);
MSMNN_PUBLIC VARP _Tile(VARP input, VARP multiples);
MSMNN_PUBLIC VARP _Gather(VARP params, VARP indices);
MSMNN_PUBLIC VARP _GatherV2(VARP params, VARP indices, VARP axis = nullptr);
MSMNN_PUBLIC VARP _Squeeze(VARP input, INTS axis = {});
MSMNN_PUBLIC VARP _Unsqueeze(VARP input, INTS axis = {});
MSMNN_PUBLIC VARP _BatchToSpaceND(VARP input, VARP block_shape, VARP crops);
MSMNN_PUBLIC VARP _GatherND(VARP params, VARP indices);
MSMNN_PUBLIC VARP _GatherElements(VARP params, VARP indices);
MSMNN_PUBLIC VARP _GatherElements(VARP params, VARP indices, VARP axis);
MSMNN_PUBLIC VARP _Selu(VARP features, float scale, float alpha);
MSMNN_PUBLIC VARP _Size(VARP input);
MSMNN_PUBLIC VARP _Elu(VARP features, float alpha=1.0);
MSMNN_PUBLIC VARP _Threshold(VARP features, float alpha=1.0);
MSMNN_PUBLIC VARP _MatrixBandPart(VARP input, VARP num_lower, VARP num_upper);
MSMNN_PUBLIC std::vector<VARP> _Moments(VARP x, INTS axis, VARP shift, bool keepDims);
MSMNN_PUBLIC VARP _SetDiff1D(VARP x, VARP y); 
MSMNN_PUBLIC VARP _SpaceToDepth(VARP input, int block_size);
MSMNN_PUBLIC VARP _SpaceToBatchND(VARP input, VARP block_shape, VARP paddings);
MSMNN_PUBLIC VARP _ZerosLike(VARP input);
MSMNN_PUBLIC std::vector<VARP> _Unstack(VARP value, int axis=0);
MSMNN_PUBLIC VARP _Rank(VARP input);
MSMNN_PUBLIC VARP _Range(VARP start, VARP limit, VARP delta);
MSMNN_PUBLIC VARP _DepthToSpace(VARP input, int block_size);
MSMNN_PUBLIC VARP _PriorBox(VARP feature, VARP image, 
                            std::vector<float> min_size, std::vector<float> max_size, std::vector<float>aspect_ratio, 
                            bool flip, bool clip, std::vector<float>variance,
                            unsigned int img_h, unsigned int img_w, float step_h, float step_w, float offset = 0.5);
MSMNN_PUBLIC VARP _Permute(VARP input, INTS dims);
MSMNN_PUBLIC VARP _DetectionOutput(VARP location, VARP confidence, VARP priorbox, 
                        unsigned int num_classes, bool share_location, int background_label_id, 
                        float nms_threshhold, int nms_topk, int code_type, 
                        bool variance_encoded_in_target,
                        int keep_top_k, float confidence_threshold, float visualize_threshold); 
MSMNN_PUBLIC  std::vector<VARP> _DetectionPostProcess(VARP encode_boxes, VARP class_predictions, VARP anchors, 
                        int num_classes, int max_detections, 
                        int max_class_per_detection, int detections_per_class, 
                        float nms_threshold, float iou_threshold, 
                        bool use_regular_nms, std::vector<float> centersize_encoding);
MSMNN_PUBLIC VARP _Interp(VARPS xs, float widthScale, float heightScale, int outputWidth, int outputHeight, int resizeType, bool alignCorners);

MSMNN_PUBLIC VARP _ZeroGrad(VARP x);

// Int8 Inference
MSMNN_PUBLIC VARP _Conv(std::vector<int8_t>&& weight, std::vector<int>&& bias, std::vector<float>&& scale, VARP x, INTS channel, INTS kernelSize,
                      PaddingMode pad, INTS stride, INTS dilate, int group, INTS pads, bool relu, int nbits = 8);
MSMNN_PUBLIC VARP _Conv(std::vector<int8_t>&& weight, std::vector<int>&& bias, std::vector<float>&& scale,
                      VARP x, INTS channel, INTS kernelSize,
                      PaddingMode pad, INTS stride, INTS dilate, int group, INTS pads, bool relu,
                      int8_t inputZeroPoint, int8_t outputZeroPoint,
                      int8_t minValue, int8_t maxValue, bool accumulateToInt16);
MSMNN_PUBLIC VARP _Conv(std::vector<int8_t>&& weight, std::vector<float>&& bias, std::vector<float>&& weightScale,
                      VARP x, INTS channel, INTS kernelSize,
                      PaddingMode pad, INTS stride, INTS dilate, int group, INTS pads, bool relu,
                      float scaleIn, float scaleOut,
                      int8_t inputZeroPoint, int8_t outputZeroPoint,
                      int8_t minValue, int8_t maxValue, float weightClampValue, bool accumulateToInt16);
MSMNN_PUBLIC VARP _CosineSimilarity(VARP input0, VARP input1, VARP inputDim);

enum GridSamplePaddingMode {GRID_SAMPLE_PADDING_ZEROS, GRID_SAMPLE_PADDING_BORDER, GRID_SAMPLE_PADDING_REFLECTION};
MSMNN_PUBLIC VARP _GridSample(VARP input, VARP grid, InterpolationMethod mode=BILINEAR, GridSamplePaddingMode paddingMode=GRID_SAMPLE_PADDING_ZEROS, bool alignCorners=false);
MSMNN_PUBLIC VARP _FloatToInt8(VARP x, VARP scale, char minValue, char maxValue);
MSMNN_PUBLIC VARP _FloatToInt8(VARP x, VARP scale, int8_t minValue, int8_t maxValue, int8_t zeroPoint);
MSMNN_PUBLIC VARP _Int8ToFloat(VARP x, VARP scale);
MSMNN_PUBLIC VARP _Int8ToFloat(VARP x, VARP scale, int8_t zeroPoint);

MSMNN_PUBLIC VARP _Select(VARP select, VARP input0, VARP input1);
MSMNN_PUBLIC std::vector<VARP> _TopKV2(VARP input0, VARP input1);
MSMNN_PUBLIC VARP _ImageProcess(VARP input, CV::ImageProcess::Config config, CV::Matrix matrix, int oh, int ow, int oc, int dtype, uint8_t padVal = 0);
MSMNN_PUBLIC VARP _Where(VARP x);
MSMNN_PUBLIC VARP _Sort(VARP x, int axis = -1, bool arg = false, bool descend = false);
MSMNN_PUBLIC VARP _Raster(const std::vector<VARP>& vars, const std::vector<int>& regions, const std::vector<int>& shape);
MSMNN_PUBLIC VARP _RasterRaw(const std::vector<VARP>& vars, const std::vector<int>& region, const std::vector<int>& shape, halide_type_t dataType, Dimensionformat format);

MSMNN_PUBLIC VARP _Nms(VARP boxes, VARP scores, int maxDetections, float iouThreshold = -1, float scoreThreshold = -1);
MSMNN_PUBLIC VARP _Im2Col(VARP x, INTS kernelSize, INTS dilate, INTS pads, INTS stride);
MSMNN_PUBLIC VARP _Col2Im(VARP x, VARP outputShape, INTS kernelSize, INTS dilate, INTS pads, INTS stride);

/**
 Onnx's Loop
 */
MSMNN_PUBLIC VARPS _Loop(VARPS x, const std::string& submoduleName);

} // namespace Express
} // namespace MSMNN

#endif /* NeuralNetWorkOp_HPP */
