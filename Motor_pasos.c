#include <18F4550.h>
#device adc=10
#fuses HSPLL,NOWDT,NOPROTECT,NOLVP,NODEBUG,USBDIV,PLL5,CPUDIV4,VREGEN
#use delay(clock=48000000)
#define  USB_HID_DEVICE     FALSE              //deshabilitamos el uso de las directivas HID
#define  USB_EP1_TX_ENABLE  USB_ENABLE_BULK    //turn on EP1(EndPoint1) for IN bulk/interrupt transfers
#define  USB_EP1_RX_ENABLE  USB_ENABLE_BULK    //turn on EP1(EndPoint1) for OUT bulk/interrupt transfers
#define  USB_EP1_TX_SIZE    10                 //size to allocate for the tx endpoint 1 buffer
#define  USB_EP1_RX_SIZE    10                 //size to allocate for the rx endpoint 1 buffer
#include <pic18_usb.h>              //Microchip PIC18Fxx5x Hardware layer for CCS's PIC USB driver
#include <usb_desc_scope.h>         //descriptors del Pic USB
#include <usb.c>                    //handles usb setup tokens and get descriptor reports
#include <stdio.h>
#include <stdlib.h>
void secuencia(long paso, int retardo,int8 primero,int8 segundo,int8 tercero,int8 cuarto,int motor) ;
long Resolucion();
char datoin[10];
int bobinas1=0,bobinas2=0,bobinas3=0;

void secuencia(long paso, int retardo,int8 primero,int8 segundo,int8 tercero,int8 cuarto,int motor) 
{
   long cont=0;
 
   while (cont<(paso))
   {
      if(bobinas1==0 || bobinas2==0 || bobinas3==0)
      {     
         if (motor==1 || motor==2)
         {
            Output_B( primero );
         }
         if (motor==3)
         {
            Output_A( primero );
         }
         delay_ms(retardo);
         cont++;
         if (motor==1)
         bobinas1=1;
         if (motor==2)
         bobinas2=1;
         if (motor==3)
         bobinas3=1;
         if(cont==(paso))
         {
            break;
         }                           
      }
      if(bobinas1==1 || bobinas2==1 || bobinas3==1)
      {
         if (motor==1 || motor==2)
         {
            Output_B( segundo );
         }
         if (motor==3)
         {
            Output_A( segundo );
         }
         delay_ms(retardo);
         cont++;
         if (motor==1)
         bobinas1=2;
         if (motor==2)
         bobinas2=2;
         if (motor==3)
         bobinas3=2;
         if(cont==(paso))
         {
            break;
         }                         
      }
      if(bobinas1==2 || bobinas2==2 || bobinas3==2)
      {
         if (motor==1 || motor==2)
         {
            Output_B( tercero );
         }
         if (motor==3)
         {
            Output_A( tercero );
         }
         delay_ms(retardo);
         cont++;
         if (motor==1)
         bobinas1=3;
         if (motor==2)
         bobinas2=3;
         if (motor==3)
         bobinas3=3;
         if(cont==(paso))
         {
            break;
         }                     
      }
      if(bobinas1==3 || bobinas2==3 || bobinas3==3)
      {
         if (motor==1 || motor==2)
         {
            Output_B( cuarto );
         }
         if (motor==3)
         {
            Output_A( cuarto );
         }
         delay_ms(retardo);                       
         cont++;
         if (motor==1)
         bobinas1=0;
         if (motor==2)
         bobinas2=0;
         if (motor==3)
         bobinas3=0;
         if(cont==(paso))
         {
            break;
         }   
      }
   }cont=0;
   Output_B( 0x00 );
   Output_A( 0x00 );
   datoin[0]='f'; 
} 
 
long Resolucion()
{
   char resolucion[4];
   int i=2;
   long paso;
  
   for (i=2;i<6;i++)
   {
      resolucion[i-2]=datoin[i];
   }i=2;
   paso=atol(resolucion);
   return paso;
}
 
void main()
{
int paso,motor;
int retardo=2,retardo2=18;
int8 primero,segundo,tercero,cuarto;
SET_TRIS_B( 0x00);
SET_TRIS_A( 0x00);
Output_B( 0x00);
Output_A( 0x00);

usb_init();
usb_task();
usb_wait_for_enumeration();

do{  
         if(usb_enumerated())                      // si el Pic está configurado via USB
         {        
            if (usb_kbhit(1))                      // si el endpoint de salida contiene datos del host
            {    
               usb_get_packet(1, datoin, 10);        // tomamos el paquete de tamaño 6bytes del EP1 y almacenamos en dato
               usb_flush_out(1,USB_DTS_TOGGLE);
            //Clock-wise****************************************************************************************************************             
               //Motor1
               if(datoin[1]=='1' && datoin[0]=='g')
               {
                  primero=3,segundo=6,tercero=12,cuarto=9,motor=1;
                  secuencia(Resolucion(),retardo2,primero,segundo,tercero,cuarto,motor);   
               }   
               //Motor2
               if (datoin[1]=='1' && datoin[0]=='d')
               {
                  primero=48,segundo=96,tercero=192,cuarto=144,motor=2;
                  secuencia(Resolucion(),retardo,primero,segundo,tercero,cuarto,motor);
               }  
               //Motor3
               if(datoin[1]=='1' && datoin[0]=='k')
               {
                  primero=3,segundo=6,tercero=12,cuarto=9,motor=3;
                  secuencia(Resolucion(),retardo,primero,segundo,tercero,cuarto,motor);
               }
                                                                                                      
            //sentido opuesto**********************************************************************************************************                                            
               //Motor 1
               if(datoin[1]=='2' && datoin[0]=='g')
               {
                  primero=9,segundo=12,tercero=6,cuarto=3,motor=1;
                  secuencia(Resolucion(),retardo2,primero,segundo,tercero,cuarto,motor); 
               }   
               //Motor 2
               if (datoin[1]=='2' && datoin[0]=='d')
               {
                  primero=144,segundo=192,tercero=96,cuarto=48,motor=2;
                  secuencia(Resolucion(),retardo,primero,segundo,tercero,cuarto,motor);
               }            
               //Motor 3                  
               if(datoin[1]=='2' && datoin[0]=='k')
               {
                  primero=9,segundo=12,tercero=6,cuarto=3,motor=3;
                  secuencia(Resolucion(),retardo,primero,segundo,tercero,cuarto,motor);        
               }             
            }                             
         }                    
   } while(1);

}
  
   













