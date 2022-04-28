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
#include <stdio.h>

#include "AFMotor.h"

namespace motor {
    short leftSpeed_;   // 左侧速度
    short rightSpeed_;  // 右侧速度
    short tolSpeed_;    // 总速度
    bool direction;     // 方向 true = 正向
    AF_DCMotor Lfront_;
    AF_DCMotor Rfront_;
    AF_DCMotor Lrear_;
    AF_DCMotor Rrear_;
    // 速度修正
    void correctSpeed() {
        leftSpeed_ = tolSpeed_;
        rightSpeed_ = tolSpeed_;
    }
    // 设置方向
    void setDirection() {
        if (direction) {
            Lfront_.run(FORWARD);
            Rfront_.run(FORWARD);
            Lrear_.run(FORWARD);
            Rrear_.run(FORWARD);
        } else {
            Lfront_.run(BACKWARD);
            Rfront_.run(BACKWARD);
            Lrear_.run(BACKWARD);
            Rrear_.run(BACKWARD);
        }
    }
    // 设置总速度
    void setTolSpeed() {
        Lfront_.setSpeed(tolSpeed_);
        Rfront_.setSpeed(tolSpeed_);
        Lrear_.setSpeed(tolSpeed_);
        Rrear_.setSpeed(tolSpeed_);
    }
    // 设置左侧速度
    void setLeftSpeed() {
        Lfront_.setSpeed(leftSpeed_);
        Lrear_.setSpeed(leftSpeed_);
    }
    // 设置右侧速度
    void setRightSpeed() {
        Rfront_.setSpeed(rightSpeed_);
        Rrear_.setSpeed(rightSpeed_);
    }
}

/**
 * @brief Construct a new L293D object
 *
 * @param Lfront 左前轮电机端口号
 * @param Rfront 右前轮电机端口号
 * @param Lrear  左后轮电机端口号
 * @param Rrear  右后轮电机端口号
 */
void L293D(const short Lfront,
           const short Rfront,
           const short Lrear,
           const short Rrear);
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