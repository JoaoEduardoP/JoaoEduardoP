library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity ULA_tb is
end ULA_tb;

architecture Behavioral of ULA_tb is

    -- Componente ULA
    component ULA is
        Port ( A     : in STD_LOGIC_VECTOR(3 downto 0);
               B     : in STD_LOGIC_VECTOR(3 downto 0);
               S     : in STD_LOGIC_VECTOR(1 downto 0);
               F     : out STD_LOGIC_VECTOR(3 downto 0);
               over  : out STD_LOGIC;
               c_out : out STD_LOGIC );
    end component;

    -- Sinais para estímulo e monitoramento
    signal S_A     : STD_LOGIC_VECTOR(3 downto 0) := "0000";
    signal S_B     : STD_LOGIC_VECTOR(3 downto 0) := "0000";
    signal S_S     : STD_LOGIC_VECTOR(1 downto 0) := "00";  -- Soma
    signal S_F     : STD_LOGIC_VECTOR(3 downto 0);
    signal S_over  : STD_LOGIC;
    signal S_c_out : STD_LOGIC;

begin

    -- Instância da ULA
    uut: ULA port map(
        A     => S_A,
        B     => S_B,
        S     => S_S,
        F     => S_F,
        over  => S_over,
        c_out => S_c_out
    );

    -- Estímulos para os sinais
    process
    begin
        
        for i in 0 to 15 loop
            for n in 0 to 15 loop
            -- A e B variam de 0000 a 1111
                -- Convertendo os valores de i e j para binário manualmente
                case i is
                    when 0  => S_A <= "0000";
                    when 1  => S_A <= "0001";
                    when 2  => S_A <= "0010";
                    when 3  => S_A <= "0011";
                    when 4  => S_A <= "0100";
                    when 5  => S_A <= "0101";
                    when 6  => S_A <= "0110";
                    when 7  => S_A <= "0111";
                    when 8  => S_A <= "1000";
                    when 9  => S_A <= "1001";
                    when 10 => S_A <= "1010";
                    when 11 => S_A <= "1011";
                    when 12 => S_A <= "1100";
                    when 13 => S_A <= "1101";
                    when 14 => S_A <= "1110";
                    when 15 => S_A <= "1111";
                    when others => S_A <= "0000"; -- Caso de fallback
                end case;

                case n is
                    when 0  => S_B <= "0000";
                    when 1  => S_B <= "0001";
                    when 2  => S_B <= "0010";
                    when 3  => S_B <= "0011";
                    when 4  => S_B <= "0100";
                    when 5  => S_B <= "0101";
                    when 6  => S_B <= "0110";
                    when 7  => S_B <= "0111";
                    when 8  => S_B <= "1000";
                    when 9  => S_B <= "1001";
                    when 10 => S_B <= "1010";
                    when 11 => S_B <= "1011";
                    when 12 => S_B <= "1100";
                    when 13 => S_B <= "1101";
                    when 14 => S_B <= "1110";
                    when 15 => S_B <= "1111";
                    when others => S_B <= "0000"; -- Caso de fallback
                end case;
                
                -- Teste para operação de soma (S = "00")
                S_S <= "00";  -- Soma
                wait for 10 ns;

                -- Teste para operação de subtração (S = "01")
                S_S <= "01";  -- Subtração
                wait for 10 ns;

                -- Teste para operação AND (S = "10")
                S_S <= "10";  -- AND
                wait for 10 ns;

                -- Teste para operação OR (S = "11")
                S_S <= "11";  -- OR
                wait for 10 ns;
            
            end loop;
        end loop;

        -- Finaliza a simulação
        wait;
    end process;

end Behavioral;
