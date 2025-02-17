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
 ** @file atim3.c
 **
 ** @brief Source file for ATIM3 functions
 **
 ** @author MADS Team 
 **
 ******************************************************************************/

/*******************************************************************************
 * Include files
 ******************************************************************************/
#include "atim3.h"
/**
 *******************************************************************************
 ** \addtogroup ATIM3Group
 ******************************************************************************/
//@{

/*******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/


/*******************************************************************************
 * Global variable definitions (declared in header file with 'extern')
 ******************************************************************************/

/*******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/

/*******************************************************************************
 * Local variable definitions ('static')
 ******************************************************************************/


/*******************************************************************************
 * Local function prototypes ('static')
 ******************************************************************************/


/*******************************************************************************
 * Function implementation - global ('extern') and local ('static')
 ******************************************************************************/



/**
 *****************************************************************************
 ** \brief ATIM3 初始化配置(模式0)
 **
 ** \param [in]  pstcCfg       初始化配置结构体指针
 **              pstcCfg->u32WorkMode                //工作模式配置
 **                       ATIM3_M0_M0CR_WORK_MODE_TIMER       //定时器模式(模式0)
 **                       ATIM3_M0_M0CR_WORK_MODE_PWC         //PWC模式(模式1)
 **                       ATIM3_M0_M0CR_WORK_MODE_SAWTOOTH    //锯齿波模式(模式2)
 **                       ATIM3_M0_M0CR_WORK_MODE_TRIANGULAR  //三角波模式(模式3)
 **
 **              pstcCfg->u32GatePolar               //端口门控极性控制
 **                       ATIM3_M0_M0CR_GATE_POLAR_HIGH       //端口门控高电平有效
 **                       ATIM3_M0_M0CR_GATE_POLAR_LOW        //端口门控低电平有效
 **
 **              pstcCfg->u32EnGate                 //定时器门控控制
 **                       ATIM3_M0_M0CR_GATE_OFF             //定时器门控禁止
 **                       ATIM3_M0_M0CR_GATE_ON              //定时器门控使能
 **
 **              pstcCfg->u32PRS                     //内部时钟分频选择
 **                       ATIM3_M0_M0CR_ATIM3CLK_PRS1        //PCLK
 **                       ATIM3_M0_M0CR_ATIM3CLK_PRS2        //PCLK/2
 **                       ATIM3_M0_M0CR_ATIM3CLK_PRS4        //PCLK/4
 **                       ATIM3_M0_M0CR_ATIM3CLK_PRS8        //PCLK/8
 **                       ATIM3_M0_M0CR_ATIM3CLK_PRS16       //PCLK/16
 **                       ATIM3_M0_M0CR_ATIM3CLK_PRS32       //PCLK/32
 **                       ATIM3_M0_M0CR_ATIM3CLK_PRS64       //PCLK/64
 **                       ATIM3_M0_M0CR_ATIM3CLK_PRS256      //PCLK/256
 **
 **              pstcCfg->u32EnTog                   //模式0下翻转输出控制
 **                       ATIM3_M0_M0CR_TOG_OFF          //翻转输出使能
 **                       ATIM3_M0_M0CR_TOG_ON           //翻转输出禁止
 **
 **              pstcCfg->u32CountClkSel             //计数时钟选择
 **                       ATIM3_M0_M0CR_CT_PCLK          //内部计数时钟PCLK
 **                       ATIM3_M0_M0CR_CT_ETR           //外部输入计数时钟ETR
 **
 **              pstcCfg->u32CntMode                 //计数模式选择     
 **                       ATIM3_M0_M0CR_MD_32BIT_FREE    //32位自由计数
 **                       ATIM3_M0_M0CR_MD_16BIT_ARR     //16位重载计数
 **
 ** \retval NULL                                      
 *****************************************************************************/
void ATIM3_Mode0_Init(stc_atim3_mode0_cfg_t* pstcCfg)
{
    REG_MODIFY(ATIM3MODE0->M0CR,ATIM3MODE0_M0CR_MODE|\
                                    ATIM3MODE0_M0CR_GATEP|\
                                    ATIM3MODE0_M0CR_GATE|\
                                    ATIM3MODE0_M0CR_PRS|\
                                    ATIM3MODE0_M0CR_TOG|\
                                    ATIM3MODE0_M0CR_CT|\
                                    ATIM3MODE0_M0CR_MD,
                                                         pstcCfg->u32WorkMode|\
                                                         pstcCfg->u32GatePolar|\
                                                         pstcCfg->u32EnGate|\
                                                         pstcCfg->u32PRS|\
                                                         pstcCfg->u32EnTog|\
                                                         pstcCfg->u32CountClkSel|\
                                                         pstcCfg->u32CntMode);
}

/**
 *****************************************************************************
 ** \brief ATIM3 启动运行(模式0)
 **
 **
 ** \param [in]  none
 ** 
 ** \retval NULL                                     
 *****************************************************************************/
void ATIM3_Mode0_Run(void)
{
    REG_SETBITS(ATIM3MODE0->M0CR, ATIM3MODE0_M0CR_CEN);
}

/**
 *****************************************************************************
 ** \brief ATIM3 停止运行(模式0)
 **
 **
 ** \param [in]  none
 ** 
 ** \retval NULL                                     
 *****************************************************************************/
void ATIM3_Mode0_Stop(void)
{   
    REG_CLEARBITS(ATIM3MODE0->M0CR, ATIM3MODE0_M0CR_CEN); 
}

/**
 *****************************************************************************
 ** \brief ATIM3 重载值设置(模式0)
 **
 **
 ** \param [in]  u16Data          16bits重载值
 ** 
 ** \retval None                                    
 *****************************************************************************/
void ATIM3_Mode0_ARRSet(uint32_t u16Data)
{
    REG_WRITE(ATIM3MODE0->ARR, (u16Data&0xFFFFu));
}

/**
 *****************************************************************************
 ** \brief ATIM3 获取重载值(模式0)
 **
 **
 ** \param [in]  None
 ** 
 ** \retval 16bits重载值                                     
 *****************************************************************************/
uint32_t ATIM3_Mode0_ARRGet(void)
{
    return((REG_READ(ATIM3MODE0->ARR))&0xFFFFu);
}

/**
 *****************************************************************************
 ** \brief ATIM3 16位计数器初值设置(模式0)
 **
 **
 ** \param [in]  u16Data          CNT 16位初值
 ** 
 ** \retval NULL                                     
 *****************************************************************************/
void ATIM3_Mode0_Cnt16Set(uint32_t u16Data)
{
    REG_WRITE(ATIM3MODE0->CNT, (u16Data&0xFFFFu));
}

/**
 *****************************************************************************
 ** \brief ATIM3 16位计数值获取(模式0)
 **
 **
 ** \param [in]  none
 ** 
 ** \retval 16bits计数值                                      
 *****************************************************************************/
uint32_t ATIM3_Mode0_Cnt16Get(void)
{
    return((REG_READ(ATIM3MODE0->CNT))&0xFFFFu);
}

/**
 *****************************************************************************
 ** \brief ATIM3 32位计数器初值设置(模式0)
 **
 **
 ** \param [in]  u32Data          32位初值
 ** 
 ** \retval None                                     
 *****************************************************************************/
void ATIM3_Mode0_Cnt32Set(uint32_t u32Data)
{
    REG_WRITE(ATIM3MODE0->CNT32, u32Data);
}

/**
 *****************************************************************************
 ** \brief ATIM3 32位计数值获取(模式0)
 **
 **
 ** \param [in]  None
 ** 
 ** \retval 32bits计数值                                      
 *****************************************************************************/
uint32_t ATIM3_Mode0_Cnt32Get(void)
{
    return(REG_READ(ATIM3MODE0->CNT32));
}

/**
 *****************************************************************************
 ** \brief ATIM3 端口输出使能/禁止设定(模式0)
 **
 ** \param [in]  bEnOutput          翻转输出设定 TRUE:使能, FALSE:禁止
 **
 **
 ** \retval NULL                                      
 *****************************************************************************/
void ATIM3_Mode0_Enable_Output(boolean_t bEnOutput)
{
    REG_MODIFY(ATIM3MODE0->DTR, ATIM3MODE0_DTR_MO, (uint32_t)bEnOutput << ATIM3MODE0_DTR_MO_Pos);
}

/**
 *****************************************************************************
 ** \brief ATIM3 翻转使能/禁止（低电平）设定(模式0)
 **
 **  \param [in]  bEnTOG          翻转输出设定 TRUE:使能, FALSE:禁止
 **
 **
 ** \retval Ok or Error                                      
 *****************************************************************************/
void ATIM3_Mode0_Enable_TOG(boolean_t bEnTOG)
{
    REG_MODIFY(ATIM3MODE0->M0CR, ATIM3MODE0_M0CR_TOG, (uint32_t)bEnTOG << ATIM3MODE0_M0CR_TOG_Pos);
}




/**
 *****************************************************************************
 ** \brief ATIM3 初始化配置(模式1)
 **
 ** \param [in]  pstcCfg       初始化配置结构体指针
 **              pstcCfg->u32WorkMode                //工作模式配置
 **                       ATIM3_M1_M1CR_WORK_MODE_TIMER       //定时器模式(模式0)
 **                       ATIM3_M1_M1CR_WORK_MODE_PWC         //PWC模式(模式1)
 **                       ATIM3_M1_M1CR_WORK_MODE_SAWTOOTH    //锯齿波模式(模式2)
 **                       ATIM3_M1_M1CR_WORK_MODE_TRIANGULAR  //三角波模式(模式3)
 **
 **              pstcCfg->u32CountClkSel             //计数时钟选择
 **                       ATIM3_M1_M1CR_CT_PCLK               //内部计数时钟PCLK
 **                       ATIM3_M1_M1CR_CT_ETR                //外部输入计数时钟ETR
 **
 **              pstcCfg->u32PRS                     //内部时钟分频选择
 **                       ATIM3_M1_M1CR_ATIM3CLK_PRS1        //PCLK
 **                       ATIM3_M1_M1CR_ATIM3CLK_PRS2        //PCLK/2
 **                       ATIM3_M1_M1CR_ATIM3CLK_PRS4        //PCLK/4
 **                       ATIM3_M1_M1CR_ATIM3CLK_PRS8        //PCLK/8
 **                       ATIM3_M1_M1CR_ATIM3CLK_PRS16       //PCLK/16
 **                       ATIM3_M1_M1CR_ATIM3CLK_PRS32       //PCLK/32
 **                       ATIM3_M1_M1CR_ATIM3CLK_PRS64       //PCLK/64
 **                       ATIM3_M1_M1CR_ATIM3CLK_PRS256      //PCLK/256
 **
 **              pstcCfg->u32ShotMode               //测量触发模式选择
 **                       ATIM3_M1_M1CR_SHOT_CYCLE           //循环测量
 **                       ATIM3_M1_M1CR_SHOT_ONE             //单次测量
 **
 ** \retval None                                   
 *****************************************************************************/
void ATIM3_Mode1_Init(stc_atim3_mode1_cfg_t* pstcCfg)
{
    REG_MODIFY(ATIM3MODE1->M1CR, ATIM3MODE1_M1CR_MODE|\
                                     ATIM3MODE1_M1CR_PRS|\
                                     ATIM3MODE1_M1CR_CT|\
                                     ATIM3MODE1_M1CR_ONESHOT,
                                                              pstcCfg->u32WorkMode|\
                                                              pstcCfg->u32PRS|\
                                                              pstcCfg->u32CountClkSel|\
                                                              pstcCfg->u32ShotMode);
}

