	.arch msp430g2553

	.p2align 1,0

JT:
	.word LED1
	.word LED1
	.word LED2
	.word LED3
	.word default
	
	
	
	.global toggleLed
toggleLed:
	mov #1,&leds_changed		;leds_changed = 1
	call #count			;call count allows for dim0

	cmp.b #5,&state			;number of cases
	jhs default

	mov.b &state,r12
	add r12,r12
	mov JT(r12),r0			;next in line for pc counter

LED1:	
	jmp end				;deafult does not change led
	
LED2:
	mov.b #1, &green_led
	mov.b #1, &red_led
	jmp end
LED3:
	call #bright			
	jmp end
LED4:
	mov.b #0, &green_led
	mov.b #0, &red_led
	jmp end
default:
	mov.b #0, &green_led
	mov.b #0, &red_led
	jmp end
	
end:
	call #led_update
	pop r0
	
	
