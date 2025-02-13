library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity D_flip_flop is
    Port ( D   : in STD_LOGIC;
           CLK : in STD_LOGIC;
           R   : in STD_LOGIC;  -- Reset ativo em nível baixo
           Q   : out STD_LOGIC
    );
end D_flip_flop;

architecture Behavioral of D_flip_flop is
begin
    process (CLK, R)
    begin
        if (R = '0') then
            Q <= '0';  -- Resetar saída
        elsif (rising_edge(CLK)) then
            Q <= D;  -- Transferir valor de D para Q
        end if;
    end process;
end Behavioral;
