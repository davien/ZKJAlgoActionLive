//
//  MathOp.hpp
//  MSMNN
//
//  Created by MSMNN on 2019/06/27.
//  Copyright © 2018, Alibaba Group Holding Limited
//

#ifndef MSMNN_MathOp_HPP
#define MSMNN_MathOp_HPP

namespace MSMNN {
namespace Express {
//BinaryOPs
MSMNN_PUBLIC VARP _Add(VARP x, VARP y);
MSMNN_PUBLIC VARP _Subtract(VARP x, VARP y);    
MSMNN_PUBLIC VARP _Multiply(VARP x, VARP y);
MSMNN_PUBLIC VARP _Divide(VARP x, VARP y);
MSMNN_PUBLIC VARP _Pow(VARP x, VARP y);
MSMNN_PUBLIC VARP _Minimum(VARP x, VARP y);
MSMNN_PUBLIC VARP _Maximum(VARP x, VARP y);
MSMNN_PUBLIC VARP _BiasAdd(VARP value, VARP bias);
MSMNN_PUBLIC VARP _Greater(VARP x, VARP y);
MSMNN_PUBLIC VARP _GreaterEqual(VARP x, VARP y);
MSMNN_PUBLIC VARP _Less(VARP x, VARP y);
MSMNN_PUBLIC VARP _FloorDiv(VARP x, VARP y);
MSMNN_PUBLIC VARP _SquaredDifference(VARP x, VARP y);
MSMNN_PUBLIC VARP _Equal(VARP x, VARP y);
MSMNN_PUBLIC VARP _LessEqual(VARP x, VARP y);
MSMNN_PUBLIC VARP _FloorMod(VARP x, VARP y);
MSMNN_PUBLIC VARP _Atan2(VARP x, VARP y);
MSMNN_PUBLIC VARP _LogicalOr(VARP x, VARP y);
MSMNN_PUBLIC VARP _NotEqual(VARP x, VARP y);
MSMNN_PUBLIC VARP _BitwiseAnd(VARP x, VARP y);
MSMNN_PUBLIC VARP _BitwiseOr(VARP x, VARP y);
MSMNN_PUBLIC VARP _BitwiseXor(VARP x, VARP y);

//UnaryOPs
MSMNN_PUBLIC VARP _Sign(VARP a);
MSMNN_PUBLIC VARP _Abs(VARP x);
MSMNN_PUBLIC VARP _Negative(VARP x);
MSMNN_PUBLIC VARP _Floor(VARP x);
MSMNN_PUBLIC VARP _Round(VARP x);
MSMNN_PUBLIC VARP _Ceil(VARP x);
MSMNN_PUBLIC VARP _Square(VARP x);
MSMNN_PUBLIC VARP _Sqrt(VARP x);
MSMNN_PUBLIC VARP _Rsqrt(VARP x);
MSMNN_PUBLIC VARP _Exp(VARP x);
MSMNN_PUBLIC VARP _Log(VARP x);
MSMNN_PUBLIC VARP _Sin(VARP x);
MSMNN_PUBLIC VARP _Sinh(VARP x);
MSMNN_PUBLIC VARP _Cos(VARP x);
MSMNN_PUBLIC VARP _Cosh(VARP x);
MSMNN_PUBLIC VARP _Tan(VARP x);
MSMNN_PUBLIC VARP _Asin(VARP x);
MSMNN_PUBLIC VARP _Asinh(VARP x);
MSMNN_PUBLIC VARP _Acos(VARP x);
MSMNN_PUBLIC VARP _Acosh(VARP x);
MSMNN_PUBLIC VARP _Atan(VARP x);
MSMNN_PUBLIC VARP _Atanh(VARP x);
MSMNN_PUBLIC VARP _Reciprocal(VARP x);
MSMNN_PUBLIC VARP _Log1p(VARP x);
MSMNN_PUBLIC VARP _Gelu(VARP x);
//Only one but not in UnaryOPs 
MSMNN_PUBLIC VARP _Tanh(VARP x);
MSMNN_PUBLIC VARP _Sigmoid(VARP x);
MSMNN_PUBLIC VARP _Erf(VARP x);
MSMNN_PUBLIC VARP _Erfc(VARP x);
MSMNN_PUBLIC VARP _Erfinv(VARP x);
MSMNN_PUBLIC VARP _Expm1(VARP x);
MSMNN_PUBLIC VARP _Hardswish(VARP x);

//ReduceOPs
MSMNN_PUBLIC VARP _ReduceSum(VARP input_variable, INTS axis = {}, bool keepDims = false);
MSMNN_PUBLIC VARP _ReduceMean(VARP input_variable, INTS axis = {}, bool keepDims = false);
MSMNN_PUBLIC VARP _ReduceMax(VARP input_variable, INTS axis = {}, bool keepDims = false);
MSMNN_PUBLIC VARP _ReduceMin(VARP input_variable, INTS axis = {}, bool keepDims = false);
MSMNN_PUBLIC VARP _ReduceProd(VARP input_variable, INTS axis = {}, bool keepDims = false);
MSMNN_PUBLIC VARP _ReduceAny(VARP input_variable, INTS axis = {}, bool keepDims = false);
MSMNN_PUBLIC VARP _ReduceAll(VARP input_variable, INTS axis = {}, bool keepDims = false);

MSMNN_PUBLIC VARP _ReduceSumMutable(VARP input_variable, VARP axis, bool keepDims = false);
MSMNN_PUBLIC VARP _ReduceMeanMutable(VARP input_variable, VARP axis, bool keepDims = false);
MSMNN_PUBLIC VARP _ReduceMaxMutable(VARP input_variable, VARP axis, bool keepDims = false);
MSMNN_PUBLIC VARP _ReduceMinMutable(VARP input_variable, VARP axis, bool keepDims = false);
MSMNN_PUBLIC VARP _ReduceProdMutable(VARP input_variable, VARP axis, bool keepDims = false);
MSMNN_PUBLIC VARP _ReduceAnyMutable(VARP input_variable, VARP axis, bool keepDims = false);
MSMNN_PUBLIC VARP _ReduceAllMutable(VARP input_variable, VARP axis, bool keepDims = false);

//EltwiseOPs
MSMNN_PUBLIC VARP _Prod(VARP a, VARP b, std::vector<float> coeff);
MSMNN_PUBLIC VARP _Sum(VARP a, VARP b, std::vector<float> coeff);
MSMNN_PUBLIC VARP _Max(VARP a, VARP b, std::vector<float> coeff);
MSMNN_PUBLIC VARP _Sub(VARP a, VARP b, std::vector<float> coeff);
MSMNN_PUBLIC VARP _EltwiseProdInt8(VARP x, VARP y, 
                    std::vector<int8_t> x_weight, std::vector<int32_t> x_bias, std::vector<float> x_scale, std::vector<float> x_tensorScale,
                    std::vector<int8_t> y_weight, std::vector<int32_t> y_bias, std::vector<float> y_scale, std::vector<float> y_tensorScale,
                    std::vector<int8_t> output_weight, std::vector<int32_t> output_bias, std::vector<float> output_scale, std::vector<float> output_tensorScale);
MSMNN_PUBLIC VARP _EltwiseSumInt8(VARP x, VARP y, 
                     std::vector<int8_t> x_weight, std::vector<int32_t> x_bias, std::vector<float> x_scale, std::vector<float> x_tensorScale,
                    std::vector<int8_t> y_weight, std::vector<int32_t> y_bias, std::vector<float> y_scale, std::vector<float> y_tensorScale,
                    std::vector<int8_t> output_weight, std::vector<int32_t> output_bias, std::vector<float> output_scale, std::vector<float> output_tensorScale);
MSMNN_PUBLIC VARP _EltwiseSubInt8(VARP x, VARP y, 
                     std::vector<int8_t> x_weight, std::vector<int32_t> x_bias, std::vector<float> x_scale, std::vector<float> x_tensorScale,
                    std::vector<int8_t> y_weight, std::vector<int32_t> y_bias, std::vector<float> y_scale, std::vector<float> y_tensorScale,
                    std::vector<int8_t> output_weight, std::vector<int32_t> output_bias, std::vector<float> output_scale, std::vector<float> output_tensorScale);
MSMNN_PUBLIC VARP _EltwiseMaxInt8(VARP x, VARP y, 
                      std::vector<int8_t> x_weight, std::vector<int32_t> x_bias, std::vector<float> x_scale, std::vector<float> x_tensorScale,
                    std::vector<int8_t> y_weight, std::vector<int32_t> y_bias, std::vector<float> y_scale, std::vector<float> y_tensorScale,
                    std::vector<int8_t> output_weight, std::vector<int32_t> output_bias, std::vector<float> output_scale, std::vector<float> output_tensorScale);
MSMNN_PUBLIC VARP _Mod(VARP x, VARP y);


//OtherOPs
template<typename T>
VARP _Cast(VARP x) {
    return _Cast(x, halide_type_of<T>());
}
MSMNN_PUBLIC VARP _Cast(VARP x, halide_type_t dtype);
MSMNN_PUBLIC VARP _MatMul(VARP a, VARP b, bool tranposeA = false, bool tranposeB = false);
MSMNN_PUBLIC VARP _Normalize(VARP x, int32_t acrossSpatial, int32_t channelShared, float eps, std::vector<float> scale);
MSMNN_PUBLIC VARP _ArgMax(VARP input, int axis = 0);
MSMNN_PUBLIC VARP _ArgMin(VARP input, int axis = 0);
MSMNN_PUBLIC VARP _BatchMatMul(VARP x, VARP y, bool adj_x = false, bool adj_y = false);
MSMNN_PUBLIC VARP _UnravelIndex(VARP indices, VARP dims);
MSMNN_PUBLIC VARP _ScatterNd(VARP indices, VARP updates, VARP shape);
MSMNN_PUBLIC VARP _ScatterNd(VARP indices, VARP updates, VARP shape, VARP input);
MSMNN_PUBLIC VARP _ScatterNd(VARP indices, VARP updates, VARP shape, int reduction);
MSMNN_PUBLIC VARP _ScatterNd(VARP indices, VARP updates, VARP shape, VARP input, int reduction);
MSMNN_PUBLIC VARP _ScatterElements(VARP data, VARP indices, VARP updates, int reduction = -1);
MSMNN_PUBLIC VARP _ScatterElements(VARP data, VARP indices, VARP updates, VARP axis, int reduction = -1);
MSMNN_PUBLIC VARP _OneHot(VARP indices, VARP depth, VARP onValue, VARP offValue, int axis = -1);
MSMNN_PUBLIC VARP _BroadcastTo(VARP a, VARP shape);
MSMNN_PUBLIC VARP _LinSpace(VARP start, VARP stop, VARP num);

MSMNN_PUBLIC VARP _RandomUnifom(VARP shape, halide_type_t dtype, float low = 0.0f, float high = 1.0f, int seed0 = 0, int seed1 = 0);
MSMNN_PUBLIC VARP _CumSum(VARP x, int axis, bool exclusive = false, bool reverse = false);
MSMNN_PUBLIC VARP _CumProd(VARP x, int axis);
MSMNN_PUBLIC VARPS _Svd(VARP x);
MSMNN_PUBLIC VARP _Histogram(VARP x, int bin, int min, int max, int channel = -1);
}; // namespace Express
}; // namespace MSMNN

#endif /* MathOp_HPP */
