/**
  ******************************************************************************
  * File Name          : ADXL355.c
  * Description        : This file provides code for the initial the  sensor or
  *                      read 3 axis Adata from it.
  ******************************************************************************

  ******************************************************************************
  */

#include "adxl355.h"

double  ax;
double  ay;
double  az;

/*
 函数功能: ADXL355 初始化
 配置相关寄存器  XL355_RANGE、XL355_SYNC等
 判断传感器是否连接正常
*/
void ADXL355_Init(void)
{

    printf("ADXL355 Init...");
/**********************ADLX355BZ CONFG***************************************************/
    SPI_ADXL355_WRITE(XL355_RANGE, 0x81);         /* Set sensor range within RANGE register */ //设置为 1000 0001 高速模式  ±2g
    printf("ADXL355 2...");
    SPI_ADXL355_WRITE(XL355_SYNC, 0x03);
/***************************************************************************/	
	
    uint32_t volatile ui32test  = SPI_ADXL355_READ1BYTE(XL355_DEVID_AD);              /* Read the ID register */
    uint32_t volatile ui32test2 = SPI_ADXL355_READ1BYTE(XL355_DEVID_MST);             /* Read the ID register */
    uint32_t volatile ui32test3 = SPI_ADXL355_READ1BYTE(XL355_PARTID);                /* Read the ID register */
    uint32_t volatile ui32test4 = SPI_ADXL355_READ1BYTE(XL355_REVID);

    /* Read the ID register */
//    uint32_t volatile ui32test5 = SPI_ADXL355_READ1BYTE(XL355_RANGE);                /* Read the ID register */
//    uint32_t volatile ui32test6 = SPI_ADXL355_READ1BYTE(XL355_SYNC);
    /* 验证ADXL355设备是否连接正常*/
    if(SPI_ADXL355_READ1BYTE(XL355_PARTID) == 0xED)

    {
        HAL_Delay(5);
        printf("\r\n设备正常!\r\n");
        printf("ADXL355_DEVID_AD:%x\r XL355_DEVID_MST:%x\r\n", ui32test, ui32test2);
        printf("ADXL355_PARTID:%x\r XL355_REVID:%x\r \n", ui32test3, ui32test4);
//		printf("ADXL355_29:%x\r XL355_2C:%x\r \n", ui32test5, ui32test6);
    }
    else
    {
        HAL_Delay(5);
        printf("\r\n设备不正常，请检查！\r\n");
    }
}
/*
  函数功能: ADXL355 传感器开始工作
*/
void ADXL355_Start_Sensor(void)
{
    uint8_t ui8temp;
    ui8temp = (uint8_t)SPI_ADXL355_READ1BYTE(XL355_POWER_CTL);       /* Read POWER_CTL register, before modifying it */
    ui8temp = ui8temp & 0xFE;                                        /* Set measurement bit in POWER_CTL register */
    SPI_ADXL355_WRITE(XL355_POWER_CTL, ui8temp);                     /* Write the new value to POWER_CTL register */
}
/*
  函数功能：通过SPI 向 ADXL355 WRITE一个字节的数据
  adress：地址
  data  ：数据
  写一个字节的数据
*/
void SPI_ADXL355_WRITE(uint8_t adress, uint8_t data)
{
    unsigned char writeadress;                                          //unsigned char没有符号位，因此能表示0~255
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);    //CS = LOW  片选信号拉低
    printf("PIN LOWED");
//	HAL_Delay(1);					                                    //CS to SCLK set up time 片选到时钟信号的建立时间tcss
    writeadress = adress << 1;                                          //寄存器的地址7位 左移1位 右边补0表示写数据  即 xxxxxxx0共8位
    SPI_ReadWriteByte(writeadress);		                                //write adress写入地址
    printf("WRITE ADDRESS");
    SPI_ReadWriteByte(data);                                            //data to be written写入数据
    printf("WRITE DATA");
//	HAL_Delay(1);							                            //CS to SCLK set up time
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);		//CS = High	 片选信号拉高
    printf("PIN HIGHED");
//	HAL_Delay(1);                                                       //Wait Time
}
/*
  函数功能：通过SPI 从 ADXL355读取一个字节的数据
  adress：地址
  读取一个字节的数据
*/
uint8_t SPI_ADXL355_READ1BYTE(uint8_t adress)
{

    uint8_t result;
    unsigned char readadress;

    HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, GPIO_PIN_RESET);   //CS = LOW
//	HAL_Delay(1);						                               //CS to SCLK set up time
    readadress = adress << 1;                                          //寄存器的地址7位 左移1位
    readadress |= 0x01;                                                //寄存器的地址7位 左移1位 右边与1或表示读数据  即 xxxxxxx1共8位
    result = SPI_ReadWriteByte(readadress);                            //read adress读地址
    result = SPI_ReadWriteByte(0xff);                                  //Read 8bit data (Send Dummy data 0xff)
//  HAL_Delay(1);			                                           //CS to SCLK set up time
    HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, GPIO_PIN_SET);     //CS = High
//	HAL_Delay(1);				                                       //Wait Time
    return result;
}

