library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity Cronom is
    Port ( CLK : in STD_LOGIC;
           SW : in STD_LOGIC_VECTOR(2 downto 0);
           AN : out STD_LOGIC_VECTOR(3 downto 0);
           SEG : out STD_LOGIC_VECTOR(6 downto 0));
end Cronom;

architecture Behavioral of Cronom is
    signal clock_d : STD_LOGIC;
    signal contadorde1hz : integer range 0 to 62499999 := 0;
    
    signal habilitarContador : STD_LOGIC := '0';
    signal min : integer range 0 to 9 := 0;
    signal dezena_segundo : integer range 0 to 5 := 0;
    signal unitario_segundo : integer range 0 to 9 := 0;
    
    signal display_select : STD_LOGIC_VECTOR(1 downto 0) := "00";
    signal current_digit : STD_LOGIC_VECTOR(3 downto 0);
    signal display_counter : integer range 0 to 62499 := 0;
    
begin
    process(CLK)
    begin
        if rising_edge(CLK) then
            if contadorde1hz = 62499999 then
                clock_d <= not clock_d;
                contadorde1hz <= 0;
            else
                contadorde1hz <= contadorde1hz + 1;
            end if;
        end if;
    end process;
    
    process(clock_d)
    begin
        if SW(2) = '1' then 
            min <= 0;
            dezena_segundo <= 0;
            unitario_segundo <= 0;
            habilitarContador <= '0';
        elsif rising_edge(clock_d) then
            if SW(0) = '1' then 
                habilitarContador <= '1';
            elsif SW(1) = '1' then  
                habilitarContador <= '0';
            end if;
            
            if habilitarContador = '1' then
                if unitario_segundo = 9 then
                    unitario_segundo <= 0;
                    if dezena_segundo = 5 then
                        dezena_segundo <= 0;
                        if min = 9 then
                            min <= 0;
                        else
                            min <= min + 1;
                        end if;
                    else
                        dezena_segundo <= dezena_segundo + 1;
                    end if;
                else
                    unitario_segundo <= unitario_segundo + 1;
                end if;
            end if;
        end if;
    end process;
    
    process(CLK)
    begin
        if rising_edge(CLK) then
            if display_counter = 62499 then
                display_counter <= 0;
                display_select <= std_logic_vector(unsigned(display_select) + 1);
            else
                display_counter <= display_counter + 1;
            end if;
        end if;
    end process;
    
    with display_select select
        current_digit <= std_logic_vector(to_unsigned(min, 4)) when "00",
                         std_logic_vector(to_unsigned(dezena_segundo, 4)) when "01",
                         std_logic_vector(to_unsigned(unitario_segundo, 4)) when others;
                        
    with display_select select
        AN <= "1110" when "00",
              "1101" when "01",
              "1011" when "10",
              "1111" when others;
              
    process(current_digit)
    begin
        case current_digit is
            when "0000" => SEG <= "0000001"; -- 0
            when "0001" => SEG <= "1001111"; -- 1
            when "0010" => SEG <= "0010010"; -- 2
            when "0011" => SEG <= "0000110"; -- 3
            when "0100" => SEG <= "1001100"; -- 4
            when "0101" => SEG <= "0100100"; -- 5
            when "0110" => SEG <= "0100000"; -- 6
            when "0111" => SEG <= "0001111"; -- 7
            when "1000" => SEG <= "0000000"; -- 8
            when "1001" => SEG <= "0000100"; -- 9
            when others => SEG <= "1111111"; -- apagado
        end case;
    end process;
    
end Behavioral;