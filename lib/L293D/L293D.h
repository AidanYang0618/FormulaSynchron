/**
 * @file L293D.h
 * @author magician-do
 * @brief 基于库AFMotor对L293D的封装
 * @version 0.1
 * @date 2022-04-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef _L293D_H_
#define _L293D_H_

#include <Arduino.h>

#include "AFMotor.h"

namespace motor {
// 速度修正
void correctSpeed();
// 设置方向
void setDirection();
// 设置总速度
void setTolSpeed();
// 设置左侧速度
void setLeftSpeed();
// 设置右侧速度
void setRightSpeed();
// 设置方向
void setDirection();
// 设置总速度
void setTolSpeed();
// 设置左侧速度
void set_leftSpeed();
// 设置右侧速度
void set_rightSpeed();
}  // namespace motor

/**
 * @brief Construct a new L293D object
 *
 * @param Lfront 左前轮电机端口号
 * @param Rfront 右前轮电机端口号
 * @param Lrear  左后轮电机端口号
 * @param Rrear  右后轮电机端口号
 *
 * @deprecated 已失效
 */
void L293D(const short Lfront, const short Rfront, const short Lrear, const short Rrear);
/**
 * @brief 提高指定量速度
 *
 * @param variable 变化量
 */
void upSpeed(const short variable);
/**
 * @brief 减少指定量速度
 *
 * @param variable 变化量
 */
void downSpeed(const short variable);
/**
 * @brief 重新设定速度
 *
 * @param tolSpeed 需设定的速度值
 */
void setSpeed(const short tolSpeed);
// 熄火
void carStop();
/**
 * @brief 刹车
 *
 * @deprecated 太难写了
 */
void brake();
// 变为前进状态
void straight();
// 变为左转状态
void turnLeft();
// 变为右转状态
void turnRight();
// 变为原地掉头状态
void turnRound();
// 变为后退状态
void backup();

#endif