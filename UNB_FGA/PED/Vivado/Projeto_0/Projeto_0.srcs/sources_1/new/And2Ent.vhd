----------------------------------------------------------------------------------
-- Company: Universidade de Brasília
-- Engineer: João Eduardo Pereira Rabelo
-- 
-- Create Date: 20.11.2024 22:12:44
-- Design Name: Porta AND com duas Entradas 
-- Module Name: And2Ent - Behavioral
-- Project Name: Projeto AND
-- Target Devices: 
-- Tool Versions: 0.0.1
-- Description: Design de uma porta And com duas entradas e uma saída
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity And2Ent is
    Port ( a : in STD_LOGIC;
           b : in STD_LOGIC;
           s : out STD_LOGIC);
end And2Ent;

architecture Behavioral of And2Ent is

begin

    s <= a and b;

end Behavioral;
