++++[->+++++++++++<]++++[->>++++++++<<]>> >          先设置逗号、空格，再多走一格是为了都算完了以后往回找好找（直接找是0的格子就行）

>++>+++>+++++>+++++++                                作弊！先把2、3、5、7这些10以内的素数塞进去
>>+++++++++++                                        从11开始，判断到99（反正99、100都不是素数）
[                                                    判断这个数字有没有超过99
	>+++++++++++[-<--------->]<                      这个数减99看看是不是等于0
	[                                                如果这个数等于0说明到99了，就直接跳出循环了
		>+++++++++++[-<+++++++++>]                   再加99
		
		>++++++                                      因子（因为下面会加1所以这里填6）
		[
			+                                        加回来
			[->>>>+>+<<<<<]>>>>>[-<<<<<+>>>>>]<<<<<  存一下除数
			<<
			[>+>->+<[>]>[<+>-]<<[<]>-]               网上抄的取余数的公式
			>[-<+>]                                  先把循环的数存回去
			>[-]>                                    这个格子表示余数（中间没用的数清了）
			>+<[[-]>->+<<]>                          对余数取非
			[                                        余数为0的情况，说明不是素数
				>>[-]+<<-                            置标志位
			]>
			[                                        余数不为0，算下一个因子
				->[-<<<<+>>>>]<<<<--->>>             因子减2，不需要除以2因为算的都是奇数，多减1是为了判断到没到1
			]
			<<<
		]

		>>>>                                         查看标志位
		>+<[->->+<<]>>[-<<+>>]<<                     标志位后面一位置成标志位的非
		[                                            如果标志位为1，说明有因子，不是素数
			<<<<<<++                                 循环中的数字加2，表示处理下一个
			>>>>>>-
		]>
		[                                            标志位是0，说明是素数，存上然后右边的数加2
			<<<<<<<[-<+>>+<]>++                      下一个数
			>>>>>>-                                  这个非标志位也置回去
			>                                        反正多移一位也是0，正好数位往前移了一位，对上了
		]
		<<<<<<<
		>+++++++++++[-<--------->]<                  减99
	]
]<<

[<]>
[
	[-<<<<+>>>>]<<<<                                 找个僻静的地方好计算这个数的个位和十位
	
	<++++++++++>                                     要除以10取余，所以先写上
	[-<-[<+<<]<[+[->+<]<+<<]>>>>>]                   除加取余的函数，网上抄的
	<<[->>+<<]>[-]<<[->>+<<]>>                       把个位数和十位数移到对应的位置

	[
		<++++++++[->++++++<]>.[-]                    打印十位
	]
	++++++++[->++++++<]>.[-]                         打印个位
	>.>.[->+<]<[->+<]>>>>                            打印逗号和空格，然后把这些符号右移一位，方便下次打印数字的更新
]