/**
 *****************************************************************************
 ** \brief ATIM3 PWC 输入配置(模式1)
 **
 ** \param [in]  pstcCfg       初始化配置结构体指针
 **              pstcCfg->u32IA0Sel         //CH0A输入选择
 **                       ATIM3_M1_MSCR_IA0S_CH0A                    //CH0A
 **                       ATIM3_M1_MSCR_IA0S_CH012A_XOR              //CH0A CH1A CH2A XOR
 **
 **              pstcCfg->u32IB0Sel         //CH0B输入选择
 **                       ATIM3_M1_MSCR_IB0S_CH0B                   //CH0B
 **                       ATIM3_M1_MSCR_IB0S_TS_SEL                 //内部触发TS选择信号
 **
 **              pstcCfg->u32TsSel         //触发源选择
 **                       ATIM3_M1_MSCR_TS_ETR                       //端口ETR的滤波相位选择后的信号ETFP 
 **                       ATIM3_M1_MSCR_TS_ITR0                      //内部互联信号 ITR0
 **                       ATIM3_M1_MSCR_TS_ITR1                      //内部互联信号 ITR1
 **                       ATIM3_M1_MSCR_TS_ITR2                      //内部互联信号 ITR2
 **                       ATIM3_M1_MSCR_TS_ITR3                      //内部互联信号 ITR3
 **                       ATIM3_M1_MSCR_TS_CH0A_EDGE                 //端口CH0A的边沿信号
 **                       ATIM3_M1_MSCR_TS_CH0A_FILTER               //端口CH0A的滤波相位选择后的信号IAFP
 **                       ATIM3_M1_MSCR_TS_CH0B_FILTER               //端口CH0B的滤波相位选择后的信号IBFP
 **
 **              pstcCfg->u32FltIA0         //CH0A输入滤波设置
 **              pstcCfg->u32FltIB0         //CH0B输入滤波设置
 **              pstcCfg->u32FltETR         //ETR输入滤波设置
 **                       ATIM3_M1_FLTR_FLTA0_B0_ET_NONE             //无滤波
 **                       ATIM3_M1_FLTR_FLTA0_B0_ET_3_PCLK           //PCLK, 3个连续有效
 **                       ATIM3_M1_FLTR_FLTA0_B0_ET_3_PCLKDIV4       //PCLK/4, 3个连续有效
 **                       ATIM3_M1_FLTR_FLTA0_B0_ET_3_PCLKDIV16      //PCLK/16, 3个连续有效
 **                       ATIM3_M1_FLTR_FLTA0_B0_ET_3_PCLKDIV64      //PCLK/64, 3个连续有效
 **
 **
 **              pstcCfg->u32ETR             //ETR输入相位选择
 **                       ATIM3_M1_FLTR_ETP_POLARITY_POSITIVE        //同相位
 **                       ATIM3_M1_FLTR_ETP_POLARITY_NEGATIVE        //反相输入
 **
 ** \retval Ok or Error                                      
 *****************************************************************************/
void ATIM3_Mode1_Input_Cfg(stc_atim3_pwc_input_cfg_t* pstcCfg)
{
    REG_MODIFY(ATIM3MODE1->MSCR, ATIM3MODE1_MSCR_TS|\
                                     ATIM3MODE1_MSCR_IA0S|\
                                     ATIM3MODE1_MSCR_IB0S,
                                                            pstcCfg->u32IA0Sel|\
                                                            pstcCfg->u32IB0Sel|\
                                                            pstcCfg->u32TsSel);
    
    REG_MODIFY(ATIM3MODE1->FLTR, ATIM3MODE1_FLTR_FLTA0|\
                                     ATIM3MODE1_FLTR_FLTB0|\
                                     ATIM3MODE1_FLTR_FLTET|\
                                     ATIM3MODE1_FLTR_ETP,
                                                             pstcCfg->u32FltIA0|\
                                                             (pstcCfg->u32FltIB0 << ATIM3MODE1_FLTR_FLTB0_Pos)|\
                                                             (pstcCfg->u32FltETR << ATIM3MODE1_FLTR_FLTET_Pos)|\
                                                             pstcCfg->u32ETR);
}

                                        
    
/**
 *****************************************************************************
** \brief ATIM3 PWC测量边沿起始结束选择(周期) (模式1)
 **
 ** \param [in]  u32DetectEdgeSel                     //测量起始和结束边沿选择
**               ATIM3_M1_M1CR_DETECT_EDGE_RISE_TO_RISE  //上沿-->上沿 (周期)
 **              ATIM3_M1_M1CR_DETECT_EDGE_FALL_TO_RISE  //下沿-->上沿 (低电平)
 **              ATIM3_M1_M1CR_DETECT_EDGE_RISE_TO_FALL  //上沿-->下沿 (高电平)
 **              ATIM3_M1_M1CR_DETECT_EDGE_FALL_TO_FALL  //下沿-->下沿 (周期)
 **
 ** \retval None                                      
 *****************************************************************************/
void ATIM3_Mode1_PWC_Edge_Sel(uint32_t u32DetectEdgeSel)
{
    REG_MODIFY(ATIM3MODE1->M1CR,ATIM3MODE1_M1CR_EDG2ND|\
                                    ATIM3MODE1_M1CR_EDG1ST,
                                                            u32DetectEdgeSel);    
}

/**
 *****************************************************************************
 ** \brief ATIM3 启动运行(模式1)
 **
 **
 ** \param [in]  none
 ** 
 ** \retval NULL                                     
 *****************************************************************************/
void ATIM3_Mode1_Run(void)
{
    REG_SETBITS(ATIM3MODE1->M1CR, ATIM3MODE1_M1CR_CEN);
}

/**
 *****************************************************************************
 ** \brief ATIM3 停止运行(模式1)
 **
 **
 ** \param [in]  none
 ** 
 ** \retval NULL                                     
 *****************************************************************************/
void ATIM3_Mode1_Stop(void)
{   
    REG_CLEARBITS(ATIM3MODE1->M1CR, ATIM3MODE1_M1CR_CEN); 
}

/**
 *****************************************************************************
 ** \brief ATIM3 16位计数器初值设置(模式1)
 **
 **
 ** \param [in]  u16Data          CNT 16位初值
 ** 
 ** \retval NULL                                     
 *****************************************************************************/
void ATIM3_Mode1_Cnt16Set(uint32_t u16Data)
{
    REG_WRITE(ATIM3MODE1->CNT, (u16Data&0xFFFFu));
}

/**
 *****************************************************************************
 ** \brief ATIM3 16位计数值获取(模式1)
 **
 **
 ** \param [in]  none
 ** 
 ** \retval 16bits计数值                                      
 *****************************************************************************/
uint32_t ATIM3_Mode1_Cnt16Get(void)
{
    return((REG_READ(ATIM3MODE1->CNT))&0xFFFFu);
}

/**
 *****************************************************************************
 ** \brief ATIM3 脉冲宽度测量结果数值获取(模式1)
 **
 **
 ** \param [in]  none
 ** 
 ** \retval 16bits脉冲宽度测量结果                                      
 *****************************************************************************/
uint32_t ATIM3_Mode1_PWC_CapValueGet(void)
{
    return((REG_READ(ATIM3MODE1->CCR0A))&0xFFFFu);
}




/**
 *****************************************************************************
 ** \brief ATIM3 初始化配置(模式23)
 **
 ** \param [in]  pstcCfg       初始化配置结构体指针
 **              pstcCfg->u32WorkMode                //工作模式配置
 **                       ATIM3_M23_M23CR_WORK_MODE_TIMER       //定时器模式(模式0)
 **                       ATIM3_M23_M23CR_WORK_MODE_PWC         //PWC模式(模式1)
 **                       ATIM3_M23_M23CR_WORK_MODE_SAWTOOTH    //锯齿波模式(模式2)
 **                       ATIM3_M23_M23CR_WORK_MODE_TRIANGULAR  //三角波模式(模式3)
 **
 **              pstcCfg->u32CntDir                  //计数方向设置(仅在锯齿波模式下可写)
 **                       ATIM3_M23_M23CR_DIR_UP_CNT            //向上计数
 **                       ATIM3_M23_M23CR_DIR_DOWN_CNT          //向下计数
 **
 **              pstcCfg->u32PRS                     //内部时钟分频选择
 **                       ATIM3_M23_M23CR_ATIM3CLK_PRS1        //PCLK
 **                       ATIM3_M23_M23CR_ATIM3CLK_PRS2        //PCLK/2
 **                       ATIM3_M23_M23CR_ATIM3CLK_PRS4        //PCLK/4
 **                       ATIM3_M23_M23CR_ATIM3CLK_PRS8        //PCLK/8
 **                       ATIM3_M23_M23CR_ATIM3CLK_PRS16       //PCLK/16
 **                       ATIM3_M23_M23CR_ATIM3CLK_PRS32       //PCLK/32
 **                       ATIM3_M23_M23CR_ATIM3CLK_PRS64       //PCLK/64
 **                       ATIM3_M23_M23CR_ATIM3CLK_PRS256      //PCLK/256
 **
 **              pstcCfg->u32CountClkSel             //计数时钟选择
 **                       ATIM3_M23_M23CR_CT_PCLK               //内部计数时钟PCLK
 **                       ATIM3_M23_M23CR_CT_ETR                //外部输入计数时钟ETR
 **
 **              pstcCfg->u32PWMTypeSel              //PWM独立、互补输出模式设置
 **                       ATIM3_M23_M23CR_COMP_PWM_INDEPT              //独立PWM
 **                       ATIM3_M23_M23CR_COMP_PWM_COMP                //互补PWM
 **
 **              pstcCfg->u32PWM2sSel              //双点、单点比较模式设置
 **                       ATIM3_M23_M23CR_PWM2S_COMPARE_DOUBLE_POINT   //双点比较
 **                       ATIM3_M23_M23CR_PWM2S_COMPARE_SINGLE_POINT   //单点比较
 **
 **              pstcCfg->u32ShotMode              //单次触发模式设置
 **                       ATIM3_M23_M23CR_SHOT_CYCLE                   //循环计数
 **                       ATIM3_M23_M23CR_SHOT_ONE                     //单次，发送事件更新后定时器停止
 **
 **              pstcCfg->u32URSSel                //更新源选择
 **                       ATIM3_M23_M23CR_URS_OV_UND_UG_RST            //上溢出/下溢出/软件更新UG/从模式复位
 **                       ATIM3_M23_M23CR_URS_OV_UND                   //上溢出/下溢出
 **
 ** 
 ** \retval None                                     
 *****************************************************************************/
void ATIM3_Mode23_Init(stc_atim3_mode23_cfg_t* pstcCfg)
{
    REG_MODIFY(ATIM3MODE23->M23CR, ATIM3MODE23_M23CR_MODE|\
                                        ATIM3MODE23_M23CR_DIR|\
                                        ATIM3MODE23_M23CR_PRS|\
                                        ATIM3MODE23_M23CR_CT|\
                                        ATIM3MODE23_M23CR_COMP|\
                                        ATIM3MODE23_M23CR_PWM2S|\
                                        ATIM3MODE23_M23CR_ONESHOT|\
                                        ATIM3MODE23_M23CR_URS,
                                                                pstcCfg->u32WorkMode|\
                                                                pstcCfg->u32CntDir|\
                                                                pstcCfg->u32PRS|\
                                                                pstcCfg->u32CountClkSel|\
                                                                pstcCfg->u32PWMTypeSel|\
                                                                pstcCfg->u32PWM2sSel|\
                                                                pstcCfg->u32ShotMode|\
                                                                pstcCfg->u32URSSel);
}

