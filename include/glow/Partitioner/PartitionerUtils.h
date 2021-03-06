/**
 * Copyright (c) 2017-present, Facebook, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef GLOW_PARTITIONER_PARTITIONUTILS_H
#define GLOW_PARTITIONER_PARTITIONUTILS_H

#include "glow/Graph/Graph.h"

namespace glow {

/// The memory usage of a subgraph (i.e. a list of nodes of a function).
struct GraphMemInfo {
  // The memory usage of all input nodes (whose predecessors are not included in
  // this subgraph) of this subgraph.
  uint64_t inMemSize;
  // The memory usage of all output nodes (whose successors are not included in
  // this subgraph) of this subgraph.
  uint64_t outMemSize;
  // The memory usage of all constants used in this subgraph.
  uint64_t constMemSize;

  GraphMemInfo() : inMemSize(0), outMemSize(0), constMemSize(0){};
};

/// Given \p nodes, return a list of nodes who use any node in this set.
std::vector<Node *> getOutUsers(const std::set<Node *> &nodes);

/// Given \p nodes, return a list of nodes who use only the nodes in this set or
/// constant.
std::vector<Node *>
getOutUsersWithOnePredecessor(const std::set<Node *> &nodes);

/// Return the memory usage of a given nodes set.
GraphMemInfo getGraphMemInfo(const std::set<Node *> &nodes);
} // namespace glow
#endif // GLOW_PARTITIONER_PARTITIONUTILS_H
