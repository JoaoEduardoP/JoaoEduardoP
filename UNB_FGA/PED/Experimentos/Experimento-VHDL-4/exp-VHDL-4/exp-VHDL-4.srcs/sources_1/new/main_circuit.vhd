library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity flip_flop is
    Port ( S : in STD_LOGIC;
           CLK : in STD_LOGIC;
           RST : in STD_LOGIC;
           Q : out STD_LOGIC);
end flip_flop;

architecture Behavioral of flip_flop is
begin
    process(CLK, RST)
    begin
        if RST = '0' then
            Q <= '0';
        elsif rising_edge(CLK) then
            Q <= S;
        end if;
    end process;
end Behavioral;

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity divisor_clock is
    Port ( CLK_IN : in STD_LOGIC;
           CLK_OUT : out STD_LOGIC);
end divisor_clock;

architecture Behavioral of divisor_clock is
    signal counter : integer range 0 to 62499999 := 0;
    signal temp_clk : STD_LOGIC := '0';
begin
    process(CLK_IN)
    begin
        if rising_edge(CLK_IN) then
            if counter = 62499999 then
                temp_clk <= not temp_clk;
                counter <= 0;
            else
                counter <= counter + 1;
            end if;
        end if;
    end process;
    
    CLK_OUT <= temp_clk;
end Behavioral;

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity modulo_superior is
    Port ( CLK : in STD_LOGIC;
           RST : in STD_LOGIC;
           SW : in STD_LOGIC_VECTOR(3 downto 0);
           LED : out STD_LOGIC_VECTOR(3 downto 0));
end modulo_superior;

architecture Behavioral of modulo_superior is
    signal slow_clock : STD_LOGIC;

    component flip_flop is
        Port ( S : in STD_LOGIC;
               CLK : in STD_LOGIC;
               RST : in STD_LOGIC;
               Q : out STD_LOGIC);
    end component;
    
    component divisor_clock is
        Port ( CLK_IN : in STD_LOGIC;
               CLK_OUT : out STD_LOGIC);
    end component;
    
begin
    clk_div: divisor_clock port map (
        CLK_IN => CLK,
        CLK_OUT => slow_clock
    );
    
    ff0: flip_flop port map (
        S => SW(0),
        CLK => slow_clock,
        RST => RST,
        Q => LED(0)
    );
    
    ff1: flip_flop port map (
        S => SW(1),
        CLK => slow_clock,
        RST => RST,
        Q => LED(1)
    );
    
    ff2: flip_flop port map (
        S => SW(2),
        CLK => slow_clock,
        RST => RST,
        Q => LED(2)
    );
    
    ff3: flip_flop port map (
        S => SW(3),
        CLK => slow_clock,
        RST => RST,
        Q => LED(3)
    );
    
end Behavioral;