/**
 *****************************************************************************
 ** \brief ATIM3 启动运行(模式23)
 **
 **
 ** \param [in]  none
 ** 
 ** \retval None                                    
 *****************************************************************************/
void ATIM3_Mode23_Run(void)
{
    REG_SETBITS(ATIM3MODE23->M23CR, ATIM3MODE23_M23CR_CTEN);
}

/**
 *****************************************************************************
 ** \brief ATIM3 停止运行(模式23)
 **
 **
 ** \param [in]  none
 ** 
 ** \retval None                                    
 *****************************************************************************/
void ATIM3_Mode23_Stop(void)
{
    REG_CLEARBITS(ATIM3MODE23->M23CR, ATIM3MODE23_M23CR_CTEN);
}

/**
 *****************************************************************************
 ** \brief ATIM3 手动PWM输出使能/禁止(模式23)
 **
 ** \param [in]  bEnOutput
 **              TRUE: 使能
 **              FALSE: 禁止
 ** \retval None                                   
 *****************************************************************************/
void ATIM3_Mode23_Manual_PWM_Output_Enable(boolean_t bEnOutput)
{
    REG_MODIFY(ATIM3MODE23->DTR, ATIM3MODE23_DTR_MO, (uint32_t)bEnOutput << ATIM3MODE23_DTR_MO_Pos);
}


/**
 *****************************************************************************
 ** \brief ATIM3 自动动PWM输出使能/禁止(模式23)
 **
 ** \param [in]  bEnOutput
 **              TRUE: 使能
 **              FALSE: 禁止
 ** 
 ** \retval None                                   
 *****************************************************************************/
void ATIM3_Mode23_Auto_PWM_Output_Enable(boolean_t bEnAutoOutput)
{
    REG_MODIFY(ATIM3MODE23->DTR, ATIM3MODE23_DTR_AO, (uint32_t)bEnAutoOutput << ATIM3MODE23_DTR_AO_Pos);
}


/**
 *****************************************************************************
 ** \brief ATIM3 重载(周期)缓存使能(模式23)
 **
 ** \param [in]  bEnBuffer
 **              TRUE: 使能
 **              FALSE: 禁止
 ** 
 ** \retval None                                      
 *****************************************************************************/
void ATIM3_Mode23_ARR_Buffer_Enable(boolean_t bEnBuffer)
{
    REG_MODIFY(ATIM3MODE23->M23CR, ATIM3MODE23_M23CR_BUFP, (uint32_t)bEnBuffer << ATIM3MODE23_M23CR_BUFP_Pos);
}

/**
 *****************************************************************************
 ** \brief ATIM3 重载值设置(模式23)
 **
 **
 ** \param [in]  u16Data          16bits重载值
 ** 
 ** \retval None                                      
 *****************************************************************************/
void ATIM3_Mode23_ARRSet(uint16_t u16Data)
{
    REG_WRITE(ATIM3MODE23->ARR, (uint32_t)u16Data);
}

/**
 *****************************************************************************
 ** \brief ATIM3 重载值获取(模式23)
 **
 **
 ** \param [in]  None
 ** 
 ** \retval 16bit重载值                                      
 *****************************************************************************/
uint32_t ATIM3_Mode23_GetARR(void)
{
    return((REG_READ(ATIM3MODE23->ARR))&0xFFFFu);
}
                
                
/**
 *****************************************************************************
 ** \brief ATIM3 16位计数器初值设置(模式23)
 **
 **
 ** \param [in]  u16Data          16位初值
 ** 
 ** \retval None                                    
 *****************************************************************************/
void ATIM3_Mode23_Cnt16Set(uint16_t u16Data)
{
    REG_WRITE(ATIM3MODE23->CNT, (uint32_t)u16Data);
}
                
/**
 *****************************************************************************
 ** \brief ATIM3 16位计数值获取(模式23)
 **
 **
 ** \param [in]  none
 ** 
 ** \retval 16bits计数值                                      
 *****************************************************************************/
uint32_t ATIM3_Mode23_Cnt16Get(void)
{
    return((REG_READ(ATIM3MODE23->CNT))&0xFFFFu);
}

/**
 *****************************************************************************
 ** \brief ATIM3 通道CHxA/CHxB比较值设置(CCRxA/CCRxB/CCR)(模式23)
 **
 **  \param [in]  u32Channel    ATIM3 通道
 **               ATIM3_COMPARE_CAPTURE_CH0A       //ATIM3_CCR0A
 **               ATIM3_COMPARE_CAPTURE_CH0B       //ATIM3_CCR0B
 **               ATIM3_COMPARE_CAPTURE_CH1A       //ATIM3_CCR1A
 **               ATIM3_COMPARE_CAPTURE_CH1B       //ATIM3_CCR1B
 **               ATIM3_COMPARE_CAPTURE_CH2A       //ATIM3_CCR2A
 **               ATIM3_COMPARE_CAPTURE_CH2B       //ATIM3_CCR2B
 **               ATIM3_COMPARE_CAPTURE_CH3        //ATIM3_CCR3
 ** 
 **  \param [in]  u16Data    CCRxA/CCRxB 16位比较值
 **
 **  \retval None                                  
 *****************************************************************************/
void ATIM3_Mode23_Channel_Compare_Value_Set(uint32_t u32Channel, uint16_t u16Data)
{
    REG_WRITE(*(&ATIM3MODE23->CCR0A + u32Channel), (uint32_t)u16Data);
}


/**
 *****************************************************************************
 ** \brief ATIM3 通道CHxA/CHxB捕获值读取、CCR3寄存器值读取(CCRxA/CCRxB/CCR3)(模式23)
 **
 **  \param [in]  u32Channel    ATIM3 通道
 **               ATIM3_COMPARE_CAPTURE_CH0A       //ATIM3_CCR0A
 **               ATIM3_COMPARE_CAPTURE_CH0B       //ATIM3_CCR0B
 **               ATIM3_COMPARE_CAPTURE_CH1A       //ATIM3_CCR1A
 **               ATIM3_COMPARE_CAPTURE_CH1B       //ATIM3_CCR1B
 **               ATIM3_COMPARE_CAPTURE_CH2A       //ATIM3_CCR2A
 **               ATIM3_COMPARE_CAPTURE_CH2B       //ATIM3_CCR2B
 **               ATIM3_COMPARE_CAPTURE_CH3        //ATIM3_CCR3
 ** 
 ** 
 ** \retval 16 bits CCRxA/CCRxB捕获值                                     
 *****************************************************************************/
uint32_t ATIM3_Mode23_Channel_Capture_Value_Get(uint32_t u32Channel)
{
    return((REG_READ( *(&ATIM3MODE23->CCR0A + u32Channel) ) ) & 0xFFFFu);
}


/**
 *****************************************************************************
 ** \brief ATIM3 PWM互补输出模式下，GATE功能选择,只有在PWM互补输出时有效(模式23)
 **
 ** \param [in]  pstcCfg       初始化配置结构体指针
 **              pstcCfg->u32GateFuncSel       //GATE 在PWM互补模式下捕获/比较选择(只有在PWM互补输出时有效)
 **                       ATIM3_M23_M23CR_GATE_FUN_COMPARE         //比较模式
 **                       ATIM3_M23_M23CR_GATE_FUN_CAPTURE         //捕获模式
 **
**              pstcCfg->u32GateRiseCap       //GATE作为捕获输入时，上沿捕获有效控制(只有在PWM互补输出时有效)
**                        ATIM3_M23_M23CR_GATE_CAP_RISE_DISABLE    //上沿捕获无效
**                        ATIM3_M23_M23CR_GATE_CAP_RISE_ENABLE     //上沿捕获有效
 **
 **              pstcCfg->u32GateFallCap       //GATE作为捕获输入时，下沿捕获有效控制(只有在PWM互补输出时有效)
 **                       ATIM3_M23_M23CR_GATE_CAP_FALL_DISABLE    //下沿捕获无效
 **                       ATIM3_M23_M23CR_GATE_CAP_FALL_ENABLE     //下沿捕获有效
 **
 ** \retval None
 *****************************************************************************/
void ATIM3_Mode23_GateFuncSel(stc_atim3_m23_gate_cfg_t* pstcCfg)
{
    REG_MODIFY(ATIM3MODE23->M23CR, 
               ATIM3MODE23_M23CR_CSG | ATIM3MODE23_M23CR_CRG | ATIM3MODE23_M23CR_CFG,
               pstcCfg->u32GateFuncSel | pstcCfg->u32GateRiseCap | pstcCfg->u32GateFallCap); 
}

/**
 *****************************************************************************
 ** \brief ATIM3 主从触发配置(模式23)
 **
 ** \param [in]  pstcCfg       初始化配置结构体指针
 **              pstcCfg->u32MasterSlaveSel      //主从选择
 **                       ATIM3_M23_MSCR_MSM_SlAVE      //从模式
 **                       ATIM3_M23_MSCR_MSM_MASTER     //主模式
 **
 **              pstcCfg->u32MasterSrc           //主模式输出选择
 **                       ATIM3_M23_MSCR_MMS_TRIG_SOURCE_UG        //软件更新UG，写CR.UG
 **                       ATIM3_M23_MSCR_MMS_TRIG_SOURCE_CTEN      //定时器使能CTEN
 **                       ATIM3_M23_MSCR_MMS_TRIG_SOURCE_UEV       //定时器事件更新UEV
 **                       ATIM3_M23_MSCR_MMS_TRIG_SOURCE_CMPSO     //比较匹配选择输出CMPSO
 **                       ATIM3_M23_MSCR_MMS_TRIG_SOURCE_OCREF0A   //定时器比较参数输出OCREF0A
 **                       ATIM3_M23_MSCR_MMS_TRIG_SOURCE_OCREF1A   //定时器比较参数输出OCREF1A
 **                       ATIM3_M23_MSCR_MMS_TRIG_SOURCE_OCREF2A   //定时器比较参数输出OCREF2A
 **                       ATIM3_M23_MSCR_MMS_TRIG_SOURCE_OCREF0B   //定时器比较参数输出OCREF0B
 **
 **              pstcCfg->u32SlaveModeSel        //从模式功能选择
 **                       ATIM3_M23_MSCR_SMS_INTERNAL_CLK          //使用内部时钟
 **                       ATIM3_M23_MSCR_SMS_RESET                 //复位功能
 **                       ATIM3_M23_MSCR_SMS_TRIG                  //触发模式
 **                       ATIM3_M23_MSCR_SMS_EXTERNAL_CLK          //外部时钟模式
 **                       ATIM3_M23_MSCR_SMS_QUADRATURE_M1         //正交编码计数模式1
 **                       ATIM3_M23_MSCR_SMS_QUADRATURE_M2         //正交编码计数模式2
 **                       ATIM3_M23_MSCR_SMS_QUADRATURE_M3         //正交编码计数模式3
 **                       ATIM3_M23_MSCR_SMS_GATE                  //门控功能
 **
 **              pstcCfg->u32TsSel               //触发从模式的来源选择
 **                       ATIM3_M23_MSCR_TS_ETFP                   //端口ETR的滤波相位选择后的信号ETFP
 **                       ATIM3_M23_MSCR_TS_ITR0                   //内部互联信号 ITR0
 **                       ATIM3_M23_MSCR_TS_ITR1                   //内部互联信号 ITR1
 **                       ATIM3_M23_MSCR_TS_ITR2                   //内部互联信号 ITR2
 **                       ATIM3_M23_MSCR_TS_ITR3                   //内部互联信号 ITR3
 **                       ATIM3_M23_MSCR_TS_CH0A_EDGE              //端口CH0A的边沿信号
 **                       ATIM3_M23_MSCR_TS_IAFP                   //端口CH0A的滤波相位选择后的信号IAFP
 **                       ATIM3_M23_MSCR_TS_IBFP                   //端口CH0B的滤波相位选择后的信号IBFP
 ** 
 ** \retval None                                   
 *****************************************************************************/
