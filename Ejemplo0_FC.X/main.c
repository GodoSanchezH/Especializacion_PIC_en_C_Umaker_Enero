/* 
 * File:   main.c
 * Author: HP
 *
 * Created on 29 de enero de 2023, 04:33 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
/*
 * 
 */

struct{

    char *string;
    uint16_t Adc_read[3];
    bool StatusButton[5];
    float Termocuplas[2];
    float SensorHumedad;
    char *JSON;
}data_Send;

typedef enum{
    IDLE=0,
            Adquirir,
            Send_Cloud,
            HTTP_Get,
            Send_SMS,
            CloseServer,
            ListenSocket
}State;

State FSM=IDLE;

int main(int argc, char** argv) {

    
    asm("nop");
    
    printf("Hola mundo\n\r");
    printf("Bienvenidos al curso\n\r");
    printf("PIC EN C UMAKER\n\r");
    asm("nop");
    

    /************************************************/
    
    data_Send.string = "ENVIO DE DATOS";
    data_Send.Adc_read[0]= 5225;
    data_Send.Adc_read[1]= 250;
    data_Send.Adc_read[2]= 4336;
    data_Send.SensorHumedad = 102.56;
    data_Send.StatusButton[0]= true;
    data_Send.StatusButton[1]= true;
    data_Send.StatusButton[2]= false;
    data_Send.StatusButton[3]= true;
    data_Send.StatusButton[4]= false;
    data_Send.Termocuplas[0] = 27.3655;
    data_Send.Termocuplas[1] = 87.3655;
    data_Send.JSON = "POST /api/v1.6/devices/dspic/?token=BBFF-7ZM4xDD1WEPQTp9PuKSvrPFiVcEld2 HTTP/1.1Host: industrial.api.ubidots.comContent-Type: application/jsonContent-Length:  53";
    for(;;){//while(1) while(true)
    
    
        switch(FSM){
        
            case IDLE:
                break;
            case Adquirir:
                break;       
            case HTTP_Get:
                break;       
            case ListenSocket:
                break;
            case Send_Cloud:
                break;
             case Send_SMS+:
                break;               
        }
    
    
    }
    
    
    
    
    return (EXIT_SUCCESS);
}

