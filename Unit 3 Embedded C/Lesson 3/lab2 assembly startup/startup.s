/* Ahmed Mohammed Hussanein Ali
	Lab 2 lesson 3
	startup.s for ARM cortexM3
	*/

.section .vectors
.word		0x20001000  		/* stack top address */
.word	 	_reset				/* 1.  reset */
.word 		Vector_handler		/* 2.  NMI */
.word 		Vector_handler		/* 3.  Hard Fault */
.word 		Vector_handler		/* 4.  MM Fault */
.word 		Vector_handler		/* 5.  Bus Fault */
.word 		Vector_handler		/* 6.  Usage Fault */
.word 		Vector_handler		/* 7.  Reserved */
.word 		Vector_handler		/* 8.  Reserved */
.word 		Vector_handler		/* 9.  Reserved */
.word 		Vector_handler		/* 10. Reserved */
.word 		Vector_handler		/* 11. CV call */
.word 		Vector_handler		/* 12. Debug reserved */
.word 		Vector_handler		/* 13. Reserved */
.word 		Vector_handler		/* 14. PendSV */
.word 		Vector_handler		/* 15. SysTick */
.word 		Vector_handler		/* 16. ..... */


.section .text
_reset:
	bl main
	b .

.thumb_func
Vector_handler:
	b _reset
