	.arch msp430g2553

		.data
state:		.byte 0
sc:		.byte 2
sr:		.byte 4
colorBGR:	.byte 6
sound:		.byte 8

	.text
jt:	.word case1
	.word case2
	.word case3
	.word case4

	.global
	
	