void ATIM3_Mode23_MasterSlave_Trig_Set(stc_atim3_m23_master_slave_cfg_t* pstcCfg)
{
    REG_MODIFY(ATIM3MODE23->MSCR, 
               ATIM3MODE23_MSCR_MSM|ATIM3MODE23_MSCR_MMS|ATIM3MODE23_MSCR_SMS|ATIM3MODE23_MSCR_TS,
               pstcCfg->u32MasterSlaveSel|pstcCfg->u32MasterSrc|pstcCfg->u32SlaveModeSel|pstcCfg->u32TsSel); 
}

/**
 *****************************************************************************
 ** \brief ATIM3 IA0输入选择(模式23)
 **
 ** \param [in]  u32Ia0Sel       CH0A输入通道选择
 **              ATIM3_M23_MSCR_IA0_CH0A        //IA0选择CH0A
 **              ATIM3_M23_MSCR_IA0_CH012A_XOR  //CH0A,CH1A,CH2A的XOR的值
 ** 
 ** \retval None                                   
 *****************************************************************************/
void ATIM3_Mode23_MSCR_IA0_Sel(uint32_t u32Ia0Sel)
{
    REG_MODIFY(ATIM3MODE23->MSCR, ATIM3MODE23_MSCR_IA0S, u32Ia0Sel); 
}

/**
 *****************************************************************************
 ** \brief ATIM3 IB0输入选择(模式23)
 **
 ** \param [in]  u32Ib0Sel       CH0B输入通道选择
 **              ATIM3_M23_MSCR_IB0_CH0B        //IB0选择CH0B
 **              ATIM3_M23_MSCR_IB0_TS_SOURCE   //IB0选择TS的源
 ** 
 ** \retval None                                   
 *****************************************************************************/
void ATIM3_Mode23_MSCR_IB0_Sel(uint32_t u32Ib0Sel)
{
    REG_MODIFY(ATIM3MODE23->MSCR, ATIM3MODE23_MSCR_IB0S, u32Ib0Sel); 
}

/**
 *****************************************************************************
 ** \brief ATIM3 通道0/1/2 CHxA输出设置(模式23)
 **
 ** \param [in]  u32Channel       通道序号
 **              ATIM3_M23_OUTPUT_CHANNEL_CH0       //通道0
 **              ATIM3_M23_OUTPUT_CHANNEL_CH1       //通道1
 **              ATIM3_M23_OUTPUT_CHANNEL_CH2       //通道2
 **
 ** \param [in]  pstcCfg          初始化配置结构体指针
 **              pstcCfg->u32CHxACmpCap             //通道CHxA比较捕获功能选择
 **                       ATIM3_M23_CRCHx_CSA_CSB_COMPARE          //比较模式
 **                       ATIM3_M23_CRCHx_CSA_CSB_CAPTURE          //捕获模式
 **
 **              pstcCfg->u32CHxACmpModeCtrl        //CHxA比较输出模式控制
 **                       ATIM3_M23_FLTR_OCMxx_FORCE_LOW           //强制为0低电平
 **                       ATIM3_M23_FLTR_OCMxx_FORCE_HIGH          //强制为1高电平
 **                       ATIM3_M23_FLTR_OCMxx_COMP_FORCE_LOW      //比较匹配时候强制为0低电平
 **                       ATIM3_M23_FLTR_OCMxx_COMP_FORCE_HIGH     //比较匹配时候强制为1高电平
 **                       ATIM3_M23_FLTR_OCMxx_COMP_REVERSE        //比较匹配时候翻转
 **                       ATIM3_M23_FLTR_OCMxx_COMP_ONE_PRD_HIGH   //比较匹配时候输出一个计数周期的高电平
 **                       ATIM3_M23_FLTR_OCMxx_PWM_MODE_1          //PWM模式1
 **                       ATIM3_M23_FLTR_OCMxx_PWM_MODE_2          //PWM模式2
 **
 **              pstcCfg->u32CHxAPolarity           //CHxA极性控制
 **                       ATIM3_M23_FLTR_CCPxx_NORMAL_IN_OUT       //正常输出
 **                       ATIM3_M23_FLTR_CCPxx_REVERSE_IN_OUT      //反向输出
 **
 **              pstcCfg->u32CHxACmpBufEn           //CHxA比较缓存使能控制
 **                       ATIM3_M23_CRCHx_BUFEx_DISABLE            //禁止
 **                       ATIM3_M23_CRCHx_BUFEx_ENABLE             //使能
 **
 **              pstcCfg->u32CHxACmpIntSel          //CHxA比较匹配控制
 **                       ATIM3_M23_M23CR_CISA_DISABLE_IRQ         //无匹配
 **                       ATIM3_M23_M23CR_CISA_RISE_IRQ            //上升沿匹配
 **                       ATIM3_M23_M23CR_CISA_FALL_IRQ            //下降沿匹配
 **                       ATIM3_M23_M23CR_CISA_RISE_FALL_IRQ       //上升沿和下降沿匹配
 ** 
 ** \retval None
 *****************************************************************************/
void ATIM3_Mode23_PortOutput_CHxA_Cfg(uint32_t u32Channel, stc_atim3_m23_compare_cfg_t* pstcCfg)
{
    REG_MODIFY(*(&ATIM3MODE23->CRCH0 + u32Channel),
                ATIM3MODE23_CRCH0_CSA | ATIM3MODE23_CRCH0_BUFEA,
                pstcCfg->u32CHxCmpCap | pstcCfg->u32CHxCmpBufEn);
    
    REG_MODIFY(ATIM3MODE23->FLTR, 
                  (ATIM3MODE23_FLTR_OCMA0FLTA0 << (u32Channel*ATIM3MODE23_FLTR_OCMA1FLTA1_Pos))\
                  | (ATIM3MODE23_FLTR_CCPA0 << (u32Channel*ATIM3MODE23_FLTR_OCMA1FLTA1_Pos)),
                  (pstcCfg->u32CHxCmpModeCtrl << (u32Channel*ATIM3MODE23_FLTR_OCMA1FLTA1_Pos))\
                  | (pstcCfg->u32CHxPolarity << (u32Channel*ATIM3MODE23_FLTR_OCMA1FLTA1_Pos))); 
    
    REG_MODIFY(ATIM3MODE23->M23CR, ATIM3MODE23_M23CR_CIS, pstcCfg->u32CHxCmpIntSel);
}


/**
 *****************************************************************************
 ** \brief ATIM3 通道0/1/2 CHxB输出设置(模式23)
 **
 ** \param [in]  u32Channel       通道序号
 **              ATIM3_M23_OUTPUT_CHANNEL_CH0       //通道0
 **              ATIM3_M23_OUTPUT_CHANNEL_CH1       //通道1
 **              ATIM3_M23_OUTPUT_CHANNEL_CH2       //通道2
 **
 ** \param [in]  pstcCfg          初始化配置结构体指针
 **              pstcCfg->u32CHxBCmpCap             //通道CHxB比较捕获功能选择
 **                       ATIM3_M23_CRCHx_CSA_CSB_COMPARE          //比较模式
 **                       ATIM3_M23_CRCHx_CSA_CSB_CAPTURE          //捕获模式
 **
 **              pstcCfg->u32CHxBCmpModeCtrl        //CHxB比较输出模式控制
 **                       ATIM3_M23_FLTR_OCMxx_FORCE_LOW           //强制为0低电平
 **                       ATIM3_M23_FLTR_OCMxx_FORCE_HIGH          //强制为1高电平
 **                       ATIM3_M23_FLTR_OCMxx_COMP_FORCE_LOW      //比较匹配时候强制为0低电平
 **                       ATIM3_M23_FLTR_OCMxx_COMP_FORCE_HIGH     //比较匹配时候强制为1高电平
 **                       ATIM3_M23_FLTR_OCMxx_COMP_REVERSE        //比较匹配时候翻转
 **                       ATIM3_M23_FLTR_OCMxx_COMP_ONE_PRD_HIGH   //比较匹配时候输出一个计数周期的高电平
 **                       ATIM3_M23_FLTR_OCMxx_PWM_MODE_1          //PWM模式1
 **                       ATIM3_M23_FLTR_OCMxx_PWM_MODE_2          //PWM模式2
 **
 **              pstcCfg->u32CHxBPolarity           //CHxB极性控制
 **                       ATIM3_M23_FLTR_CCPxx_NORMAL_IN_OUT       //正常输出
 **                       ATIM3_M23_FLTR_CCPxx_REVERSE_IN_OUT      //反向输出
 **
 **              pstcCfg->u32CHxBCmpBufEn           //CHxB比较缓存使能控制
 **                       ATIM3_M23_CRCHx_BUFEx_DISABLE            //禁止
 **                       ATIM3_M23_CRCHx_BUFEx_ENABLE             //使能
 **
 **              pstcCfg->u32CHxBCmpIntSel          //CHxB比较匹配控制
 **                       ATIM3_M23_CRCHx_CISBx_DISABLE_IRQ        //无匹配
 **                       ATIM3_M23_CRCHx_CISBx_RISE_IRQ           //上升沿匹配
 **                       ATIM3_M23_CRCHx_CISBx_FALL_IRQ           //下降沿匹配
 **                       ATIM3_M23_CRCHx_CISBx_RISE_FALL_IRQ      //上升沿和下降沿匹配
 ** 
 ** \retval None
 *****************************************************************************/
void ATIM3_Mode23_PortOutput_CHxB_Cfg(uint32_t u32Channel, stc_atim3_m23_compare_cfg_t* pstcCfg)
{
    REG_MODIFY(*(&ATIM3MODE23->CRCH0 + u32Channel),\
                      ATIM3MODE23_CRCH0_CSB | ATIM3MODE23_CRCH0_BUFEB | ATIM3MODE23_CRCH0_CISB,
                      (pstcCfg->u32CHxCmpCap<<1) | (pstcCfg->u32CHxCmpBufEn<<1) | pstcCfg->u32CHxCmpIntSel);
    
    REG_MODIFY(ATIM3MODE23->FLTR, 
                  (ATIM3MODE23_FLTR_OCMB0FLTB0 << (u32Channel*ATIM3MODE23_FLTR_OCMA1FLTA1_Pos))\
                  | (ATIM3MODE23_FLTR_CCPB0 << (u32Channel*ATIM3MODE23_FLTR_OCMA1FLTA1_Pos)),
                  (pstcCfg->u32CHxCmpModeCtrl << (u32Channel*ATIM3MODE23_FLTR_OCMA1FLTA1_Pos+ATIM3MODE23_FLTR_OCMB0FLTB0_Pos))\
                  | (pstcCfg->u32CHxPolarity << (u32Channel*ATIM3MODE23_FLTR_OCMA1FLTA1_Pos+ATIM3MODE23_FLTR_OCMB0FLTB0_Pos))); 
}

