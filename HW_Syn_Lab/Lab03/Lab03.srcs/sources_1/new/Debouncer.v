`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/06/2023 10:36:50 PM
// Design Name: 
// Module Name: Debouncer
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module Debouncer(
    output Q,
    input D,
    input clock
    );
    wire [2:0] signal;
    assign signal[0] = D;
    assign Q = signal[2] & signal[1] & signal[0];
    genvar i;
    generate for(i=0;i<2;i=i+1) begin
        DFlipFlop db(signal[i+1],clock,1'b1,signal[i]);
    end endgenerate
endmodule
