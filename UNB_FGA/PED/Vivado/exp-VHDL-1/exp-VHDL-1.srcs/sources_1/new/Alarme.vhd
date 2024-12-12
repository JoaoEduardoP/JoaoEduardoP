----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 21.11.2024 17:16:49
-- Design Name: 
-- Module Name: Alarme - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity Alarme is
    Port ( P : in STD_LOGIC;
           I : in STD_LOGIC;
           F : in STD_LOGIC;
           S : out STD_LOGIC);
end Alarme;

architecture Behavioral of Alarme is

begin

    S <= (F AND NOT I) OR (P AND I);

end Behavioral;
