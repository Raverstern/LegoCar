module NIOSCar(

	//////////// CLOCK //////////
	CLOCK_50,

	//////////// LED //////////
	LED,

	//////////// KEY //////////
	KEY,

	//////////// SW //////////
	SW,

	//////////// SDRAM //////////
	DRAM_ADDR,
	DRAM_BA,
	DRAM_CAS_N,
	DRAM_CKE,
	DRAM_CLK,
	DRAM_CS_N,
	DRAM_DQ,
	DRAM_DQM,
	DRAM_RAS_N,
	DRAM_WE_N,
   //////////// ADC //////////
	ADC_CS_N,
	ADC_SADDR,
	ADC_SCLK,
	ADC_SDAT,
	//////////// U0 //////////
	U0_F,
	U0_T,
	//////////// U1 //////////
	U1_F,
	U1_T,
	//////////// U2 //////////
	U2_F,
	U2_T,
	//////////// U3 //////////
	U3_F,
	U3_T,
	//////////// U4 //////////
	U4_F,
	U4_T,
	//////////// U5 //////////
	U5_F,
	U5_T,
	//////////// pwm0 //////////
	PWM0Ch0,
	PWM0Ch1,
	//////////// pwm1 //////////
	PWM1Ch0,
	PWM1Ch1,
	//////////// pwm2 //////////
	PWM2Ch0,
	PWM2Ch1,
	//////////// pwm3 //////////
	PWM3Ch0,
	PWM3Ch1,
	//////////// INPUT//////////
	PIO1,
	//////////// endcoder0 //////////
	Encoder0,
	//////////// endcoder1 //////////
	Encoder1,
	//////////// PIO //////////
	GPIO_0,
	//////////// uart //////////
	// 115200, data bit:8, stop bit: 1, Parity: none
	tx_out,
	rx_in
	
);

//=======================================================
//  PARAMETER declarations
//=======================================================


//=======================================================
//  PORT declarations
//=======================================================

//////////// CLOCK //////////
input 		          		CLOCK_50;

//////////// LED //////////
output		     [7:0]		LED;

//////////// KEY //////////
input 		     [1:0]		KEY;

//////////// PIO1 //////////
input 		     [3:0]		PIO1;

//////////// SW //////////
input 		     [3:0]		SW;

//////////// SDRAM //////////
output		    [12:0]		DRAM_ADDR;
output		     [1:0]		DRAM_BA;
output		          		DRAM_CAS_N;
output		          		DRAM_CKE;
output		          		DRAM_CLK;
output		          		DRAM_CS_N;
inout 		    [15:0]		DRAM_DQ;
output		     [1:0]		DRAM_DQM;
output		          		DRAM_RAS_N;
output		          		DRAM_WE_N;

////////////// EPCS //////////
//output		          		EPCS_ASDO;
//input 		          		EPCS_DATA0;
//output		          		EPCS_DCLK;
//output		          		EPCS_NCSO;

////////////// Accelerometer and EEPROM //////////
//output		          		G_SENSOR_CS_N;
//input 		          		G_SENSOR_INT;
//output							I2C_SCLK;
//inout 		          		I2C_SDAT;

//////////// ADC //////////
output		          		ADC_CS_N;
output		          		ADC_SADDR;
output		          		ADC_SCLK;
input 		          		ADC_SDAT;

//////////// U0 //////////
input U0_F;
output U0_T;
//////////// U1 //////////
input U1_F;
output U1_T;
//////////// U2 //////////
input U2_F;
output U2_T;
//////////// U3 //////////
input U3_F;
output U3_T;
//////////// U4 //////////
input U4_F;
output U4_T;
//////////// U5 //////////
input U5_F;
output U5_T;
//////////// pwm0 //////////
output PWM0Ch0;
output PWM0Ch1;
//////////// pwm1 //////////
output PWM1Ch0;
output PWM1Ch1;
//////////// pwm2 //////////
output PWM2Ch0;
output PWM2Ch1;
//////////// pwm3 //////////
output PWM3Ch0;
output PWM3Ch1;
//////////// endcoder0 //////////
input [1:0] Encoder0;
//////////// endcoder1 //////////
input [1:0] Encoder1;
//////////// endcoder1 //////////
output [7:0] GPIO_0;
//////////// uart //////////
// 115200, data bit:8, stop bit: 1, Parity: none
output tx_out;
input rx_in;
////////////// 2x13 GPIO Header //////////
//inout 		    [12:0]		GPIO_2;
//input 		     [2:0]		GPIO_2_IN;
//
////////////// GPIO_0, GPIO_0 connect to GPIO Default //////////
//inout 		    [33:0]		GPIO_0;
//input 		     [1:0]		GPIO_0_IN;
//
////////////// GPIO_1, GPIO_1 connect to GPIO Default //////////
//inout 		    [33:0]		GPIO_1;
//input 		     [1:0]		GPIO_1_IN;


