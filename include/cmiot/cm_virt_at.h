/**
 * @file        cm_virt_at.h
 * @brief       虚拟AT通道接口
 * @copyright   Copyright © 2021 China Mobile IOT. All rights reserved.
 * @author      By XGL
 * @date        2022/07/10
 *
 * @defgroup virt_at virt_at
 * @ingroup virt_at
 * @{
 */

#ifndef __CM_VIRT_AT_H__
#define __CM_VIRT_AT_H__

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <stdint.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/


/****************************************************************************
 * Public Types
 ****************************************************************************/


/****************************************************************************
 * Public Data
 ****************************************************************************/


/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/
/****************************************************************************
 * *********************虚拟AT需注意事项*************************************
 * 虚拟AT不完全支持中移开发的AT手册中的指令,仅支持3GPP的AT指令
 * 例如：AT+MUESTATS=radio  AT+MUESTATS=scell  AT+MUESTATS=sband 等AT指令不支持
 * 用户需根据实际使用测试结果为准
 ***************************************************************************/

#ifdef __cplusplus
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/**虚拟AT通道回调函数类型*/
typedef void (*cm_virt_at_cb)(void *param);

/**
 * @brief 初始化AT虚拟通道
 * 
 * @param [in] cb AT虚拟通道消息回调函数
 *
 * @return 
 *   = 0  - 成功 \n
 *   < 0  - 失败
 * 
 * @details More details
 */
int32_t cm_virt_at_init(cm_virt_at_cb cb);
/**
 * @brief 通过AT虚拟通道发送数据
 * 
 * @param [in] data 数据缓冲区指针
 * @param [in] len  要发送的数据长度
 *
 * @return 
 *   >= 0  - 实际发送的长度 \n
 *   < 0   - 失败
 * 
 * @details More details
 */
int32_t cm_virt_at_send(uint8_t * data,int32_t len);
/**
 * @brief 通过AT虚拟通道接收数据
 * 
 * @param [in] data 数据缓冲区指针
 * @param [in] len  数据缓冲区长度
 *
 * @return 
 *   >= 0  - 实际接收的长度 \n
 *   < 0   - 失败
 * 
 * @details More details
 */
int32_t cm_virt_at_get(unsigned char* data,int len);

/**
 * @brief AT虚拟通道去初始化
 *
 * @return 
 *   空
 * 
 * @details More details
 */
void cm_virt_at_deinit(void);

#undef EXTERN
#ifdef __cplusplus
}
#endif

#endif /* __CM_VIRT_AT_H__ */

/** @}*/
