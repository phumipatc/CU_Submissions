//Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
//Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2023.1 (win64) Build 3865809 Sun May  7 15:05:29 MDT 2023
//Date        : Tue Sep 19 12:53:56 2023
//Host        : PHUMIPAT-C running 64-bit major release  (build 9200)
//Command     : generate_target Calculator.bd
//Design      : Calculator
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CORE_GENERATION_INFO = "Calculator,IP_Integrator,{x_ipVendor=xilinx.com,x_ipLibrary=BlockDiagram,x_ipName=Calculator,x_ipVersion=1.00.a,x_ipLanguage=VERILOG,numBlks=1,numReposBlks=1,numNonXlnxBlks=0,numHierBlks=0,maxHierDepth=0,numSysgenBlks=0,numHlsBlks=0,numHdlrefBlks=1,numPkgbdBlks=0,bdsource=USER,synth_mode=OOC_per_IP}" *) (* HW_HANDOFF = "Calculator.hwdef" *) 
module Calculator
   (an,
    btnD,
    btnL,
    btnR,
    btnU,
    clock,
    seg,
    sw);
  output [3:0]an;
  input btnD;
  input btnL;
  input btnR;
  input btnU;
  (* X_INTERFACE_INFO = "xilinx.com:signal:clock:1.0 CLK.CLOCK CLK" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME CLK.CLOCK, CLK_DOMAIN Calculator_clock_0, FREQ_HZ 100000000, FREQ_TOLERANCE_HZ 0, INSERT_VIP 0, PHASE 0.0" *) input clock;
  output [6:0]seg;
  input [7:0]sw;

  wire [3:0]CalculatorDisplayer_0_an;
  wire [6:0]CalculatorDisplayer_0_seg;
  wire btnD_0_1;
  wire btnL_0_1;
  wire btnR_0_1;
  wire btnU_0_1;
  wire clock_0_1;
  wire [7:0]sw_0_1;

  assign an[3:0] = CalculatorDisplayer_0_an;
  assign btnD_0_1 = btnD;
  assign btnL_0_1 = btnL;
  assign btnR_0_1 = btnR;
  assign btnU_0_1 = btnU;
  assign clock_0_1 = clock;
  assign seg[6:0] = CalculatorDisplayer_0_seg;
  assign sw_0_1 = sw[7:0];
  Calculator_CalculatorDisplayer_0_0 CalculatorDisplayer_0
       (.an(CalculatorDisplayer_0_an),
        .btnD(btnD_0_1),
        .btnL(btnL_0_1),
        .btnR(btnR_0_1),
        .btnU(btnU_0_1),
        .clock(clock_0_1),
        .seg(CalculatorDisplayer_0_seg),
        .sw(sw_0_1));
endmodule