/**
 *****************************************************************************
 ** \brief ATIM3 CH3通道3输出设置(模式23)
 **
 ** \param [in]  pstcCfg          初始化配置结构体指针
 **              pstcCfg->bEnableCH3Compare //通道CH3比较使能/禁止
 **                       FALSE:                                   //禁止
 **                       TRUE:                                    //使能
 **
 **              pstcCfg->u32CH3CmpIntSel   //CH3比较匹配中断模式设置
 **                       ATIM3_M23_CRCH3_CIS_DISABLE_IRQ          //无匹配
 **                       ATIM3_M23_CRCH3_CIS_RISE_IRQ             //上升沿匹配
 **                       ATIM3_M23_CRCH3_CIS_FALL_IRQ             //下降沿匹配
 **                       ATIM3_M23_CRCH3_CIS_RISE_FALL_IRQ        //上升沿和下降沿匹配
 **
 **              pstcCfg->bTrigDMA          //CH3比较触发DMA使能/禁止
 **                       FALSE:                                   //禁止
 **                       TRUE:                                    //使能
 **
 **              pstcCfg->bEnableCh3Buffer  //CH3比较缓存使能控制
 **                       FALSE:                                   //禁止
 **                       TRUE:                                    //使能
 ** 
 ** \retval None
 *****************************************************************************/
void ATIM3_Mode23_CH3_Compare_Cfg(stc_atim3_m23_ch3_ctl_cfg_t* pstcCfg)
{
    REG_MODIFY(ATIM3MODE23->CRCH3,
               ATIM3MODE23_CRCH3_C3 | ATIM3MODE23_CRCH3_CIS | ATIM3MODE23_CRCH3_CD | ATIM3MODE23_CRCH3_BUF,
               (uint32_t)pstcCfg->bEnableCH3Compare << ATIM3MODE23_CRCH3_C3_Pos\
               | pstcCfg->u32CH3CmpIntSel\
               | (uint32_t)pstcCfg->bTrigDMA << ATIM3MODE23_CRCH3_CD_Pos\
               | (uint32_t)pstcCfg->bEnableCh3Buffer << ATIM3MODE23_CRCH3_BUF_Pos);
}

/**
 *****************************************************************************
 ** \brief ATIM3通道0/1/2 CHxA输入设置(模式23)
 **
 ** \param [in]  u32Channel       通道序号
 **              ATIM3_M23_OUTPUT_CHANNEL_CH0       //通道0
 **              ATIM3_M23_OUTPUT_CHANNEL_CH1       //通道1
 **              ATIM3_M23_OUTPUT_CHANNEL_CH2       //通道2
 **
 ** \param [in]  pstcCfg          初始化配置结构体指针
 **              pstcCfg->u32CHxACmpCap             //通道CHxA比较捕获功能选择
 **                       ATIM3_M23_CRCHx_CSA_CSB_COMPARE                //比较模式
 **                       ATIM3_M23_CRCHx_CSA_CSB_CAPTURE                //捕获模式
 ** 
 **              pstcCfg->enCHxACapSel              //CHxA通道捕获边沿选择
 **                       ATIM3_M23_CRCHx_CRxCFx_CAPTURE_EDGE_DISABLE    //禁止上升沿或下降沿捕获
 **                       ATIM3_M23_CRCHx_CRxCFx_CAPTURE_EDGE_RISE       //上升沿捕获使能
 **                       ATIM3_M23_CRCHx_CRxCFx_CAPTURE_EDGE_FALL       //下降沿捕获使能
 **                       ATIM3_M23_CRCHx_CRxCFx_CAPTURE_EDGE_RISE_FALL  //上升沿和下降沿捕获使能
 ** 
 **              pstcCfg->u32CHxAInFlt             //CHxA输入通道滤波设置
 **                       ATIM3_M23_FLTR_FLTxx_NONE                      //无滤波
 **                       ATIM3_M23_FLTR_FLTxx_THREE_PCLK                //PCLK 3个连续有效
 **                       ATIM3_M23_FLTR_FLTxx_THREE_PCLK_4              //PCLK/4 3个连续有效
 **                       ATIM3_M23_FLTR_FLTxx_THREE_PCLK_16             //PCLK/16 3个连续有效
 **                       ATIM3_M23_FLTR_FLTxx_THREE_PCLK_64             //PCLK/64 3个连续有效
 **
 **              pstcCfg->u32CHxAPolarity          //CHxA极性控制
 **                       ATIM3_M23_FLTR_CCPxx_NORMAL_IN_OUT             //正常输入
 **                       ATIM3_M23_FLTR_CCPxx_REVERSE_IN_OUT            //反向输入
 ** 
 **
 ** \retval None
 *****************************************************************************/
void ATIM3_Mode23_PortInput_CHxA_Cfg(uint32_t u32Channel, stc_atim3_m23_input_cfg_t* pstcCfg)
{         
    REG_MODIFY(*(&ATIM3MODE23->CRCH0 + u32Channel),
                      ATIM3MODE23_CRCH0_CSA | ATIM3MODE23_CRCH0_BKSACFACRA,
                      pstcCfg->u32CHxCmpCap | pstcCfg->u32CHxCapSel);
    
    REG_MODIFY(ATIM3MODE23->FLTR,\
                   (ATIM3MODE23_FLTR_OCMA0FLTA0 << (u32Channel * ATIM3MODE23_FLTR_OCMA1FLTA1_Pos))\
                   | (ATIM3MODE23_FLTR_CCPA0 << (u32Channel * ATIM3MODE23_FLTR_OCMA1FLTA1_Pos)),
                   (pstcCfg->u32CHxInFlt << (u32Channel * ATIM3MODE23_FLTR_OCMA1FLTA1_Pos))\
                   | (pstcCfg->u32CHxPolarity << (u32Channel * ATIM3MODE23_FLTR_OCMA1FLTA1_Pos))); 
} 
   
/**
 *****************************************************************************
 ** \brief ATIM3 通道0/1/2 CHxB输入设置(模式23)
 **
 ** \param [in]  u32Channel       通道序号
 **              ATIM3_M23_OUTPUT_CHANNEL_CH0       //通道0
 **              ATIM3_M23_OUTPUT_CHANNEL_CH1       //通道1
 **              ATIM3_M23_OUTPUT_CHANNEL_CH2       //通道2
 **
 ** \param [in]  pstcCfg          初始化配置结构体指针
 **              pstcCfg->u32CHxBCmpCap            //通道CHxB比较捕获功能选择
 **                       ATIM3_M23_CRCHx_CSA_CSB_COMPARE                //比较模式
 **                       ATIM3_M23_CRCHx_CSA_CSB_CAPTURE                //捕获模式
 ** 
 **              pstcCfg->enCHxBCapSel              //CHxB通道捕获边沿选择
 **                      ATIM3_M23_CRCHx_CRxCFx_CAPTURE_EDGE_DISABLE     //禁止上升沿或下降沿捕获
 **                      ATIM3_M23_CRCHx_CRxCFx_CAPTURE_EDGE_RISE        //上升沿捕获使能
 **                       ATIM3_M23_CRCHx_CRxCFx_CAPTURE_EDGE_FALL       //下降沿捕获使能
 **                       ATIM3_M23_CRCHx_CRxCFx_CAPTURE_EDGE_RISE_FALL  //上升沿和下降沿捕获使能
 ** 
 **              pstcCfg->u32CHxBInFlt             //CHxB输入通道滤波设置
 **                       ATIM3_M23_FLTR_FLTxx_NONE                      //无滤波
 **                       ATIM3_M23_FLTR_FLTxx_THREE_PCLK                //PCLK 3个连续有效
 **                       ATIM3_M23_FLTR_FLTxx_THREE_PCLK_4              //PCLK/4 3个连续有效
 **                       ATIM3_M23_FLTR_FLTxx_THREE_PCLK_16             //PCLK/16 3个连续有效
 **                       ATIM3_M23_FLTR_FLTxx_THREE_PCLK_64             //PCLK/64 3个连续有效
 **
 **              pstcCfg->u32CHxBPolarity          //CHxB极性控制
 **                       ATIM3_M23_FLTR_CCPxx_NORMAL_IN_OUT             //正常输入
 **                       ATIM3_M23_FLTR_CCPxx_REVERSE_IN_OUT            //反向输入
 ** 
 **
 ** \retval None
 *****************************************************************************/
void ATIM3_Mode23_PortInput_CHxB_Cfg(uint32_t u32Channel, stc_atim3_m23_input_cfg_t* pstcCfg)
{         
    REG_MODIFY(*(&ATIM3MODE23->CRCH0 + u32Channel), 
                      ATIM3MODE23_CRCH0_CSB | ATIM3MODE23_CRCH0_BKSBCFBCRB,
                     (pstcCfg->u32CHxCmpCap << 1) | (pstcCfg->u32CHxCapSel << ATIM3MODE23_CRCH0_BKSBCFBCRB_Pos));
    
    REG_MODIFY(ATIM3MODE23->FLTR, \
                  (ATIM3MODE23_FLTR_OCMB0FLTB0 << (u32Channel * ATIM3MODE23_FLTR_OCMA1FLTA1_Pos))\
                  | (ATIM3MODE23_FLTR_CCPB0 << (u32Channel * ATIM3MODE23_FLTR_OCMA1FLTA1_Pos)),
                  (pstcCfg->u32CHxInFlt << (u32Channel * ATIM3MODE23_FLTR_OCMA1FLTA1_Pos +ATIM3MODE23_FLTR_OCMB0FLTB0_Pos))\
                  | (pstcCfg->u32CHxPolarity << (u32Channel * ATIM3MODE23_FLTR_OCMA1FLTA1_Pos +ATIM3MODE23_FLTR_OCMB0FLTB0_Pos))); 
  
}

/**
 *****************************************************************************
 ** \brief ATIM3 ERT输入控制(模式23)
 **
 ** \param [in]  pstcCfg       初始化配置结构体指针
 **              pstcCfg->u32ETRFlt             //ETP输入通道滤波设置
  **                      ATIM3_M23_FLTR_FLTxx_THREE_PCLK       //PCLK 3个连续有效
 **                       ATIM3_M23_FLTR_FLTxx_THREE_PCLK_4     //PCLK/4 3个连续有效
 **                       ATIM3_M23_FLTR_FLTxx_THREE_PCLK_16    //PCLK/16 3个连续有效
 **                       ATIM3_M23_FLTR_FLTxx_THREE_PCLK_64    //PCLK/64 3个连续有效
 **
 **              pstcCfg->u32ETRPolarity       //ETP输入极性控制
 **                       ATIM3_M23_FLTR_ETP_NORMAL_IN          //正常输入
 **                       ATIM3_M23_FLTR_ETP_REVERSE_IN         //反向输入
 ** 
 ** \retval None
 *****************************************************************************/
void ATIM3_Mode23_ETRInput_Cfg(stc_atim3_m23_etr_input_cfg_t* pstcCfg)
{
    REG_MODIFY(ATIM3MODE23->FLTR, 
               ATIM3MODE23_FLTR_ETP | ATIM3MODE23_FLTR_FLTET,
               pstcCfg->u32ETRPolarity | (pstcCfg->u32ETRFlt << ATIM3MODE23_FLTR_FLTET_Pos));   
}

