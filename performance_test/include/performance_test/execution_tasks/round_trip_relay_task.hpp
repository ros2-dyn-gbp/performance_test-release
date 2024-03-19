// Copyright 2022-2024 Apex.AI, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef PERFORMANCE_TEST__EXECUTION_TASKS__ROUND_TRIP_RELAY_TASK_HPP_
#define PERFORMANCE_TEST__EXECUTION_TASKS__ROUND_TRIP_RELAY_TASK_HPP_

#include <memory>

#include "performance_test/experiment_configuration/experiment_configuration.hpp"
#include "performance_test/experiment_metrics/message_received_listener.hpp"
#include "performance_test/plugin/publisher.hpp"
#include "performance_test/plugin/subscriber.hpp"
#include "performance_test/utilities/memory_checker.hpp"

namespace performance_test
{
class RoundTripRelayTask : public MessageReceivedListener
{
public:
  RoundTripRelayTask(
    const ExperimentConfiguration & ec,
    std::unique_ptr<Publisher> && pub,
    std::unique_ptr<Subscriber> && sub);

  RoundTripRelayTask & operator=(const RoundTripRelayTask &) = delete;
  RoundTripRelayTask(const RoundTripRelayTask &) = delete;

  void run();

  void on_message_received(
    const std::int64_t time_msg_sent_ns,
    const std::int64_t,
    const std::uint64_t sample_id,
    const std::size_t
  ) override;

private:
  std::unique_ptr<Publisher> m_pub;
  std::unique_ptr<Subscriber> m_sub;
  MemoryChecker m_memory_checker;
};

}  // namespace performance_test

#endif  // PERFORMANCE_TEST__EXECUTION_TASKS__ROUND_TRIP_RELAY_TASK_HPP_