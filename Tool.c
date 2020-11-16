#include "stm32f10x.h"
#include "tool.h"

//函数功能:数组(字符串)对比
//函数参数:两个数组指针和需要对比的长度
//函数返回:相同返回1，不同返回0
u8 String_Compare(u8 *str1,u8 *str2,u8 size){
	u8 i=0;
	for(i=0;i<size;i++){
		if(str1[i]!=str2[i]){
			return 1;
		}
	}
	return 0;
}

//函数功能:转换一个字节数据为两个字节ASCLL便于显示和传输
//函数参数:一个字节的数据
//函数返回:两个字节的ascii,16进制显示
u16 Transformation_hexadecimal(u8 ready){
    u16 data=0;
    u8 test=0;
    test=(ready>>4)&0x0F;//原始数据高4位右移
    
    if(test<10)
        data=0x30+test;
    else
        data=0x37+test;
    
    data=data<<8;//转换后的数据左移8位
    test=ready&0x0F;//原始数据高四位置零
    
    if(test<10)
        data+=(0x30+test);
    else
        data+=(0x37+test);//与转换后的数据结合
    return data;
}

//函数功能:转换一个字的数据为5位ASCLL便于显示和传输
//函数参数:一个字的数据,最大65535,一个5位的数组
//函数返回:10进制的ascii,一个5位的数组
void Transformation_decimal(u16 num,u8 *decimal){

    u16 num_cache=num;//余数暂存
    decimal[0]=(num_cache/10000)+48;//万位取模
    num_cache%=10000;//万位取余
    decimal[1]=(num_cache/1000)+48;//千位
    num_cache%=1000;
    decimal[2]=(num_cache/100)+48;//百位
    num_cache%=100;
    decimal[3]=(num_cache/10)+48;//十位
    num_cache%=10;
    decimal[4]=num_cache%10+48;//个位
}

