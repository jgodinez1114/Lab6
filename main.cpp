#include"mbed.h" 
 
DigitalOut clk(p27);  
DigitalOut rst(p28);  
DigitalOut data(p30); 

DigitalIn row1(p26);
DigitalIn row2(p25);
DigitalIn row3(p24);
DigitalIn row4(p23);

DigitalOut col1(p8);
DigitalOut col2(p7);
DigitalOut col3(p6);
DigitalOut col4(p5);

int arr[16][8] = {  {1,1,0,0,0,0,0,0}, //0 
				{1,1,1,1,1,0,0,1}, //1 
				{1,0,1,0,0,1,0,0}, //2 
				{1,0,1,1,0,0,0,0}, //3 
				{1,0,0,1,1,0,0,1}, //4 
				{1,0,0,1,0,0,1,0}, //5 
				{1,0,0,0,0,0,1,0}, //6 
				{1,1,1,1,1,0,0,0}, //7 
				{1,0,0,0,0,0,0,0}, //8 
				{1,0,0,1,1,0,0,0}, //9 
				{1,0,0,0,1,0,0,0}, //A
				{1,0,0,0,0,0,1,1}, //B
				{1,1,0,0,0,1,1,0}, //C
				{1,0,1,0,0,0,0,1}, //d
				{1,0,0,0,0,1,1,0}, //E
				{1,0,0,0,1,1,1,0}}; //F

int readPad(int row1, int row2, int row3, int row4, int co1, int col2, int col3, int col4 ){

	if (!row1){
		if(!col1)return 1;
		else if (!col2) return 2;
		else if (!col3) return 3;
		else if (!col4) return 10;
			}
	else if (!row2){
		if(!col1)return 4;
		else if (!col2) return 5;
		else if (!col3) return 6;
		else if (!col4) return 11;
	}
	else if (!row3){
		if(!col1)return 7;
		else if (!col2) return 8;
		else if (!col3) return 9;
		else if (!col4) return 12;
	}
	else if (!row4){
		if(!col1)return 0;
		else if (!col2) return 15;
		else if (!col3) return 14;
		else if (!col4) return 13;
	}
	else return 88;
}




 
void EdgeClock(){ 
 wait(0.000001); 
 clk = 1; 
 wait(0.000001); 
 clk=0; 
  
} 


void displayVal(int val1){
	
	
	for (int j = 0; j < 8 ; j++) { 	
		data = arr[val1][j]; 
		EdgeClock();
		 
	} 
	 wait(0.2);
}




int main(){ 
	rst = 0; 
	EdgeClock(); 
	rst = 1; 
	EdgeClock(); 

	displayVal(0);
	displayVal(0);
	displayVal(0);
	
	while(1){
		
		int val;
		col1=0;
		col2=1;
		col3=1;
		col4=1;
		val=readPad(row1, row2, row3, row4, col1, col2, col3, col4);

		
		if (val!=88){
			
			displayVal(val);
		}
		
		
		col1=1;
		col2=0;
		col3=1;
		col4=1;
		val=readPad(row1, row2, row3, row4, col1, col2, col3, col4);
		
		
		if (val!=88){
			
			displayVal(val);
		}
		
		
		col1=1;
		col2=1;
		col3=0;
		col4=1;
		val=readPad(row1, row2, row3, row4, col1, col2, col3, col4);
		

		if (val!=88){
			
			displayVal(val);
		}		
		
		col1=1;
		col2=1;
		col3=1;
		col4=0;
		val=readPad(row1, row2, row3, row4, col1, col2, col3, col4);

		
		if (val!=88){
			
			displayVal(val);
		}
 
	}
}//end main