////=======================================================
////  REG/WIRE declarations
////=======================================================
//wire reset_n;
//wire select_i2c_clk;
//wire i2c_clk;
//wire spi_clk;



//=======================================================
//  Structural coding
//=======================================================

assign reset_n = 1'b1;

NIOS_Sys u0(
        .led_external_connection_export (LED), // led_external_connection.export
        .sdram_wire_addr                (DRAM_ADDR),                //              sdram_wire.addr
        .sdram_wire_ba                  (DRAM_BA),                  //                        .ba
        .sdram_wire_cas_n               (DRAM_CAS_N),               //                        .cas_n
        .sdram_wire_cke                 (DRAM_CKE),                 //                        .cke
        .sdram_wire_cs_n                (DRAM_CS_N),                //                        .cs_n
        .sdram_wire_dq                  (DRAM_DQ),                  //                        .dq
        .sdram_wire_dqm                 (DRAM_DQM),                 //                        .dqm
        .sdram_wire_ras_n               (DRAM_RAS_N),               //                        .ras_n
        .sdram_wire_we_n                (DRAM_WE_N),                //                        .we_n
        .key_external_connection_export (KEY), // key_external_connection.export
        .sw_external_connection_export  (SW),  //  sw_external_connection.export
        .reset_reset_n                  (reset_n),                  //                   reset.reset_n
        .altpll_0_c1_clk                (DRAM_CLK),                 //             altpll_0_c1.clk
		  .clk_clk                        (CLOCK_50),
		  .ultrasound0_conduit_end_feedback_in (U0_F), //  ultrasound0_conduit_end.feedback_in
        .ultrasound0_conduit_end_trigger_out (U0_T), //                         .trigger_out
        .ultrasound1_conduit_end_feedback_in (U1_F), //  ultrasound1_conduit_end.feedback_in
        .ultrasound1_conduit_end_trigger_out (U1_T), //                         .trigger_out
        .adc_spi_read_conduit_end_OUT        (ADC_SADDR),        // adc_spi_read_conduit_end.OUT
        .adc_spi_read_conduit_end_IN         (ADC_SDAT),         //                         .IN
        .adc_spi_read_conduit_end_CS_n       (ADC_CS_N),       //                         .CS_n
        .adc_spi_read_conduit_end_CLK        (ADC_SCLK),         //                         .CLK
		  .pwm0_conduit_end_pwm1               (PWM0Ch0),               //         pwm0_conduit_end.pwm1
        .pwm0_conduit_end_pwm2               (PWM0Ch1),               //                         .pwm2
        .pwm1_conduit_end_pwm1               (PWM1Ch0),               //         pwm1_conduit_end.pwm1
        .pwm1_conduit_end_pwm2               (PWM1Ch1),               //                         .pwm2
        .encoder0_conduit_end_export         (Encoder0),         //     encoder0_conduit_end.export
        .encoder1_conduit_end_export         (Encoder1),          //     encoder1_conduit_end.export
		  .pio_0_external_connection_export    (GPIO_0),     // pio_0_external_connection.export
		  .uart_0_external_connection_rxd      (rx_in),      // uart_0_external_connection.rxd
        .uart_0_external_connection_txd      (tx_out),       //                           .txd
        .ultrasound2_conduit_end_feedback_in (U2_F), //    ultrasound2_conduit_end.feedback_in
        .ultrasound2_conduit_end_trigger_out (U2_T), //                           .trigger_out
        .ultrasound3_conduit_end_feedback_in (U3_F), //    ultrasound3_conduit_end.feedback_in
        .ultrasound3_conduit_end_trigger_out (U3_T), //                           .trigger_out
        .ultrasound5_conduit_end_feedback_in (U5_F), //    ultrasound5_conduit_end.feedback_in
        .ultrasound5_conduit_end_trigger_out (U5_T), //                           .trigger_out
        .pwm2_conduit_end_pwm1               (PWM2Ch0),               //           pwm2_conduit_end.pwm1
        .pwm2_conduit_end_pwm2               (PWM2Ch1),               //                           .pwm2
        .pwm3_conduit_end_pwm1               (PWM3Ch0),               //           pwm3_conduit_end.pwm1
        .pwm3_conduit_end_pwm2               (PWM3Ch1),               //                           .pwm2
        .ultrasound4_conduit_end_feedback_in (U4_F), //    ultrasound4_conduit_end.feedback_in
        .ultrasound4_conduit_end_trigger_out (U4_T),  //    
		  .pio_1_external_connection_export(PIO1)
	 
	 
	 );						  
						  					  
endmodule
































