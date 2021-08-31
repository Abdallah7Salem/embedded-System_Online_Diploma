#include "Platform_Types.h"
extern int main(void);
extern unsigned int _E_text;
extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_bss;
extern unsigned int _E_bss;
extern unsigned int _stack_top ;

void Reset_Handler(void);

/* make handlers point to the same address 
and do the same action using alias */

void Default_Handler(void)
{
	Reset_Handler();
}


/* using weak attribute to make the symbol of vector
"weak" can be defined more than once */

void NMI_Handler()           __attribute__ ((weak, alias ("Default_Handler")));;
void H_fault_Handler()       __attribute__ ((weak, alias ("Default_Handler")));;
void MM_Fault_Handler()      __attribute__ ((weak, alias ("Default_Handler")));;
void Bus_Fault()             __attribute__ ((weak, alias ("Default_Handler")));;
void Usage_Fault_Handler()   __attribute__ ((weak, alias ("Default_Handler")));;


uint32_t vectors[] __attribute__((section(".vectors"))) = {

(uint32_t)	&_stack_top ,
(uint32_t)  &Reset_Handler ,
(uint32_t)  &NMI_Handler ,
(uint32_t)  &H_fault_Handler ,
(uint32_t)  &MM_Fault_Handler ,
(uint32_t)  &Bus_Fault ,
(uint32_t)  &Usage_Fault_Handler

};


void Reset_Handler (void)
{
	// copy data section from flash to ram
	unsigned int DATA_size = (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA ;
	unsigned char* P_src = (unsigned char*)&_E_text ;
	unsigned char* P_dst = (unsigned char*)&_S_DATA ;
	int i ;
	for (i = 0; i < DATA_size; i++)
	{
		*((unsigned char*)P_dst++) = *((unsigned char*)P_src++) ;
	}

	// init .bss section in SRAM = 0
	unsigned int bss_size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss ;
	P_dst = (unsigned char*)&_S_bss ;
	for (i = 0; i < bss_size; i++)
	{
		*((unsigned char*)P_dst++) = (unsigned char)0 ;
	}
	
    // jump main()
	main();
}
