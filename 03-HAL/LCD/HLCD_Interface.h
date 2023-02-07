/*
 * HLCD_Interface.h
 *
 *  Created on: Feb 5, 2023
 *      Author: hp
 */

#ifndef HLCD_INTERFACE_H_
#define HLCD_INTERFACE_H_

/**************************************************************************************************
 * macros
 *************************************************************************************************/
#define LCD_FUNC_SET_CMD				0b00111000
#define LCD_DSP_ON_OFF_CTRL_CMD 		0b00001110
#define LCD_DSP_CLEAR_CMD		 		0b00000001
#define LCD_ENTRY_MOD_SET_CMD		 	0b00000110
#define LCD_CURSOR_DSP_SHFT_CMD			0b00011000
#define LCD_RETURN_HOME_CMD				0b00000010
#define LCD_SET_CGRAM_ADDR_CMD			0x40


#define index		5

/**************************************************************************************************
 * functions prototype
 *************************************************************************************************/
/*
 * function		: LCD_vidInit
 * description 	: func to set LCD initialization
 * input param 	: void
 * return		: void
 * */
void LCD_vidInit(void);

/*
 * function		: LCD_vidWritecmd
 * description 	: func to configure some commands on lcd
 * input param 	:
 * 					u8commandCopy --> take lcd cmd instructions from instruction table <https://components101.com/sites/default/files/component_datasheet/16x2%20LCD%20Datasheet.pdf>
 * return		: void
 * */
void LCD_vidWritecmd(u8 u8commandCopy);



/*
 * function		: LCD_vidWriteChar
 * description 	: func to write char on lcd
 * input param 	: u8CharCopy -> take ascii code of char   or   char address on CGROM
 * return		: void
 * */
void LCD_vidWriteChar(u8 u8CharCopy);


/*
 * function		: LCD_ClrDisplay
 * description 	: func to clear anything on lcd
 * input param 	: void
 * return		: void
 * */
void LCD_ClrDisplay(void);


/*
 * function		: LCD_ShiftLeft
 * description 	: func to shift the lcd display from right to left
 * input param 	: void
 * return		: void
 * */
void LCD_ShiftLeft(void);


/*
 * function		: LCD_gotoXY
 * description 	: func to determine position which char print at this position on lcd  ### NOTE : (2rows x 16coloms)
 * input param 	:
 * 				  row -> take row number 0 or 1
 * 				  pos -> take colom number from 0 ~ 16
 * return		: void
 * */
void LCD_gotoXY(u8 row, u8 pos);


/*
 * function		: LCD_WriteString
 * description 	: func to write string on lcd
 * input param 	: str --> which take string as argument
 * return		: void
 * */
void LCD_WriteString(u8* str);



/*
 * function		: LCD_WriteInt
 * description 	: func to write integer number on lcd
 * input param 	: number --> which take number as argument
 * return		: void
 * */
//void LCD_WriteInt(u32 number);



/*
 * function		: LCD_WriteArabic
 * description 	: func to write Arabic string on lcd
 * input param 	: u8ArCharCopy --> which take string as argument
 * return		: void
 * */
void LCD_WriteArabic(u8 u8ArCharCopy);




/*
 * function		: LCD_vidCreatCustomChar
 * description 	: func to store new patterm on CGRAM
 * input param 	:
 * 				  pu8custom  -> take pointer to array which having LCD Custom Character Generated data ### take only 8 characters
 * 				  u8Location -> determine location on CGRAM [0 ~ 8]
 * return		: void
 * */
void LCD_vidCreatCustomChar(u8* pu8custom, u8 u8Location);





#endif /* HLCD_INTERFACE_H_ */
