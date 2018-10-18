#pragma once
#include "cpu/vision.h"

at::Tensor nms(const at::Tensor& dets,
               const at::Tensor& scores,
               const float threshold) {

  if (dets.type().is_cuda())
    AT_ERROR("NMS not implemented on the GPU");

  at::Tensor result = nms_cpu(dets, scores, threshold);
  return result;
}