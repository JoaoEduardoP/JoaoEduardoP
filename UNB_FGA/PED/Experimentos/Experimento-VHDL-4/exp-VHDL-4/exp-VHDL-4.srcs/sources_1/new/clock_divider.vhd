library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity clock_divider is
    Port ( clk_in  : in STD_LOGIC;  -- Clock de 100 MHz
           reset   : in STD_LOGIC;  -- Reset
           clk_out : out STD_LOGIC  -- Clock de 1 Hz
    );
end clock_divider;

architecture Behavioral of clock_divider is
    constant DIVISOR : integer := 100_000_000 / 2; -- Metade da frequência (1Hz)
    signal counter   : integer := 0;
    signal clk_reg   : STD_LOGIC := '0';
begin
    process (clk_in, reset)
    begin
        if (reset = '0') then
            counter <= 0;
            clk_reg <= '0';
        elsif (rising_edge(clk_in)) then
            if (counter = DIVISOR - 1) then
                counter <= 0;
                clk_reg <= not clk_reg;
            else
                counter <= counter + 1;
            end if;
        end if;
    end process;

    clk_out <= clk_reg;
end Behavioral;
