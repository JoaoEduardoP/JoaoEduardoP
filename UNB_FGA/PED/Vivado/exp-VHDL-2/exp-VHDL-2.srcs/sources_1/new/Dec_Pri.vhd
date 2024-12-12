----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 05.12.2024 17:08:25
-- Design Name: 
-- Module Name: Dec_Pri - Behavioral
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

entity Dec_Pri is
    Port ( p0 : in STD_LOGIC;
           p1 : in STD_LOGIC;
           p2 : in STD_LOGIC;
           p3 : in STD_LOGIC;
           x1 : out STD_LOGIC;
           x0 : out STD_LOGIC;
           int : out STD_LOGIC);
end Dec_Pri;

architecture Behavioral of Dec_Pri is

begin

    x1 <= p0 NOR p1;
    x0 <= NOT p0 AND (NOT p2 OR p1);
    int <= p0 OR p1 OR p2 OR p3;

end Behavioral;