/*
  函数功能：通过SPI 从 ADXL355读取3个字节的数据
  adress：地址
  读取3个字节的数据
*/
static uint32_t SPI_ADXL355_READ3BYTE(uint8_t adress)
{

    uint32_t result;
    unsigned char readadress;

    HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, GPIO_PIN_RESET);  //CS = LOW
    readadress = adress << 1;                                         //寄存器的地址7位 左移1位
    readadress |= 0x01;                                               //寄存器的地址7位 左移1位 右边与1或表示读数据  即 xxxxxxx1共8位
    result = SPI_ReadWriteByte(readadress);                           //read adress
    result = SPI_ReadWriteByte(0xff);                                 //Read 8bit data读取一个字节的数据 8位 00000000 00000000 00000000 xxxxxxxx
    result = result << 8 | SPI_ReadWriteByte(0xff);                   //Read 16bit data读取2个字节的数据 16位00000000 00000000 xxxxxxxx xxxxxxxx
    result = result << 8 | SPI_ReadWriteByte(0xff);                   //Read 24bit data读取3个字节的数据 24位00000000 xxxxxxxx xxxxxxxx xxxxxxxx
    HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, GPIO_PIN_SET); 	  //CS = High
    return result;
}


/*
  函数功能： ADXL355数据扫描
  Reads the accelerometer data.
  发送ADXL355采集的数据
*/
void ADXL355_Data_Scan(uint8_t * buff)
{

    uint32_t volatile ui32SensorX = SPI_ADXL355_READ3BYTE(XL355_XDATA3);                  //XL355_XDATA3为X轴3数据寄存器的首地址  ui32SensorX为3个字节的数据  00000000 xxxxxxxx xxxxxxxx xxxxxxxx
    uint32_t volatile ui32SensorY = SPI_ADXL355_READ3BYTE(XL355_YDATA3);                  //XL355_YDATA3为Y轴3数据寄存器的首地址
    uint32_t volatile ui32SensorZ = SPI_ADXL355_READ3BYTE(XL355_ZDATA3);                  //XL355_ZDATA3为Z轴3数据寄存器的首地址
    int32_t  volatile i32SensorX = ADXL355_Acceleration_Data_Conversion(ui32SensorX);     //将AD采集到的数据进行转换
    int32_t  volatile i32SensorY = ADXL355_Acceleration_Data_Conversion(ui32SensorY);
    int32_t  volatile i32SensorZ = ADXL355_Acceleration_Data_Conversion(ui32SensorZ);

//    buff[0] = 0x16;
//    buff[1] = i32SensorX >> 16;
//    buff[2] = i32SensorX >> 8;
//    buff[3] = i32SensorX;
//    buff[4] = i32SensorY >> 16;
//    buff[5] = i32SensorY >> 8;
//    buff[6] = i32SensorY;
//    buff[7] = i32SensorZ >> 16;
//    buff[8] = i32SensorZ >> 8;
//    buff[9] = i32SensorZ;

//		HAL_UART_Transmit_IT(&huart1,buff, 10);
//      printf("ADXL355 检测中...... \r\n");
//		printf("X轴加速度值：%x \r\n",ui32SensorX);
//		printf("Y轴加速度值：%x \r\n",ui32SensorY);
//      printf("Z轴加速度值：%x \r\n\r\n", ui32SensorZ);
//		printf("Z轴加速度值：%d \r\n\r\n",ui32SensorZ);
//		printf("Z轴加速度值：%d \r\n\r\n",ui32SensorZ/256000);

    ax = (double)i32SensorX / 256;
    ay = (double)i32SensorY / 256;
    az = (double)i32SensorZ / 256;
//    printf("X轴加速度值：%lf \r\n", ax);
//    printf("Y轴加速度值：%lf \r\n", ay);
//    printf("Z轴加速度值：%lf \r\n\r\n", az);

}


/*
  函数功能： ADXL355加速度数据转换
   @brief Convert the two's complement data in X,Y,Z registers to signed integers

   @param ui32SensorData - raw data from register

   @return int32_t - signed integer data
*/
static int32_t ADXL355_Acceleration_Data_Conversion (uint32_t ui32SensorData)
{
    int32_t volatile i32Conversion = 0;

    //加速度数据为20位 读取的3个字节（24位）加速度数据其中最低4位无效[3:0]     00000000 xxxxxxxx xxxxxxxx xxxxxxxx
    ui32SensorData = (ui32SensorData  >> 4);                  //右移4位
    ui32SensorData = (ui32SensorData & 0x000FFFFF);           //得到32位真实的数据 00000000 0000xxxx xxxxxxxx xxxxxxxx

    if((ui32SensorData & 0x00080000)  == 0x00080000)          //       如果数据是  00000000 00001xxx xxxxxxxx xxxxxxxx
    {
        i32Conversion = (ui32SensorData | 0xFFF00000);      //      则数据转换成 11111111 11111xxx xxxxxxxx xxxxxxxx
    }
    else
    {
        i32Conversion = ui32SensorData;                   //      否则数据转换成 00000000 0000xxxx xxxxxxxx xxxxxxxx
    }

    return i32Conversion;
}




