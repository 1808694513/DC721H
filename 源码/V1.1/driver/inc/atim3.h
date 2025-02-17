/******************************************************************************
 * Copyright (C) 2021, Xiaohua Semiconductor Co., Ltd. All rights reserved.
 *
 * This software component is licensed by XHSC under BSD 3-Clause license
 * (the "License"); You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                    opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************/

/******************************************************************************
 ** @file atim3.h
 **
 ** @brief Header file for ATIM3 functions
 **
 ** @author MADS Team 
 **
 ******************************************************************************/

#ifndef __TIMER3_H__
#define __TIMER3_H__

/*****************************************************************************
 * Include files
 *****************************************************************************/
#include "ddl.h"


#ifdef __cplusplus
extern "C"
{
#endif

/**
 ******************************************************************************
 ** \defgroup Tim3Group Timer3 (TIM3)
  **
 ******************************************************************************/
//@{
    
/******************************************************************************/
/* Global pre-processor symbols/macros ('#define')                            */
/******************************************************************************/

/******************************************************************************
 * Global type definitions
 ******************************************************************************/


/**
 ******************************************************************************
 ** \brief ATIM3 mode0 配置结构体定义(模式0)
 *****************************************************************************/
typedef struct stc_atim3_mode0_cfg
{
    uint32_t     u32WorkMode;       ///< 工作模式设置
    uint32_t     u32GatePolar;      ///< 门控极性控制
    uint32_t     u32EnGate;         ///< 门控使能
    uint32_t     u32PRS;            ///< 预除频配置
    uint32_t     u32EnTog;          ///< 翻转输出使能
    uint32_t     u32CountClkSel;    ///< 定时/计数功能选择
    uint32_t     u32CntMode;        ///< 计数模式配置
}stc_atim3_mode0_cfg_t;


/** @defgroup stc_atim3_mode0_cfg_t WorkMode
  * @{
  */
#define ATIM3_M0_M0CR_WORK_MODE_TIMER                   (0x00000000u)
#define ATIM3_M0_M0CR_WORK_MODE_PWC                     (1u<<ATIM3MODE0_M0CR_MODE_Pos)
#define ATIM3_M0_M0CR_WORK_MODE_SAWTOOTH                (2u<<ATIM3MODE0_M0CR_MODE_Pos)
#define ATIM3_M0_M0CR_WORK_MODE_TRIANGULAR              (ATIM3MODE0_M0CR_MODE)
/**
  * @}
  */


/** @defgroup stc_atim3_mode0_cfg_t GatePolar
  * @{
  */
#define ATIM3_M0_M0CR_GATE_POLAR_HIGH           (0x00000000u)
#define ATIM3_M0_M0CR_GATE_POLAR_LOW            (ATIM3MODE0_M0CR_GATEP)
/**
  * @}
  */

/** @defgroup stc_atim3_mode0_cfg_t Gate Enable
  * @{
  */
#define ATIM3_M0_M0CR_GATE_OFF                (0x00000000u)
#define ATIM3_M0_M0CR_GATE_ON                 (ATIM3MODE0_M0CR_GATE)
/**
  * @}
  */



/** @defgroup stc_atim3_mode0_cfg_t PRS config
  * @{
  */
#define ATIM3_M0_M0CR_ATIM3CLK_PRS1                (0x00000000u)
#define ATIM3_M0_M0CR_ATIM3CLK_PRS2                (1u<<ATIM3MODE0_M0CR_PRS_Pos)
#define ATIM3_M0_M0CR_ATIM3CLK_PRS4                (2u<<ATIM3MODE0_M0CR_PRS_Pos)
#define ATIM3_M0_M0CR_ATIM3CLK_PRS8                (3u<<ATIM3MODE0_M0CR_PRS_Pos)
#define ATIM3_M0_M0CR_ATIM3CLK_PRS16               (4u<<ATIM3MODE0_M0CR_PRS_Pos)
#define ATIM3_M0_M0CR_ATIM3CLK_PRS32               (5u<<ATIM3MODE0_M0CR_PRS_Pos)
#define ATIM3_M0_M0CR_ATIM3CLK_PRS64               (6u<<ATIM3MODE0_M0CR_PRS_Pos)
#define ATIM3_M0_M0CR_ATIM3CLK_PRS256              (ATIM3MODE0_M0CR_PRS)
/**
  * @}
  */

/** @defgroup stc_atim3_mode0_cfg_t Tog Enable or Disable command
  * @{
  */
#define ATIM3_M0_M0CR_TOG_OFF            (0x00000000u)
#define ATIM3_M0_M0CR_TOG_ON             (ATIM3MODE0_M0CR_TOG)
/**
  * @}
  */
    
/** @defgroup stc_atim3_mode0_cfg_t Count Clock Selection
  * @{
  */
#define ATIM3_M0_M0CR_CT_PCLK                (0x00000000u)
#define ATIM3_M0_M0CR_CT_ETR                 (ATIM3MODE0_M0CR_CT)
/**
  * @}
  */

/** @defgroup stc_atim3_mode0_cfg_t Count Mode Selection
  * @{
  */
#define ATIM3_M0_M0CR_MD_32BIT_FREE                (0x00000000u)
#define ATIM3_M0_M0CR_MD_16BIT_ARR                 (ATIM3MODE0_M0CR_MD)
/**
  * @}
  */
   


/**
 ******************************************************************************
 ** \brief ATIM3 mode1 配置结构体定义(模式1)
 *****************************************************************************/
typedef struct stc_atim3_mode1_cfg
{
    uint32_t     u32WorkMode;       ///< 工作模式设置
    uint32_t     u32PRS;            ///< 预除频配置
    uint32_t     u32CountClkSel;    ///< 定时/计数功能选择
    uint32_t     u32ShotMode;       ///< 单次测量/循环测量选择
}stc_atim3_mode1_cfg_t;


/** @defgroup stc_atim3_mode1_cfg_t WorkMode
  * @{
  */
#define ATIM3_M1_M1CR_WORK_MODE_TIMER                   (0x00000000u)
#define ATIM3_M1_M1CR_WORK_MODE_PWC                     (1u<<ATIM3MODE1_M1CR_MODE_Pos)
#define ATIM3_M1_M1CR_WORK_MODE_SAWTOOTH                (2u<<ATIM3MODE1_M1CR_MODE_Pos)
#define ATIM3_M1_M1CR_WORK_MODE_TRIANGULAR              (ATIM3MODE1_M1CR_MODE)
/**
  * @}
  */

/** @defgroup stc_atim3_mode1_cfg_t PRS config
  * @{
  */
#define ATIM3_M1_M1CR_ATIM3CLK_PRS1                (0x00000000u)
#define ATIM3_M1_M1CR_ATIM3CLK_PRS2                (1u<<ATIM3MODE1_M1CR_PRS_Pos)
#define ATIM3_M1_M1CR_ATIM3CLK_PRS4                (2u<<ATIM3MODE1_M1CR_PRS_Pos)
#define ATIM3_M1_M1CR_ATIM3CLK_PRS8                (3u<<ATIM3MODE1_M1CR_PRS_Pos)
#define ATIM3_M1_M1CR_ATIM3CLK_PRS16               (4u<<ATIM3MODE1_M1CR_PRS_Pos)
#define ATIM3_M1_M1CR_ATIM3CLK_PRS32               (5u<<ATIM3MODE1_M1CR_PRS_Pos)
#define ATIM3_M1_M1CR_ATIM3CLK_PRS64               (6u<<ATIM3MODE1_M1CR_PRS_Pos)
#define ATIM3_M1_M1CR_ATIM3CLK_PRS256              (ATIM3MODE1_M1CR_PRS)
/**
  * @}
  */

/** @defgroup stc_atim3_mode1_cfg_t Count Clock Selection
  * @{
  */
#define ATIM3_M1_M1CR_CT_PCLK                (0x00000000u)
#define ATIM3_M1_M1CR_CT_ETR                 (ATIM3MODE1_M1CR_CT)
/**
  * @}
  */


/** @defgroup stc_atim3_mode1_cfg_t shot mode selection
  * @{
  */
#define ATIM3_M1_M1CR_SHOT_CYCLE               (0x00000000u)
#define ATIM3_M1_M1CR_SHOT_ONE                 (ATIM3MODE1_M1CR_ONESHOT)
/**
  * @}
  */

/** @defgroup stc_atim3_mode1_cfg_t PWC Start Edge and END Edge 
  * @{
  */
#define ATIM3_M1_M1CR_DETECT_EDGE_RISE_TO_RISE    (0x00000000u)
#define ATIM3_M1_M1CR_DETECT_EDGE_FALL_TO_RISE    (ATIM3MODE1_M1CR_EDG1ST)
#define ATIM3_M1_M1CR_DETECT_EDGE_RISE_TO_FALL    (ATIM3MODE1_M1CR_EDG2ND)
#define ATIM3_M1_M1CR_DETECT_EDGE_FALL_TO_FALL    (ATIM3MODE1_M1CR_EDG2ND | ATIM3MODE1_M1CR_EDG1ST)
/**
  * @}
  */

/**
 ******************************************************************************
 ** \brief PWC输入配置结构体定义(模式1)
 *****************************************************************************/
typedef struct stc_atim3_pwc_input_cfg
{
    uint32_t     u32TsSel;       ///< 触发输入源选择
    uint32_t     u32IA0Sel;      ///< CHA0输入选择
    uint32_t     u32IB0Sel;      ///< CHB0输入选择
    uint32_t     u32ETR;         ///< ETR相位选择
    uint32_t     u32FltETR;      ///< ETR滤波设置
    uint32_t     u32FltIA0;      ///< CHA0滤波设置
    uint32_t     u32FltIB0;      ///< CHB0滤波设置
}stc_atim3_pwc_input_cfg_t;

/** @defgroup stc_atim3_pwc_input_t MSCR_TS trigger source selection
  * @{
  */
#define ATIM3_M1_MSCR_TS_ETR               (0x00000000u)
#define ATIM3_M1_MSCR_TS_ITR0              (1u<<ATIM3MODE1_MSCR_TS_Pos)
#define ATIM3_M1_MSCR_TS_ITR1              (2u<<ATIM3MODE1_MSCR_TS_Pos)
#define ATIM3_M1_MSCR_TS_ITR2              (3u<<ATIM3MODE1_MSCR_TS_Pos)
#define ATIM3_M1_MSCR_TS_ITR3              (4u<<ATIM3MODE1_MSCR_TS_Pos)
#define ATIM3_M1_MSCR_TS_CH0A_EDGE         (5u<<ATIM3MODE1_MSCR_TS_Pos)
#define ATIM3_M1_MSCR_TS_CH0A_FILTER       (6u<<ATIM3MODE1_MSCR_TS_Pos)
#define ATIM3_M1_MSCR_TS_CH0B_FILTER       (ATIM3MODE1_MSCR_TS)
/**
  * @}
  */

/** @defgroup stc_atim3_pwc_input_t MSCR_IA0S input selection
  * @{
  */
#define ATIM3_M1_MSCR_IA0S_CH0A          (0x00000000u)
#define ATIM3_M1_MSCR_IA0S_CH012A_XOR    (ATIM3MODE1_MSCR_IA0S)
/**
  * @}
  */

/** @defgroup stc_atim3_pwc_input_t MSCR_IB0S input selection
  * @{
  */
#define ATIM3_M1_MSCR_IB0S_CH0B          (0x00000000u)
#define ATIM3_M1_MSCR_IB0S_TS_SEL        (ATIM3MODE1_MSCR_IB0S)
/**
  * @}
  */


/** @defgroup stc_atim3_pwc_input_t FLTR_FLTA0 CHA/CHB/ETR input filter config
  * @{
  */
#define ATIM3_M1_FLTR_FLTA0_B0_ET_NONE          (0x00000000u)
#define ATIM3_M1_FLTR_FLTA0_B0_ET_3_PCLK        (4u<<ATIM3MODE1_FLTR_FLTA0_Pos)
#define ATIM3_M1_FLTR_FLTA0_B0_ET_3_PCLKDIV4    (5u<<ATIM3MODE1_FLTR_FLTA0_Pos)
#define ATIM3_M1_FLTR_FLTA0_B0_ET_3_PCLKDIV16   (6u<<ATIM3MODE1_FLTR_FLTA0_Pos)
#define ATIM3_M1_FLTR_FLTA0_B0_ET_3_PCLKDIV64   (ATIM3MODE1_FLTR_FLTA0)
/**
  * @}
  */


/** @defgroup stc_atim3_pwc_input_t FLTR_ETP ET Polarity Config
  * @{
  */
#define ATIM3_M1_FLTR_ETP_POLARITY_POSITIVE        (0x00000000u)
#define ATIM3_M1_FLTR_ETP_POLARITY_NEGATIVE        (ATIM3MODE1_FLTR_ETP)
/**
  * @}
  */



/**
 ******************************************************************************
 ** \brief ATIM3 mode23 配置结构体定义(模式23)
 *****************************************************************************/
typedef struct stc_atim3_mode23_cfg
{
    uint32_t      u32WorkMode;       ///< 工作模式设置
    uint32_t      u32CntDir;         ///< 计数方向
    uint32_t      u32PRS;            ///< 时钟预除频配置
    uint32_t      u32CountClkSel;    ///< 定时/计数功能选择
    uint32_t      u32PWMTypeSel;     ///< PWM模式选择（独立/互补）
    uint32_t      u32PWM2sSel;       ///< OCREFA双点比较功能选择
    uint32_t      u32ShotMode;        ///< 单次触发模式使能/禁止
    uint32_t      u32URSSel;         ///< 更新源选择
}stc_atim3_mode23_cfg_t;

/** @defgroup stc_atim3_mode23_cfg_t WorkMode
  * @{
  */
#define ATIM3_M23_M23CR_WORK_MODE_TIMER                   (0x00000000u)
#define ATIM3_M23_M23CR_WORK_MODE_PWC                     (1u<<ATIM3MODE23_M23CR_MODE_Pos)
#define ATIM3_M23_M23CR_WORK_MODE_SAWTOOTH                (2u<<ATIM3MODE23_M23CR_MODE_Pos)
#define ATIM3_M23_M23CR_WORK_MODE_TRIANGULAR              (ATIM3MODE23_M23CR_MODE)
/**
  * @}
  */


/** @defgroup stc_atim3_mode23_cfg_t PRS config
  * @{
  */
#define ATIM3_M23_M23CR_ATIM3CLK_PRS1                (0x00000000u)
#define ATIM3_M23_M23CR_ATIM3CLK_PRS2                (1u<<ATIM3MODE23_M23CR_PRS_Pos)
#define ATIM3_M23_M23CR_ATIM3CLK_PRS4                (2u<<ATIM3MODE23_M23CR_PRS_Pos)
#define ATIM3_M23_M23CR_ATIM3CLK_PRS8                (3u<<ATIM3MODE23_M23CR_PRS_Pos)
#define ATIM3_M23_M23CR_ATIM3CLK_PRS16               (4u<<ATIM3MODE23_M23CR_PRS_Pos)
#define ATIM3_M23_M23CR_ATIM3CLK_PRS32               (5u<<ATIM3MODE23_M23CR_PRS_Pos)
#define ATIM3_M23_M23CR_ATIM3CLK_PRS64               (6u<<ATIM3MODE23_M23CR_PRS_Pos)
#define ATIM3_M23_M23CR_ATIM3CLK_PRS256              (ATIM3MODE23_M23CR_PRS)
/**
  * @}
  */


/** @defgroup stc_atim3_mode23_cfg_t Count Direction Selection
  * @{
  */
#define ATIM3_M23_M23CR_DIR_UP_CNT             (0x00000000u)
#define ATIM3_M23_M23CR_DIR_DOWN_CNT           (ATIM3MODE23_M23CR_DIR)
/**
  * @}
  */


/** @defgroup stc_atim3_mode23_cfg_t Count Clock Selection
  * @{
  */
#define ATIM3_M23_M23CR_CT_PCLK                (0x00000000u)
#define ATIM3_M23_M23CR_CT_ETR                 (ATIM3MODE23_M23CR_CT)
/**
  * @}
  */

/** @defgroup stc_atim3_mode23_cfg_t PWM Type Selection
  * @{
  */
#define ATIM3_M23_M23CR_COMP_PWM_INDEPT        (0x00000000u)
#define ATIM3_M23_M23CR_COMP_PWM_COMP          (ATIM3MODE23_M23CR_COMP)
/**
  * @}
  */

/** @defgroup stc_atim3_mode23_cfg_t OCREFA Compare type Selection
  * @{
  */
#define ATIM3_M23_M23CR_PWM2S_COMPARE_DOUBLE_POINT    (0x00000000u)
#define ATIM3_M23_M23CR_PWM2S_COMPARE_SINGLE_POINT     (ATIM3MODE23_M23CR_PWM2S)
/**
  * @}
  */

/** @defgroup stc_atim3_mode23_cfg_t shot mode selection
  * @{
  */
#define ATIM3_M23_M23CR_SHOT_CYCLE             (0x00000000u)
#define ATIM3_M23_M23CR_SHOT_ONE               (ATIM3MODE23_M23CR_ONESHOT)
/**
  * @}
  */

/** @defgroup stc_atim3_mode23_cfg_t Refresh Source selection
  * @{
  */
#define ATIM3_M23_M23CR_URS_OV_UND_UG_RST      (0x00000000u)
#define ATIM3_M23_M23CR_URS_OV_UND             (ATIM3MODE23_M23CR_URS)
/**
  * @}
  */


/** @defgroup Atimer3 CCRxx channel number define
  * @{
  */
#define  ATIM3_COMPARE_CAPTURE_CH0A                  0    //ATIM3_CCR0A相对于ATIM3_CCR0A的偏移
#define  ATIM3_COMPARE_CAPTURE_CH0B                  1    //ATIM3_CCR0B相对于ATIM3_CCR0A的偏移
#define  ATIM3_COMPARE_CAPTURE_CH1A                  2    //ATIM3_CCR1A相对于ATIM3_CCR0A的偏移
#define  ATIM3_COMPARE_CAPTURE_CH1B                  3    //ATIM3_CCR1B相对于ATIM3_CCR0A的偏移
#define  ATIM3_COMPARE_CAPTURE_CH2A                  4    //ATIM3_CCR2A相对于ATIM3_CCR0A的偏移
#define  ATIM3_COMPARE_CAPTURE_CH2B                  5    //ATIM3_CCR2B相对于ATIM3_CCR0A的偏移
#define  ATIM3_COMPARE_CAPTURE_CH3                   6    //ATIM3_CCR3 相对于ATIM3_CCR0A的偏移
/**
  * @}
  */
    
    
    
/**
 ******************************************************************************
 ** \brief GATE在PWM互补模式下捕获或比较功能 配置结构体定义(模式23)
 *****************************************************************************/
typedef struct stc_atim3_m23_gate_cfg
{
    uint32_t        u32GateFuncSel;      ///< Gate比较、捕获功能选择
    uint32_t        u32GateRiseCap;       ///< GATE作为捕获功能时，上沿捕获有效控制
    uint32_t        u32GateFallCap;       ///< GATE作为捕获功能时，下沿捕获有效控制
}stc_atim3_m23_gate_cfg_t;


/** @defgroup stc_atim3_mode23_gate_cfg Gate function setting
  * @{
  */
#define ATIM3_M23_M23CR_GATE_FUN_COMPARE      (0x00000000u)
#define ATIM3_M23_M23CR_GATE_FUN_CAPTURE      (ATIM3MODE23_M23CR_CSG)
/**
  * @}
  */

/** @defgroup stc_atim3_mode23_gate_cfg Rising capture enable as Gate used for capture
  * @{
  */
#define ATIM3_M23_M23CR_GATE_CAP_RISE_DISABLE      (0x00000000u)
#define ATIM3_M23_M23CR_GATE_CAP_RISE_ENABLE       (ATIM3MODE23_M23CR_CRG)
/**
  * @}
  */

/** @defgroup stc_atim3_mode23_gate_cfg Falling capture enable as Gate used for capture
  * @{
  */
#define ATIM3_M23_M23CR_GATE_CAP_FALL_DISABLE      (0x00000000u)
#define ATIM3_M23_M23CR_GATE_CAP_FALL_ENABLE       (ATIM3MODE23_M23CR_CFG)
/**
  * @}
  */

/**
 ******************************************************************************
 ** \brief  主从触发 配置结构体定义(模式23)
 *****************************************************************************/
typedef struct stc_atim3_m23_master_slave_cfg
{
    uint32_t      u32MasterSlaveSel;  ///< 主从模式选择
    uint32_t      u32MasterSrc;       ///< 主模式触发源选择
    uint32_t      u32SlaveModeSel;    ///< 从模式选择
    uint32_t      u32TsSel;           ///< 触发输入源选择
}stc_atim3_m23_master_slave_cfg_t;


/** @defgroup stc_atim3_mode23_master_slave_cfg Master or Slave Mode for trigger Setting
  * @{
  */
#define ATIM3_M23_MSCR_MSM_SlAVE      (0x00000000u)
#define ATIM3_M23_MSCR_MSM_MASTER     (ATIM3MODE23_MSCR_MSM)
/**
  * @}
  */

/** @defgroup stc_atim3_mode23_master_slave_cfg Trigger Source of Master Setting
  * @{
  */
#define ATIM3_M23_MSCR_MMS_TRIG_SOURCE_UG         (0x00000000u)
#define ATIM3_M23_MSCR_MMS_TRIG_SOURCE_CTEN       (1u<<ATIM3MODE23_MSCR_MMS_Pos)
#define ATIM3_M23_MSCR_MMS_TRIG_SOURCE_UEV        (2u<<ATIM3MODE23_MSCR_MMS_Pos)
#define ATIM3_M23_MSCR_MMS_TRIG_SOURCE_CMPSO      (3u<<ATIM3MODE23_MSCR_MMS_Pos)
#define ATIM3_M23_MSCR_MMS_TRIG_SOURCE_OCREF0A    (4u<<ATIM3MODE23_MSCR_MMS_Pos)
#define ATIM3_M23_MSCR_MMS_TRIG_SOURCE_OCREF1A    (5u<<ATIM3MODE23_MSCR_MMS_Pos)
#define ATIM3_M23_MSCR_MMS_TRIG_SOURCE_OCREF2A    (6u<<ATIM3MODE23_MSCR_MMS_Pos)
#define ATIM3_M23_MSCR_MMS_TRIG_SOURCE_OCREF0B    (ATIM3MODE23_MSCR_MMS)
/**
  * @}
  */

/** @defgroup stc_atim3_mode23_master_slave_cfg Slave Mode Function Setting
  * @{
  */
#define ATIM3_M23_MSCR_SMS_INTERNAL_CLK      (0x00000000u)
#define ATIM3_M23_MSCR_SMS_RESET             (1u<<ATIM3MODE23_MSCR_SMS_Pos)
#define ATIM3_M23_MSCR_SMS_TRIG              (2u<<ATIM3MODE23_MSCR_SMS_Pos)
#define ATIM3_M23_MSCR_SMS_EXTERNAL_CLK      (3u<<ATIM3MODE23_MSCR_SMS_Pos)
#define ATIM3_M23_MSCR_SMS_QUADRATURE_M1     (4u<<ATIM3MODE23_MSCR_SMS_Pos)
#define ATIM3_M23_MSCR_SMS_QUADRATURE_M2     (5u<<ATIM3MODE23_MSCR_SMS_Pos)
#define ATIM3_M23_MSCR_SMS_QUADRATURE_M3     (6u<<ATIM3MODE23_MSCR_SMS_Pos)
#define ATIM3_M23_MSCR_SMS_GATE              (ATIM3MODE23_MSCR_SMS)
/**
  * @}
  */

/** @defgroup stc_atim3_mode23_master_slave_cfg Trigger Source Setting
  * @{
  */
#define ATIM3_M23_MSCR_TS_ETFP       (0x00000000u)
#define ATIM3_M23_MSCR_TS_ITR0       (1u<<ATIM3MODE23_MSCR_TS_Pos)
#define ATIM3_M23_MSCR_TS_ITR1       (2u<<ATIM3MODE23_MSCR_TS_Pos)
#define ATIM3_M23_MSCR_TS_ITR2       (3u<<ATIM3MODE23_MSCR_TS_Pos)
#define ATIM3_M23_MSCR_TS_ITR3       (4u<<ATIM3MODE23_MSCR_TS_Pos)
#define ATIM3_M23_MSCR_TS_CH0A_EDGE  (5u<<ATIM3MODE23_MSCR_TS_Pos)
#define ATIM3_M23_MSCR_TS_IAFP       (6u<<ATIM3MODE23_MSCR_TS_Pos)
#define ATIM3_M23_MSCR_TS_IBFP       (ATIM3MODE23_MSCR_TS)
/**
  * @}
  */


/** @defgroup IA0(CH0A) Input Selection (MSCR.IA0S)
  * @{
  */
#define ATIM3_M23_MSCR_IA0_CH0A           (0x00000000u)
#define ATIM3_M23_MSCR_IA0_CH012A_XOR     (ATIM3MODE23_MSCR_IA0S)
/**
  * @}
  */
    
/** @defgroup IB0(CH0B) Input Selection (MSCR.IB0S)
  * @{
  */
#define ATIM3_M23_MSCR_IB0_CH0B           (0x00000000u)
#define ATIM3_M23_MSCR_IB0_TS_SOURCE      (ATIM3MODE23_MSCR_IB0S)
/**
  * @}
  */

/**
 ******************************************************************************
 ** \brief CHxA通道比较、输出控制 配置结构体定义(模式23)
 *****************************************************************************/
typedef struct stc_atim3_m23_compare_cfg
{
    uint32_t       u32CHxCmpCap;       ///< CHxA/CHxB比较/捕获功能选择
    uint32_t       u32CHxCmpModeCtrl;  ///< CHxA/CHxB通道比较控制
    uint32_t       u32CHxPolarity;     ///< CHxA/CHxB输出极性控制
    uint32_t       u32CHxCmpBufEn;     ///< 比较A/B缓存功能 使能/禁止
    uint32_t       u32CHxCmpIntSel;    ///< CHxA/CHxB比较匹配中断选择
}stc_atim3_m23_compare_cfg_t;


#define ATIM3_M23_OUTPUT_CHANNEL_CH0      0
#define ATIM3_M23_OUTPUT_CHANNEL_CH1      1
#define ATIM3_M23_OUTPUT_CHANNEL_CH2      2


/** @defgroup stc_atim3_mode23_compare_cfg cha function setting
  * @{
  */
#define ATIM3_M23_CRCHx_CSA_CSB_COMPARE      (0x00000000u)
#define ATIM3_M23_CRCHx_CSA_CSB_CAPTURE      (ATIM3MODE23_CRCH0_CSA)
/**
  * @}
  */

/** @defgroup stc_atim3_mode23_compare_cfg cha buffer enable/disable function setting
  * @{
  */
#define ATIM3_M23_CRCHx_BUFEx_DISABLE      (0x00000000u)
#define ATIM3_M23_CRCHx_BUFEx_ENABLE       (ATIM3MODE23_CRCH0_BUFEA)
/**
  * @}
  */

/** @defgroup stc_atim3_mode23_compare_cfg cha  compare match interrupt function setting
  * @{
  */
#define ATIM3_M23_M23CR_CISA_DISABLE_IRQ      (0x00000000u)
#define ATIM3_M23_M23CR_CISA_RISE_IRQ         (1<<ATIM3MODE23_M23CR_CIS_Pos)
#define ATIM3_M23_M23CR_CISA_FALL_IRQ         (2<<ATIM3MODE23_M23CR_CIS_Pos)
#define ATIM3_M23_M23CR_CISA_RISE_FALL_IRQ    (ATIM3MODE23_M23CR_CIS)
/**
  * @}
  */


/** @defgroup stc_atim3_mode23_compare_cfg PWM Compare control mode function setting
  * @{
  */
#define ATIM3_M23_FLTR_OCMxx_FORCE_LOW           (0x00000000u)
#define ATIM3_M23_FLTR_OCMxx_FORCE_HIGH          (1u<<ATIM3MODE23_FLTR_OCMA0FLTA0_Pos)
#define ATIM3_M23_FLTR_OCMxx_COMP_FORCE_LOW      (2u<<ATIM3MODE23_FLTR_OCMA0FLTA0_Pos)
#define ATIM3_M23_FLTR_OCMxx_COMP_FORCE_HIGH     (3u<<ATIM3MODE23_FLTR_OCMA0FLTA0_Pos)
#define ATIM3_M23_FLTR_OCMxx_COMP_REVERSE        (4u<<ATIM3MODE23_FLTR_OCMA0FLTA0_Pos)
#define ATIM3_M23_FLTR_OCMxx_COMP_ONE_PRD_HIGH   (5u<<ATIM3MODE23_FLTR_OCMA0FLTA0_Pos)
#define ATIM3_M23_FLTR_OCMxx_PWM_MODE_1          (6u<<ATIM3MODE23_FLTR_OCMA0FLTA0_Pos)
#define ATIM3_M23_FLTR_OCMxx_PWM_MODE_2          (ATIM3MODE23_FLTR_OCMA0FLTA0)
/**
  * @}
  */

/** @defgroup stc_atim3_mode23_compare_cfg PWM Input or output polarsetting
  * @{
  */
#define ATIM3_M23_FLTR_CCPxx_NORMAL_IN_OUT      (0x00000000u)
#define ATIM3_M23_FLTR_CCPxx_REVERSE_IN_OUT     (ATIM3MODE23_FLTR_CCPA0)
/**
  * @}
  */

/**
 ******************************************************************************
 ** \brief CHxB通道比较、输出控制 配置定义(模式23)
 *****************************************************************************/


/** @defgroup stc_atim3_mode23_compare_cfg chb compare match interrupt function setting
  * @{
  */
#define ATIM3_M23_CRCHx_CISBx_DISABLE_IRQ      (0x00000000u)
#define ATIM3_M23_CRCHx_CISBx_RISE_IRQ         (1<<ATIM3MODE23_CRCH0_CISB_Pos)
#define ATIM3_M23_CRCHx_CISBx_FALL_IRQ         (2<<ATIM3MODE23_CRCH0_CISB_Pos)
#define ATIM3_M23_CRCHx_CISBx_RISE_FALL_IRQ    (ATIM3MODE23_CRCH0_CISB)
/**
  * @}
  */



/**
 ******************************************************************************
 ** \brief CHA/CHB通道捕获、输入控制 配置结构体定义(模式23)
 *****************************************************************************/
typedef struct stc_atim3_m23_input_cfg
{
    uint32_t      u32CHxCmpCap;     ///< CHxA/CHxB比较/捕获功能选择
    uint32_t      u32CHxCapSel;     ///< CHxA/CHxB捕获边沿选择
    uint32_t      u32CHxInFlt;      ///< CHxA/CHxB通道捕获滤波控制
    uint32_t      u32CHxPolarity;   ///< CHxA/CHxB输入相位
}stc_atim3_m23_input_cfg_t;   



/** @defgroup stc_atim3_mode23_inuput_cfg CRA_CFA(BKSA)& CRB_CFB(BKSB) Capture edge setting
  * @{
  */
#define ATIM3_M23_CRCHx_CRxCFx_CAPTURE_EDGE_DISABLE      (0x00000000u)
#define ATIM3_M23_CRCHx_CRxCFx_CAPTURE_EDGE_RISE         (1<<ATIM3MODE23_CRCH0_BKSACFACRA_Pos)
#define ATIM3_M23_CRCHx_CRxCFx_CAPTURE_EDGE_FALL         (2<<ATIM3MODE23_CRCH0_BKSACFACRA_Pos)
#define ATIM3_M23_CRCHx_CRxCFx_CAPTURE_EDGE_RISE_FALL    (ATIM3MODE23_CRCH0_BKSACFACRA)
/**
  * @}
  */


/** @defgroup stc_atim3_mode23_inuput_cfg FLTAx/FLTBx/FLTET Input channel filer setting
  * @{
  */
#define ATIM3_M23_FLTR_FLTxx_NONE            (0x00000000u)
#define ATIM3_M23_FLTR_FLTxx_THREE_PCLK      (4<<ATIM3MODE23_FLTR_OCMA0FLTA0_Pos)
#define ATIM3_M23_FLTR_FLTxx_THREE_PCLK_4    (5<<ATIM3MODE23_FLTR_OCMA0FLTA0_Pos)
#define ATIM3_M23_FLTR_FLTxx_THREE_PCLK_16   (6<<ATIM3MODE23_FLTR_OCMA0FLTA0_Pos)
#define ATIM3_M23_FLTR_FLTxx_THREE_PCLK_64   (ATIM3MODE23_FLTR_OCMA0FLTA0)
/**
  * @}
  */


/**
 ******************************************************************************
 ** \brief ETR输入相位滤波配置结构体定义(模式23)
 *****************************************************************************/
typedef struct stc_atim3_m23_etr_input_cfg
{
    uint32_t     u32ETRPolarity;  ///< ETR输入极性设置
    uint32_t     u32ETRFlt;       ///< ETR滤波设置
}stc_atim3_m23_etr_input_cfg_t;


/** @defgroup stc_atim3_mode23_etr_input_cfg ETP Input polar setting
  * @{
  */
#define ATIM3_M23_FLTR_ETP_NORMAL_IN      (0x00000000u)
#define ATIM3_M23_FLTR_ETP_REVERSE_IN     (ATIM3MODE23_FLTR_ETP)
/**
  * @}
  */


/**
 ******************************************************************************
 ** \brief 刹车BK输入相位滤波配置结构体定义(模式23)
 *****************************************************************************/
typedef struct stc_atim3_m23_bk_input_cfg
{
    uint32_t       u32EnBrake;         ///< 刹车使能
    uint32_t       u32EnSafetyBk;      ///< 使能safety刹车
    uint32_t       u32BrakePolarity;   ///< 刹车BK输入极性设置
    uint32_t       u32BrakeFlt;        ///< 刹车BK滤波设置
}stc_atim3_m23_bk_input_cfg_t;


/** @defgroup stc_atim3_mode23_bk_input BKE: Brake Enable of disable setting
  * @{
  */
#define ATIM3_M23_DTR_BKE_BRAKE_DISABLE      (0x00000000u)
#define ATIM3_M23_DTR_BKE_BRAKE_ENABLE       (ATIM3MODE23_DTR_BK)
/**
  * @}
  */

/** @defgroup stc_atim3_mode23_bk_input SAFEEN: Safety Brake Enable of disable setting
  * @{
  */
#define ATIM3_M23_DTR_SAFEEN_BRAKE_DISABLE      (0x00000000u)
#define ATIM3_M23_DTR_SAFEEN_BRAKE_ENABLE       (ATIM3MODE23_DTR_SAFE)
/**
  * @}
  */
    
/** @defgroup stc_atim3_mode23_bk_input SAFEEN: BKSEL Brake sync setting
  * @{
  */
#define ATIM3_M23_DTR_BKSEL_BRAKE_SYNC_DISABLE      (0x00000000u)
#define ATIM3_M23_DTR_BKSEL_BRAKE_SYNC_ENABLE       (ATIM3MODE23_DTR_BKSEL)
/**
  * @}
  */
    
/** @defgroup  BKSA/BKSB: CHxA&CHxB Port Output Level when Brake Happen
  * @{
  */
#define ATIM3_M23_CRCHx_BKSA_BKSB_PORT_OUTPUT_HIZ       (0x00000000u)
#define ATIM3_M23_CRCHx_BKSA_BKSB_PORT_OUTPUT_KEEP      (1<<ATIM3MODE23_CRCH0_BKSACFACRA_Pos)
#define ATIM3_M23_CRCHx_BKSA_BKSB_PORT_OUTPUT_LOW       (2<<ATIM3MODE23_CRCH0_BKSACFACRA_Pos)
#define ATIM3_M23_CRCHx_BKSA_BKSB_PORT_OUTPUT_HIGH      (ATIM3MODE23_CRCH0_BKSACFACRA)
/**
  * @}
  */
    
/** @defgroup stc_atim3_mode23_etr_input_cfg BKP Input polar setting
  * @{
  */
#define ATIM3_M23_FLTR_BKP_NORMAL_IN      (0x00000000u)
#define ATIM3_M23_FLTR_BKP_REVERSE_IN     (ATIM3MODE23_FLTR_BKP)
/**
  * @}
  */
    
    
/**
 ******************************************************************************
** \brief 死区功能配置结构体定义(模式23)
 *****************************************************************************/
typedef struct stc_atim3_m23_dt_cfg
{
    boolean_t       bEnDeadTime;       ///< 死区使能设置
    uint32_t        u32DeadTimeValue;  ///< 8 bit 死区时间设置
}stc_atim3_m23_dt_cfg_t;
  
    
/**
 ******************************************************************************
 ** \brief 触发ADC配置结构体定义(模式23)
 *****************************************************************************/
typedef struct stc_atim3_m23_adc_trig_cfg
{
    boolean_t     bEnTrigADC;          ///< 触发ADC全局控制
    boolean_t     bEnUevTrigADC;       ///< 事件更新触发ADC
    boolean_t     bEnCH0ACmpTrigADC;   ///< CH0A比较匹配触发ADC
    boolean_t     bEnCH0BCmpTrigADC;   ///< CH0B比较匹配触发ADC
    boolean_t     bEnCH1ACmpTrigADC;   ///< CH0A比较匹配触发ADC
    boolean_t     bEnCH1BCmpTrigADC;   ///< CH0B比较匹配触发ADC
    boolean_t     bEnCH2ACmpTrigADC;   ///< CH0A比较匹配触发ADC
    boolean_t     bEnCH2BCmpTrigADC;   ///< CH0B比较匹配触发ADC
}stc_atim3_m23_adc_trig_cfg_t;


/**
 ******************************************************************************
** \brief 重复计数功能配置结构体定义(模式23)
 *****************************************************************************/
typedef struct stc_atim3_m23_rcr_cfg
{
    uint32_t        u32EnUnderFlowMask;     ///< 下溢屏蔽设置
    uint32_t        u32EnOverFLowMask;      ///< 上溢屏蔽设置
    uint32_t        u32RepeatCountNum;      ///< 重复计数值
}stc_atim3_m23_rcr_cfg_t;

/** @defgroup stc_atim3_mode23_rcr_cfg Under Flow Repeat Count setting
  * @{
  */
#define ATIM3_M23_RCR_UND_IRQ_EVT_CNT_ENABLE     (0x00000000u)
#define ATIM3_M23_RCR_UND_IRQ_EVT_CNT_MASK       (ATIM3MODE23_RCR_UD)
/**
  * @}
  */
    
/** @defgroup stc_atim3_mode23_rcr_cfg Over Flow Repeat Count setting
  * @{
  */
#define ATIM3_M23_RCR_OVF_IRQ_EVT_CNT_ENABLE     (0x00000000u)
#define ATIM3_M23_RCR_OVF_IRQ_EVT_CNT_MASK       (ATIM3MODE23_RCR_OV)
/**
  * @}
  */
    

/**
 ******************************************************************************
 ** \brief  OCREF清除功能 配置结构体定义(模式23)
 *****************************************************************************/
typedef struct stc_atim3_m23_ocref_clr_cfg
{
    uint32_t       u32OCRefClrSrcSel;  ///< OCREF清除源选择
    boolean_t      bOCSourceClrEn;    ///< 来自OCCS的OCREF_Clr源是否使能清除OCREF输出
}stc_atim3_m23_ocref_clr_cfg_t;

/** @defgroup stc_atim3_mode23_ocref_clr_cfg  OCREF Signal Clear Source setting
  * @{
  */
#define ATIM3_M23_M23CR_OCCS_VC       (0x00000000u)
#define ATIM3_M23_M23CR_OCCS_ETR      (ATIM3MODE23_M23CR_OCCS)
/**
  * @}
  */


/** @defgroup atim3 mode23 trig dma cfg MSCR: CCDS: Compare trig DMA enable or disable setting
  * @{
  */
#define ATIM3_M23_MSCR_COMPARE_TRIG_DMA_ENABLE       (0x00000000u)
#define ATIM3_M23_MSCR_COMPARE_TRIG_DMA_DISABLE      (ATIM3MODE23_MSCR_CCDS)
/**
  * @}
  */

/**
 ******************************************************************************
 ** \brief  CH3通道 配置结构体定义(模式23)
 *****************************************************************************/
typedef struct stc_atim3_m23_ch3_ctl_cfg
{
    boolean_t     bEnableCH3Compare;  ///< CH3通道比较使能
    uint32_t      u32CH3CmpIntSel;    ///< CH3比较匹配中断模式设置
    boolean_t     bTrigDMA;           ///< CH3比较触发DMA使能/禁止
    boolean_t     bEnableCh3Buffer;   ///< CH3比较缓存使能控制
}stc_atim3_m23_ch3_ctl_cfg_t;

/** @defgroup stc_atim3_m23_ch3_ctl_cfg ch3 compare match irq setting
  * @{
  */
#define ATIM3_M23_CRCH3_CIS_DISABLE_IRQ      (0x00000000u)
#define ATIM3_M23_CRCH3_CIS_RISE_IRQ         (1<<ATIM3MODE23_CRCH3_CIS_Pos)
#define ATIM3_M23_CRCH3_CIS_FALL_IRQ         (2<<ATIM3MODE23_CRCH3_CIS_Pos)
#define ATIM3_M23_CRCH3_CIS_RISE_FALL_IRQ    (ATIM3MODE23_CRCH3_CIS)
/**
  * @}
  */

/*****ATIM3 Mode0/1/2/3 Interrupt Flag******/
#define ATIM3_INT_FLAG_UI        (ATIM3MODE23_IFR_UI)
#define ATIM3_INT_FLAG_PWC_CA0   (ATIM3MODE23_IFR_CA0)
#define ATIM3_INT_FLAG_CA1       (ATIM3MODE23_IFR_CA1)
#define ATIM3_INT_FLAG_CA2       (ATIM3MODE23_IFR_CA2)
#define ATIM3_INT_FLAG_CB0       (ATIM3MODE23_IFR_CB0)
#define ATIM3_INT_FLAG_CB1       (ATIM3MODE23_IFR_CB1)
#define ATIM3_INT_FLAG_CB2       (ATIM3MODE23_IFR_CB2)
#define ATIM3_INT_FLAG_CA0E      (ATIM3MODE23_IFR_CA0E)
#define ATIM3_INT_FLAG_CA1E      (ATIM3MODE23_IFR_CA1E)
#define ATIM3_INT_FLAG_CA2E      (ATIM3MODE23_IFR_CA2E)
#define ATIM3_INT_FLAG_CB0E      (ATIM3MODE23_IFR_CB0E)
#define ATIM3_INT_FLAG_CB1E      (ATIM3MODE23_IFR_CB1E)
#define ATIM3_INT_FLAG_CB2E      (ATIM3MODE23_IFR_CB2E)
#define ATIM3_INT_FLAG_BI        (ATIM3MODE23_IFR_BI)
#define ATIM3_INT_FLAG_TI        (ATIM3MODE23_IFR_TI)
#define ATIM3_INT_FLAG_OV        (ATIM3MODE23_IFR_OV)
#define ATIM3_INT_FLAG_UND       (ATIM3MODE23_IFR_UND)
#define ATIM3_INT_FLAG_CA3       (ATIM3MODE23_IFR_CA3)


/*****ATIM3 Mode0/1/2/3 Interrupt Clear Flag******/
#define ATIM3_INT_CLR_UI        (ATIM3MODE23_ICLR_UI)
#define ATIM3_INT_CLR_PWC_CA0   (ATIM3MODE23_ICLR_CA0)
#define ATIM3_INT_CLR_CA1       (ATIM3MODE23_ICLR_CA1)
#define ATIM3_INT_CLR_CA2       (ATIM3MODE23_ICLR_CA2)
#define ATIM3_INT_CLR_CB0       (ATIM3MODE23_ICLR_CB0)
#define ATIM3_INT_CLR_CB1       (ATIM3MODE23_ICLR_CB1)
#define ATIM3_INT_CLR_CB2       (ATIM3MODE23_ICLR_CB2)
#define ATIM3_INT_CLR_CA0E      (ATIM3MODE23_ICLR_CA0E)
#define ATIM3_INT_CLR_CA1E      (ATIM3MODE23_ICLR_CA1E)
#define ATIM3_INT_CLR_CA2E      (ATIM3MODE23_ICLR_CA2E)
#define ATIM3_INT_CLR_CB0E      (ATIM3MODE23_ICLR_CB0E)
#define ATIM3_INT_CLR_CB1E      (ATIM3MODE23_ICLR_CB1E)
#define ATIM3_INT_CLR_CB2E      (ATIM3MODE23_ICLR_CB2E)
#define ATIM3_INT_CLR_BI        (ATIM3MODE23_ICLR_BI)
#define ATIM3_INT_CLR_TI        (ATIM3MODE23_ICLR_TI)
#define ATIM3_INT_CLR_OV        (ATIM3MODE23_ICLR_OV)
#define ATIM3_INT_CLR_UND       (ATIM3MODE23_ICLR_UND)
#define ATIM3_INT_CLR_CA3       (ATIM3MODE23_ICLR_CA3)


/*****ATIM3 Mode1 Interrupt Request******/
#define ATIM3_M1_INT_UI        (0x00000001u) /*!< 模式1 溢出中断 */
#define ATIM3_M1_INT_CA0       (0x00000002u) /*!< 模式1 脉宽测量完成中断 */


/*****ATIM3 Mode2/3 Interrupt Request******/

#define _INTERRUPT_M23CR_ID     (0x80000000U)
#define _INTERRUPT_CRCH0_ID     (0x08000000U)
#define _INTERRUPT_CRCH1_ID     (0x04000000U)
#define _INTERRUPT_CRCH2_ID     (0x02000000U)
    
#define _INTERRUPT_M23CR_MASK     (0x30180400U)
#define _INTERRUPT_CRCH0_MASK     (0x00000300U)
#define _INTERRUPT_CRCH1_MASK     (0x000000C0U)
#define _INTERRUPT_CRCH2_MASK     (0x00000030U)

#define ATIM3_M23_INT_UI        (_INTERRUPT_M23CR_ID | ATIM3MODE23_M23CR_UI)   /*!< 模式23 溢出中断 */
#define ATIM3_M23_INT_BI        (_INTERRUPT_M23CR_ID | ATIM3MODE23_M23CR_BI)   /*!< 模式23 刹车中断 */
#define ATIM3_M23_INT_TI        (_INTERRUPT_M23CR_ID | ATIM3MODE23_M23CR_TI)   /*!< 模式23 触发中断 */
#define ATIM3_M23_INT_OV        (_INTERRUPT_M23CR_ID | ATIM3MODE23_M23CR_OV)   /*!< 模式23 上溢中断 */
#define ATIM3_M23_INT_UND       (_INTERRUPT_M23CR_ID | ATIM3MODE23_M23CR_UND)  /*!< 模式23 下溢中断 */
#define ATIM3_M23_INT_CA0       (_INTERRUPT_CRCH0_ID | ATIM3MODE23_CRCH0_CIEA) /*!< 模式23 比较捕获CH0A中断 */
#define ATIM3_M23_INT_CB0       (_INTERRUPT_CRCH0_ID | ATIM3MODE23_CRCH0_CIEB) /*!< 模式23 比较捕获CH0B中断 */
#define ATIM3_M23_INT_CA1       (_INTERRUPT_CRCH1_ID | (ATIM3MODE23_CRCH1_CIEA >> 2)) /*!< 模式23 比较捕获CH1A中断 */
#define ATIM3_M23_INT_CB1       (_INTERRUPT_CRCH1_ID | (ATIM3MODE23_CRCH1_CIEB >> 2)) /*!< 模式23 比较捕获CH1B中断 */
#define ATIM3_M23_INT_CA2       (_INTERRUPT_CRCH2_ID | (ATIM3MODE23_CRCH2_CIEA >> 4)) /*!< 模式23 比较捕获CH2A中断 */
#define ATIM3_M23_INT_CB2       (_INTERRUPT_CRCH2_ID | (ATIM3MODE23_CRCH2_CIEB >> 4)) /*!< 模式23 比较捕获CH2B中断 */
#define ATIM3_M23_INT_CA3       (ATIM3MODE23_CRCH3_CI) /*!< 模式23 比较CH3中断 */



/******************************************************************************
 * Global variable declarations ('extern', definition in C source)
 *****************************************************************************/

/******************************************************************************
 * Global function prototypes (definition in C source)
 *****************************************************************************/

//模式0初始化及相关功能操作

//timer配置及初始化
void ATIM3_Mode0_Init(stc_atim3_mode0_cfg_t* pstcCfg);
//timer 启动/停止
void ATIM3_Mode0_Run(void);
void ATIM3_Mode0_Stop(void);
//重载值设置/获取
void ATIM3_Mode0_ARRSet(uint32_t u16Data);
uint32_t ATIM3_Mode0_ARRGet(void);
//16位计数值设置/获取
void ATIM3_Mode0_Cnt16Set(uint32_t u16Data);
uint32_t ATIM3_Mode0_Cnt16Get(void);
//32位计数值设置/获取
void ATIM3_Mode0_Cnt32Set(uint32_t u32Data);
uint32_t ATIM3_Mode0_Cnt32Get(void);
//端口输出使能/禁止设定
void ATIM3_Mode0_Enable_Output(boolean_t bEnOutput);
//翻转使能/禁止（低电平）设定
void ATIM3_Mode0_Enable_TOG(boolean_t bEnTOG);


//模式1初始化及相关功能操作

//timer配置及初始化
void ATIM3_Mode1_Init(stc_atim3_mode1_cfg_t* pstcCfg);
//PWC 输入配置
void ATIM3_Mode1_Input_Cfg(stc_atim3_pwc_input_cfg_t* pstcCfg);
//PWC测量边沿起始结束选择
void ATIM3_Mode1_PWC_Edge_Sel(uint32_t u32DetectEdgeSel);
//timer 启动/停止
void ATIM3_Mode1_Run(void);
void ATIM3_Mode1_Stop(void);
//16位计数值设置/获取
void ATIM3_Mode1_Cnt16Set(uint32_t u16Data);
uint32_t ATIM3_Mode1_Cnt16Get(void);
//脉冲宽度测量结果数值获取
uint32_t ATIM3_Mode1_PWC_CapValueGet(void);



//模式23初始化及相关功能操作

//timer配置及初始化
void ATIM3_Mode23_Init(stc_atim3_mode23_cfg_t* pstcCfg);
//timer 启动/停止
void ATIM3_Mode23_Run(void);
void ATIM3_Mode23_Stop(void);
//PWM 手动 输出使能/禁止
void ATIM3_Mode23_Manual_PWM_Output_Enable(boolean_t bEnOutput);
//PWM 自动 输出使能/禁止
void ATIM3_Mode23_Auto_PWM_Output_Enable(boolean_t bEnAutoOutput);
//重载值(周期)缓存功能使能/禁止
void ATIM3_Mode23_ARR_Buffer_Enable(boolean_t bEnBuffer);
//重载值(周期)设置/获取
void ATIM3_Mode23_ARRSet(uint16_t u16Data);
uint32_t ATIM3_Mode23_GetARR(void);
//16位计数值设置/获取
void ATIM3_Mode23_Cnt16Set(uint16_t u16Data);
uint32_t ATIM3_Mode23_Cnt16Get(void);
//比较捕获寄存器CCRxA/CCRxB/CCR3设置/读取
void ATIM3_Mode23_Channel_Compare_Value_Set(uint32_t u32Channel, uint16_t u16Data);
uint32_t ATIM3_Mode23_Channel_Capture_Value_Get(uint32_t u32Channel);
//PWM互补输出模式下，GATE功能选择
void ATIM3_Mode23_GateFuncSel(stc_atim3_m23_gate_cfg_t* pstcCfg);
//主从触发配置
void ATIM3_Mode23_MasterSlave_Trig_Set(stc_atim3_m23_master_slave_cfg_t* pstcCfg);
void ATIM3_Mode23_MSCR_IA0_Sel(uint32_t u32Ia0Sel);
void ATIM3_Mode23_MSCR_IB0_Sel(uint32_t u32Ib0Sel);
//CHxA/CHxB比较输出通道控制
void ATIM3_Mode23_PortOutput_CHxA_Cfg(uint32_t u32Channel, stc_atim3_m23_compare_cfg_t* pstcCfg);
void ATIM3_Mode23_PortOutput_CHxB_Cfg(uint32_t u32Channel, stc_atim3_m23_compare_cfg_t* pstcCfg);
void ATIM3_Mode23_CH3_Compare_Cfg(stc_atim3_m23_ch3_ctl_cfg_t* pstcCfg);
//CH0A/CH0B输入控制
void ATIM3_Mode23_PortInput_CHxA_Cfg(uint32_t u32Channel, stc_atim3_m23_input_cfg_t* pstcCfg);
void ATIM3_Mode23_PortInput_CHxB_Cfg(uint32_t u32Channel, stc_atim3_m23_input_cfg_t* pstcCfg);
//ERT输入控制
void ATIM3_Mode23_ETRInput_Cfg(stc_atim3_m23_etr_input_cfg_t* pstcCfg);
//刹车BK输入控制
void ATIM3_Mode23_BrakeInput_Cfg(stc_atim3_m23_bk_input_cfg_t* pstcBkCfg);
void ATIM3_Mode23_Brake_Port_Status_Cfg(uint32_t u32Channel, uint32_t u32ChxaStatus, uint32_t u32ChxbStatus);
//死区功能
void ATIM3_Mode23_DT_Cfg(stc_atim3_m23_dt_cfg_t* pstcCfg);
//触发ADC控制
void ATIM3_Mode23_TrigADC_Cfg(stc_atim3_m23_adc_trig_cfg_t* pstcCfg);
//重复周期设置
void ATIM3_Mode23_SetRepeatPeriod(stc_atim3_m23_rcr_cfg_t* pstcCfg);
//OCREF清除功能
void ATIM3_Mode23_OCRefClr(stc_atim3_m23_ocref_clr_cfg_t* pstcCfg);
//使能DMA传输
void ATIM3_Mode23_EnDisable_UEV_TrigDMA(boolean_t bUevTrigDMA);
void ATIM3_Mode23_EnDisable_Trigger_TrigDMA(boolean_t bTITrigDMA);
void ATIM3_Mode23_EnDisable_CH0A_TrigDMA(boolean_t bCH0ATrigDMA);
void ATIM3_Mode23_EnDisable_CH0B_TrigDMA(boolean_t bCH0BTrigDMA);
void ATIM3_Mode23_EnDisable_CH1A_TrigDMA(boolean_t bCH1ATrigDMA);
void ATIM3_Mode23_EnDisable_CH1B_TrigDMA(boolean_t bCH1BTrigDMA);
void ATIM3_Mode23_EnDisable_CH2A_TrigDMA(boolean_t bCH2ATrigDMA);
void ATIM3_Mode23_EnDisable_CH2B_TrigDMA(boolean_t bCH2BTrigDMA);
void ATIM3_Mode23_EnDisable_CH3_TrigDMA(boolean_t bCH3TrigDMA);
void ATIM3_Mode23_Compare_Trig_DMA_Sel(uint32_t u32CmpUevTrigDMA);
//CHxA/CHxB捕获比较软件触发
void ATIM3_Mode23_Enable_CH0A_SwTrig_Capture_Compare(void);
void ATIM3_Mode23_Enable_CH0B_SwTrig_Capture_Compare(void);
void ATIM3_Mode23_Enable_CH1A_SwTrig_Capture_Compare(void);
void ATIM3_Mode23_Enable_CH1B_SwTrig_Capture_Compare(void);
void ATIM3_Mode23_Enable_CH2A_SwTrig_Capture_Compare(void);
void ATIM3_Mode23_Enable_CH2B_SwTrig_Capture_Compare(void);
//软件更新使能
void ATIM3_Mode23_EnableSoftwareUev(void);
//软件触发使能
void ATIM3_Mode23_EnableSoftwareTrig(void);
//软件刹车使能
void ATIM3_Mode23_EnableSoftwareBrake(void);

//中断相关函数

//中断标志获取
uint32_t ATIM3_GetIntFlag(uint32_t u32InterruptFlagTypes);
//中断标志清除
void ATIM3_ClearIrqFlag(uint32_t u32InterruptFlagTypes);
//所有中断标志清除
void ATIM3_ClearAllIrqFlag(void);
//模式0中断使能
void ATIM3_Mode0_EnableIrq(void);
//模式0中断禁止
void ATIM3_Mode0_DisableIrq(void);
//模式1中断使能
void ATIM3_Mode1_EnableIrq(uint32_t u32InterruptTypes);
//模式1中断禁止
void ATIM3_Mode1_DisableIrq(uint32_t u32InterruptTypes);
//模式23中断使能
void ATIM3_Mode23_EnableIrq (uint32_t u32InterruptTypes);
//模式23中断禁止
void ATIM3_Mode23_DisableIrq (uint32_t u32InterruptTypes);

//@} // Tim3Group

#ifdef __cplusplus
#endif


#endif /* __BT_H__ */
/******************************************************************************
 * EOF (not truncated)
 *****************************************************************************/