/**
 *****************************************************************************
 ** \brief ATIM3 刹车BK输入控制(模式23)
 **
 ** \param [in]  pstcBkCfg      初始化配置结构体指针
 **              pstcBkCfg->u32EnBrake                  //刹车使能设置
 **                       ATIM3_M23_DTR_BKE_BRAKE_DISABLE               //禁止
 **                       ATIM3_M23_DTR_BKE_BRAKE_ENABLE                //使能
 **
 **              pstcBkCfg->u32EnSafetyBk               //安全模式(osc fail,brown down,lockup)刹车使能设置
 **                       ATIM3_M23_DTR_SAFEEN_BRAKE_DISABLE            //禁止
 **                       ATIM3_M23_DTR_SAFEEN_BRAKE_ENABLE             //使能
 **
 **              pstcBkCfg->u32BrakePolarity            //刹车输入极性设置
 **                       ATIM3_M23_FLTR_BKP_NORMAL_IN                  //正相
 **                       ATIM3_M23_FLTR_BKP_REVERSE_IN                 //反相
 **
 **              pstcBkCfg->u32BrakeFlt                 //刹车输入滤波设置
 **                       ATIM3_M23_FLTR_FLTxx_THREE_PCLK               //PCLK 3个连续有效
 **                       ATIM3_M23_FLTR_FLTxx_THREE_PCLK_4             //PCLK/4 3个连续有效
 **                       ATIM3_M23_FLTR_FLTxx_THREE_PCLK_16            //PCLK/16 3个连续有效
 **                       ATIM3_M23_FLTR_FLTxx_THREE_PCLK_64            //PCLK/64 3个连续有效
 **
 ** \retval None
 **
 *****************************************************************************/
void ATIM3_Mode23_BrakeInput_Cfg(stc_atim3_m23_bk_input_cfg_t* pstcBkCfg)
{
    REG_MODIFY(ATIM3MODE23->DTR, 
               ATIM3MODE23_DTR_BK | ATIM3MODE23_DTR_SAFE,
               pstcBkCfg->u32EnBrake | pstcBkCfg->u32EnSafetyBk);
    
    REG_MODIFY(ATIM3MODE23->FLTR, 
               ATIM3MODE23_FLTR_BKP | ATIM3MODE23_FLTR_FLTBK,
               pstcBkCfg->u32BrakePolarity | (pstcBkCfg->u32BrakeFlt << ATIM3MODE23_FLTR_FLTBK_Pos));
}

/**
 *****************************************************************************
 ** \brief ATIM3 刹车BK输入控制(模式23)
 **
 **              u32Channel                 //Atimer3 通道选择
 **                       ATIM3_M23_OUTPUT_CHANNEL_CH0            //通道0 CH0
 **                       ATIM3_M23_OUTPUT_CHANNEL_CH1            //通道1 CH1
 **                       ATIM3_M23_OUTPUT_CHANNEL_CH2            //通道2 CH2
 **
 **              u32ChxaStatus               //CHxA端口
 **              u32ChxbStatus               //CHxB端口
 **                       ATIM3_M23_CRCHx_BKSA_BKSB_PORT_OUTPUT_HIZ     //高阻态
 **                       ATIM3_M23_CRCHx_BKSA_BKSB_PORT_OUTPUT_KEEP    //保持，无影响
 **                       ATIM3_M23_CRCHx_BKSA_BKSB_PORT_OUTPUT_LOW     //强制输出低电平
 **                       ATIM3_M23_CRCHx_BKSA_BKSB_PORT_OUTPUT_HIGH    //强制输出高电平
 **
 ** \retval None
 *****************************************************************************/
void ATIM3_Mode23_Brake_Port_Status_Cfg(uint32_t u32Channel, uint32_t u32ChxaStatus, uint32_t u32ChxbStatus)
{
    REG_MODIFY( *(&ATIM3MODE23->CRCH0 + u32Channel), 
                   ATIM3MODE23_CRCH0_BKSACFACRA | ATIM3MODE23_CRCH0_BKSBCFBCRB,
                   u32ChxaStatus | (u32ChxbStatus << ATIM3MODE23_CRCH0_BKSBCFBCRB_Pos));
}

/**
 *****************************************************************************
** \brief ATIM3 死区功能(模式23)
 **
 ** \param [in]  pstcCfg       初始化配置结构体指针
 **              pstcBkCfg->bEnDeadTime        //死区使能控制    FALSE: //禁止,  TRUE: //使能
 **              
 **              pstcBkCfg->u32DeadTimeValue   //8bit 死区时间值
 ** 
 ** \retval None
 *****************************************************************************/
void ATIM3_Mode23_DT_Cfg(stc_atim3_m23_dt_cfg_t* pstcCfg)
{
    REG_MODIFY(ATIM3MODE23->DTR, 
               ATIM3MODE23_DTR_DT | ATIM3MODE23_DTR_DTR,
               (((uint32_t)pstcCfg->bEnDeadTime) << ATIM3MODE23_DTR_DT_Pos)\
               | (pstcCfg->u32DeadTimeValue & 0xFF));
}


/**
 *****************************************************************************
 ** \brief Base ATIM3 触发ADC控制(模式23)
 **
 ** \param [in]  pstcCfg       初始化配置结构体指针
 **              pstcCfg->bEnTrigADC           //使能ADC触发全局控制    FALSE: //禁止,  TRUE: //使能
 **              pstcCfg->bEnUevTrigADC        //使能事件更新触发ADC    FALSE: //禁止,  TRUE: //使能
 **              pstcCfg->bEnCH0ACmpTrigADC    //使能通道CH0A比较匹配触发ADC    FALSE: //禁止,  TRUE: //使能
 **              pstcCfg->bEnCH0BCmpTrigADC    //使能通道CH0B比较匹配触发ADC    FALSE: //禁止,  TRUE: //使能
 **              pstcCfg->bEnCH1ACmpTrigADC    //使能通道CH1A比较匹配触发ADC    FALSE: //禁止,  TRUE: //使能
 **              pstcCfg->bEnCH1BCmpTrigADC    //使能通道CH1B比较匹配触发ADC    FALSE: //禁止,  TRUE: //使能
 **              pstcCfg->bEnCH2ACmpTrigADC    //使能通道CH2A比较匹配触发ADC    FALSE: //禁止,  TRUE: //使能
 **              pstcCfg->bEnCH2BCmpTrigADC    //使能通道CH2B比较匹配触发ADC    FALSE: //禁止,  TRUE: //使能
 ** 
 ** \retval None
 *****************************************************************************/
void ATIM3_Mode23_TrigADC_Cfg(stc_atim3_m23_adc_trig_cfg_t* pstcCfg)
{
    REG_MODIFY(ATIM3MODE23->ADTR, ATIM3MODE23_ADTR_ADT|\
                                      ATIM3MODE23_ADTR_UEV|\
                                      ATIM3MODE23_ADTR_CMA0|\
                                      ATIM3MODE23_ADTR_CMA1|\
                                      ATIM3MODE23_ADTR_CMA2|\
                                      ATIM3MODE23_ADTR_CMB0|\
                                      ATIM3MODE23_ADTR_CMB1|\
                                      ATIM3MODE23_ADTR_CMB2,
                                      ((uint32_t)pstcCfg->bEnTrigADC)        << ATIM3MODE23_ADTR_ADT_Pos|\
                                      ((uint32_t)pstcCfg->bEnUevTrigADC)     << ATIM3MODE23_ADTR_UEV_Pos|\
                                      ((uint32_t)pstcCfg->bEnCH0ACmpTrigADC) << ATIM3MODE23_ADTR_CMA0_Pos|\
                                      ((uint32_t)pstcCfg->bEnCH0BCmpTrigADC) << ATIM3MODE23_ADTR_CMB0_Pos|\
                                      ((uint32_t)pstcCfg->bEnCH1ACmpTrigADC) << ATIM3MODE23_ADTR_CMA1_Pos|\
                                      ((uint32_t)pstcCfg->bEnCH1BCmpTrigADC) << ATIM3MODE23_ADTR_CMB1_Pos|\
                                      ((uint32_t)pstcCfg->bEnCH2ACmpTrigADC) << ATIM3MODE23_ADTR_CMA2_Pos|\
                                      ((uint32_t)pstcCfg->bEnCH2BCmpTrigADC) << ATIM3MODE23_ADTR_CMB2_Pos);   
}

/**
 *****************************************************************************
** \brief ATIM3 重复周期设置(模式23)
 **
 ** \param [in]  pstcCfg       初始化配置结构体指针
 **              pstcCfg->u32EnUnderFlowMask          //重复计数控制下溢出屏蔽
                          ATIM3_M23_RCR_UND_IRQ_EVT_CNT_MASK          //下溢出计数屏蔽，RCR不计算下溢出
                          ATIM3_M23_RCR_UND_IRQ_EVT_CNT_ENABLE        //下溢出计数使能，RCR计算下溢出
                
                 pstcCfg->u32EnOverFLowMask           //重复计数控制上溢出屏蔽
                          ATIM3_M23_RCR_OVF_IRQ_EVT_CNT_MASK          //上溢出屏蔽，RCR不计算上溢出
                          ATIM3_M23_RCR_OVF_IRQ_EVT_CNT_ENABLE        //上溢出不屏蔽，RCR计算上溢出

                 pstcCfg->u32RepeatCountNum          //8 bit重复计数次数设置寄存器
 ** 
 ** \retval None                                 
 *****************************************************************************/
void ATIM3_Mode23_SetRepeatPeriod(stc_atim3_m23_rcr_cfg_t* pstcCfg)
{
    REG_MODIFY(ATIM3MODE23->RCR, 
               ATIM3MODE23_RCR_UD | ATIM3MODE23_RCR_OV | ATIM3MODE23_RCR_RCR,
               pstcCfg->u32EnUnderFlowMask | pstcCfg->u32EnOverFLowMask | pstcCfg->u32RepeatCountNum);
}

/**
 *****************************************************************************
 ** \brief ATIM3 OCREF清除功能(模式23)
 **
 ** \param [in]  pstcCfg       初始化配置结构体指针
 **              pstcCfg->bOCSourceClrEn     //来自OCCS的OCREF_Clr源是否使能清除OCREF输出
 **                       FALSE     //禁止
 **                       TRUE      //使能
 **
 **              pstcCfg->u32OCRefClrSrcSel  //OCREF清除源选择
 **                        ATIM3_M23_M23CR_OCCS_VC            //来自VC输出的OCREF_Clr
 **                        ATIM3_M23_M23CR_OCCS_ETR           //来自ETR端口滤波相位选择后的OCREF_Clr
 **
 ** \retval None                                   
 *****************************************************************************/
void ATIM3_Mode23_OCRefClr(stc_atim3_m23_ocref_clr_cfg_t* pstcCfg)
{
    REG_MODIFY(ATIM3MODE23->M23CR, 
               ATIM3MODE23_M23CR_OCC | ATIM3MODE23_M23CR_OCCS,
               ((uint32_t)pstcCfg->bOCSourceClrEn) << ATIM3MODE23_M23CR_OCC_Pos\
               | pstcCfg->u32OCRefClrSrcSel);
}

/**
 *****************************************************************************
 ** \brief ATIM3 使能/禁止 UVE更新触发DMA传输(模式23)
 **
 ** \param [in]  boolean_t bUevTrigDMA      //UEV更新触发DMA         FALSE://禁止     TRUE //使能
 **
 ** \retval None                                      
 *****************************************************************************/
void ATIM3_Mode23_EnDisable_UEV_TrigDMA(boolean_t bUevTrigDMA)
{
    REG_MODIFY(ATIM3MODE23->M23CR, ATIM3MODE23_M23CR_UD, (uint32_t)bUevTrigDMA << ATIM3MODE23_M23CR_UD_Pos);
}

/**
 *****************************************************************************
 ** \brief ATIM3 使能/禁止 TRIGGER触发DMA传输(模式23)
 **
 ** \param [in]  boolean_t bTITrigDMA      //Trigger触发DMA         FALSE://禁止     TRUE //使能
 **
 ** \retval None                                    
 *****************************************************************************/
