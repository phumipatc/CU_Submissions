//Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
//Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2023.1 (win64) Build 3865809 Sun May  7 15:05:29 MDT 2023
//Date        : Tue Sep 19 12:53:56 2023
//Host        : PHUMIPAT-C running 64-bit major release  (build 9200)
//Command     : generate_target Calculator_wrapper.bd
//Design      : Calculator_wrapper
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

module Calculator_wrapper
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
  input clock;
  output [6:0]seg;
  input [7:0]sw;

  wire [3:0]an;
  wire btnD;
  wire btnL;
  wire btnR;
  wire btnU;
  wire clock;
  wire [6:0]seg;
  wire [7:0]sw;

  Calculator Calculator_i
       (.an(an),
        .btnD(btnD),
        .btnL(btnL),
        .btnR(btnR),
        .btnU(btnU),
        .clock(clock),
        .seg(seg),
        .sw(sw));
endmodule
