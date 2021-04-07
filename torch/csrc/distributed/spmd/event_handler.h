#pragma once

#include <torch/csrc/distributed/spmd/event.h>

#include <vector>

#include <ATen/core/ivalue.h>
#include <torch/csrc/utils/memory.h>

namespace torch {
namespace distributed {
namespace spmd {

using c10::ivalue::Future;

class TORCH_API EventHandler {
 public:
  virtual std::vector<EventSchema> ingressEvents() const = 0;
  virtual std::vector<EventSchema> egressEvents() const = 0;
  // returned Future contents Event objects generated by this handler.
  virtual std::vector<std::shared_ptr<Future>> handleEvent(
      const c10::intrusive_ptr<Event>&) = 0;

  virtual ~EventHandler() {}
};

} // namespace spmd
} // namespace distributed
} // namespace torch
