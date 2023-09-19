`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/15/2023 06:17:21 PM
// Design Name: 
// Module Name: ROM
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

module ROM
#(
    parameter RAM_WIDTH = 8,
    parameter RAM_ADDR_BITS = 5,
    parameter INITFILE = ""
)
(
    output reg [RAM_WIDTH-1:0] outData,
    input [RAM_ADDR_BITS-1:0] address,
    input clock
    );

    (* rom_style="block" *) reg [RAM_WIDTH-1:0] mem [(2**RAM_ADDR_BITS)-1:0];
    
    initial $readmemb(INITFILE, mem);
    
    
    always @(posedge clock) begin
        outData <= mem[address];
    end
endmodule

