//
//  ExecutorScope.hpp
//  MSMNN
//
//  Created by MSMNN on 2020/10/26.
//  Copyright © 2018, Alibaba Group Holding Limited
//

#ifndef MSMNN_EXPR_EXECUTOR_SCOPE_HPP_
#define MSMNN_EXPR_EXECUTOR_SCOPE_HPP_

#include <MSMNN/expr/Executor.hpp>

namespace MSMNN {
namespace Express {

struct MSMNN_PUBLIC ExecutorScope final {
public:
    ExecutorScope() = delete;
    explicit ExecutorScope(const ExecutorScope&) = delete;
    explicit ExecutorScope(const std::shared_ptr<Executor>& current);

    explicit ExecutorScope(const std::string& scope_name,
                           const std::shared_ptr<Executor>& current);

    virtual ~ExecutorScope();

    static const std::shared_ptr<Executor> Current();
};

}  // namespace MSMNN
}  // namespace Express
#endif  // MSMNN_EXPR_EXECUTOR_SCOPE_HPP_