void ATIM3_Mode23_EnDisable_Trigger_TrigDMA(boolean_t bTITrigDMA)
{
    REG_MODIFY(ATIM3MODE23->M23CR, ATIM3MODE23_M23CR_TD, (uint32_t)bTITrigDMA << ATIM3MODE23_M23CR_TD_Pos);
}

/**
 *****************************************************************************
 ** \brief ATIM3 使能/禁止 CH0A捕获比较触发DMA传输(模式23)
 **
 ** \param [in]  bCH0ATrigDMA      //CHOA捕获比较触发DMA         FALSE://禁止     TRUE //使能
 **
 ** \retval None
 *****************************************************************************/
void ATIM3_Mode23_EnDisable_CH0A_TrigDMA(boolean_t bCH0ATrigDMA)
{
    REG_MODIFY(ATIM3MODE23->CRCH0, ATIM3MODE23_CRCH0_CDEA, (uint32_t)bCH0ATrigDMA << ATIM3MODE23_CRCH0_CDEA_Pos);
}

/**
 *****************************************************************************
 ** \brief ATIM3 使能/禁止 CH0B捕获比较触发DMA传输(模式23)
 **
 ** \param [in]  bCH0BTrigDMA      //CHOB捕获比较触发DMA         FALSE://禁止     TRUE //使能
 **
 ** \retval None
 *****************************************************************************/
void ATIM3_Mode23_EnDisable_CH0B_TrigDMA(boolean_t bCH0BTrigDMA)
{
    REG_MODIFY(ATIM3MODE23->CRCH0, ATIM3MODE23_CRCH0_CDEB, (uint32_t)bCH0BTrigDMA << ATIM3MODE23_CRCH0_CDEB_Pos);
}

/**
 *****************************************************************************
 ** \brief ATIM3 使能/禁止 CH1A捕获比较触发DMA传输(模式23)
 **
 ** \param [in]  bCH1ATrigDMA      //CH1A捕获比较触发DMA         FALSE://禁止     TRUE //使能
 **
 ** \retval None
 *****************************************************************************/
void ATIM3_Mode23_EnDisable_CH1A_TrigDMA(boolean_t bCH1ATrigDMA)
{
    REG_MODIFY(ATIM3MODE23->CRCH1, ATIM3MODE23_CRCH1_CDEA, (uint32_t)bCH1ATrigDMA << ATIM3MODE23_CRCH1_CDEA_Pos);
}

/**
 *****************************************************************************
 ** \brief ATIM3 使能/禁止 CH1B捕获比较触发DMA传输(模式23)
 **
 ** \param [in]  bCH1BTrigDMA      //CH1B捕获比较触发DMA         FALSE://禁止     TRUE //使能
 **
 ** \retval None
 *****************************************************************************/
void ATIM3_Mode23_EnDisable_CH1B_TrigDMA(boolean_t bCH1BTrigDMA)
{
    REG_MODIFY(ATIM3MODE23->CRCH1, ATIM3MODE23_CRCH1_CDEB, (uint32_t)bCH1BTrigDMA << ATIM3MODE23_CRCH1_CDEB_Pos);
}

/**
 *****************************************************************************
 ** \brief ATIM3 使能/禁止 CH2A捕获比较触发DMA传输(模式23)
 **
 ** \param [in]  bCH2ATrigDMA      //CH2A捕获比较触发DMA         FALSE://禁止     TRUE //使能
 **
 ** \retval None
 *****************************************************************************/
void ATIM3_Mode23_EnDisable_CH2A_TrigDMA(boolean_t bCH2ATrigDMA)
{
    REG_MODIFY(ATIM3MODE23->CRCH2, ATIM3MODE23_CRCH2_CDEA, (uint32_t)bCH2ATrigDMA << ATIM3MODE23_CRCH2_CDEA_Pos);
}

/**
 *****************************************************************************
 ** \brief ATIM3 使能/禁止 CH2B捕获比较触发DMA传输(模式23)
 **
 ** \param [in]  bCH2BTrigDMA      //CH2B捕获比较触发DMA         FALSE://禁止     TRUE //使能
 **
 ** \retval None
 *****************************************************************************/
void ATIM3_Mode23_EnDisable_CH2B_TrigDMA(boolean_t bCH2BTrigDMA)
{
    REG_MODIFY(ATIM3MODE23->CRCH2, ATIM3MODE23_CRCH2_CDEB, (uint32_t)bCH2BTrigDMA << ATIM3MODE23_CRCH2_CDEB_Pos);
}

/**
 *****************************************************************************
 ** \brief ATIM3 使能/禁止 CH3比较触发DMA传输(模式23)
 **
 ** \param [in]  bCH3TrigDMA      //CH3捕获比较触发DMA         FALSE://禁止     TRUE //使能
 **
 ** \retval None
 *****************************************************************************/
void ATIM3_Mode23_EnDisable_CH3_TrigDMA(boolean_t bCH3TrigDMA)
{
    REG_MODIFY(ATIM3MODE23->CRCH3, ATIM3MODE23_CRCH3_CD, (uint32_t)bCH3TrigDMA << ATIM3MODE23_CRCH3_CD_Pos);
}


/**
 *****************************************************************************
 ** \brief ATIM3 比较模式下DMA比较触发选择(模式23)
 **
 ** \param [in]  u32CmpUevTrigDMA      //比较模式下DMA比较触发选择
 **              ATIM3_M23_MSCR_COMPARE_TRIG_DMA_ENABLE     //比较模式下，比较匹配触发DAM许可
 **              ATIM3_M23_MSCR_COMPARE_TRIG_DMA_DISABLE    //比较模式下，比较匹配不触发DMA，使用事件更新替代触发DMA
 ** 
 ** \retval None
 *****************************************************************************/
void ATIM3_Mode23_Compare_Trig_DMA_Sel(uint32_t u32CmpUevTrigDMA)
{
    REG_MODIFY(ATIM3MODE23->MSCR, ATIM3MODE23_MSCR_CCDS, u32CmpUevTrigDMA);
}

/**
 *****************************************************************************
 ** \brief ATIM3 CH0A通道0A捕获比较软件触发(模式23)
 **
 ** \param [in]  None
 ** 
 ** 
 ** \retval None                                  
 *****************************************************************************/
void ATIM3_Mode23_Enable_CH0A_SwTrig_Capture_Compare(void)
{
    REG_SETBITS(ATIM3MODE23->CRCH0, ATIM3MODE23_CRCH0_CCGA);
}

/**
 *****************************************************************************
 ** \brief ATIM3 CH0B通道0B捕获比较软件触发(模式23)
 **
 ** \param [in]  None
 ** 
 ** 
 ** \retval None                                     
 *****************************************************************************/
void ATIM3_Mode23_Enable_CH0B_SwTrig_Capture_Compare(void)
{
    REG_SETBITS(ATIM3MODE23->CRCH0, ATIM3MODE23_CRCH0_CCGB);
}


/**
 *****************************************************************************
 ** \brief ATIM3 CH1A通道1A捕获比较软件触发(模式23)
 **
 ** \param [in]  None
 ** 
 ** 
 ** \retval None                                  
 *****************************************************************************/
void ATIM3_Mode23_Enable_CH1A_SwTrig_Capture_Compare(void)
{
    REG_SETBITS(ATIM3MODE23->CRCH1, ATIM3MODE23_CRCH1_CCGA);
}

/**
 *****************************************************************************
 ** \brief ATIM3 CH1B通道1B捕获比较软件触发(模式23)
 **
 ** \param [in]  None
 ** 
 ** 
 ** \retval None                                     
 *****************************************************************************/
void ATIM3_Mode23_Enable_CH1B_SwTrig_Capture_Compare(void)
{
    REG_SETBITS(ATIM3MODE23->CRCH1, ATIM3MODE23_CRCH1_CCGB);
}

/**
 *****************************************************************************
 ** \brief ATIM3 CH2A通道2A捕获比较软件触发(模式23)
 **
 ** \param [in]  None
 ** 
 ** 
 ** \retval None                                  
 *****************************************************************************/
void ATIM3_Mode23_Enable_CH2A_SwTrig_Capture_Compare(void)
{
    REG_SETBITS(ATIM3MODE23->CRCH2, ATIM3MODE23_CRCH2_CCGA);
}

/**
 *****************************************************************************
 ** \brief ATIM3 CH2B通道2B捕获比较软件触发(模式23)
 **
 ** \param [in]  None
 ** 
 ** 
 ** \retval None                                     
 *****************************************************************************/
void ATIM3_Mode23_Enable_CH2B_SwTrig_Capture_Compare(void)
{
    REG_SETBITS(ATIM3MODE23->CRCH2, ATIM3MODE23_CRCH2_CCGB);
}


/**
 *****************************************************************************
 ** \brief ATIM3 软件更新使能(模式23)
 **
 **
 ** \param [in]  none
 ** 
 ** \retval None                                    
 *****************************************************************************/
void ATIM3_Mode23_EnableSoftwareUev(void)
{
    REG_SETBITS(ATIM3MODE23->M23CR, ATIM3MODE23_M23CR_UG);
}

/**
 *****************************************************************************
 ** \brief ATIM3 软件触发使能(模式23)
 **
 **
 ** \param [in]  none
 ** 
 ** \retval None                                     
 *****************************************************************************/
void ATIM3_Mode23_EnableSoftwareTrig(void)
{
    REG_SETBITS(ATIM3MODE23->M23CR, ATIM3MODE23_M23CR_TG);
}

/**
 *****************************************************************************
 ** \brief ATIM3 软件刹车使能(模式23)
 **
 **
 ** \param [in]  none
 ** 
 ** \retval None                                     
 *****************************************************************************/
void ATIM3_Mode23_EnableSoftwareBrake(void)
{
    REG_SETBITS(ATIM3MODE23->M23CR, ATIM3MODE23_M23CR_BG);   
}

/**
 *****************************************************************************
 ** \brief  获取 ATIM3 模式0/1/2/3 中断标志
 **
 ** \param  [in] u32InterruptFlagTypes: ATIMx中断标志类型
 **               ATIM3_INT_FLAG_UI        //溢出中断标志
 **               ATIM3_INT_FLAG_PWC_CA0   //通道CH0A发生捕获/比较匹配标志
 **               ATIM3_INT_FLAG_CA1       //通道CH1A发生捕获/比较匹配标志(仅ATIM3存在)
 **               ATIM3_INT_FLAG_CA2       //通道CH2A发生捕获/比较匹配标志(仅ATIM3存在)
 **               ATIM3_INT_FLAG_CB0       //通道CH0B发生捕获/比较匹配标志
 **               ATIM3_INT_FLAG_CB1       //通道CH1B发生捕获/比较匹配标志(仅ATIM3存在)
 **               ATIM3_INT_FLAG_CB2       //通道CH2B发生捕获/比较匹配标志(仅ATIM3存在)
 **               ATIM3_INT_FLAG_CA0E      //通道CH0A捕获数据丢失标志
 **               ATIM3_INT_FLAG_CA1E      //通道CH1A捕获数据丢失标志(仅ATIM3存在)
 **               ATIM3_INT_FLAG_CA2E      //通道CH2A捕获数据丢失标志(仅ATIM3存在)
 **               ATIM3_INT_FLAG_CB0E      //通道CH0B捕获数据丢失标志
 **               ATIM3_INT_FLAG_CB1E      //通道CH1B捕获数据丢失标志(仅ATIM3存在)
 **               ATIM3_INT_FLAG_CB2E      //通道CH2B捕获数据丢失标志(仅ATIM3存在)
 **               ATIM3_INT_FLAG_BI        //刹车中断标志
 **               ATIM3_INT_FLAG_TI        //触发中断标志
 **               ATIM3_INT_FLAG_OV        //上溢出中断标志
 **               ATIM3_INT_FLAG_UND       //下溢出中断标志
 **               ATIM3_INT_FLAG_CA3       //通道CH3比较匹配标志
 **
 ** \retval [out] 返回值: 0或者1
 *****************************************************************************/
