-- Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
-- Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2023.1 (win64) Build 3865809 Sun May  7 15:05:29 MDT 2023
-- Date        : Tue Sep 19 12:54:32 2023
-- Host        : PHUMIPAT-C running 64-bit major release  (build 9200)
-- Command     : write_vhdl -force -mode synth_stub
--               d:/Code/CU/HW_Syn_Lab/Lab04/Lab04.gen/sources_1/bd/Calculator/ip/Calculator_CalculatorDisplayer_0_0/Calculator_CalculatorDisplayer_0_0_stub.vhdl
-- Design      : Calculator_CalculatorDisplayer_0_0
-- Purpose     : Stub declaration of top-level module interface
-- Device      : xc7a35tcpg236-1
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Calculator_CalculatorDisplayer_0_0 is
  Port ( 
    seg : out STD_LOGIC_VECTOR ( 6 downto 0 );
    an : out STD_LOGIC_VECTOR ( 3 downto 0 );
    sw : in STD_LOGIC_VECTOR ( 7 downto 0 );
    btnU : in STD_LOGIC;
    btnL : in STD_LOGIC;
    btnD : in STD_LOGIC;
    btnR : in STD_LOGIC;
    clock : in STD_LOGIC
  );

end Calculator_CalculatorDisplayer_0_0;

architecture stub of Calculator_CalculatorDisplayer_0_0 is
attribute syn_black_box : boolean;
attribute black_box_pad_pin : string;
attribute syn_black_box of stub : architecture is true;
attribute black_box_pad_pin of stub : architecture is "seg[6:0],an[3:0],sw[7:0],btnU,btnL,btnD,btnR,clock";
attribute X_CORE_INFO : string;
attribute X_CORE_INFO of stub : architecture is "CalculatorDisplayer,Vivado 2023.1";
begin
end;
