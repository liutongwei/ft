// Copyright [2020] <Copyright Kevin, kevin.lau.gd@gmail.com>

#ifndef FT_SRC_TRADER_RISK_MANAGEMENT_COMMON_NO_SELF_TRADE_H_
#define FT_SRC_TRADER_RISK_MANAGEMENT_COMMON_NO_SELF_TRADE_H_

#include <map>
#include <string>

#include "spdlog/spdlog.h"
#include "trader/risk_management/risk_rule.h"

namespace ft {

// 拦截自成交订单，检查相反方向的挂单
// 1. 市价单
// 2. 非市价单的其他订单，且价格可以成功撮合的
class NoSelfTradeRule : public RiskRule {
 public:
  bool Init(RiskRuleParams* params) override;

  int CheckOrderRequest(const Order* req) override;

 private:
  OrderMap* order_map_;
};

}  // namespace ft

#endif  // FT_SRC_TRADER_RISK_MANAGEMENT_COMMON_NO_SELF_TRADE_H_