uint32_t ATIM3_GetIntFlag(uint32_t u32InterruptFlagTypes)
{
    return(REG_READBITS(ATIM3MODE23->IFR, u32InterruptFlagTypes) == u32InterruptFlagTypes);
}


/**
 *****************************************************************************
 ** \brief  清除 ATIM3 模式0/1/2/3 中断 标志位
 **
 ** \param  [in] u32InterruptFlagTypes:  ATIMx清除中断标志类型
 **         ATIM3_INT_CLR_UI        //清除溢出中断标志
 **         ATIM3_INT_CLR_PWC_CA0   //清除通道CH0A发生捕获/比较匹配标志
 **         ATIM3_INT_CLR_CA1       //清除通道CH1A发生捕获/比较匹配标志(仅ATIM3存在)
 **         ATIM3_INT_CLR_CA2       //清除通道CH2A发生捕获/比较匹配标志(仅ATIM3存在)
 **         ATIM3_INT_CLR_CB0       //清除通道CH0B发生捕获/比较匹配标志
 **         ATIM3_INT_CLR_CB1       //清除通道CH1B发生捕获/比较匹配标志(仅ATIM3存在)
 **         ATIM3_INT_CLR_CB2       //清除通道CH2B发生捕获/比较匹配标志(仅ATIM3存在)
 **         ATIM3_INT_CLR_CA0E      //清除通道CH0A捕获数据丢失标志
 **         ATIM3_INT_CLR_CA1E      //清除通道CH1A捕获数据丢失标志(仅ATIM3存在)
 **         ATIM3_INT_CLR_CA2E      //清除通道CH2A捕获数据丢失标志(仅ATIM3存在)
 **         ATIM3_INT_CLR_CB0E      //清除通道CH0B捕获数据丢失标志
 **         ATIM3_INT_CLR_CB1E      //清除通道CH1B捕获数据丢失标志(仅ATIM3存在)
 **         ATIM3_INT_CLR_CB2E      //清除通道CH2B捕获数据丢失标志(仅ATIM3存在)
 **         ATIM3_INT_CLR_BI        //清除刹车中断标志
 **         ATIM3_INT_CLR_TI        //清除触发中断标志
 **         ATIM3_INT_CLR_OV        //清除上溢出中断标志
 **         ATIM3_INT_CLR_UND       //清除下溢出中断标志
 **         ATIM3_INT_CLR_CA3       //清除通道CH3比较匹配标志
 **
 **
 ** \retval NULL
 *****************************************************************************/
void ATIM3_ClearIrqFlag(uint32_t u32InterruptFlagTypes)
{
    REG_CLEARBITS(ATIM3MODE23->ICLR, u32InterruptFlagTypes);
}


/**
 *****************************************************************************
 ** \brief ATIM3 中断所有标志清除(模式23)
 **
 ** \param [in]  none
 ** 
 ** 
 ** \retval NULL
 *****************************************************************************/
void ATIM3_ClearAllIrqFlag(void)
{
    REG_CLEARBITS(ATIM3MODE23->ICLR, 0x7FFFDu);
}


/**
 *****************************************************************************
 ** \brief ATIM3 中断使能(模式0)
 **
 **
 ** \param [in]  none
 ** 
 ** \retval NULL
 *****************************************************************************/
void ATIM3_Mode0_EnableIrq(void)
{
    REG_SETBITS(ATIM3MODE0->M0CR, ATIM3MODE0_M0CR_UI);
}


/**
 *****************************************************************************
 ** \brief ATIM3 中断禁止(模式0)
 **
 **
 ** \param [in]  none
 ** 
 ** \retval NULL
 *****************************************************************************/
void ATIM3_Mode0_DisableIrq(void)
{
    REG_CLEARBITS(ATIM3MODE0->M0CR, ATIM3MODE0_M0CR_UI);
}


/**
 *****************************************************************************
 ** \brief ATIM3 中断使能(模式1)
 **
 ** \param [in]  u32InterruptTypes  中断类型
 **              ATIM3_M1_INT_UI     //溢出中断
 **              ATIM3_M1_INT_CA0    //脉冲宽度测量完成中断
 ** \retval NULL
 *****************************************************************************/
void ATIM3_Mode1_EnableIrq(uint32_t u32InterruptTypes)
{
    if(u32InterruptTypes & ATIM3_M1_INT_UI)
    {
        REG_SETBITS(ATIM3MODE1->M1CR, ATIM3MODE1_M1CR_UI);
    }
    if(u32InterruptTypes & ATIM3_M1_INT_CA0)
    {
        REG_SETBITS(ATIM3MODE1->CR0, ATIM3MODE1_CR0_CIEA);
    }
}


/**
 *****************************************************************************
 ** \brief ATIM3 中断禁止(模式1)
 **
 ** \param [in]  u32InterruptTypes  中断类型
 **              ATIM3_M1_INT_UI     //溢出中断
 **              ATIM3_M1_INT_CA0    //脉冲宽度测量完成中断
 ** 
 ** \retval NULL
 *****************************************************************************/
void ATIM3_Mode1_DisableIrq(uint32_t u32InterruptTypes)
{
    if(u32InterruptTypes & ATIM3_M1_INT_UI)
    {
        REG_CLEARBITS(ATIM3MODE1->M1CR, ATIM3MODE1_M1CR_UI);
    }
    if(u32InterruptTypes & ATIM3_M1_INT_CA0)
    {
        REG_CLEARBITS(ATIM3MODE1->CR0, ATIM3MODE1_CR0_CIEA);
    }
}


/**
 *****************************************************************************
 ** \brief ATIM3 中断使能(模式23)
 **
 ** \param [in]  u32InterruptTypes  中断类型
 **              ATIM3_M23_INT_UI   //溢出中断
 **              ATIM3_M23_INT_CA0  //通道CH0A发生捕获/比较匹配中断
 **              ATIM3_M23_INT_CB0  //通道CH0B发生捕获/比较匹配中断
 **              ATIM3_M23_INT_CA1  //通道CH1A发生捕获/比较匹配中断(仅ATIM3存在)
 **              ATIM3_M23_INT_CB1  //通道CH1B发生捕获/比较匹配中断(仅ATIM3存在)
 **              ATIM3_M23_INT_CA2  //通道CH2A发生捕获/比较匹配中断(仅ATIM3存在)
 **              ATIM3_M23_INT_CB2  //通道CH2B发生捕获/比较匹配中断(仅ATIM3存在)
 **              ATIM3_M23_INT_BI   //刹车中断
 **              ATIM3_M23_INT_TI   //触发中断
 **              ATIM3_M23_INT_OV   //上溢出中断
 **              ATIM3_M23_INT_UND  //下溢出中断
 **              ATIM3_M23_INT_CA3  //通道CH3比较匹配中断
 ** 
 ** \retval NULL
 *****************************************************************************/
void ATIM3_Mode23_EnableIrq (uint32_t u32InterruptTypes)
{
    uint32_t u32Types = 0;

    if(_INTERRUPT_M23CR_ID & u32InterruptTypes)
    {
        u32Types = u32InterruptTypes & _INTERRUPT_M23CR_MASK;
        REG_SETBITS(ATIM3MODE23->M23CR, u32Types);
    }
    
    if(_INTERRUPT_CRCH0_ID & u32InterruptTypes)
    {
        u32Types = u32InterruptTypes & _INTERRUPT_CRCH0_MASK;
        REG_SETBITS(ATIM3MODE23->CRCH0, u32Types);
    }
    
    if(_INTERRUPT_CRCH1_ID & u32InterruptTypes)
    {
        u32Types = u32InterruptTypes & _INTERRUPT_CRCH1_MASK;
        REG_SETBITS(ATIM3MODE23->CRCH1, u32Types << 2);
    }
    
    if(_INTERRUPT_CRCH2_ID & u32InterruptTypes)
    {
        u32Types = u32InterruptTypes & _INTERRUPT_CRCH2_MASK;
        REG_SETBITS(ATIM3MODE23->CRCH2, u32Types << 4);
    }
    
    if(u32InterruptTypes & ATIM3_M23_INT_CA3)
    {
        REG_SETBITS(ATIM3MODE23->CRCH3, ATIM3_M23_INT_CA3);
    }
}

/**
 *****************************************************************************
 ** \brief ATIM3 中断禁止(模式23)
 **
 ** \param [in]  u32InterruptTypes  中断类型
 **              ATIM3_M23_INT_UI   //溢出中断
 **              ATIM3_M23_INT_CA0  //通道CH0A发生捕获/比较匹配中断
 **              ATIM3_M23_INT_CB0  //通道CH0B发生捕获/比较匹配中断
 **              ATIM3_M23_INT_CA1  //通道CH1A发生捕获/比较匹配中断(仅ATIM3存在)
 **              ATIM3_M23_INT_CB1  //通道CH1B发生捕获/比较匹配中断(仅ATIM3存在)
 **              ATIM3_M23_INT_CA2  //通道CH2A发生捕获/比较匹配中断(仅ATIM3存在)
 **              ATIM3_M23_INT_CB2  //通道CH2B发生捕获/比较匹配中断(仅ATIM3存在)
 **              ATIM3_M23_INT_BI   //刹车中断
 **              ATIM3_M23_INT_TI   //触发中断
 **              ATIM3_M23_INT_OV   //上溢出中断
 **              ATIM3_M23_INT_UND  //下溢出中断
 **              ATIM3_M23_INT_CA3  //通道CH3比较匹配中断
 ** 
 ** \retval NULL                                   
 *****************************************************************************/
void ATIM3_Mode23_DisableIrq (uint32_t u32InterruptTypes)
{    
    uint32_t u32Types = 0;
    
    if(_INTERRUPT_M23CR_ID & u32InterruptTypes)
    {
        u32Types = u32InterruptTypes & _INTERRUPT_M23CR_MASK;
        REG_CLEARBITS(ATIM3MODE23->M23CR, u32Types);
    }
    
    if(_INTERRUPT_CRCH0_ID & u32InterruptTypes)
    {
        u32Types = u32InterruptTypes & _INTERRUPT_CRCH0_MASK;
        REG_CLEARBITS(ATIM3MODE23->CRCH0, u32Types);
    }
    
    if(_INTERRUPT_CRCH1_ID & u32InterruptTypes)
    {
        u32Types = u32InterruptTypes & _INTERRUPT_CRCH1_MASK;
        REG_CLEARBITS(ATIM3MODE23->CRCH1, u32Types << 2);
    }
    
    if(_INTERRUPT_CRCH2_ID & u32InterruptTypes)
    {
        u32Types = u32InterruptTypes & _INTERRUPT_CRCH2_MASK;
        REG_CLEARBITS(ATIM3MODE23->CRCH2, u32Types << 4);
    }
    if(u32InterruptTypes & ATIM3_M23_INT_CA3)
    {
        REG_CLEARBITS(ATIM3MODE23->CRCH3, ATIM3_M23_INT_CA3);
    }
}



//@} // ATIM3Group

/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
