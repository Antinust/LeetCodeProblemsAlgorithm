//
//  VTBMultiSlice.m
//  Demo
//
//  Created by Zhuo,Chuncai on 2020/4/25.
//  Copyright © 2020 Zhuo,Chuncai. All rights reserved.
//

#import "VTBMultiSlice.h"

@implementation VTBMultiSlice


//unsigned int oneFreamIndex = 0;
//unsigned int spsIndex = 0;
//unsigned int ppsIndex = 0;
//unsigned char* spsPtr = NULL;
//unsigned char* ppsPtr = NULL;
//unsigned char* framePtr = NULL;
//unsigned int contentLen = 0;                                                   //有效码流长度
//unsigned char imgLenArr[4]={0};                                                //起使码转换成长度子节
//static unsigned int spsLen ;                                                      //sps字段长度
//static unsigned int ppsLen ;                                                      //pps字段长度
//static unsigned char* spsBuff;                                                    //sps字段缓存
//static unsigned char* ppsBuff;
//unsigned char* contentFream;
//bool  multislice;
//CVPixelBufferRef pixelbuffer = NULL;                                          //该帧数据，硬解的结果
//while(oneFreamIndex < (buffFrameLen))                                       //start code
//{
//    multislice = false;//默认非多slice
//    if(bufferOneFream[oneFreamIndex] == 0x00
//    && bufferOneFream[oneFreamIndex + 1] == 0x00
//    && bufferOneFream[oneFreamIndex + 2] == 0x00
//    && bufferOneFream[oneFreamIndex + 3] == 0x01)
//{
//naluType = (bufferOneFream[oneFreamIndex + 4]) & 0x0F;
//    switch(naluType)
//    {
//    case 0x06:// SEI
//    break;
//    case 0x09://aud
//    //std::cout<<"aud"<<std::endl;
//    break;
//    case 0x07:                                                                  //sps
//    //std::cout<<"sps"<<std::endl;
//    spsPtr = &bufferOneFream[oneFreamIndex + 4];
//    spsIndex = oneFreamIndex + 4;
//    break;
//    case 0x08:
//    //std::cout<<"pps"<<std::endl;                                                    //pps
//    ppsPtr = &bufferOneFream[oneFreamIndex + 4];
//    ppsIndex = oneFreamIndex + 4;
//    spsBuff=(unsigned char*)malloc(ppsIndex-spsIndex-4);
//    memcpy(spsBuff,spsPtr,(ppsIndex-spsIndex-4));                          //memcpy sps
//    spsLen = ppsIndex-spsIndex-4;
//    break;
//    case 0x05://i frame
//    //std::cout<<"i fream"<<std::endl;
//    {
//    ppsBuff=(unsigned char*)malloc(oneFreamIndex - ppsIndex);
//    memcpy(ppsBuff,ppsPtr,(oneFreamIndex - ppsIndex));                     //memcpy pps
//    ppsLen = oneFreamIndex - ppsIndex;                                     //memcpy PPS
//    ////I帧内容
//    framePtr =  &bufferOneFream[oneFreamIndex + 4];                         //内容流的位置
//    contentLen = buffFreanLen - (oneFreamIndex + 4);                        //内容流的长度，不包含4字节start code
//    int nalu_size1 =0;
//    int nale_size2 =0;
//    int nextStartcode = 0;
//    for(int index2 = 0; index2< contentLen;index2++)
//    {
//        if(bufferOneFream[oneFreamIndex + 4+ index2]==0x00
//        && bufferOneFream[oneFreamIndex + 5+ index2] == 0x00
//        && bufferOneFream[oneFreamIndex + 6+ index2] == 0x00
//        && bufferOneFream[oneFreamIndex + 7+ index2] == 0x01)////找第二个nale 的start code
//        {
//            nextStartcode = index2;
//            multislice = true;
//            break;
//        }
//    }
//    if(multislice == true)
//    {
//        NSLog(@"i yes");
//        nalu_size1 = nextStartcode;
//        nale_size2 = contentLen - nextStartcode - 4;///slice2的内容要减去前边的四个字节
//        bufferOneFream[oneFreamIndex + 4+ nalu_size1]=(nale_size2 & 0xff000000)>>24;
//        bufferOneFream[oneFreamIndex + 5+ nalu_size1] = (nale_size2 & 0x00ff0000)>>16;
//        bufferOneFream[oneFreamIndex + 6+ nalu_size1] = (nale_size2 & 0x0000ff00)>>8;
//        bufferOneFream[oneFreamIndex + 7+ nalu_size1] = (nale_size2 & 0x000000ff);
//        ////////
//        imgLenArr[0] = (nalu_size1  & 0xff000000)>>24;                           //大端码流长度转换
//        imgLenArr[1] = (nalu_size1  & 0x00ff0000)>>16;
//        imgLenArr[2] = (nalu_size1  & 0x0000ff00)>>8;
//        imgLenArr[3] = nalu_size1  & 0x000000ff;
//        //                    imgLenArr[0] = (contentLen & 0xff000000)>>24;                           //大端码流长度转换
//        //                    imgLenArr[1] = (contentLen & 0x00ff0000)>>16;
//        //                    imgLenArr[2] = (contentLen & 0x0000ff00)>>8;
//        //                    imgLenArr[3] = contentLen & 0x000000ff;
//        //
//        contentFream = (unsigned char*)malloc(contentLen + 4);
//        memcpy(contentFream,imgLenArr, 4);
//        memcpy(contentFream+4 ,framePtr, contentLen);                                           //表示长度的四个字节和码流内容
//        pixelbuffer = HardDecode(contentFream,contentLen+4, spsBuff, spsLen, ppsBuff, ppsLen,1);//解码后数据
//        /////复位
//        multislice = false;
//        //保存yuv数据///////////////////////////////////////////////////////////////////
//        //SaveYUV(pixelbuffer, fout);
//        free(contentFream);
//        return pixelbuffer;
//        }else{////signal slice
//            NSLog(@"i no");
//            imgLenArr[0] = (contentLen & 0xff000000)>>24;                           //大端码流长度转换
//            imgLenArr[1] = (contentLen & 0x00ff0000)>>16;
//            imgLenArr[2] = (contentLen & 0x0000ff00)>>8;
//            imgLenArr[3] = contentLen & 0x000000ff;
//            contentFream = (unsigned char*)malloc(contentLen + 4);
//            memcpy(contentFream,imgLenArr, 4);
//            memcpy(contentFream+4 ,framePtr, contentLen);                                           //表示长度的四个字节和码流内容
//            pixelbuffer = HardDecode(contentFream,contentLen+4, spsBuff, spsLen, ppsBuff, ppsLen,1);//解码后数据
//            //保存yuv数据///////////////////////////////////////////////////////////////////
//            //SaveYUV(pixelbuffer, fout);
//            free(contentFream);
//            return pixelbuffer;
//        }
//    }
//case 0x01://p fream
//{
////std::cout<<"p fream"<<std::endl;
//framePtr =  &bufferOneFream[oneFreamIndex + 4];
//contentLen = buffFreanLen - (oneFreamIndex + 4);
//int nalu_size1 =0;
//int nale_size2 =0;
//int nextStartcode = 0;
//for(int index2 = 0; index2< contentLen;index2++)
//{
//if(bufferOneFream[oneFreamIndex + 4+ index2]==0x00
//&& bufferOneFream[oneFreamIndex + 5+ index2] == 0x00
//&& bufferOneFream[oneFreamIndex + 6+ index2] == 0x00
//&& bufferOneFream[oneFreamIndex + 7+ index2] == 0x01)
//{
//nextStartcode = index2;
//multislice = true;
//break;
//}
//}
//if(multislice ==  true)
//{
//NSLog(@"p yes");
//nalu_size1 = nextStartcode;
//nale_size2 = contentLen - nextStartcode - 4;///slice2的内容要减去前边的四个字节
//bufferOneFream[oneFreamIndex + 4+ nalu_size1]=(nale_size2 & 0xff000000)>>24;
//bufferOneFream[oneFreamIndex + 5+ nalu_size1] = (nale_size2 & 0x00ff0000)>>16;
//bufferOneFream[oneFreamIndex + 6+ nalu_size1] = (nale_size2 & 0x0000ff00)>>8;
//bufferOneFream[oneFreamIndex + 7+ nalu_size1] = (nale_size2 & 0x000000ff);
//////////
//imgLenArr[0] = (nalu_size1  & 0xff000000)>>24;                           //大端码流长度转换
//imgLenArr[1] = (nalu_size1  & 0x00ff0000)>>16;
//imgLenArr[2] = (nalu_size1  & 0x0000ff00)>>8;
//imgLenArr[3] = nalu_size1  & 0x000000ff;
//contentFream = (unsigned char*)malloc(contentLen + 4);     //转换成标准格式的一帧数据
//memcpy(contentFream,imgLenArr, 4);
//memcpy(contentFream+4 ,framePtr, contentLen);
//NSLog(@"buffFreanLen %d,contentLen %d,nalu_size1 %d,nale_size2 %d",buffFreanLen,contentLen,nalu_size1,nale_size2);
//pixelbuffer = HardDecode(contentFream, contentLen+4, spsBuff, spsLen, ppsBuff, ppsLen,0);
////保存yuv数据///////////////////////////////////////////////////////////////////
////SaveYUV(pixelbuffer, fout);
//multislice = false ;
//free(contentFream);
//return pixelbuffer ;
//}else{///p slgnal slice
//NSLog(@"p no");
//imgLenArr[0] = (contentLen & 0xff000000)>>24;                           //大端码流长度转换
//imgLenArr[1] = (contentLen & 0x00ff0000)>>16;
//imgLenArr[2] = (contentLen & 0x0000ff00)>>8;
//imgLenArr[3] = contentLen & 0x000000ff;
//contentFream = (unsigned char*)malloc(contentLen + 4);     //转换成标准格式的一帧数据
//memcpy(contentFream,imgLenArr, 4);
//memcpy(contentFream+4 ,framePtr, contentLen);
//pixelbuffer = HardDecode(contentFream, contentLen+4, spsBuff, spsLen, ppsBuff, ppsLen,0);
////保存yuv数据///////////////////////////////////////////////////////////////////
////SaveYUV(pixelbuffer, fout);
//free(contentFream);
//return pixelbuffer ;
//}
//}
//default://other,
//break;
//}
    
@end
